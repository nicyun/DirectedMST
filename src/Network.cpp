#include <iostream>
#include <vector>

#include "Network.hpp"
#include "Simulator.hpp"

using namespace std;

Network::Network(int n)
{
	numNode = n;
	vector<double> tmp(numNode, INF);
	for(int i = 0; i < numNode; i++){
		graph.push_back(tmp);
	}
}

void Network::addEdge(int i, int j, double weight)
{
	if(i == j) return;
	if(weight < graph[i][j])
		graph[i][j] = weight;
}

double Network::simulateDistribution(int root)
{
	Simulator simulator(graph);
	simulator.run();
	return simulator.getMST(root);
}
