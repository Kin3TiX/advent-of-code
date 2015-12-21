// Includes
#include "Node.h"
#include <iostream>
#include "conio.h"
#include <vector>
#include <unordered_map>
#include <fstream>
#include <regex>

// Nodes representing tree roots (aka sources)
typedef struct algorithm_source {
	Node * starting_node;
	unsigned short starting_value;
};

// Regular expressions for parsing components/nets
std::regex regex_net		(".+->\\s(.+)"							);
std::regex regex_src		("([0-9]+)\\s->\\s(.+)"					);
std::regex regex_and		("(.+)\\sAND\\s(.+)\\s->\\s(.+)"		);
std::regex regex_or			("(.+)\\sOR\\s(.+)\\s->\\s(.+)"			);
std::regex regex_not		("NOT\\s(.+)\\s->\\s(.+)"				);
std::regex regex_lshft		("(.+)\\sLSHIFT\\s([0-9]+)\\s->\\s(.+)"	);
std::regex regex_rshft		("(.+)\\sRSHIFT\\s([0-9]+)\\s->\\s(.+)"	);
std::regex regex_link		("([^0-9]{1,2})\\s->\\s(.+)"				);

// Data structures for implementing algorithm
std::vector<Node*> algorithm_components;
std::vector<algorithm_source*> algorithm_sources;
std::unordered_map<std::string, Net*> algorithm_nets;
std::vector<Net*> algorithm_dummies;

// File IO data
std::ifstream token_file("C:\\Users\\Owen James\\Documents\\Visual Studio 2015\\Projects\\AdventDay 7\\input2.txt"); // Input modified for part 2
std::string token_buffer;

// Parse net information from file
void getNets() {

	while( std::getline(token_file, token_buffer) ) {

		std::smatch token_matches;
		std::regex_match(token_buffer, token_matches, regex_net);
		std::string token_net = token_matches[token_matches.size() - 1].str();

		if( !algorithm_nets.count(token_net) ) {
			Net* algorithm_node = new Net(token_net);
			algorithm_nets.insert(std::pair<std::string, Net*>(token_net, algorithm_node));
		}

	}
	token_file.clear();
	token_file.seekg(0, std::ios::beg);

}

