#pragma once
#include <vector>
#include <string>

class Node {

public:

	Node() { }

	~Node() { }

	inline void addInput(Node* i) {
		inputs.push_back(i);
	}

	inline void addOutput(Node* o) {
		outputs.push_back(o);
	}

	inline Node* getInput(unsigned short i) {
		if(i<inputs.size() )
			return inputs[i];
		return nullptr;
	}

	inline Node* getOutput(unsigned short i) {
		if( i<outputs.size() )
			return outputs[i];
		return nullptr;
	}

	virtual void propogate(unsigned short v, Node* caller) { };

private:

	std::vector<Node*> inputs;
	std::vector<Node*> outputs;

};

class Net : public Node {

public:

	Net(std::string n) : name(n), value(0), updated(false) { }

	~Net() { }

	inline void setUpdated(bool u) {
		updated = u;
	}

	inline bool getUpdated() {
		return updated;
	}

	inline void setValue(unsigned short v) {
		value = v;
	}

	inline unsigned short getValue() {
		return value;
	}

	inline void setName(std::string n) {
		name = n;
	}

	inline std::string getName() {
		return name;
	}

	virtual void propogate(unsigned short v, Node* caller) {

		value = v;
		updated = true;
		
		unsigned short i = 0;
		Node* current;
		while( current = getOutput(i) ) {
			++i;
			current->propogate(value, this);
		}

	}

private:

	bool updated;
	unsigned short value;
	std::string name;

};

class And : public Node {

public:

	inline std::pair<unsigned short, bool> getInputA() {
		return inputA;
	}

	inline void setInputA(std::pair<unsigned short, bool> inA) {
		inputA = inA;
	}

	inline std::pair<unsigned short, bool> getInputB() {
		return inputB;
	}

	inline void setInputB(std::pair<unsigned short, bool> inB) {
		inputB = inB;
	}

	virtual void propogate(unsigned short v, Node* caller) {

		unsigned short i;
		for( i = 0; i < 2; i++ ) {
			Node* current = getInput(i);
			if( current == caller )
				break;
		}
		if( i == 0 )
			setInputA(std::pair<unsigned short, bool>(v, true));
		else
			setInputB(std::pair<unsigned short, bool>(v, true));

		if( inputA.second && inputB.second ) {
			unsigned short temp = inputA.first & inputB.first;
			Node* output = getOutput(0);
			output->propogate(temp, this);
		}

	}

private:

	std::pair<unsigned short, bool> inputA;
	std::pair<unsigned short, bool> inputB;

};

class Or : public Node {

public:

	inline std::pair<unsigned short, bool> getInputA() {
		return inputA;
	}

	inline void setInputA(std::pair<unsigned short, bool> inA) {
		inputA = inA;
	}

	inline std::pair<unsigned short, bool> getInputB() {
		return inputB;
	}

	inline void setInputB(std::pair<unsigned short, bool> inB) {
		inputB = inB;
	}

	virtual void propogate(unsigned short v, Node* caller) {

		unsigned short i;
		for( i = 0; i < 2; i++ ) {
			Node* current = getInput(i);
			if( current == caller )
				break;
		}
		if( i == 0 )
			setInputA(std::pair<unsigned short, bool>(v, true));
		else
			setInputB(std::pair<unsigned short, bool>(v, true));

		if( inputA.second && inputB.second ) {
			unsigned short temp = inputA.first | inputB.first;
			Node* output = getOutput(0);
			output->propogate(temp, this);
		}

	}

private:

	std::pair<unsigned short, bool> inputA;
	std::pair<unsigned short, bool> inputB;

};

class Not : public Node {

public:

	virtual void propogate(unsigned short v, Node* caller) {
	
		getOutput(0)->propogate(~v, this);

	}

};

class Lshift : public Node {

public:

	Lshift(unsigned short s = 0 ) : shift(s) { }
	~Lshift() { }

	virtual void propogate(unsigned short v, Node* caller) {

		getOutput(0)->propogate(v << shift, this);

	}

private:

	unsigned short shift;

};

class Rshift : public Node {

public:

	Rshift(unsigned short s = 0) : shift(s) { }
	~Rshift() { }

	virtual void propogate(unsigned short v, Node* caller) {

		getOutput(0)->propogate(v >> shift, this);

	}

private:

	unsigned short shift;

};