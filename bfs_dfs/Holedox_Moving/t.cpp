#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int maxr=21;
const int maxc=21;
int vis[maxr][maxc][1<<14];//vis第三维的高位二进制表示紧接着蛇头的那格在蛇头的相对方向
int maze[maxr][maxc];
int R,C;
struct Node//注意这里记录的st状态中的方向是指,后面一个格子处于前面一个格子的哪个方向
{
    int x,y;
    int st,dist;
    Node(int x,int y,int st,int dist):x(x),y(y),st(st),dist(dist){}
};
int L;//蛇长
int kase=0;//当前实例
int dir[10];//用来保存解码后的方向
int dx[]={1,0,-1,0};//下,左,上,右
int dy[]={0,-1,0,1};
bool check(int x,int y,Node node)//判断x,y坐标是否处于node状态的蛇身
{
    for(int i=L-1;i>=1;i--)
    {
        dir[i]=node.st&3;//提取相对方向
        node.st>>=2;
    }
    int xx=node.x,yy=node.y;
    for(int i=1;i<L;i++)
    {
        xx+= dx[dir[i]];
        yy+= dy[dir[i]];
        if(xx==x&&yy==y) return true;//表示冲突
    }
    return false;//表示无冲突
}
queue<Node> Q;
int BFS(Node nod)
{
    kase++;
    if(nod.x==1&&nod.y==1) return 0;
    while(!Q.empty())Q.pop();
    Q.push(nod);
    vis[nod.x][nod.y][nod.st]=kase;
    while(!Q.empty())
    {
        Node node=Q.front();Q.pop();
        int x=node.x,y=node.y,st=node.st,dist=node.dist;
        for(int d=0;d<4;d++)
        {
            int nx=x+dx[d],ny=y+dy[d];
            if(nx==1&&ny==1) return dist+1;
            if(nx<1||nx>R||ny<1||ny>C||maze[nx][ny]==1||check(nx,ny,node)) continue;
            int ndist=dist+1,nst=(st>>2)+( ((d+2)%4)<<(2*(L-2)));//新距离,新状态,注意这里(d+2)%4表示对d取反向
            if(vis[nx][ny][nst]==kase)continue;//之前走过
            Q.push(Node(nx,ny,nst,ndist));
            vis[nx][ny][nst]=kase;
        }
    }
    return -1;
}
int main()
{
    while(scanf("%d%d%d",&R,&C,&L)==3)
    {
        if(R==0&&C==0&&L==0) break;
        int x,y,nx,ny;
        Node node(0,0,0,0);
        scanf("%d%d",&node.x,&node.y);
        x=node.x,y=node.y;
        for(int i=1;i<L;i++)
        {
            scanf("%d%d",&nx,&ny);
            for(int d=0;d<4;d++)
            {
                if(x+dx[d]==nx && y+dy[d]==ny)
                {
                    node.st = (node.st<<2)+d;
                    break;
                }
            }
            x=nx,y=ny;
        }
        int blocks;
        scanf("%d",&blocks);
        memset(maze,0,sizeof(maze));
        for(int i=1;i<=blocks;i++)
        {
            scanf("%d%d",&x,&y);
            maze[x][y]=1;
        }
        printf("Case %d: %d\n",kase,BFS(node));
    }
    return 0;
}

