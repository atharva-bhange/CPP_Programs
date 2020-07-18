/*
Prob. No. 1
#Perfect Numbers
The Perfect numbers are the numbers which can be expressed as 
the sum of all its factors including 1 and excluding the number itself.

1.Write a CPP code to print all the perfect numbers between 1 to 9999.

*/

#include <iostream>

using namespace std;

int main(void){
	int upper_bound = 9999;

	for (int i = 1 ; i <= upper_bound; i++){

		int sum = 1;
		int max = upper_bound +1;
		for (int j = 2 ; j<i ; j++){

			if (j >= max){
				break;
			}

			if (i%j == 0){
				max = i/j;
				sum += j;
				sum += max;
				if (sum > i){
					break;
				}
			}

		}

		if (sum == i){
			cout << i << endl;
		}

	}

	return 0;
}