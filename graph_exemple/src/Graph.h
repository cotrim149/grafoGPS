/*
 * Graph.h
 *
 *  Created on: Oct 27, 2014
 *      Author: cotrim
 */

#ifndef GRAPH_H_
#define GRAPH_H_
#include <stdio.h>
#include <vector>
#include "Node.h"

using namespace std;

class Graph {
public:
	Graph();
	virtual ~Graph();

	int id;

	vector<Node> nodes;

	void insertNode(Node node);
	void removeNode(Node node);

	void busca(Graph component,bool type);


};

#endif /* GRAPH_H_ */
