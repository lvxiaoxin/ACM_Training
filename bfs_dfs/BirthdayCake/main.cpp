/**
 * Name: 生日蛋糕
 * P_ID: POJ 1190
 * date: 2016-04-13
 */
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int N, M;
int best;
int leftMinS[22], leftMinV[22];

void dfs(int now, int sumS, int sumV, int r, int h)
{
    if(now==0)
    {
        if(sumV==N && best>sumS)
            best = sumS;
        return;
    }

    if(sumS+leftMinS[now]>best || sumV+leftMinV[now]>N)
        return;

    /**
     *  2*r*h=S
     *  r*r*h=V
     *  => V*2/r = S
     *  S + sumS >= best => return;
     */
    if((2*(N-sumV)/r + sumS) >=best)
        return;

    for(int i=r-1; i>=now; i--)
    {
        if(now==M)
            sumS = i*i;
        int maxH = min((N-leftMinV[now-1]-sumV)/(i*i), h-1);
        for(int j=maxH; j>=now; j--)
        {
            dfs(now-1, sumS+i*j*2, sumV+i*i*j, i, j);
        }
    }
}


int main()
{
    leftMinS[0] = 0;
    leftMinV[0] = 0;
    for(int i=1; i<22; i++)
    {
        leftMinS[i] = leftMinS[i-1] + i*i*2;
        leftMinV[i] = leftMinV[i-1] + i*i*i;
    }
    scanf("%d", &N);
    getchar();
    scanf("%d", &M);
    getchar();
    best = 9999999;
    dfs(M, 0, 0, 100, 10000);
    if(best==9999999) best = 0;
    printf("%d\n", best);
    return 0;
}