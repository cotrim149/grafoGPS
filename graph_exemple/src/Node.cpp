/*
 * Node.cpp
 *
 *  Created on: Oct 28, 2014
 *      Author: cotrim
 */

#include "Node.h"

Node::Node() {
	// TODO Auto-generated constructor stub

}

Node::~Node() {
	// TODO Auto-generated destructor stub
}

void Node::insertEdge(Node node){
	degree.insert(degree.begin(),node);
}

void Node::removeEdge(Node node){

	int id=-1;

	for(unsigned int i=0;i < degree.size(); i++){
		if(degree.at(i).id == node.id){
			id = i;
		}

	}
	if(id >=0){
		degree.erase(degree.begin()+id);
		cout << "Edge " << node.id << " removed from node " << this->id << endl;
	}
	else
		cout << "Edge " << node.id << " not found in node " << this->id << endl;

}
