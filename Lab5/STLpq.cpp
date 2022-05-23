#include <queue>
#include <string>
#include <iostream>
using namespace std;
//Program to use priority_queue class of STL
//	for Lab 5 of CSC245
//By Adrian Faircloth
//10-27-21

//Function declarations
void insertNames(priority_queue<string>&);
void printNames(priority_queue<string>&);

int main()
{
	//creating priority queue to hold strings
	priority_queue<string> pq;
	//putting 10 names into pq and printing them
	insertNames(pq);
	cout << "Printing names: " << endl;
	printNames(pq);
	cout << endl;
}

void insertNames(priority_queue<string>& pq)
{
	//Inserting 10 names into priority queue passed by reference
	string names[] = {"Adam", "John", "Sarah", "Amy", "Bill", "Kevin", 
			  "Josh", "Chris", "Logan", "Emery"};
	for (int i = 0; i <= 9; i++)
		pq.push(names[i]);
}

void printNames(priority_queue<string>& pq)
{
	//Printing out names in priority queue
	while (pq.empty() != true)
	{
		cout << pq.top() << " ";
		pq.pop();
	}
}
