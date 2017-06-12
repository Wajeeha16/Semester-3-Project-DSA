#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<map>
#include<sstream>
#include<utility>
#include<set>
#include<algorithm>
using namespace std;
map<int,vector<int>> invert;
vector<pair<int,pair<int,int>>> f;
void find_frequency();
bool search(unsigned long id);
vector<int> copy1;
void copy_vector(vector<int> a);
ofstream inverted_final("inverted final1.txt");
ofstream frequency_f("frequency1.txt");
int main()
{
	fstream file;
	file.open("inverted_index1.txt");
	unsigned long word_id=0,doc_id=0;
	file>>word_id;
	file>>doc_id;
	invert[word_id];
	invert[word_id].push_back(doc_id);
	while(!file.eof())
	{
		file>>word_id;
		file>>doc_id;
		if(search(word_id))
		{
			invert[word_id].push_back(doc_id);
		}
		else
		{
			invert[word_id];
			invert[word_id].push_back(doc_id);
		}
	}
	find_frequency();
	for(vector<pair<int,pair<int,int>>>::iterator it=f.begin();it!=f.end();it++)
	{
		frequency_f<<it->first<<"   "<<it->second.first<<"  "<<it->second.second<<endl;
	}
	for(map<int,vector<int>>::iterator it=invert.begin();it!=invert.end();it++)
	{
		it->second.erase(unique(it->second.begin(),it->second.end()),it->second.end());
	}
	for(map<int,vector<int>>::iterator it=invert.begin();it!=invert.end();it++)
	{
		inverted_final<<it->first<<" ";
		for(int i=0;i<it->second.size();i++)
		{
			inverted_final<<it->second[i]<<" ";
		}
		inverted_final<<endl;
	}
	system("pause");
	return 0;
}
bool search(unsigned long id)
{
	for(map<int,vector<int>>::iterator it=invert.begin();it!=invert.end();it++)
	{
		if(id==it->first)
		{
			return true;
		}
	}
	return false;
}
void find_frequency()
{
	//int freq=1;//j=0;
	for(map<int,vector<int>>::iterator it=invert.begin();it!=invert.end();it++)
	{
		copy_vector(it->second);
		for(int i=0;i<copy1.size();i++)
		{
			//cout<<count(it->second.begin(),it->second.end(),copy1[i])<<endl;
			f.push_back(make_pair(it->first,make_pair(copy1[i],count(it->second.begin(),it->second.end(),copy1[i]))));
		}
		copy1.clear();
	}
}
void copy_vector(vector<int> a)
{
	for(int i=0;i<a.size();i++)
	{
		copy1.push_back(a[i]);
	}
	copy1.erase(std::unique(copy1.begin(),copy1.end()),copy1.end());
	sort(copy1.begin(),copy1.end());
}