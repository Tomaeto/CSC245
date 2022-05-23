#include "bst.h"
//Client Program for Lab 4 of CSC245
//Tests functions added to bst.cpp file
//By Adrian Faircloth
//09-29-21


int main()
{	
	//Initializing BST and inserting values
	BinarySearchTree<int> T(0);	
	T.insert(6);
	T.insert(2);
	T.insert(8);
	T.insert(4);
	T.insert(1);
	T.insert(3);

	//Testing postOrder function of bst,
	//Prints bst with post-order traversal
	cout << "Printing tree postorder:" << endl;
	T.postOrder();

	//Testing height function of bst,
	//prints height of bst if the tree has entries,
	//else prints error message
	if (T.isEmpty())
		cout << "Tree is empty, cannot compute height." << endl;
	else
		cout << "Height of tree: " << T.Height() << endl;
	
	//Testing numLeaves function of bst,
	//prints number of leaves in tree
	cout << "Numer of leaves in tree: " << T.numLeaves() << endl;

	//Testing isBalanced function of bst,
	//returns 'true' if tree is balanced, false otherwise
	if (T.isBalanced() == true)
		cout << "It's balanced!" << endl;
	else
		cout << "It's not balanced!" << endl;	

	//Adding 9 to bst, testing isBalanced function again
	cout << "Adding 9 to tree..." << endl;
	T.insert(9);
	if (T.isBalanced() == true)
		cout << "It's balanced!" << endl;
	else
		cout << "It's not balanced!" << endl;
}
