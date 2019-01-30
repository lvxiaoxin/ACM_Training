#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define N 550000

int mod[N];

int main(){
    int n;
    while (scanf("%d",&n)!=EOF && n){
        mod[1]=1;
        int i;
        for (i=2;mod[i-1]!=0;i++)
            mod[i]=((mod[i>>1]*10)+(i&1))%n;

        int num=0;
        i--;
        while (i){
            mod[num++]=i&1;
            i>>=1;
        }

        while (num){
            printf("%d",mod[--num]);
        }
        printf("\n");
    }

    return 0;
}

