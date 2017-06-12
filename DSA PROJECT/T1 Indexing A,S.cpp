#include<iostream>
#include<fstream>
#include<string>
#include<regex>
#include<map>
#include <algorithm>            
#include<vector>
using namespace std;
int main() {
	ifstream file; ofstream f;
	f.open("indexed_document1.txt");
	file.open("1.txt");
	string word;//int a=0;
	std::map< string, std::vector<int> > map;
	int j = -1; regex r("[[:digit:]]"); regex g("([a-z]|[A-Z])+");
	f << "WORD"; f << "                    "; f << "POSITION"; f << "\n";
	while (file >> word) {
		j++;
		if (regex_match(word, r) || regex_match(word, g)) {
			std::transform(word.begin(), word.end(), word.begin(), ::tolower);
			if (word != "which" && word != "have"&& word != "a"&& word != "is"&&
				word != "the"&& word != "this"&& word != "of"&& word != "or"
				&& word != "has"&& word != "on"&& word != "to"
				&& word != "and"&& word != "by"&& word != "in"
				&& word != "etc"&& word != "for"&& word != "with"&& word != "did" && word != "was") {
				map[word].push_back(j);//break;
			}
		}
	}
	cout << endl;//auto itr = map.begin();f<<itr->first;f<<"\n";
	for (auto itr = map.begin(); itr != map.end(); itr++) {
		std::cout << itr->first << ":"; f << itr->first; f << ":  ";
		for (auto vitr = itr->second.begin(); vitr != itr->second.end(); vitr++) {
			std::cout << *vitr << ","; f << *vitr; f << " ";
		}f << "\n";
		cout << endl;
	}
	system("pause");
}