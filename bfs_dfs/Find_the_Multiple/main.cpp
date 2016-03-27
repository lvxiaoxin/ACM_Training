#include<iostream>
#include<cmath>
#include<queue>
using namespace std;
int a;
queue<long long> myInt;

long long bfs(int x)
{
    while(!myInt.empty())
        myInt.pop();
    myInt.push(x);
    while(1)
    {
        long long temp = myInt.front();
        myInt.pop();
        if(temp%a == 0) return temp;
        myInt.push(temp*10);
        myInt.push(temp*10 + 1);
    }
}

int main()
{
    cin >> a;
    while(a!=0)
    {
        cout << bfs(1) << endl;
        cin >> a;
    }
    return 0;
}