// Parse component information from file
void getComponents() {

	std::regex regex_list[] = { regex_src, regex_and, regex_or, regex_not, regex_lshft, regex_rshft, regex_link };

	while( std::getline(token_file, token_buffer) ) {

		for( int i = 0; i < 7; ++i ) {

			std::smatch token_matches;
			std::regex_match(token_buffer, token_matches, regex_list[i]);

			if( token_matches.empty() )
				continue;

			std::unordered_map<std::string, Net*>::iterator token_lookup;
			std::unordered_map<std::string, Net*>::iterator token_temp_lookup;

			switch(i) {

				case 0:
				{
					token_lookup = algorithm_nets.find(token_matches[2].str());
					algorithm_source* src = new algorithm_source();
					src->starting_node = (*token_lookup).second;
					src->starting_value = stoi(token_matches[1].str());
					algorithm_sources.push_back(src);
					break;
				}

				case 1:
				{

					And* a = new And();

					token_lookup = algorithm_nets.find(token_matches[1].str());
					if( token_lookup != algorithm_nets.end() ) {
						a->addInput((*token_lookup).second);
						(*token_lookup).second->addOutput(a);
					} else {
						Net* temp = new Net("");
						temp->setUpdated(true);
						algorithm_dummies.push_back(temp);
						a->addInput(temp);
						a->setInputA(std::pair<short, bool>(stoi(token_matches[1].str()), true));
					}

					token_lookup = algorithm_nets.find(token_matches[2].str());
					if( token_lookup != algorithm_nets.end() ) {
						a->addInput((*token_lookup).second);
						(*token_lookup).second->addOutput(a);
					} else {
						Net* temp = new Net("");
						temp->setUpdated(true);
						algorithm_dummies.push_back(temp);
						a->addInput(temp);
						a->setInputB(std::pair<short, bool>(stoi(token_matches[2].str()), true));
					}

					token_lookup = algorithm_nets.find(token_matches[3].str());
					a->addOutput((*token_lookup).second);
					algorithm_components.push_back(a);
					break;
				}

				case 2:
				{
					Or* o = new Or();

					token_lookup = algorithm_nets.find(token_matches[1].str());
					if( token_lookup != algorithm_nets.end() ) {
						o->addInput((*token_lookup).second);
						(*token_lookup).second->addOutput(o);
					} else {
						Net* temp = new Net("");
						temp->setUpdated(true);
						algorithm_dummies.push_back(temp);
						o->addInput(temp);
						o->setInputA(std::pair<short, bool>(stoi(token_matches[1].str()), true));
					}

					token_lookup = algorithm_nets.find(token_matches[2].str());
					if( token_lookup != algorithm_nets.end() ) {
						o->addInput((*token_lookup).second);
						(*token_lookup).second->addOutput(o);
					} else {
						Net* temp = new Net("");
						temp->setUpdated(true);
						algorithm_dummies.push_back(temp);
						o->addInput(temp);
						o->setInputB(std::pair<short, bool>(stoi(token_matches[2].str()), true));
					}

					token_lookup = algorithm_nets.find(token_matches[3].str());
					o->addOutput((*token_lookup).second);
					algorithm_components.push_back(o);
					break;
				}

				case 3:
				{
					Not* n = new Not();

					token_lookup = algorithm_nets.find(token_matches[1].str());
					if( token_lookup != algorithm_nets.end() ) {
						n->addInput((*token_lookup).second);
						(*token_lookup).second->addOutput(n);
					} else {

					}

					token_lookup = algorithm_nets.find(token_matches[2].str());
					n->addOutput((*token_lookup).second);
					algorithm_components.push_back(n);
					break;
				}

				case 4:
				{
					Lshift* l = new Lshift(stoi(token_matches[2].str()));

					token_lookup = algorithm_nets.find(token_matches[1].str());
					if( token_lookup != algorithm_nets.end() ) {
						l->addInput((*token_lookup).second);
						(*token_lookup).second->addOutput(l);
					} else {

					}

					token_lookup = algorithm_nets.find(token_matches[3].str());
					l->addOutput((*token_lookup).second);
					algorithm_components.push_back(l);
					break;
				}

				case 5:
				{
					Rshift* r = new Rshift(stoi(token_matches[2].str()));

					token_lookup = algorithm_nets.find(token_matches[1].str());
					if( token_lookup != algorithm_nets.end() ) {
						r->addInput((*token_lookup).second);
						(*token_lookup).second->addOutput(r);
					} else {

					}

					token_lookup = algorithm_nets.find(token_matches[3].str());
					r->addOutput((*token_lookup).second);
					algorithm_components.push_back(r);
					break;
				}

				case 6:
				{
					
					token_lookup = algorithm_nets.find(token_matches[1].str());
					token_temp_lookup = algorithm_nets.find(token_matches[2].str());
					(*token_lookup).second->addOutput((*token_temp_lookup).second);
					(*token_temp_lookup).second->addInput((*token_lookup).second);
					break;
				}

				default:
					break;

			}

		}

	}
	token_file.clear();
	token_file.seekg(0, std::ios::beg);

}

// ENTRYPOINT
void main() {

	// Initialize data structures based on file input
	getNets();
	getComponents();

	// Start recursing through the tree(s)
	for( std::vector<algorithm_source*>::iterator i = algorithm_sources.begin(); i != algorithm_sources.end(); ++i ) {
		(*i)->starting_node->propogate((*i)->starting_value, nullptr);
	}
	
	// Search for and display result of net 'a'
	std::unordered_map<std::string, Net*>::iterator a = algorithm_nets.find("a");
	if( a != algorithm_nets.end() )
		std::cout << "Node a: " << (*a).second->getValue() << std::endl;
	else
		std::cout << "Could not find node a in the extracted nets" << std::endl;

	/*
	// DEBUG
	// Show state of all nets
	for( std::unordered_map<std::string, Net*>::iterator i = algorithm_nets.begin(); i != algorithm_nets.end(); ++i ) {
		std::cout << "Node " << (*i).second->getName() << ": " << (*i).second->getValue() << std::endl;
	}
	*/

	// Wait for user to finish reviewing data
	std::cout << "Press any key to continue..." << std::endl;
	while( !_kbhit() ) {
	}

	// Free nets
	for( std::unordered_map<std::string, Net*>::iterator i = algorithm_nets.begin(); i != algorithm_nets.end(); ++i ) {
		if( (*i).second )
			delete (*i).second;
	}
	algorithm_nets.clear();

	// Free components
	for( std::vector<Node*>::iterator i = algorithm_components.begin(); i != algorithm_components.end(); ++i ) {
		if( (*i) )
			delete (*i);
	}
	algorithm_components.clear();

	// Free sources
	for( std::vector<algorithm_source*>::iterator i = algorithm_sources.begin(); i != algorithm_sources.end(); ++i ) {
		if( (*i) ) {
			delete (*i);
		}
	}
	algorithm_sources.clear();

	// Free dummies
	for( std::vector<Net*>::iterator i = algorithm_dummies.begin(); i != algorithm_dummies.end(); ++i ) {
		if( (*i) ) {
			delete (*i);
		}
	}
	algorithm_dummies.clear();

}