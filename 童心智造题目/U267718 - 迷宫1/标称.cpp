#include<iostream>
#include<cstring>
#include<testlib.h>
#include<queue>

using namespace std;

const int N = 1e3+ 10;

struct node{
    int x,y;
};
int x[N] = {0,1,-1,0};
int y[N] = {1,0,0,-1};

int dist[N][N],flag[N][N],c[N][N];
int n,m,t;
void bfs(){
    queue<node>q;
    q.push({1,1});
    memset(dist,0,sizeof dist);
    dist[1][1] = 1;

    while(q.size()){
        node p = q.front();
        q.pop();
        for(int i = 0; i < 4; i++){
            int xx = p.x + x[i],yy = p.y + y[i];
            if(xx > n || xx < 1 || yy > m || yy < 1 || c[xx][yy] == 1) continue;
            if(!dist[xx][yy]){
                dist[xx][yy] = dist[p.x][p.y] + 1;
                q.push({xx,yy});
            }
        }
    }
}

int main(){
    for(int _= 1; _ <= 11;_++){
        endTest(_);

        cin >> n >> m >> t;
        memset(c,0,sizeof c);

        for(int i = 1; i <= t; i++){
            int x,y;
            scanf("%d %d",&x,&y);
            c[x][y] = 1;
        }

        bfs();


        if(dist[n][m] != 0x3f3f3f3f)
            cout << dist[n][m] - 1 << endl;
        else cout << -1 << endl;

    }




    return 0;
}
