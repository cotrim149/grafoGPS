//============================================================================
// Name        : graph_exemple.cpp
// Author      : Cotrim
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include "Graph.h"
#include "Node.h"


int main() {
	cout << "Hello World baby" << endl; // prints Hello World baby

	Graph graph1;
	graph1.id=1;

	Node node1; // faz o conjunto para graph
	node1.id=1;
	Node node2;
	node2.id=2;
	Node node3;
	node3.id=3;
	Node node4;
	node4.id=4;
	Node node5;
	node5.id=5;
	Node node6;
	node6.id=6;
	Node node7;
	node7.id=7;


	node1.insertEdge(node2);
	node1.insertEdge(node3);
	node1.insertEdge(node7);

	node2.insertEdge(node3);
	node2.insertEdge(node4);

	node3.insertEdge(node2);
	node3.insertEdge(node4);
	node3.insertEdge(node5);

	node4.insertEdge(node1);
	node4.insertEdge(node6);

	node5.insertEdge(node1);
	node5.insertEdge(node4);

	node6.insertEdge(node1);
	node6.insertEdge(node5);
	node6.insertEdge(node4);

	node7.insertEdge(node1);
	node7.insertEdge(node2);


	graph1.insertNode(node1);
	graph1.insertNode(node2);
	graph1.insertNode(node3);
	graph1.insertNode(node4);
	graph1.insertNode(node5);
	graph1.insertNode(node6);
	graph1.insertNode(node7);

	cout << "Nodes in Graph: " << graph1.nodes.size() << endl;

	cout << "Degree node1: " << node1.degree.size() << endl;
	cout << "Degree node2: " << node2.degree.size() << endl;
	cout << "Degree node3: " << node3.degree.size() << endl;
	cout << "Degree node4: " << node4.degree.size() << endl;
	cout << "Degree node5: " << node5.degree.size() << endl;
	cout << "Degree node6: " << node6.degree.size() << endl;
	cout << "Degree node7: " << node7.degree.size() << endl;

//	cout << "\nRemoving node 4 from graph" << endl;
//	graph1.removeNode(node4);
//
//	cout << "Nodes in Graph: " << graph1.nodes.size() << endl;
//
//	for(unsigned int i=0; i < graph1.nodes.size(); i++){
//		cout << "\nDegree node" << graph1.nodes.at(i).id << ": " << graph1.nodes.at(i).degree.size() << endl;
//
//	}

	Graph copiedGraph = graph1;

	cout << "Busca em largura" << endl;
	graph1.busca(copiedGraph,true);

	Graph copiedGraph2 = graph1;

	cout << "\nBusca em Profundidade" << endl;
	graph1.busca(copiedGraph2,false);

//	teste de copia
//	printf("\nPonteiro original: %p \nPonteiro copiado: %p\n",&graph1,&copiedGraph);
//
//	copiedGraph.nodes.at(0).removeEdge(node2);
//
//	cout << "Degree node 1, copied graph: "<<copiedGraph.nodes.at(0).degree.size() << endl;
//	cout << "Degree node 1, graph1 : "<<graph1.nodes.at(0).degree.size() << endl;

	return 0;
}
