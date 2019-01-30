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

int main()
{
    int a = 1;
    a = (a<<2)  + 1; 
    cout << a << endl;
    int b = a&3;
    cout << b << endl;
    b>>=2;
    cout << b << endl;
	return 0;

