/*
Prob. No. 4
# Armstrong Numbers
An armstrong number is the number whose some of cube of all the digits is equal to the number itself.
e.g 153=(1^3) + (5^3) + (3^3) 
1. Write a python prgram to print all the Armstrong numbers within the given input range.
2. Write a python program whether the input number is Armstrong Number or not.

*/

#include <iostream>
#include <math.h>

using namespace std;

int find_sum(int num);

int main(void){

	cout << "MODES\n";
	cout << "1) Print all the Armstrong numbers within the given input range\n";
	cout << "2) Check whether the input number is Armstrong Number or not\n";
	cout << "Choose Mode Input 1/2: ";
	int mode;
	cin >> mode;

	if(mode == 1){

		int range;
		cout << "Input the range: ";
		cin >> range;

		for(int i = 1; i <= range; i++){

			if (find_sum(i) == i){
				cout << i << endl;
			}

		}


	}else if(mode == 2){
		int check;
		cout << "Input the number: ";
		cin >> check;

		if (find_sum(check) == check){
			cout << check << " is a Armstrong Number\n";
		}else{
			cout << check << " is not a Armstrong Number\n";
		}

	}else{
		cout << "Mode is not valid \n";
		return 1;
	}

	return 0;
}

int find_sum(int num){
	int single_digit;
	int sum = 0;

	while(num != 0){
		single_digit = num % 10;
		sum += pow(single_digit, 3);

		num /= 10;
	}

	return sum;
}