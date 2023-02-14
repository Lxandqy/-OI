#include<iostream>
#include<cstring>
#include<queue>
#include<testlib.h>

using namespace std;
const int N = 50010,M = 2e5 + 10;
int head[M],to[M],w[M],last[M],cnt;
int n,m;
struct node{
	int to,w;
	bool operator < (const node &p)const{
		return w > p.w;
	}
};

void add(int a,int b,int c){
	w[++cnt] = c;
	to[cnt] = b;
	last[cnt] = head[a];
	head[a] = cnt;
}

int a[10];
int flag[N],dist[10][N];
void dij(int start){
	memset(flag,0,sizeof flag);
	priority_queue<node>q;
	q.push({a[start],0});
	dist[start][a[start]] = 0;
	while(q.size()){
		node p = q.top();
		q.pop();
		if(!flag[p.to]) flag[p.to] = 1;
		else continue;
		for(int i = head[p.to]; i != -1; i = last[i]){
			if(dist[start][to[i]] > dist[start][p.to] + w[i]){
				dist[start][to[i]] = dist[start][p.to] + w[i];
				q.push({to[i],dist[start][to[i]]});
			}
		}
	}
}

bool st[N];
int dfs(int start,int distance,int cnt){
	if(cnt == 6){
		return distance;
	}
	int res = 0x3f3f3f3f;
	for(int i = 1; i <= 5; i++){
		if(!st[a[i]]){
			st[a[i]] = 1;
			res = min(res,dfs(i,distance + dist[start][a[i]],cnt + 1));
			st[a[i]] = 0;
		}
	}
	return res;
}

int main(){

    for(int _ = 1; _ <= 10; _++){
        endTest(_);
        cin >> n >> m;

        for(int i = 1; i <= 5; i++){
            cin >> a[i];
        }

        memset(head,-1,sizeof head);
        memset(dist,0x3f,sizeof dist);
        cnt = 0;
        int x,y,w;
        for(int i = 1; i <= m; i++){
            scanf("%d%d%d",&x,&y,&w);
            add(x,y,w);
            add(y,x,w);
        }

        a[0] = 1;
        for(int i = 0; i <= 5; i++){
            dij(i);
        }

        st[1] = 1;
        cout << dfs(0,0,1);
    }



	return 0;
}
