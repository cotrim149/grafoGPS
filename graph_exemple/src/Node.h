/*
 * Node.h
 *
 *  Created on: Oct 28, 2014
 *      Author: cotrim
 */

#ifndef NODE_H_
#define NODE_H_
#include <iostream>
#include <vector>

using namespace std;

class Node {
public:
	Node();
	virtual ~Node();
	int id;
	vector<Node> degree;

	void insertEdge(Node node);
	void removeEdge(Node node);
};

#endif /* NODE_H_ */
