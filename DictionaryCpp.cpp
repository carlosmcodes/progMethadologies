#include "DictionaryCpp.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstring>
#include <map>
#include <algorithm>

using namespace std;
void breakAtLine(const string& s, std::map< string, pair <vector<string>, vector<string>>> &map);
void loadMap(const string &str, const vector<string> &pos, const vector<string> &def, std::map< string, pair <vector<string>, vector<string>>> &map);
vector<string> splitStr(string &s);
int checkExist(const vector<string> &p, const string &val);
void runDistinctAt3(pair< vector<string>, vector<string> >  &str, string &s);
pair <vector<string>, vector<string> > uniqueMost(pair<vector<string>, vector<string> > &str);
int main(void) {
	std::map< string, pair <vector<string>, vector<string>>> map;
	fstream fileRead;
	string stringIn{ "" };
	vector<string> vec;
	cout << "! Opening data file... ./Data.CS.SFSU.txt" << endl;
	fileRead.open("Data.CS.SFSU.txt", ios::in);
	if (fileRead.fail())
		cout << "File Not Found" << endl;
	cout << "! Loading data..." << endl;
	while (getline(fileRead, stringIn)) {
		breakAtLine(stringIn, map);
	}
	cout << "! Loading completed..." << endl;
	fileRead.close();
	cout << "! Closing data file... ./Data.CS.SFSU.txt" << endl;
	cout << "----- DICTIONARY 340 C++ -----" << endl;
	string userInput{ NULL };
	char stringr[100];
	do {
		cout << "Search: ";
		cin.getline(stringr, 100, '\n');
		userInput = stringr;
		transform(userInput.begin(), userInput.end(), userInput.begin(), tolower);
		vec = splitStr(userInput);
		cout << "|" << endl;
		string key = vec.at(0);

		if (map.count(key)) {
			switch (vec.size()) {
			case 1:
				for (int i = 0; i != map.find(key)->second.first.size(); i++) {
					cout << map.find(key)->first << " [" << map.find(key)->second.first[i] << "]" << " : " << map.find(key)->second.second[i] << endl;
				}
				break;
			case 2:
				if (vec.at(1) == "distinct") {
					pair<vector<string>, vector<string>> p;
					p = uniqueMost(map.find(key)->second);
					map.find(key)->second.first = p.first;
					map.find(key)->second.second = p.second;
					map.find(key)->second.first.resize(p.first.size());
					map.find(key)->second.second.resize(p.second.size());
					int sec1 = map.find(key)->second.first.size();
					for (int i = 0; i < map.find(key)->second.first.size(); i++) {
						cout << map.find(key)->first << " [" << map.find(key)->second.first[i] << "]" << " : " << map.find(key)->second.second[i] << endl;
					}

				}

				else if (checkExist(map.find(key)->second.first, vec.at(1)) == 0) {

					for (int i = 0; i < map.find(key)->second.first.size(); i++) {
						if (map.find(key)->second.first[i] == vec.at(1)) {
							cout << map.find(key)->first << " [" << map.find(key)->second.first[i] << "]" << " : " << map.find(key)->second.second[i] << endl;
						}
					}
				}

				else if (checkExist(map.find(key)->second.first, vec.at(1)) == 1) {
					cout << "<Not found>" << endl;
				}
				else if (checkExist(map.find(key)->second.first, vec.at(1)) == 2) {
					cout << "<2nd argument must be a part of speech or \"distinct\">" << endl;
				}
				break;
			case 3:
				if (checkExist(map.find(key)->second.first, vec.at(1)) == 0) {
					if (vec.at(2) == "distinct") {
						pair<vector<string>, vector<string>> p;
						p = make_pair(vector<string>(map.find(key)->second.first), vector<string>(map.find(key)->second.second));
						runDistinctAt3(p, vec.at(1));
					}

				}
				else if (checkExist(map.find(key)->second.first, vec.at(1)) == 1) {
					cout << "<Not found>" << endl;
					break;
				}
				else if (checkExist(map.find(key)->second.first, vec.at(1)) == 2) {

					cout << "<2nd argument must be a part of speech or \"distinct\">" << endl;
				}

				break;
			}

		}
		else {
			cout << "<Not found>" << endl;
		}

		cout << "|" << endl;
		std::transform(userInput.begin(), userInput.end(), userInput.begin(), ::toupper);
	} while (userInput != "!Q");

	cout << "-----THANK YOU-----" << endl;

	system("pause");
	return 0;
}
int checkExist(const vector<string> &p, const string &val) {
	for (int i = 0; i < p.size(); i++) {
		if (p.at(i) == val) {
			return 0;
		}
	}
	if (val == "verb")
		return 1;
	if (val == "noun")
		return 1;
	if (val == "adjective")
		return 1;
	if (val == "adverb")
		return 1;
	if (val == "conjunction")
		return 1;
	if (val == "preposition")
		return 1;
	if (val == "pronoun")
		return 1;
	if (val == "inerjection")
		return 1;
	return 2;
}

