/**
 * Name: Ananagrams
 * note: STL map
 * date: 2016-0517
 * P_ID: UVA 156
 */
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;
const int MAXN = 1e5 + 3;


string standStr(const string &str)
{
    string temp = str;
    for(int i=0; i<str.length(); ++i)
    {
        temp[i] = tolower(temp[i]);
    }
    sort(temp.begin(), temp.end());
    return temp;
}

map<string, int> rec;
vector<string> words;

int main()
{
	string s;
    while(cin>>s)
    {
        if(s[0]=='#') break;
        words.push_back(s);
        string st = standStr(s);
        if(!rec.count(st)) rec[st] = 0;
        rec[st]++;
    }

    sort(words.begin(), words.end());

    for(int i=0; i<words.size(); ++i)
    {
        if(rec[standStr(words[i])]==1) cout << words[i] << endl;
    }
	return 0;
}
