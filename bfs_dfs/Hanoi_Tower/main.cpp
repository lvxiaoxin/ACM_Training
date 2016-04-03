/**
 *name: Hanoi tower
 *P_ID: BNUOJ 4033
 * date: 2016-04-03
 */
#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

void dfs(char a, char b, char c, int n)
{
    if(n==1)
    {
        cout << a << ">" << c << endl;
        return;
    }
    dfs(a, c, b, n-1);
    cout << a << ">" << c << endl;
    dfs(b, a, c, n-1);
}


int main()
{
    char A = 'A', B = 'B', C = 'C';
    int n;
    cin >> n;
    dfs(A, B, C, n);
    return 0;
}
