#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <climits>
#include <vector>
#include <queue>
#include <cstdlib>
#include <string>
#include <set>
#include <stack>
#define LL long long
#define pii pair<int,int>
#define INF 0x3f3f3f3f
using namespace std;
const int maxn = 30;
struct stats{
    int px,py,bx,by;
    string path;
};
struct node{
    int x,y;
    string path;
};
char mp[maxn][maxn];
int r,c,box_x,box_y,pson_x,pson_y;
string ans;
const int dir[4][2] = {0,-1,0,1,-1,0,1,0};
const char dc[4] = {'W','E','N','S'};
const char dc2[4] = {'w','e','n','s'};
bool check(int x,int y){
    return mp[x][y] != '#';
}
bool bfs2(int nx,int ny,int tx,int ty,int kx,int ky,string &pans){
    queue<node>q;
    bool vis[maxn][maxn] = {false};
    vis[nx][ny] = vis[kx][ky] = true;
    node now,tmp;
    now.x = nx;
    now.y = ny;
    now.path = "";
    q.push(now);
    while(!q.empty()){
        now = q.front();
        q.pop();
        if(now.x == tx && now.y == ty){
            pans = now.path;
            return true;
        }
        for(int i = 0; i < 4; i++){
            int zx = now.x + dir[i][0];
            int zy = now.y + dir[i][1];
            if(check(zx,zy)&&!vis[zx][zy]){
                vis[zx][zy] = true;
                tmp.x = zx;
                tmp.y = zy;
                tmp.path = now.path + dc2[i];
                q.push(tmp);
            }
        }
    }
    return false;
}
bool bfs(){
    queue<stats>q;
    bool vis[maxn][maxn] = {false};
    vis[box_x][box_y] = true;
    stats tmp,now;
    now.px = pson_x;
    now.py = pson_y;
    now.bx = box_x;
    now.by = box_y;
    now.path = "";
    q.push(now);
    while(!q.empty()){
        now = q.front();
        q.pop();
        for(int i = 0; i < 4; i++){
            int nx = now.bx + dir[i][0];
            int ny = now.by + dir[i][1];
            int tx = now.bx - dir[i][0];
            int ty = now.by - dir[i][1];
            string pans = "";
            if(check(nx,ny)&&check(tx,ty)&&!vis[nx][ny]){
                if(bfs2(now.px,now.py,tx,ty,now.bx,now.by,pans)){
                    vis[nx][ny] = true;
                    tmp.px = now.bx;
                    tmp.py = now.by;
                    tmp.bx = nx;
                    tmp.by = ny;
                    tmp.path = now.path + pans + dc[i];
                    if(mp[nx][ny] == 'T'){
                        ans = tmp.path;
                        return true;
                    }
                    q.push(tmp);
                }
            }
        }
    }
    return false;
}
int main(){
    int cs = 1;
    while(~scanf("%d %d",&r,&c) && r + c){
        memset(mp,'#',sizeof(mp));
        getchar();
        for(int i = 1; i <= r; i++){
            for(int j = 1; j <= c; j++){
                mp[i][j] = getchar();
                if(mp[i][j] == 'B'){
                    box_x = i;
                    box_y = j;
                }
                if(mp[i][j] == 'S'){
                    pson_x = i;
                    pson_y = j;
                }
            }
            getchar();
        }
        printf("Maze #%d\n", cs++);
        if(bfs()) cout<<ans<<endl;
        else puts("Impossible.");
        puts("");
    }
    return 0;
}
