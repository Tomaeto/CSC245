#include "bet.h"
#include <iostream>
#include <string>
#include <stack>
using namespace std;
//Client file for Project 2 of CSC245
//Tests functions of Binary Expression Tree program
//Gets user input of an expression, prints expression in 
//	prefix, infix, and postfix
//Runs until user decides to quit
//by Adrian Faircloth
//10-11-2021

//function declarations
void printMenu(int&);
void getExpression(string&);
void exitConfirm(char&);
void printExpressions(BET&);
void makePostorder(string, BET&);
void makePreorder(string, BET&);
void convInfix(string&);
int opLevel(char);
bool isOperand(char);


int main()
{
	BET bet;
	int choice;
	string line;
	char exit;
	//Running program until user chooses to quit
	while (toupper(exit) != 'N')
	{
		printMenu(choice);
		switch (choice)
		{
			case 1:
			//If preorder is chosen, gets expression,
			//	creates BET, prints expressions,
			//	empties BET, and prompts user to exit
				getExpression(line);
				makePreorder(line, bet);
				printExpressions(bet);
				bet.makeEmpty();
				exitConfirm(exit);
				break;
			case 2:
			//If inorder is chosen, gets expression,
			//	converts to postorder, creates BET,
			//	prints expressions, empties BET, 
			//	and prompts user to exit
				getExpression(line);
				convInfix(line);
				makePostorder(line, bet);
				printExpressions(bet);
				bet.makeEmpty();
				exitConfirm(exit);
				break;
			case 3:
			//If postorder is chosen, gets expression,
			//	creates BET, prints expressions,
			//	empties BET, and prompts user to exit
				getExpression(line);
				makePostorder(line, bet);
				printExpressions(bet);
				bet.makeEmpty();
				exitConfirm(exit);
				break;
			default:
			//Error message
				cout << "\tInvalid selection, please try again.\n" << endl;
		}
	}
		//Exit message
		cout << "\n\tDeconstructing tree and exiting program..." << endl;


}

void printMenu(int& choice)
{
	//Prints menu for program and gets user input for choice of expression type
	cout << "\t&&&&&&&&&&& BINARY EXPRESSION TREE &&&&&&&&&&&" << endl;	
	cout << "\t\t(1) Prefix\t(2) Infix\t(3) Postfix" << endl << endl;
	cout << "\t Your Expression Type ---> ";
	cin >> choice;
}

void getExpression(string& line)
{
	//Prompts user to input expression and gets input for expression
	cout << "\t Your Expression ---> ";
	cin.ignore();
	getline(cin, line);
}

void exitConfirm(char& exit)
{
	//Asks user if they want to rerun program, gets input for user choice
	cout << "\n\t Build another tree? (Y/N) "; 
	cin >> exit;
}

void printExpressions(BET& bet)
{
	//If BET is empty, prints indicating message
	//If not, prints BET as prefix, infix, and postfix expressions
	if (bet.isEmpty() != true)
	{
		cout << "\t Prefix Expression of Tree: " << endl << "\t\t";
		bet.preorder();
		cout << "\n\t Infix Expression of Tree: " << endl << "\t\t";
		bet.inorder();
		cout << "\n\t Postfix Expression of Tree: " << endl << "\t\t";
		bet.postorder();
		cout << endl;
	}

	else 
	{
		cout << "\t Tree is empty. " << endl;
	}
	
}

void makePostorder(string inLine, BET& bet)
{
	//Creates BET from postfix expression
	//From start of line, checks each char
	//If it is operator, inserts into tree and relinks nodes as needed
	//If it is operand, inserts into tree as a leaf node
	for (int i = 0; i < inLine.size(); i++)
	{
		if (inLine[i] == '+' || inLine[i] == '-' || inLine[i] == '*' || inLine[i] == '/')
			bet.insertPostfixOperator(inLine[i]);
		else if (inLine[i] != ' ')
			bet.insertOperand(inLine[i]);
	}
}

void makePreorder(string inLine, BET& bet)
{
	//Creates BET from prefix expression
	//From end of line, checks each char
	//If it is operator, inserts into tree and relinks nodes as needed
	//If it is operand, inserts into tree as leaf node
	for (int i = inLine.size(); i >= 0; i--)
	{
		if (inLine[i] == '+' || inLine[i] == '-' || inLine[i] == '*' || inLine[i] == '/')
			bet.insertPrefixOperator(inLine[i]);
		else if (inLine[i] != ' ')
			bet.insertOperand(inLine[i]);
	}
}

void convInfix(string& inLine)
{
	//Converts infix expression to postfix
	//Used to create BET from infix expression
	string convLine = "";
	stack<char> operators;
	operators.push('(');
	inLine += ')';	
	for (int i = 0; i < inLine.size(); i++)
	{
		//If char is open parenthesis, push to stack
		if (inLine[i] == '(')
			operators.push('(');
		//If char is operand, append to postfix expression
		else if (isOperand(inLine[i]) == true)
			convLine += inLine[i];
		//If char is closed parenthesis, pop all operators
		//	and add to postfix until open parenthesis
		//	is found, then pop open parenthesis
		else if (inLine[i] == ')')
		{
			while (operators.empty() == false && operators.top() != '(')
			{
				convLine += operators.top();
				operators.pop();
			}
			operators.pop();
		}
		//If char is operator, pop and add to postfix all operators of
		//	equal or higher precedence in stack, then push char to stack
		else if (inLine[i] != ' ')
		{
			while (operators.empty() == false && opLevel(operators.top()) >= opLevel(inLine[i]))
			{
				convLine += operators.top();
				operators.pop();
				
			}
			operators.push(inLine[i]);
		}
			
	}
	inLine = convLine;
}

int opLevel(char op)
{
	//Returns value representing precedence of operator
	//'+'  and '-' have lower precedence, 
	//	'*' and '/' have higher precedence
	//If char is not operator, returns 0
	//Used for infix conversion to postfix
	if (op == '+' || op == '-')
		return 1;
	if (op == '*' || op == '/')
		return 2;
	else 
		return 0;
}

bool isOperand(char token)
{
	//Checks if a char is operand
	//If token is an uppercase or lowercase letter
	//	or a number, returns true
	//Otherwise, returns false
	//Used for infix conversion to postfix
	if (token >= 'A' && token <= 'Z')
		return true;
	if (token >= 'a' && token <= 'z')
		return true;
	if (token >= '0' && token <= '9')
		return true;
	else
		return false;
}


