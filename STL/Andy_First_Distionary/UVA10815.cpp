/**
 * Name: Andy's First DIctionary
 * Note: STL set
 * date: 2016-05-15
 * P_ID: UVA 10815
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
#include <sstream>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;
const int MAXN = 1e5 + 3;


set<string> dict;

int main()
{
    string s, buf;	

    while(cin >> s)
    {
        for(int i=0; i<s.length(); i++)
            if(isalpha(s[i])) s[i] = tolower(s[i]);
            else s[i] = ' ';

            stringstream ss(s);
            while(ss >> buf) dict.insert(buf);
    }
    for(set<string>::iterator it=dict.begin(); it!=dict.end(); ++it)
        cout << *it << "\n";
    return 0;
}
