#include "Node.h"
#include <iostream>
#include "conio.h"

// This function was first static attempt at making the algorithm work
void test() {

	// Nets
	Net d = Net("d");
	Net e = Net("e");
	Net f = Net("f");
	Net g = Net("g");
	Net h = Net("h");
	Net i = Net("i");
	Net x = Net("x");
	Net y = Net("y");

	// Components
	And a1 = And();
	Or o1 = Or();
	Lshift l1 = Lshift(2);
	Rshift r1 = Rshift(2);
	Not n1 = Not();
	Not n2 = Not();

	//Set Component Inputs
	a1.addInput(&x);
	a1.addInput(&y);
	a1.addOutput(&d);
	o1.addInput(&x);
	o1.addInput(&y);
	o1.addOutput(&e);
	l1.addInput(&x);
	l1.addOutput(&f);
	r1.addInput(&y);
	r1.addOutput(&g);
	n1.addInput(&x);
	n1.addOutput(&h);
	n2.addInput(&y);
	n2.addOutput(&i);

	//Set Net Outputs
	x.addOutput(&a1);
	x.addOutput(&o1);
	x.addOutput(&l1);
	x.addOutput(&n1);
	y.addOutput(&a1);
	y.addOutput(&o1);
	y.addOutput(&r1);
	y.addOutput(&n2);

	//Start Algorithm
	x.propogate(123, nullptr);
	y.propogate(456, nullptr);

	std::cout << "Node d: " << d.getValue() << std::endl;
	std::cout << "Node e: " << e.getValue() << std::endl;
	std::cout << "Node f: " << f.getValue() << std::endl;
	std::cout << "Node g: " << g.getValue() << std::endl;
	std::cout << "Node h: " << h.getValue() << std::endl;
	std::cout << "Node i: " << i.getValue() << std::endl;
	std::cout << "Node x: " << x.getValue() << std::endl;
	std::cout << "Node y: " << y.getValue() << std::endl;
	std::cout << "Press any key to continue..." << std::endl;

	while( !_kbhit() ) {
	}

}