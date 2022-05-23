
#include <iostream>
using namespace std;

double convert(double value);	//declaration for temperature conversion

int main(){
double celTemp;
double farTemp;
//cout << "Please enter a Celcius value: ";
cin >> celTemp;
farTemp = convert(celTemp);
cout << celTemp << " degrees Celcius is " << farTemp << " degrees Fahrenheit.\n";

return 0;
}

double convert(double tmp) {
double convTemp = 1.8 * tmp + 32.0;
return convTemp;

}
