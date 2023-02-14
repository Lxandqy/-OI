#include<iostream>
#include<queue>
#include<cstring>
#include<vector>
#include<testlib.h>

using namespace std;

#define x first
#define y second
typedef pair<int,int> pii;

const int N = 25010,M = 150010,INF = 0x3f3f3f3f;
int head[N],last[M],to[M],w[M],cnt;
int T,R,P,S;

void add(int a,int b,int c){
	to[++cnt] = b;
	w[cnt] = c;
	last[cnt] = head[a];
	head[a] = cnt;
}

int bcnt[N];//隶属于哪个连通块
vector<int>v[N];//连通块里有哪些点
int flag[N],anss;
void dfs(int x,int id){
	v[id].push_back(x);
	bcnt[x] = id;

	for(int i = head[x]; i != -1; i = last[i]){
		if(!bcnt[to[i]]) dfs(to[i],id);
	}

}

int toop[N];
queue<int>q;
int dist[N],st[N];

void dij(int s){

	priority_queue<pii,vector<pii>,greater<pii> > heap;

	for(int i = 0; i < v[s].size(); i++){
		heap.push({dist[v[s][i]],v[s][i]});
	}


	while(heap.size()){
		pii p = heap.top();
		heap.pop();
		//if(p.y == S) cout << "asdasd" << endl;
		if(!st[p.y]) st[p.y] = 1;
		else continue;

		for(int i = head[p.y]; i != -1; i = last[i]){
			if(dist[to[i]] > dist[p.y] + w[i]){
				dist[to[i]] = dist[p.y] + w[i];
				if(bcnt[to[i]] == bcnt[p.y]){
					heap.push({dist[to[i]],to[i]});
				}
			}
			//if(p.y == S) cout << to[i] << " " << dist[to[i]] << endl;
			if(bcnt[to[i]] != bcnt[p.y]){
				toop[bcnt[to[i]]]--;
				if(toop[bcnt[to[i]]] == 0){
					q.push(bcnt[to[i]]);
				}
			}
		}

	}
}

void toopsort(){
	memset(dist,0x3f,sizeof dist);
	dist[S] = 0;
	for(int i = 1; i <= anss; i++){
		if(toop[i] == 0){
			q.push(i);
		}
	}
	while(q.size()){
		int p = q.front();
		q.pop();
		dij(p);
	}
}

int main(){
    for(int _ = 1; _<= 1; _++){
        endTest(_);
        cnt = 0;
        cin >> T >> R >> P >> S;
        memset(head,-1,sizeof head);
        memset(bcnt,0,sizeof bcnt);
        memset(toop,0,sizeof toop);
        anss = 0;
        for(int i = 1; i <= 25000; i++) v[i].clear();
        for(int i = 1,x,y,z; i <= R; i++){
            cin >> x >> y >> z;
            add(x,y,z);
            add(y,x,z);
        }

        for(int i = 1; i <= T; i++){
            if(!bcnt[i]){
                ++anss;
                dfs(i,anss);
            }
        }


        for(int i = 1,x,y,z; i <= P; i++){
            cin >> x >> y >> z;
            add(x,y,z);
            toop[bcnt[y]]++;
        }

        //cout << bcnt[S] << " " <<toop[bcnt[S]] << endl;


        toopsort();

        for(int i = 1; i <= T; i++){
            if(dist[i] > INF / 2) cout << "NO PATH" << endl;
            else cout << dist[i] << endl;
        }
    }


	return 0;
}
