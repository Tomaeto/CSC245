#include "bet.h"
#include <cstddef>
#include <iostream>
//Implementation file for Binary Expression Tree program
//Created for Project 2 of CSC245
//by Adrian Faircloth
//10-11-2021
BET::BET()
{
	//Class constructor
	root = NULL;
}

BET::~BET()
{
	//Class destructor
	//Empties tree and deallocates all nodes
	makeEmpty();
}

void BET::makeEmpty()
{
	//Public instance of makeEmpty, acts as call to private
	//Empties tree, deallocates all nodes,
	//	and clears Stack of any remaining symbols
	makeEmpty(root);	
	while (s.empty() !=  true)
			s.pop();
	
}

void BET::makeEmpty(BETPtr& t) const
{
	//Private instance of makeEmpty, accesses root node
	//Empties tree and deallocates all nodes
	if (t != NULL)
	{
		makeEmpty(t -> left);
		makeEmpty(t -> right);
		delete t;
	}
	t = NULL;
}

bool BET::isEmpty() const
{
	//Checks if tree is empty, returns
	//	corresponding bool value
	if (root == NULL)
		return true;
	else
		return false;
}

void BET::insertPrefixOperator(char token)
{
	//Inserts an operator into the tree from prefix expression
	//Sets info for node, pops last 2 nodes to set as children,
	//	pushes node to stack and sets it as new root
	BETPtr newNode = new BinaryNode;
	newNode -> info.whichType = OPERATOR;
	newNode -> info.theContent.opsymbol = token;
	newNode -> left = s.top();
	s.pop();
	newNode -> right = s.top();
	s.pop();
	s.push(newNode);
	root = s.top();
}

void BET::insertPostfixOperator(char token)
{
	//Inserts an operator into the tree from postfix expression
	//Sets info for node, pops last 2 nodes to set as children,
	//	pushes node to stack and sets it as new root
	BETPtr newNode = new BinaryNode;
	newNode -> info.whichType = OPERATOR;
	newNode -> info.theContent.opsymbol = token;
	newNode -> right = s.top();
	s.pop();
	newNode -> left = s.top();
	s.pop();
	s.push(newNode);
	root = s.top();
}

void BET::insertOperand(char token)
{
	//Inserts operand into stack
	//Since all operands are leaf nodes, sets links to NULL
	BETPtr newNode = new BinaryNode;
	newNode -> info.whichType = OPERAND;
	newNode -> info.theContent.variable = token;
	newNode -> left = NULL;
	newNode -> right = NULL;
	s.push(newNode);
	root = s.top();
}

void BET::preorder() const
{
	//Public instance of preorder(), acts as call to private
	preorder(root);
}

void BET::preorder(BETPtr t) const
{
	//Private instance of preorder(), accesses root
	//Prints tree in prefix expression
	//Prints root node, then traverses left subtree,
	//	then traverses right subtree
	if (t != NULL)
	{
		if (t -> info.whichType == OPERATOR)
			cout << t -> info.theContent.opsymbol << " ";
		else if (t -> info.whichType == OPERAND)
			cout << t -> info.theContent.variable << " ";
		preorder(t -> left);
		preorder(t -> right);
	}
	
}

void BET::inorder() const
{
	//Public instance of inorder(), acts as call to private
	inorder(root);
}

void BET::inorder(BETPtr t) const
{
	//Private instance of inorder(), accesses root
	//Prints tree in infix expression
	//Adds parenthesis into expression as needed
	if (t != NULL)
	{
		//Since all leaf nodes are operands, prints
		//	variable content of leaf nodes
		if (t -> left == NULL && t-> right == NULL)
		{
			cout << t -> info.theContent.variable << " ";
		}
		else
		{
			//If a node is not a leaf, prints '(', prints
			//	left subtree, prints symbol of node,
			//	prints right subtree, and prints ')'
			cout << "( ";
			inorder(t -> left);
			cout << t -> info.theContent.opsymbol << " ";
			inorder(t -> right);
			cout << ") ";
		}
	}
}

void BET::postorder() const
{
	//Public instance of postorder(), acts as call to private
	postorder(root);
}

void BET::postorder(BETPtr t) const
{
	//Private instance of postorder(), accesses root
	//Prints tree in postfix expression
	//Traverses left subtree, then traverses right subtree,
	//	then prints root node
	if (t != NULL)
	{
		postorder(t -> left);
		postorder(t -> right);
		
		if (t -> info.whichType == OPERATOR)
			cout << t -> info.theContent.opsymbol << " ";
		else if (t -> info.whichType == OPERAND)
			cout << t -> info.theContent.variable << " ";
	}
	
}


