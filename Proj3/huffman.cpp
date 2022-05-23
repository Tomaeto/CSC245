#include "huffman.h"
#include <iostream>
using namespace std;

HuffmanTree:: HuffmanTree()
	: numChars(0), built(false) {}

void HuffmanTree:: insert(char ch, int weight) {
    HNode newNode = {ch, weight, -1, -1}; 
    built = false;
    nodes.push_back(newNode);
    numChars++;

}

bool HuffmanTree:: inTree(char ch) {
	//Returns bool indicating if given character
	//	is in tree	
	int index = lookUp(ch);
	if (index == -1)
		return false;
	else
		return true;
}

int HuffmanTree:: GetFrequency(char ch) {
	//Returns weight of given character in tree
	//Calls method w/ index of desired character
	return GetFrequency(lookUp(ch));
}

int HuffmanTree:: GetFrequency(int i) {
	//Returns weight of given character in tree
	return nodes[i].weight;
}

int HuffmanTree:: lookUp(char ch) {
	//Returns index of given character in the tree
	//If char is not in tree, returns -1
	int index = -1;
	for (int i = 0; i < nodes.size(); i++)
	{
		if (nodes[i].ch == ch)
			index = i;
	}
	return index;	
}

string HuffmanTree:: GetCode(char ch) {
	//Calls method w/ index of wanted character
	//Returns binary representation of character
	return GetCode(lookUp(ch));
}


string HuffmanTree:: GetCode(int i) {
	//Returns binary representation of a given character
	if (nodes[i].parent == -1)
		return "";
	else
		return (GetCode(nodes[i].parent) + 
			(char) (nodes[i].childType + '0'));
}

void HuffmanTree:: PrintTable() {
	//Prints out index, char, weight, parent, and childType of all nodes in vector
	//For newline, space, and merged nodes, prints string representing that char
	int numMerged = 1;
	for (int i = 0; i < numNodes(); i++)
	{
		if (nodes[i].ch == '\n')
			cout << i << "\tnl\t";

		else if (nodes[i].ch == ' ')
			cout << i << "\tsp\t";
		
		else if (nodes[i].ch == '\0')
		{
			cout << i << "\tT" << numMerged << "\t";
			numMerged++;
		}
		else
			cout << i << "\t" << nodes[i].ch << "\t";

		cout << nodes[i].weight << "\t" << nodes[i].parent << "\t"
		     << nodes[i].childType << endl;
	}
}

int HuffmanTree:: numNodes() {
	//Returns the number of nodes in the tree
	return nodes.size();
}

void HuffmanTree:: build() {
	//Builds Huffman Tree	
	int smallFreq;
	int nodeIndex;
	int numUnique = numChars;
	getSmallestFreq(smallFreq);
	HNode temp1;
	temp1.weight = -1;
	HNode temp2 = temp1;
	//Creates and inserts merged nodes into vector until
	//	vector has correct number of nodes
	//All full Huffman tables contain 2C -1 nodes, where
	//	C is the number of unique characters
	while (numNodes() < (2*numUnique) - 1)
	{
		//Finds next node w/ smallest weight and no parent,
		//	sets first temp node to that node and sets
		//	the parent and childType of that node in the vector
		//Sets parent to numNodes since the index of the next inserted
		//node will be equal to current size of vector
		//First node found gets childType of 0
		nodeIndex = findNode(temp1, smallFreq);
		nodes[nodeIndex].parent = numNodes();
		nodes[nodeIndex].childType = 0;
		//Resetting smallFreq and getting next node, setting that node's params
		//Second node found gets childType of 1
		getSmallestFreq(smallFreq);
		nodeIndex = findNode(temp2, smallFreq);
		nodes[nodeIndex].parent = numNodes();
		nodes[nodeIndex].childType = 1;
		getSmallestFreq(smallFreq);
		//Merging nodes and resetting temp nodes for next run
		mergeNodes(temp1, temp2);
		temp1.weight = -1;
		temp2.weight = -1;
	}	
}

void HuffmanTree:: getSmallestFreq(int& smallFreq) {
	//Returns weight of node w/ smallest weight and no parent
	smallFreq = 1000;
	for (int i = 0; i < numNodes(); i++)
	{
		if (nodes[i].weight < smallFreq && nodes[i].parent == -1)
			smallFreq = nodes[i].weight;
	}
}

void HuffmanTree:: mergeNodes(HNode temp1, HNode temp2) {
	//Merges two nodes and inserts merged node into tree
	int mergeWeight = temp1.weight + temp2.weight;
	insert('\0', mergeWeight);
}

int HuffmanTree:: findNode(HNode& node, int smallFreq) {
	//Finds a node with the smallest frequency and no parent
	//Sets temp node to that node and returns index
	int index = -1;
	for (int i = 0; i < numNodes(); i++)
	{
		if (nodes[i].weight == smallFreq && nodes[i].parent == -1 && node.weight == -1)
		{
			node = nodes[i];
			index = i;
		}
	}
	return index;
}