void breakAtLine(const string& s, std::map< string, pair <vector<string>, vector<string>>> &map) {
	char c[999];
	vector<string> vec;
	vector<string> vecDef;
	vector<string> vecPos;
	char *cPtr = nullptr;
	//cPtr = nullptr;
	string str{ "" };
	string def{ "" };
	string pos{ "" };
	int i = 0;
	strcpy_s(c, s.c_str());
	cPtr = c;

	// gets keyword
	while (*cPtr != '|') {
		str += *cPtr;
		cPtr++;
		i++;
	}
	vec.push_back(str);
	cPtr++;
	i = 0;

	// gets FIRST pos
	while (*cPtr != ' ') {
		pos += *cPtr;
		cPtr++;
		i++;
	}
	char * afterPos = nullptr;
	vecPos.push_back(pos);
	cPtr += 6;
	afterPos = cPtr;
	i = 0;
	pos.erase();
	while (*cPtr != '\0') {
		pos += *cPtr;
		def += *cPtr;
		if (*cPtr == '|') {
			def.erase(def.begin() + def.size() - 1);
			//cout << def.length() << endl;
			vecDef.push_back(def);
			pos.erase();
			def.erase();
		}
		if (*cPtr == '-') {
			pos.erase(pos.size() - 2);
			vecPos.push_back(pos);
			cPtr = cPtr + 5;
			if (*cPtr == '\0') {
				def.erase();
				// first line special condition
				while (*afterPos != '.') {
					def += *afterPos;
					afterPos++;
				}
				vecPos.erase(vecPos.begin() + vecPos.size() - 1);
				break;
			}
			else {
				cPtr = cPtr - 5;
			}
			cPtr += 4;
			pos.erase();
			def.erase();
		}
		cPtr++;

	}
	vecDef.push_back(def);
	def.erase();
	pos.erase();


	// new stuff
	// arranges into alphabet order I HATED THIS

	string st{ "" };
	vector<string> vs;
	if (vecPos.size() < 2) {
		loadMap(vec.at(0), vecPos, vecDef, map);
		return;
	}
	else {
		for (int i = 0; i < vecPos.size(); i++) {
			st = vec.at(0) + "\t" + vecPos.at(i) + "\t" + vecDef.at(i);
			vs.push_back(st);
			st.erase();
		}
		sort(vs.begin(), vs.end());


		vec.erase(vec.begin(), vec.end());
		vecDef.erase(vecDef.begin(), vecDef.end());
		vecPos.erase(vecPos.begin(), vecPos.end());

		for (int i = 0; i < vs.size(); i++) {

			string delim = "\t";
			size_t pos = 0;
			string token;

			while (token != vs.at(i)) {
				token = vs.at(i).substr(0, vs.at(i).find_first_of("\t"));
				if (vec.size() < 1)
					vec.push_back(token);

				vs.at(i) = vs.at(i).substr(vs.at(i).find_first_of("\t") + 1);
				token = vs.at(i).substr(0, vs.at(i).find_first_of("\t"));

				vecPos.push_back(token);
				vs.at(i) = vs.at(i).substr(vs.at(i).find_first_of("\t") + 1);
				token = vs.at(i).substr(0, vs.at(i).find_first_of("\t"));
				vecDef.push_back(token);
				break;
			}
		}
	}
	loadMap(vec.at(0), vecPos, vecDef, map);
}

void runDistinctAt3(pair< vector<string>, vector<string> >  &str, string &s) {
	pair< vector<string>, vector<string> > p;



	for (int i = 0; i != str.first.size(); i++) {
		if (str.first[i] == s) {
			p.first.push_back(str.first[i]);
			p.second.push_back(str.second[i]);

		}
	}

	if (p.first.size() < 2) {
		cout << s << " [" << p.first[0] << "]" << " : " << p.second[0] << endl;
		return;
	}

	int j = 0;
	int i = 1;
	while (i < p.first.size()) {
		if (p.second[i] == p.second[j]) {
			i++;
		}
		else {
			j++;
			p.second[j].assign(p.second[i]);
			p.first[j].assign(p.first[i]);
			i++;
		}
	}
	vector<string> tempA(p.first);
	tempA.resize(j + 1);
	vector<string> tempB(p.second);
	tempB.resize(j + 1);

	for (i = 0; i < tempA.size(); i++) {
		cout << tempA[0] << " [" << tempA[i] << "]" << " : " << tempB[i] << endl;

	}
}
pair <vector<string>, vector<string> > uniqueMost(pair<vector<string>, vector<string> > &str) {
	if (str.second.size() < 2) {
		return str;
	}
	int j = 0;
	int i = 1;
	while (i < str.second.size()) {
		if ((str.first[i] + str.second[i]) == (str.first[j] + str.second[j])) {
			i++;
		}
		else {
			j++;
			str.second[j].assign(str.second[i]);
			str.first[j].assign(str.first[i]);
			i++;
		}
	}
	vector<string> tempA(str.first);
	tempA.resize(j + 1);
	vector<string> tempB(str.second);
	tempB.resize(j + 1);
	return (make_pair(vector<string>(tempA), vector<string>(tempB)));

}
void loadMap(const string &str, const vector<string> &pos, const vector<string> &def, std::map< string, pair <vector<string>, vector<string>>> &map) {

	for (int i = 0; i < pos.size(); i++) {
		map.emplace(str, make_pair(std::vector<string>(pos), std::vector<string>(def)));

	}
}
vector<string> splitStr(string &s) {
	char c[999];
	vector<string> vec;
	string token;
	char *sP = nullptr;
	strcpy_s(c, s.c_str());
	sP = c;
	while (*sP != '\0') {
		token += *sP;
		if (*sP == ' ') {
			token.erase(token.begin() + token.size() - 1);
			vec.push_back(token);
			token.erase();
		}
		sP++;
	}
	vec.push_back(token);
	return vec;
}

