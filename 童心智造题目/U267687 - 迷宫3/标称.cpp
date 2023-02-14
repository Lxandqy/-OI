#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<testlib.h>
#include<queue>
using std::cin;
using std::cout;
using std::endl;
using std::string;

const int N = 1110,mod = 1e9 + 7;
struct node{
	int x,y;
};

int x[N] = {0,1,-1,0};
int y[N] = {1,0,0,-1};
int dist[N][N];
long long shu[N][N];
int b[N],flag[N][N],c[N][N];
int n,m,t;
int sx,sy,fx,fy;
void bfs(){
    if(c[1][1] == 1) return;
	std::queue<node>q;
    q.push({1,1});
    memset(dist,0x3f,sizeof dist);
    dist[1][1] = 0;
    shu[1][1] = 1;
    while(q.size()){
        node p = q.front();
        q.pop();
        for(int i = 0; i < 4; i++){
            int xx = p.x + x[i],yy = p.y + y[i];
            if(xx > n || xx < 1 || yy > m || yy < 1 || c[xx][yy] == 1) continue;
            if(dist[xx][yy] > dist[p.x][p.y] + 1){
                dist[xx][yy] = dist[p.x][p.y] + 1;
                shu[xx][yy] = shu[p.x][p.y];
                q.push({xx,yy});
            }else if(dist[xx][yy] == dist[p.x][p.y] + 1){
            	shu[xx][yy] += shu[p.x][p.y];
            	shu[xx][yy] %= mod;
			}
        }
    }
}

int main(){
    for(int _ = 1; _ <= 10; _++){
        endTest(_);
        cin >> n >> m >> t;
        memset(c,0,sizeof c);
        memset(shu,0,sizeof shu);
        for(int i = 1; i <= t; i++){
            int x,y;
            scanf("%d %d",&x,&y);
            c[x][y] = 1;
        }

        bfs();

        cout << shu[n][m] << endl;
    }



	return 0;
}
