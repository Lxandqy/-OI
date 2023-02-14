#include<bits/stdc++.h>
#include<testlib.h>
#define N 1005
#define int long long
using namespace std;
int n, m, k, anss = -1;
vector<pair<int, int> > G[N];
bool vis[N][N];  // 走到i，超过了j次
bool dfs(int u, int pre, int tm, int mx){   // 走到哪里，上一次， 超过了几次， 限制
//	cout<<u<<endl;
	vis[u][tm] = true;
	if(u == n) return true;
	for(int i=0;i<G[u].size();i++){
		int v = G[u][i].first, w = G[u][i].second;
		if(v == pre) continue;
		if(w > mx) {
			if(tm<k && !vis[v][tm+1] && dfs(v, u, tm+1, mx)){
				return true;
			}
		}
		else {
			if(!vis[v][tm] && dfs(v, u, tm, mx)){
				return true;
			}
		}
	}
	return false;
}
signed main(){
    for(int _= 4; _ <= 10; _++){
        endTest(_);

        cin>>n>>m>>k;
        memset(vis,false,sizeof vis);
        for(int i = 1; i <= n; i++) G[i].clear();
        for(int i=1;i<=m;i++){
            int u, v, w;
            cin>>u>>v>>w;
            G[u].push_back({v, w});
            G[v].push_back({u, w});
        }
        int l = 0, r = 10000000;
        while(l<=r){
            int mid = l+r>>1;
            for(int i=1;i<=n;i++){
                for(int j=0;j<=k;j++){
                    vis[i][j] = 0;
                }
            }
            if(dfs(1, 1, 0, mid)){
                anss = mid;
                r = mid - 1;
            } else{
                l = mid + 1;
            }
        }
        cout<<anss<<endl;
    }

	return 0;
}
