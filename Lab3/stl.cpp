#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <iostream>
using namespace std;

//Function declarations
void Initialize(vector<int>& v);

void Print(vector<int> v);

void Reverse(vector<int>& v);


int main()
{
	//Creating 2 stack objects, filling each w/ strings,
	//and comparing the two stacks
	stack<string> s1, s2;
	s1.push("Hi there");
	s1.push("Hello there");
	s2.push("Hey there");
	if (s1 == s2)
		cout << "s1 = s2";
	else if (s1 < s2)
		cout << "s1 < s2";
	else if (s1 > s2)
		cout << "s2 < s1";
	cout << endl;
	
	//Creating a vector v and testing Initialize, Reverse, and Print functions
	vector<int> v;
	Initialize(v);
	Print(v);	 
	Reverse(v);
	Print(v);
	
	//Sorting vector v and printing
	sort(v.begin(), v.end());
	Print(v);
}

void Initialize(vector<int>& v)
{
	//Takes user input for integer and stores in vector v, repeats 5 times
	int entry;
	for (int i=0; i < 5; i++)
	{
		cout << "Enter an integer: ";
		cin >> entry;
		v.push_back(entry);
	}
}

void Print(vector<int> v)
{
	//Prints contents of a vector v
	cout << "Contents of v:" << endl;
	for (int i = 0; i < v.size(); i++)
	{
		cout << v.at(i) << endl;
	}
}

void Reverse(vector<int>& v)
{
	//Reverses a vector v
	reverse(v.begin(), v.end());
}
