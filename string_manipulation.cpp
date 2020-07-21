/*
Prob. No. 5
# String Operations
Write a python code to convert "string" to "gstrin"...
E.g. input - Ratio
        Output - oRati
*/

#include <iostream>
#include <string>

using namespace std;

int main(void){

	cout << "Type the word: ";
	string word,result;
	cin >> word;
	int len = word.length();

	result = word[len-1];

	for(int i = 0; i < len-1 ; i++){
		result += word[i];
	}

	cout << result << endl;
	return 0;
}