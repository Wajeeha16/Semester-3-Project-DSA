#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include "pugixml.hpp"
#include "pugiconfig.hpp"
#include<map>
#include<sstream>
#include<algorithm>
#include<set>
//set<string> t;
//typedef pair<int,string> pair1;
using namespace std;
using namespace pugi;
vector<int>doc_id;
map<int,vector<int>>inverted1;
map<int,vector<int>> doc_ids;
vector<pair<int,pair<int,int>>>f;
ifstream word_index1("word_index1.txt");
ifstream inverted_index1("inverted finalf.txt");     
ifstream frequency1("frequency1.txt");
map<int,string>rankpage;
vector<int>word_id;
vector<pair<int,int>>final_rank;
void ranking();
void func(){int h;
while(inverted_index1>>h)
{
	inverted1[h];
	string k;
	string j;
getline(inverted_index1,j,'\n');
stringstream input(j);
input.get();
for(int i=1;i<j.size();i++){
	getline(input,k,' ');
	i=i+2;
	if(k!="")
	{
	   inverted1[h].push_back(stoi(k));
	}
}
}

}
void func1(){int h;
//while(frequency1>>h)
//{
	//f[h];
cout<<"started"<<endl;
	int w_id,d_id,freq;
	
	while(!frequency1.eof())
	{
		frequency1>>w_id;
	frequency1>>d_id;
	frequency1>>freq;
	f.push_back(make_pair(w_id,make_pair(d_id,freq)));
	}
	cout<<"ended"<<endl;

}
int word_search(vector<string>w){string g;
	
	xml_document doc;int document_id;int v=0;
	int l=0;
	if (!doc.load_file("Titles.xml")) 
		return -1;
	else
	{
		cout<<"loaded"<<endl;
	}
	while(word_index1>>g){
			if(g==w[l]){
			word_index1>>g;
			word_id.push_back(stoi(g));
			l++;
			}
		}
	int a=0;
	for(int i=0;i<word_id.size();i++){
		for(map<int,vector<int>>::iterator it=inverted1.begin();it!=inverted1.end();it++){

			if(word_id[i]==it->first){
				for(int i=0;i<it->second.size();i++){
				doc_id.push_back(it->second[i]);
				}
			}
		}}
	//ranking();
	//sort(final_rank.begin(),final_rank.end());
	final_rank.erase(unique(final_rank.begin(),final_rank.end()),final_rank.end());
	xml_node panels = doc.child("media");
	xml_node panel = panels.first_child();
	for (panel = panels.first_child(); panel; panel = panel.next_sibling())
    {
		 document_id=std::stoi(panel.child_value());
		string text=(string)panel.child("title").child_value();
		for(int i=0;i<doc_id.size();i++){
          if(document_id==doc_id[i]){
					cout<<text<<"  "<<endl;//<<it->second<<endl;
			  //t.insert(text);

}}
			}
				}

int main(){
	func();
	func1();
	vector<string>w;string k;
do{cin>>k;
	w.push_back(k);}
while(k!="?");
	 word_search(w);
	// for(auto it=t.begin();it!=t.end();it++)
	// {
		// cout<<*it<<endl;
	 //}
	// ranking();
	 //sort(final_rank.begin(),final_rank.end());
	 //for(map<int,set<pair1>>::iterator it=final_rank.begin();it!=final_rank.end();it++)
	 //{
		// pair1 m;
		 //m=it->second;
		 //cout<<m.second<<endl;
	 //}
system("pause");
}
/*void ranking(){
	/*for(map<int,string>::iterator it=rankpage.begin();it!=rankpage.end();it++){
		for(int i=0;i<f.size();i++){
			if(f[i].second.first==it->first){
				final_rank.insert(make_pair(f[i].second.second,make_pair(it->first,it->second)));
			}
		}
	}*/
/*	for(vector<pair<int,pair<int,int>>>::iterator it=f.begin();it!=f.end();it++)
	{
		for(int i=0;i<word_id.size();i++)
		{
			for(int j=0;j<doc_id.size();j++)
			{
		        if(it->first=word_id[i]&&it->second.first==doc_id[j])
				{
					final_rank.push_back(make_pair(it->second.first,it->second.second));
				}
			}
		}
	}
}*/