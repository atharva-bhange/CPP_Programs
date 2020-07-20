/*
Prob. No. 2
# Binary to Decimal Converter

Take any Binary number as input and convert it to Decimal number.
Remember that validating the input is also a main 
segment of code...validate the input for only binary 
numbers in this case. 

*/

#include <iostream>
#include <math.h>

using namespace std;

int main(void){

	long long int binary_num,single_digit;
	int sum = 0;
	int power = 0;

	cout << "Input binary number: ";
	cin >> binary_num;

	while(binary_num != 0){
		single_digit = binary_num % 10;

		if (single_digit != 0 && single_digit != 1){
			cout << "This is not a binary number \n";
			return 1;
		}

		sum += pow(2,power) * single_digit;
		power++;
		binary_num /= 10;
	}

	cout << sum << endl;
	return 0;
}