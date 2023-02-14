#include<iostream>
#include<queue>
#include<cstring>
#include<utility>
#include<testlib.h>

#define x first
#define y second

using namespace std;
typedef pair<int,int> pii;
const int N = 10100,M = 200100;
int n,m,a[N],k,s;

int head[N],last[M],to[M],w[M],cnt;
void add(int a,int b,int c){
	to[++cnt] = b;
	w[cnt] = c;
	last[cnt] = head[a];
	head[a] = cnt;
}

int flag[N],dist[N];
void dij(int start){
	for(int i = 1; i <= n; i++){
		flag[i] = 0;
		dist[i] = 0x3f3f3f3f;
	}

	priority_queue<pii,vector<pii>,greater<pii> > q;
	q.push({0,start});
	dist[start] = 0;
	while(q.size()){
		pii p = q.top();
		q.pop();
		if(!flag[p.y]) flag[p.y] = 1;
		else continue;
		for(int i = head[p.y]; i != -1; i = last[i]){
			if(dist[to[i]] > dist[p.y] + w[i]){
				dist[to[i]] = dist[p.y] + w[i];
				q.push({dist[to[i]],to[i]});
			}
		}
	}
}

int main(){
    for(int _ = 10 ; _ <= 10 ; _++){
        endTest(_);
        while(cin >> n >> m >> k){

            cnt = 0;
            for(int i = 1; i <= n; i++){
                head[i] = -1;
            }

            for(int i = 1,x,y,z; i <= m; i++){
                scanf("%d%d%d",&x,&y,&z);
                add(y,x,z);
            }

            cin >> s;
            for(int i = 1; i <= s; i++){
                scanf("%d",&a[i]);
            }

            dij(k);

            int maxn = 0x3f3f3f3f;
            for(int i = 1; i <= s; i++){
                maxn = min(maxn,dist[a[i]]);
            }

            if(maxn > 0x3f3f3f3f / 2) maxn = -1;
            cout << maxn << endl;
        }
    }




	return 0;
}
/*5 10 2
4 5 1
4 3 8
5 4 1
3 2 9
4 2 5
5 3 8
1 5 4
3 1 2
1 3 9
2 1 8
1
1
*/
