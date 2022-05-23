#include <iostream>
#include <vector>
#include <queue>
#include <cstdlib>
#include <string>
using namespace std;
//Radix Sort Program
//Uses radix sorting algorithm to sort a vector of integers
//By Adrian Faircloth
//11-19-21

int maxElemLength(const vector<int>& v);
int GetDigit(int number, int k);
vector<queue<int> > ItemsToQueue(const vector<int>& L, int k);
vector<int> QueuesToArray(vector<queue<int> >& QA, int numVals);
void RadixSort(vector<int>& L, int numDigits);
void PrintVector(const vector<int>& L);

int main()
{	
	//Creating vector and filling w/ unsorted ints
	vector<int> L;
	L.push_back(380);
	L.push_back(95);
	L.push_back(345);
	L.push_back(382);
	L.push_back(260);
	L.push_back(100);
	L.push_back(492);
	cout << "Vector before sort: " << endl;
	PrintVector(L);
	//Sorting vector and printing sorted vector
	cout << "Vector after sort: " << endl;
	RadixSort(L, maxElemLength(L));
	PrintVector(L);
	return 0;
}

int maxElemLength(const vector<int>& v)
{
	//returns the length of the longest number in vector v
	string numStr;
	int maxLength = 0;
	for (int k = 0; k < v.size(); k++)
	{
		//Checks length of each number, compares to current max
		//length, sets maxLength if greater length is found
		//Length is not indexed from 0
		numStr = to_string(v[k]);
		if (numStr.length() > maxLength)
			maxLength = numStr.length();
	}
	return maxLength;
}

int GetDigit(int number, int k)
{
	//Returns kth digit of number
	//If k is greater than length of number, returns 0
	
	string numStr = to_string(number);
	if (k > numStr.length())
		return 0;
	else
	{
		//Subtract ascii of 0 from ascii of digit to
		//get integer value of digit
		k = numStr.length() - k;
		return (int)(numStr[k]) - (int)('0');
	}
}

vector<queue<int> > ItemsToQueue(const vector<int>& L, int k)
{
	//Takes items from vector and inserts them into queue based on
	//	value of kth digit	
	vector<queue<int> > QA(10);
	for (int i = 0; i < L.size(); i++)
	{
		//Inserting each number into queue within vector indexed
		//0-9 based on kth digit
		QA[GetDigit(L[i], k)].push(L[i]);
	}
	return QA;
}

vector<int> QueuesToArray(vector<queue<int> >& QA, int numVals)
{
	//Takes items from vector of queues QA  and inserts them into vector
	//	of ints L
	vector<int> L;
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

void RadixSort(vector<int>& L, int numDigits)
{
	//Sorting vector L using Radix sorting
	vector<queue<int> > QA(10);
	for (int k = 1; k <= numDigits; k++)
	{
		//For each digit of the numbers in L, sorts them into QA
		//	based on kth digit and then returns them to vector L in
		//	sorted order
		//Finally, all values in L will be sorted in ascending order
		QA = ItemsToQueue(L, k);
		L = QueuesToArray(QA, L.size());
	}
}

void PrintVector(const vector<int>& L)
{
	//Printing each value in vector L
	for (int i = 0; i < L.size(); i++)
		cout << L[i] << " ";
	cout << endl;
}
