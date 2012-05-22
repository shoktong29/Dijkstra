// Dijktra.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include "Node.h"
#include "Edge.h"

using namespace std;
void TPS(vector<Edge>&edgeList, vector<Node>&nodeList, Node &origin, Node &destination);
void sortEdgeList(vector<Edge>&edgeList);
void updateNeighborCost(vector<Edge>&edgeList);
void printEdges(vector<Edge>&edgeList);

int main()
{
	vector<Edge> edgeList;
	vector<Node> nodeList;

	//initialize nodes;
	for(int x=0 ; x<5; x++)
	{
		Node *node = new Node(x,1000+x);
		nodeList.push_back(*node);
		//
		cout<<"\nTEST: " <<(void *)node <<" " <<node;
	}
	
	//initialize paths. IDK how to add it using loop
	Edge *edge1 = new Edge(nodeList.at(0),nodeList.at(1),2);
	Edge *edge2 = new Edge(nodeList.at(0),nodeList.at(2),5);
	Edge *edge3 = new Edge(nodeList.at(0),nodeList.at(3),4);
	Edge *edge4 = new Edge(nodeList.at(1),nodeList.at(2),2);
	Edge *edge5 = new Edge(nodeList.at(1),nodeList.at(3),3);

	//add paths to list. IDK how to add it using loop
	edgeList.push_back(*edge1);
	edgeList.push_back(*edge2);
	edgeList.push_back(*edge3);
	edgeList.push_back(*edge4);
	edgeList.push_back(*edge5);

	Node origin = nodeList.at(0);
	Node destination = nodeList.at(2);
	TPS(edgeList,nodeList,origin,destination);
	cout<<endl;

	return 0;
}

void TPS(vector<Edge>&edgeList, vector<Node>&nodeList, Node &origin, Node &destination)
{
	vector<Node> TPS;

	//Set the cost of origin to 0;
	for(int j=0; j<5; j++)
	{
		Node &kill = nodeList.at(j);
		if(kill.getNodeId() == origin.getNodeId())
		{
			//get the startNode from the openList and change cost to 0;
			cout<<"\nFound START";
			kill.setNodeCost(0);
		}
	}

	//Sort the nodes according to least cost
	sortEdgeList(edgeList);

	//removed the least cost in the openList and update neighbor costs
	while(nodeList.size() != 0)
	{
		Node node = nodeList.at(0);
		TPS.push_back(node); //add the node with lowest cost to TPS
		//remove node from the nodeList

		break;
	}

	//display nodeIds
	for(int y=0; y<5; y++)
	{
		Node node = nodeList.at(y);
		printf("\n%d = %d",node.getNodeId(),node.getNodeCost());
	}

	//prints all edges in graph
	printEdges(edgeList);
}

void sortEdgeList(vector<Edge>&edgeList)
{

}

void updateNeighborCost(vector<Edge>&edgeList)
{

}

void printEdges(vector<Edge>&edgeList)
{
	cout<<"\n\nDisplay all edges in graph.";
	for(int i=0;i<5;i++)
	{
		Edge &kill= edgeList.at(i);
		Node start = kill.getStartNode();
		Node end = kill.getEndNode();
		int cost = kill.getEdgeCost();
		cout<<"\n" <<start.getNodeId() <<" -> " <<end.getNodeId() <<" = " <<cost;
	}
}

