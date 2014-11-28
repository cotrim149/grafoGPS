/*
 * Graph.cpp
 *
 *  Created on: Oct 27, 2014
 *      Author: cotrim
 */

#include "Graph.h"

Graph::Graph() {
	// TODO Auto-generated constructor stub

}

Graph::~Graph() {
	// TODO Auto-generated destructor stub
}

void Graph::insertNode(Node node){
	nodes.push_back(node);
}

void Graph::removeNode(Node node){


	for(unsigned int i=0; i<this->nodes.size();i++){
		this->nodes.at(i).removeEdge(node);

	}

	cout << "Removed all edges linked" << endl;

	int id=-1;

	for(unsigned int i=0; i < this->nodes.size(); i++){
		if(this->nodes.at(i).id == node.id){
			id = i;
		}
	}

	if(id >= 0){
		this->nodes.erase(this->nodes.begin()+id);
	}else{
		cout << "Node " << node.id << " not found in node " << this->id << endl;
	}
}

bool nodeRoundVisited = false;
bool putNodeInSelectedVector(vector<Node> *visitedNodes, Node node, vector<Node> *selectedVector, bool type){

	bool existNode = false;

	for(unsigned int i=0;i<visitedNodes->size();i++){
		if(visitedNodes->at(i).id == node.id){
			existNode = true;
			cout << "ID Nó:" << node.id << "ja foi visitado"<< endl;
		}
	}
	if(!existNode){
		if(type){// fila
			visitedNodes->push_back(node);
			selectedVector->insert(selectedVector->begin(),node);
			cout << "ID Nó:" << node.id << " sendo visitado e colocando na Fila"<< endl;

		}else{/// pilha

			if(!nodeRoundVisited){
				visitedNodes->push_back(node);
				nodeRoundVisited = true;
				cout << "ID Nó:" << node.id << " sendo visitado e colocando na Pilha"<< endl;
			}else{
				cout << "ID Nó:" << node.id << " colocando na Pilha"<< endl;
			}

			selectedVector->push_back(node);

		}


	}

	return existNode;
}


void printLine(vector<Node> line){

	if(line.size() == 0){
		cout << "Fila vazia!" << endl;
	}else{
		for(unsigned int i=0; i<line.size();i++){
			cout << line.at(i).id << " ";
		}

		cout << endl;
	}


}

/*
 * type true = busca largura
 * type false = busca profundidade
 */

void Graph::busca(Graph component, bool type){


	vector<Node> stackOrLine;
	vector<Node> visitedNodes;

	while(component.nodes.size()!=0){

		printLine(stackOrLine);

		Node node = component.nodes.at(component.nodes.size()-1);
		component.nodes.pop_back();

		putNodeInSelectedVector(&visitedNodes,node,&stackOrLine,type);

		while(stackOrLine.size()!=0){
			//Dequeue ou desempilhamento
			Node visitationNode = stackOrLine.at(stackOrLine.size()-1);
			stackOrLine.pop_back();

			if(type){
				cout << "tirando da fila : " << visitationNode.id << endl;

			}else{
				cout << "tirando da pilha : " << visitationNode.id << endl;

			}

			int degreeNode = visitationNode.degree.size();
			cout << "Degree: "<< degreeNode << endl;

			for(int i=0;i<degreeNode;i++){
				// recupera vertice
				Node edge = visitationNode.degree.at(visitationNode.degree.size()-1);
				visitationNode.degree.pop_back();
				cout << "id node: " << node.id << endl;

				if(i == (degreeNode-1))
					nodeRoundVisited = false;

				// verifica se o nó ligado ao vertice já foi visitado
				// Verifica se foi explorado, se não foi explorado add o vértice como visistado e coloca na fila ou pilha
				putNodeInSelectedVector(&visitedNodes,edge,&stackOrLine,type);
				printLine(stackOrLine);
			}

		}
	}
}

void printMatrix(int** matrix, unsigned int sizeMatrix){

	for(int line=0;line<sizeMatrix;line++){
		cout << "dentro 1 for " << line << endl;

		for(int column=0;column<sizeMatrix;column++){
			cout << " " << matrix[line][column] << " ";
			cout << "trste " << column<< endl;
			if(column == sizeMatrix-1)
				cout << endl;

		}
	}

}

int** Graph::getAdjacencyMatrix(){
	int sizeMatrix = nodes.size();
	int** matrix = (int**)malloc(sizeof(int*)*sizeMatrix);

	// Alloc matrix
	for(int line=0;line<sizeMatrix;line++){
		matrix[line] = (int*)malloc(sizeof(int)*sizeMatrix);
	}


	for(int line=0;line<sizeMatrix;line++){
		for(int column=0;column<sizeMatrix;column++){
			matrix[line][column]=0;
		}
	}
	// make matrix
	for(int i=0;i<sizeMatrix;i++){
		int idNode = nodes.at(i).id;

		for(unsigned int edges=0;edges<nodes.at(i).degree.size();edges++){
			int idEdge = nodes.at(i).degree.at(edges).id;

			matrix[idNode-1][idEdge-1] = 1;

		}
	}

	cout << "Adjacency Matrix!" << endl;
	for(int line=0;line<sizeMatrix;line++){
		for(int column=0;column<sizeMatrix;column++){
			cout << " " << matrix[line][column] << " ";
			if(column == sizeMatrix-1)
				cout << endl;
		}
	}

//	printf("matrix address %p",&matrix);
	return matrix;

}

int** Graph::getReverseAdjacencyMatrix(){
	int** matrix = getAdjacencyMatrix();

	int sizeMatrix = nodes.size();

	int** reverseMatrix = (int**)malloc(sizeof(int*)*sizeMatrix);

	for(int line=0;line<sizeMatrix;line++){
		reverseMatrix[line] = (int*)malloc(sizeof(int)*sizeMatrix);
	}

	for(int i=0;i<sizeMatrix;i++){
		for(int j=0;j<sizeMatrix;j++){
			reverseMatrix[i][j] = 0;
			if(matrix[j][i] == 1){
				reverseMatrix[i][j] = 1;
			}
		}
	}

	cout << "Reverse Matrix!" << endl;
	for(int line=0;line<sizeMatrix;line++){
		for(int column=0;column<sizeMatrix;column++){
			cout << " " << reverseMatrix[line][column] << " ";
			if(column == sizeMatrix-1)
				cout << endl;
		}
	}


	return reverseMatrix;
}

void Graph::mountReverseGraph(){

	int sizeMatrix=nodes.size();
	int **reverseMatrix = getReverseAdjacencyMatrix();

	Graph component;


	for(int line=0;line<sizeMatrix;line++){
		Node originNode;
		originNode.id = line+1;

		for(int column=0;column<sizeMatrix;column++){

			if(reverseMatrix[line][column] == 1){
				Node targetNode;
				targetNode.id = column+1;

				originNode.insertEdge(targetNode);

			}
		}
		component.insertNode(originNode);
	}

	cout << "Nodes in Reverse Graph: " << component.nodes.size() << endl;

	for(int i=0;i<component.nodes.size();i++){
		cout << "Degree Node " << i+1 << ": " << component.nodes.at(i).degree.size() << endl;
	}
}

