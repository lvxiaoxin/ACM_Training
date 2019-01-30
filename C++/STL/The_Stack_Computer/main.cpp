/**
 * Name: The SetStack Computer
 * Note: stack + set + map set_union set_intersection
 * date: 2016-05-17
 * P_ID: UVA 12096
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


typedef set<int> theSet;
map<theSet, int> theMap;
vector<theSet> theVec;


int queryID(theSet theS)
{
    if(theMap.count(theS)) return theMap[theS];

    theVec.push_back(theS);
    theMap[theS] = theVec.size() - 1;
    return theMap[theS];
}


int main()
{
    stack<int> s;
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        while(n--)
        {
            string str;
            cin >> str;
                
            if(str[0]=='P') s.push(queryID(theSet()));
            else if(str[0]=='D') s.push(s.top());
            else 
            {
                theSet x1 = theVec[s.top()]; s.pop();
                theSet x2 = theVec[s.top()]; s.pop();

                theSet x;
                if(str[0]=='U') set_union(x1.begin(), x1.end(), x2.begin(), x2.end(), inserter(x, x.begin()));
                if(str[0]=='I') set_intersection(x1.begin(), x1.end(), x2.begin(), x2.end(), inserter(x, x.begin()));
                if(str[0]=='A') 
                {
                    x = x2;
                    x.insert(queryID(x1));
                }
                s.push(queryID(x));
            }
            cout << theVec[s.top()].size() << endl;
        }
        cout << "***" << endl;
    }
	return 0;
}
