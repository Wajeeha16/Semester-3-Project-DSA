#include<iostream>
#include "pugixml.hpp"
#include "pugiconfig.hpp"
#include <sstream>
#include<fstream>
#include<vector>
#include<map>
#include<string>
#include<utility>
#include<regex>
#include<set>
using namespace std;
using namespace pugi;
typedef pair<unsigned long, string> pairs;
void hashtext(unsigned long doc_id, string text);
bool search(string word1);
unsigned long find_word(string w);
unsigned long word_ids = 0;
set<pairs> word_index;
set<pair<unsigned long, unsigned long>> forward1;
ofstream forward_index("forward_index.txt");
ofstream word_index_f("word_index.txt");
ofstream inverted_index1("inverted_index1.txt");
ofstream inverted_index2("inverted_index2.txt");
ofstream inverted_index3("inverted_index3.txt");
ofstream inverted_index4("inverted_index4.txt");
ofstream inverted_index5("inverted_index5.txt");
ofstream inverted_index6("inverted_index6.txt");
ofstream inverted_index7("inverted_index7.txt");
ofstream inverted_index8("inverted_index8.txt");
ofstream inverted_index9("inverted_index9.txt");
ofstream inverted_index10("inverted_index10.txt");
ofstream inverted_index11("inverted_index11.txt");
ofstream inverted_index12("inverted_index12.txt");
ofstream inverted_index13("inverted_index13.txt");
ofstream inverted_index14("inverted_index14.txt");
ofstream inverted_index15("inverted_index15.txt");
ofstream inverted_index16("inverted_index16.txt");
ofstream inverted_index17("inverted_index17.txt");
ofstream inverted_index18("inverted_index18.txt");
int main()
{
	unsigned long document_id;
	xml_document doc;
	if (!doc.load_file("simplewiki-20160601-pages-articles-multistream.xml"))
		return -1;
	else
	{
		cout << "loaded" << endl;
	}
	xml_node panels = doc.child("mediawiki");
	xml_node panel = panels.first_child();
	for (panel = panel.next_sibling(); panel; panel = panel.next_sibling())
	{
		document_id = stoi((string)panel.child("id").child_value());
		string text = (string)panel.child("revision").child("text").child_value();
		hashtext(document_id, text);
	}
	for (set<pairs>::iterator it = word_index.begin(); it != word_index.end(); it++)
	{
		pairs m = *it;
		word_index_f << m.first << "   " << m.second << endl;
	}
	system("pause");
	return 0;
}
void hashtext(unsigned long doc_id, string text)
{
	string word;
	stringstream input(text);
	for (unsigned long i = 0; i<text.length(); i++)
	{
		getline(input, word, ' ');
		i = i + word.length();
		string chars = "[]-{}()""=*";
		for (unsigned long i = 0; i<chars.size(); i++)
		{
			word.erase(remove(word.begin(), word.end(), chars[i]), word.end());
		}
		std::transform(word.begin(), word.end(), word.begin(), ::tolower);
		regex digit("[[:digit:]]");
		regex alphabet("([a-z]|[A-Z])+");
		if (regex_match(word, alphabet))
		{
			if (word != "is" && word != "the" && word != "and" && word != "or" && word != "which" && word != "that" && word != "why" && word != "who" && word != "or" &&
				word != "the" && word != "a" && word != "in"&& word != "on" && word != "what" && word != "etc"&& word != "for"&& word != "with"&& word != "did" &&
				word != "was"&& word != "of"&& word != "it" && word != "are" && word != "has"&& word != "its" && word != "as"&&word != "they"&&word != "were"
				&&word != "if"&&word != "both"&&word != "between"&&word != "along"&&word != "would"&&word != "had"&&word != "shall"&&word != "will"&&word != "his"
				&&word != "her"&&word != "him"&&word != "their"&&word != "there"&&word != "here"&&word != "should"&&word != "down"&&word != "due"&&word != "up"
				&&word != "been"&&word != "us"&&word != "he"&&word != "she"&&word != "it"&&word != "its"&&word != "they"&&word != "we"&&word != "by"&&word != "do"
				&&word != "does"&&word != "not"&&word != "but"&&word != "often"&&word != "into"&&word != "at"&&word != "be"&&word != "can"&&word != "could"&&word != "this"
				&&word != "to"&&word != "each"&&word != "an"&&word != "may"&&word != "might"&&word != "have"&&word != "also"&&word != "all")
			{
				if (search(word))
				{
					word_index.insert(make_pair(word_ids + 1, word));
					word_ids++;
				}
				unsigned long word_id = find_word(word);
				if (forward1.size() == 10000)
				{
					forward1.clear();
				}
				forward1.insert(make_pair(doc_id, word_id));
				forward_index << doc_id << " " << word_id << endl;
				if (word_id <= 25000 && word_id >= 1)
				{
					inverted_index1 << word_id << " " << doc_id << endl;
				}
				else if (word_id>25000 && word_id <= 50000)
				{
					inverted_index2 << word_id << " " << doc_id << endl;
				}
				else if (word_id>50000 && word_id <= 75000)
				{
					inverted_index3 << word_id << " " << doc_id << endl;
				}
				else if (word_id>75000 && word_id <= 100000)
				{
					inverted_index4 << word_id << " " << doc_id << endl;
				}
				else if (word_id>100000 && word_id <= 200000)
				{
					inverted_index5 << word_id << " " << doc_id << endl;
				}
				else if (word_id>200000 && word_id <= 300000)
				{
					inverted_index6 << word_id << " " << doc_id << endl;
				}
				else if (word_id>300000 && word_id <= 400000)
				{
					inverted_index7 << word_id << " " << doc_id << endl;
				}
				else if (word_id>400000 && word_id <= 500000)
				{
					inverted_index8 << word_id << " " << doc_id << endl;
				}
				else if (word_id>500000 && word_id <= 600000)
				{
					inverted_index9 << word_id << " " << doc_id << endl;
				}
				else if (word_id>600000 && word_id <= 700000)
				{
					inverted_index10 << word_id << " " << doc_id << endl;
				}
				else if (word_id>700000 && word_id <= 800000)
				{
					inverted_index11 << word_id << " " << doc_id << endl;
				}
				else if (word_id>800000 && word_id <= 900000)
				{
					inverted_index12 << word_id << " " << doc_id << endl;
				}
				else if (word_id>900000 && word_id <= 1000000)
				{
					inverted_index13 << word_id << " " << doc_id << endl;
				}
				else if (word_id>1000000 && word_id <= 2000000)
				{
					inverted_index14 << word_id << " " << doc_id << endl;
				}
				else if (word_id>2000000 && word_id <= 3000000)
				{
					inverted_index15 << word_id << " " << doc_id << endl;
				}
				else if (word_id>3000000 && word_id <= 4000000)
				{
					inverted_index16 << word_id << " " << doc_id << endl;
				}
				else if (word_id>4000000 && word_id <= 5000000)
				{
					inverted_index17 << word_id << " " << doc_id << endl;
				}
				else if (word_id>5000000)
				{
					inverted_index18 << word_id << " " << doc_id << endl;
				}
			}
		}
	}
	return;
}
bool search(string word1)
{
	bool b = true;
	if (!word_index.empty())
	{
		for (set<pairs>::iterator it = word_index.begin(); it != word_index.end(); it++)
		{
			pairs m = *it;
			if (m.second == word1)
			{
				b = false;
			}
		}
	}
	return b;
}
unsigned long find_word(string w)
{
	unsigned long i = 0;
	if (!word_index.empty())
	{
		for (set<pairs>::iterator it = word_index.begin(); it != word_index.end(); it++)
		{
			pairs m = *it;
			if (m.second == w)
			{
				return i;
			}
			i++;
		}
	}
}