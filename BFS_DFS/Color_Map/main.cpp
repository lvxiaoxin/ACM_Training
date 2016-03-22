#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int N, color=0;
int g[30] = {0};
bool M[30][30] = {false};

int translate(char C)
{
    return C-64;
}

void dfs(int it)
{
    int j = 0;
    int i = 0;
    for(i=0; i<4; ++i)
    {
        g[it] = i;
        for (j = 1; j <= N; ++j)
        {
            if (M[it][j] == true && g[it] == g[j])
                break;
        }
        if (j == N+1) break;
    }
    i++;
    color = max(i, color);
    if(it==N) return;
    dfs(++it);
}


int main()
{
    scanf("%d", &N);
    while(N!=0)
    {
        color = 0;
        getchar();
        char C, D;
        memset(M, false, sizeof(M));
        memset(g, -1, sizeof(g));
        for(int i=0; i<N; i++)
        {
            scanf("%c%c", &C,&D);
            int k = translate(C);
            char temp;
            while(1)
            {
                scanf("%c", &temp);
                if(temp=='\n') break;
                int m = translate(temp);
                M[k][m] = true;
            }
        }

        /*
        for(int i=1; i<=N; i++)
         {
           for(int j=1; j<=N; j++)
           {
               if(M[i][j])
                  printf("1 ");
               else printf("0 ");
           }
               printf("\n");
         }
         */
        dfs(1);
        if(color==1) printf("1 channel needed.\n");
        else printf("%d channels needed.\n", color);
        scanf("%d", &N);
    }
    return 0;
}