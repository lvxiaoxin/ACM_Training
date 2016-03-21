#include <cstdio>
#include <cstring>

int N;
bool g[30] = {false};
bool M[30][30] = {false};

int translate(char C)
{
    return C-64;
}

void dfs()
{

}

int main()
{
    scanf("%d", &N);
    while(N!=0)
    {
        getchar();
        char C, D;
        memset(M, false, sizeof(M));
        memset(g, false, sizeof(g));
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


//            dfs();
        scanf("%d", &N);
    }
    return 0;
}