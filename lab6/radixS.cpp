#include <iostream>
#include <vector>
#include <queue>
#include <cstdlib>
#include <string>
using namespace std;
//Radix Sort Program
//Uses radix sorting algorithm to sort a vector of strings
//By Adrian Faircloth
//11-19-21

int maxElemLength(const vector<string>& v);
int GetLetter(string word, int k);
void PadStrings(vector<string>& L, int k);
void UnpadStrings(vector<string>& L);
vector<queue<string> > ItemsToQueue(const vector<string>& L, int k);
vector<string> QueuesToArray(vector<queue<string> >& QA, int numVals);
void RadixSort(vector<string>& L, int numChars);
void PrintVector(const vector<string>& L);

int main()
{	
	//Creating vector and filling w/ unsorted strings,
	//padding strings to be equal lengths
	vector<string> L;
	L.push_back("zebra");
	L.push_back("apple");
	L.push_back("orange");
	L.push_back("can");
	L.push_back("candy");
	L.push_back("a");
	L.push_back("top");
	L.push_back("pumpkin");
	L.push_back("today");
	L.push_back("parade");
	cout << "Vector before sort: " << endl;
	PrintVector(L);
	PadStrings(L, maxElemLength(L));
	//Sorting vector and printing sorted vector
	RadixSort(L, maxElemLength(L));
	UnpadStrings(L);
	cout << "Vector after sort: " << endl;
	PrintVector(L);
	return 0;
}

int maxElemLength(const vector<string>& v)
{
	//returns the length of the longest string in vector v
	string str;
	int maxLength = 0;
	for (int k = 0; k < v.size(); k++)
	{
		//Checks length of each string, compares to current max
		//length, sets maxLength if greater length is found
		//Length is not indexed from 0
		str = v[k];
		if (str.length() > maxLength)
			maxLength = str.length();
	}
	return maxLength;
}

int GetLetter(string word, int k)
{
	//Returns ascii of kth character of word
	//If k is greater than length of word, returns 0
	
	if (k > word.length())
		return 0;
	else
	{
		
		k = word.length() - k;
		return (int)(word[k]);
	}
}

void PadStrings(vector<string>& L, int k)
{
	for (int i = 0; i < L.size(); i++)
	{
		while (L[i].length() < k)
			L[i] += ' ';
	}
}

void UnpadStrings(vector<string>& L)
{
	for (int i = 0; i < L.size(); i++)
	{
		L[i] = L[i].substr(0, L[i].find(' '));
	}
}

vector<queue<string> > ItemsToQueue(const vector<string>& L, int k)
{
	//Takes items from vector and inserts them into queue based on
	//	value of kth character
	vector<queue<string> > QA(128);
	for (int i = 0; i < L.size(); i++)
	{
		//Inserting each number into queue within vector indexed
		//0-127 based on kth character
		QA[GetLetter(L[i], k)].push(L[i]);
	}
	return QA;
}

vector<string> QueuesToArray(vector<queue<string> >& QA, int numVals)
{
	//Takes items from vector of queues QA  and inserts them into vector
	//	of strings L
	vector<string> L;
	int queueNum = 0;
	while (L.size() < numVals)
	{
		//If current queue is not empty, inserts front item into L
		//Otherwise, increments counter for QA
		//Finally, vector L will be filled w/ values from QA
		if (QA[queueNum].empty() != true)
		{
			L.push_back(QA[queueNum].front());
			QA[queueNum].pop();
		}
		else
			queueNum++;
	}
	return L;
}

void RadixSort(vector<string>& L, int numChars)
{
	//Sorting vector L using Radix sorting
	vector<queue<string> > QA(128);
	for (int k = 1; k <= numChars; k++)
	{
		//For each char of the strings in L, sorts them into QA
		//	based on kth character and then returns them to vector L in
		//	sorted order
		//Finally, all values in L will be sorted in ascending order
		QA = ItemsToQueue(L, k);
		L = QueuesToArray(QA, L.size());
	}
}

void PrintVector(const vector<string>& L)
{
	//Printing each value in vector L
	for (int i = 0; i < L.size(); i++)
		cout << L[i] << " ";
	cout << endl;
}
