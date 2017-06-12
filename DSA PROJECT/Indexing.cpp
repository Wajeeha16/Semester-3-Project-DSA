/*#include<iostream>
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
typedef pair<unsigned long,string> pairs;
void hashtext(unsigned long doc_id,string text);
bool search (string word1);
unsigned long find_word(string w);
unsigned long word_ids=0;
set<pairs> word_index;
set<pair<unsigned long,unsigned long>> forward1;
ofstream forward_index("forward_index.txt");
ofstream word_index_f1("word_index1.txt");
ofstream inverted_index1("inverted_index1.txt");
int main()
{
	unsigned long document_id;    
	xml_document doc;
    if (!doc.load_file("Google.xml")) 
		return -1;
	else
	{
		cout<<"loaded"<<endl;
	}
	xml_node panels = doc.child("mediawiki");
	xml_node panel = panels.first_child();
	for (panel = panel.next_sibling(); panel; panel = panel.next_sibling())
    {
		document_id=stoi((string)panel.child("id").child_value());
		string text=(string)panel.child("revision").child("text").child_value();
		hashtext(document_id,text); 
	}
	system("pause");
	return 0;
}
int f=0;
void hashtext(unsigned long doc_id,string text)
{
	string word;
	stringstream input(text);
	for(unsigned long i=0;i<text.length();i++)
	{
		getline(input,word,' ');
		i=i+word.length();
		string chars="[]-{}()""=*";
		for(unsigned long i=0;i<chars.size();i++)
		{
			word.erase(remove(word.begin(),word.end(),chars[i]),word.end());
		}
	    std::transform(word.begin(), word.end(), word.begin(), ::tolower);
	    regex digit("[[:digit:]]");
		regex alphabet("([a-z]|[A-Z])+");
	    if(regex_match(word,alphabet))
		{
			if(word!="is" && word!="the" && word!="and" && word!="or" && word!="which" && word!="that" && word!="why" && word!="who" && word!="or" && 
				word!="the" && word!="a" && word!="in"&& word!="on" && word!="what" && word!="etc"&& word!="for"&& word!="with"&& word!="did" && 
				word!="was"&& word!="of"&& word!="it" && word!="are" && word!="has"&& word!="its" && word!="as"&&word!="they"&&word!="were"
				&&word!="if"&&word!="both"&&word!="between"&&word!="along"&&word!="would"&&word!="had"&&word!="shall"&&word!="will"&&word!="his"
				&&word!="her"&&word!="him"&&word!="their"&&word!="there"&&word!="here"&&word!="should"&&word!="down"&&word!="due"&&word!="up"
				&&word!="been"&&word!="us"&&word!="he"&&word!="she"&&word!="it"&&word!="its"&&word!="they"&&word!="we"&&word!="by"&&word!="do"
				&&word!="does"&&word!="not"&&word!="but"&&word!="often"&&word!="into"&&word!="at"&&word!="be"&&word!="can"&&word!="could"&&word!="this"
				&&word!="to"&&word!="each"&&word!="an"&&word!="may"&&word!="might"&&word!="have"&&word!="also"&&word!="all"&&word!=" ")
			{
				if(search(word))
				{
						word_index.insert(make_pair(word_ids+1,word));
						word_index_f1<<word<<" "<<word_ids+1<<endl;
					    word_ids++;
				}
				unsigned long word_id=find_word(word);
				if(forward1.size()==10000)
				{
					forward1.clear();
				}
				forward1.insert(make_pair(doc_id,word_id));
				forward_index<<doc_id<<" "<<word_id<<endl;
				inverted_index1<<word_id<<" "<<doc_id<<endl;
	       }
		}
     }
	return;
}
bool search (string word1)
{
	bool b=true;
	if(!word_index.empty())
	{
		for(set<pairs>::iterator it=word_index.begin();it!=word_index.end();it++)
		{
			pairs m=*it;
			if(m.second==word1)
			{
				b=false;
			}
		}
	}
	return b;
}
unsigned long find_word(string w)
{
	unsigned long i=0;
	if(!word_index.empty())
	{
		for(set<pairs>::iterator it=word_index.begin();it!=word_index.end();it++)
		{
			pairs m=*it;
			if(m.second==w)
			{
				return i;
			}
			i++;
		}
	}
}
*/