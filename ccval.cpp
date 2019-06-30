#include "ccval.h"
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <sstream>
using namespace std;



bool isvalidcc(const string& check);
int addElements(int array[], int j);
int rightToLeft(const string& check, int j);
int num;
int storeVals[15] = { 0 };
int storeValsB[15] = { 0 };
int j;
int i;
string s;
int main() {

	int h;	//
	// PLEASE DO NOT CHANGE function main
	//
	vector<string> cardnumbers = {
		 "371449635398431", "4444444444444448", "4444424444444440", "4110144110144115",
		"4114360123456785", "4061724061724061", "5500005555555559", "5115915115915118",
		"5555555555555557", "6011016011016011", "372449635398431", "4444544444444448",
		"4444434444444440", "4110145110144115", "4124360123456785", "4062724061724061",
		"5501005555555559", "5125915115915118", "5556555555555557", "6011116011016011",
		 "372449635397431", "4444544444444448", "4444434444544440", "4110145110184115",
		"4124360123457785", "4062724061724061", "5541005555555559", "5125115115915118",
		"5556551555555557", "6011316011016011"
	};

	int i;
	vector<string>::iterator itr;



	for (i = 1, itr = cardnumbers.begin(); itr != cardnumbers.end(); ++itr, i++) {
		cout << setw(2) << i << " "
			<< setw(17) << *itr
			<< ((isvalidcc(*itr)) ? " is valid" : " is not valid") << endl;
	}
	system("pause");
	return 0;
}

bool isvalidcc(const string& check) {
	num = 0;
	int numk = 0;
	int addAB = 0;
	int aOdd = 0;
	j = 0;
	for (i = check.size() - 2; i >= 0; i--, i--) {
		s = check;
		s = s[i];
		num = stoi(s);
		numk = num * 2;
		if (numk > 9) {
			s = to_string(numk);
			numk = (s.at(0) - 48) + (s.at(1) - 48);
			storeVals[j] = numk;
			j++;
		}
		else {

			aOdd = aOdd + numk;
		}

	}
	num = addElements(storeVals, j);
	num = num + aOdd;
	addAB = rightToLeft(check, check.size());
	num = num + addAB;
	if (num % 10 == 0)
		return true;
	else
		return false;
	//return false;
}
int addElements(int array[], int j) {
	int num = 0;
	for (int i = 0; i < j; i++) {
		num = num + array[i];
	}
	return num;
}
int rightToLeft(const string& check, int j) {
	int num = 0;
	for (i = j - 1; i >= 0; i -= 2) {
		s = check;
		s = s[i];

		num = num + stoi(s);
	}
	return num;
}



