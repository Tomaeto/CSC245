
#include <iostream>
using namespace std;

//Function declarations
bool compValue(double *ptr1, double *ptr2);

bool compAddress(double *ptr1, double *ptr2);


int main()
{
	//Creating two double pointers, testing compValue and compAddress functions
	double *ptr1 = new double;
	double *ptr2 = new double;
	*ptr1 = 10;
	*ptr2 = 15;
	cout << "Testing compValue for values 10 and 15: " << compValue(ptr1, ptr2) << endl;
	*ptr1 = *ptr2;
	cout << "Testing compValue for same value: " << compValue(ptr1, ptr2) << endl;
	cout << "Testing compAddress for different addresses: " << compAddress(ptr1, ptr2) << endl;
	delete ptr1;
	ptr1 = ptr2;
	cout << "Testing compAddress for same address: " << compAddress(ptr1, ptr2) << endl;
}

bool compValue(double *ptr1, double *ptr2)
{
	//Compares the values pointed to by two pointers
	//If the values are equal, returns true
	if (*ptr1 == *ptr2)
		return true;
	else
		return false;
}

bool compAddress(double *ptr1, double *ptr2)
{
	//Compares the addresses of two pointers
	//If the addresses are the same, returns true
	if (ptr1 == ptr2)
		return true;
	else
		return false;
}
