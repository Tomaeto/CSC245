#include <iostream>
#include "dlist.h"
using namespace std;

void PrintMenu(char&);
void HeadInsert(DList<int>&);
void TailInsert(DList<int>&);
void FindAndMove(DList<int>&, int);
void AccessItem(DList<int>&);
void Delete(DList<int>&);
void PrintList(const DList<int>&);
void PrintLength(const DList<int>&);

int main()
{
	DList<int> list;
	char selection;
	while(toupper(selection) != 'Q')
	{
		PrintMenu(selection);
		
		switch(toupper(selection))
		{
			case 'H': HeadInsert(list);  break;
			case 'T': TailInsert(list);  break;
			case 'A': AccessItem(list);  break;
			case 'D': Delete(list);      break;
			case 'P': PrintList(list);   break;
			case 'L': PrintLength(list); break;
			case 'Q': cout << "\tExiting Program..." << endl;  break;
			default : cout << "\tError. Please Try Again." << endl;
		}
	}
}



void PrintMenu(char &selection)
{
	cout << "|**************************|" << endl;
	cout << "|***********Menu***********|" << endl;
	cout << "|**************************|" << endl;
	cout << "|                          |" << endl;
	cout << "| H: Insert item at front  |" << endl;
	cout << "| T: Insert item at back   |" << endl;
	cout << "| A: Access item in list   |" << endl;
	cout << "| D: Delete item in list   |" << endl;
	cout << "| P: Print list of items   |" << endl;
	cout << "| L: Print length of list  |" << endl;
	cout << "| Q: Quit Program          |" << endl;	
	cout << "|                          |" << endl;
	cout << "|**************************|" << endl;
	cout << "|                          |" << endl;
	cout << "|  Please enter a choice:  |" << endl;
	cin >> selection;
}

void HeadInsert(DList<int> &list)
{
	int inVal;
	cout << "\tWhat value would you like to insert?" << endl;
	cin >> inVal;
	if (list.inList(inVal) == true)
		cout << "\tValue is already in list." << endl;
	else
	{
		list.insertHead(inVal);
		cout << "\tDone" << endl;
	}
}

void TailInsert(DList<int> &list)
{
	int inVal;
	cout << "\tWhat value would you like to insert?" << endl;
	cin >> inVal;
	if (list.inList(inVal) == true)
		cout << "\tValue is already in list." << endl;
	else
	{
		list.appendTail(inVal);
		cout << "\tDone" << endl;
	}	
}

void FindAndMove(DList<int> &list, int val)
{
	if(list.inList(val) == true)
	{
		list.deleteItem(val);
		list.insertHead(val);	
		cout <<"\tItem found and moved to front." << endl;
	}
	else
		cout << "\tItem not found in list." << endl;
}

void AccessItem(DList<int> &list)
{
	int accVal;
	if (list.isEmpty() == true)
		cout << "\tList is empty. Values must be inserted before anything can be accessed." << endl;
	else
	{
		cout << "\tWhat value would you like to access?" << endl;
		cin >> accVal;
		FindAndMove(list, accVal);	
	}
}

void Delete(DList<int> &list)
{
	int delVal;
	if (list.isEmpty() == true)
		cout <<"\tList is empty. Values must be inserted before anyting can be deleted." << endl;
	else
	{
		cout <<"\tWhat value would you like to delete?" << endl;
		cin >> delVal;
		if (list.inList(delVal) == true)
		{
			list.deleteItem(delVal);
			cout << "\tItem deleted." << endl;
		}
		else
			cout << "\tItem not found in list." << endl;
	}
}

void PrintList(const DList<int> &list)
{
	if (list.isEmpty() == true)
		cout <<"\tList is empty." << endl;
	else
	{
		cout << "\tPrinting list..." << endl;
		list.print();
		cout << "\tEnd of list." << endl;
	}
}

void PrintLength(const DList<int> &list)
{
	cout << "\tLength of list is " << list.lengthIs() << "." << endl;
}
