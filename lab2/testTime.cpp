// Client file for testing Time Class
// for CSC 245 Lab 2
// by Adrian Faircloth
// 09/04/2021
#include "time.h"
using namespace std;

int main() {
	//Initializing Time object myTime, testing both Write and WriteAmPm functions
	Time myTime(9, 30, 0);
	myTime.Write();
	myTime.WriteAmPm();

	//Setting myTime to 8:00:00, testing WriteAmPm and Mealtime functions
	myTime.Set(8, 0, 0);
	myTime.WriteAmPm();
	myTime.Mealtime();

	//Creating Array of 10 Time objects, setting each to 11:00:00 and printing	
	Time Schedules[10];
	for (int i = 0; i < 10; i++)
	{
	     Schedules[i].Set(11, 0 , 0);
	     Schedules[i].WriteAmPm();
	}
}
