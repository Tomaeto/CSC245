#include <iostream>
#include <cstddef>
#include <cstring>
#include <cctype>
using namespace std;


struct RecType
{
	int age;
	float weight;
	char gender;
};

int main()
{
	//Creating pointer intPtr, pointing to value stored in num
	//& mulitplying value by 10
	int num = 5;
	int *intPtr = NULL;
	//intPtr = &num; 		Commented out to cause segmentation fault
	*intPtr = *intPtr * 10;
	cout << *intPtr << endl;

	//Creating pointer recPtr, pointing to RecType in dynamic memory
	//setting params of RecType using pointer overloads, printing values,
	//and deleting recPtr
	RecType *recPtr = new RecType;
	recPtr -> age = 25;
	recPtr -> weight = 190;
	recPtr -> gender = 'M';
	recPtr -> age = recPtr -> age + 5;			
	cout << recPtr -> age << " " << recPtr -> weight << " " <<recPtr -> gender << endl;
	delete recPtr;
	recPtr = NULL;

	//Creating pointer strPtr, points to C-style string
	//setting string pointed to by strPtr, printing string,
	//and counting # of lowercase chars in string
	char *strPtr = new char[50];
	strcpy (strPtr, "Operating Systems");
	cout << strPtr << endl;
	
	char *tempPtr = strPtr;
	int numLowercase = 0;
	for (int i = 0; i <= strlen(strPtr); i++)
	{
		if (islower(*tempPtr))
		{
			numLowercase++;
		}	
		*tempPtr++;	
	}
	cout << numLowercase << endl;
	
	//adding 10 to address in strPtr, printing, resetting address,
	//and deleting strPtr
	strPtr = strPtr + 10;
	cout << strPtr << endl;
	strPtr = strPtr - 10;
	delete strPtr;
	strPtr = NULL;
}
