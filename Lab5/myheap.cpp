#include "BinaryHeap.h"
//Program for testing BinaryHeap class
//	for Lab 5 of CSC245
//By Adrian Faircloth
//10-27-21

int main()
{
	//Creating minheap of chars
	BinaryHeap<char> PQ(50);

	//Filling minheap w/ chars A to J	
	for(char ch = 'A'; ch <= 'J'; ch++)
		PQ.insert(ch);
/*
	//Deleting root of heap
	PQ.deleteMin();
	//Printing left subtree of heap
	cout << "Left subtree of heap: ";
	PQ.printLtSubtree();
	cout << endl;
	//Printing height of heap
	cout << "Height of heap: " << PQ.Height() << endl;
	//Printing maximum value of heap
	cout << "Max value in heap: " << PQ.findMax() << endl;
*/
	PQ.printLeaves();
}
