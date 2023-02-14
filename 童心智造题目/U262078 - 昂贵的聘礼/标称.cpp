#include<iostream>
#include<vector>
#include<cstring>
#include<queue>
#include<cmath>
#include<testlib.h>

using namespace std;
const int N = 110;
struct node1{
	int to,w;
};
int x[N],y[N],z[N],dist[N],flag[N];

vector<node1>v[N];

struct node{
	int w,to;
	bool operator <(const node &s)const{
		return w > s.w;
	}
};
int n,m;

int spfa(int s,int t){
	memset(flag,0,sizeof flag);
	memset(dist,0x3f,sizeof dist);
	priority_queue<node>q;
	q.push({x[1],1});
	dist[1] = x[1];
	while(q.size()){
		node p = q.top();
		q.pop();
		//cout << p.to << " " << p.w << "Asd" << endl;
		flag[p.to] = 0;
		for(int i = 0; i < v[p.to].size(); i++){
			//cout << p.to << " " <<  v[p.to][i].w << " " << x[v[p.to][i].to] << endl;
			//cout << y[v[p.to][i].to] << endl;
			if(y[v[p.to][i].to] >= s && y[v[p.to][i].to] <= t && dist[v[p.to][i].to] > dist[p.to] - x[p.to] + v[p.to][i].w + x[v[p.to][i].to]){
				dist[v[p.to][i].to] = dist[p.to] - x[p.to] + v[p.to][i].w + x[v[p.to][i].to];
				if(!flag[v[p.to][i].to]){
					flag[v[p.to][i].to] = 1;
					q.push({dist[v[p.to][i].to],v[p.to][i].to});
				}
			}
		}
	}
}

int main(){

    for(int _ = 1; _ <= 10; _++){
        endTest(_);
        cin >> n >> m;
        for(int i = 0; i <= m; i++) v[i].clear();
        int s,w;
        for(int i = 1; i <= m; i++){
            cin >> x[i] >> y[i] >> z[i];
            for(int j = 1; j <= z[i]; j++){
                cin >> s >> w;
                v[i].push_back({s,w});
            }
        }


        int minn = 0x3f3f3f;
        for(int i = y[1] - n; i <= y[1]; i++){
            spfa(i,i + n);
            for(int j = 1; j <= m; j++){
                minn = min(minn,dist[j]);
            }
        }

        cout << minn << endl;
    }

	return 0;
}
