#include<iostream>
#include<cstring>
#include<testlib.h>
#include<queue>

using namespace std;

const int N = 1e2+ 10;

vector<int>v[N];
int dp[N],fa[N],flag[N];

struct node{
    int x,y;
};
int x[N] = {0,1,-1,0};
int y[N] = {1,0,0,-1};

int dist[N][N],a[N][N],c[N][N],b[N][N];
int n,m,t;
void bfs(){
    queue<node>q;
    q.push({1,1});
    memset(dist,0x3f,sizeof dist);
    dist[1][1] = 0;

    while(q.size()){
        node p = q.front();
        q.pop();
        for(int i = 0; i < 4; i++){
            int xx = p.x + x[i],yy = p.y + y[i];
            if(xx > n || xx < 1 || yy > m || yy < 1 || c[xx][yy] == 1) continue;
            if(y[i] == 1){
                if(dist[xx][yy] > dist[p.x][p.y] + a[p.x][p.y]){
                    dist[xx][yy] = dist[p.x][p.y] + a[p.x][p.y];
                    q.push({xx,yy});
                }
            }else if(y[i] == -1){
                if(dist[xx][yy] > dist[p.x][p.y] + a[xx][yy]){
                    dist[xx][yy] = dist[p.x][p.y] + a[xx][yy];
                    q.push({xx,yy});
                }
            }else if(x[i] == 1){
                if(dist[xx][yy] > dist[p.x][p.y] + b[p.x][p.y]){
                    dist[xx][yy] = dist[p.x][p.y] + b[p.x][p.y];
                    q.push({xx,yy});
                }
            }else{
                if(dist[xx][yy] > dist[p.x][p.y] + b[xx][yy]){
                    dist[xx][yy] = dist[p.x][p.y] + b[xx][yy];
                    q.push({xx,yy});
                }
            }

        }
}
    }

int main(){
    for(int _= 1; _ <= 11;_++){
        endTest(_);
        memset(a,0,sizeof a);
        memset(b,0,sizeof b);
        cin >> n >> m >> t;
        memset(c,0,sizeof c);
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m - 1; j++){
                scanf("%d",&a[i][j]);
            }
        }
        for(int i = 1; i <= n - 1; i++){
            for(int j = 1; j <= m; j++){
                scanf("%d",&b[i][j]);
            }
        }

        for(int i = 1; i <= t; i++){
            int x,y;
            scanf("%d %d",&x,&y);
            c[x][y] = 1;
        }

        bfs();


        if(dist[n][m] != 0x3f3f3f3f)
            cout << dist[n][m] << endl;
        else cout << -1 << endl;

    }




    return 0;
}
