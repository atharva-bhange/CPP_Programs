/*
Prob. No. 1
#Perfect Numbers
The Perfect numbers are the numbers which can be expressed as the sum of all its factors including 1 and excluding the number itself.


2.Write a python code to check whether input is perfect number or not.

*/

#include <iostream>

using namespace std;

int main(void){


	cout << "Enter the integer you want to check :";
	int num;
	cin >> num;

	int sum = 1;
	int max = num +1;
	for (int j = 2 ; j<num ; j++){

		if (j >= max){
			break;
		}

		if (num%j == 0){
			max = num/j;
			sum += j;
			sum += max;
			if (sum > num){
				break;
			}
		}
	}

	if (sum == num){
		cout << "It is a perfect number \n";
	}else{
		cout << "It is not a perfect number \n";
	}



	return 0;
}