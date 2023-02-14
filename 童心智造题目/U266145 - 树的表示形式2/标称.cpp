#include<iostream>
#include<cstring>
#include<testlib.h>

using namespace std;

const int N = 1e5+ 10;

vector<int>v[N];
int dp[N],fa[N],flag[N];
int n;
void dfs(int x,int pre){
    for(int i = 0; i < v[x].size(); i++){
        int j = v[x][i];
        if(j == pre) continue;
        dp[j] = dp[x] + 1;
        dfs(j,x);
    }
}

int main(){
    for(int _= 1; _ <= 10;_++){
        endTest(_);
        cin >> n;
        memset(fa,0,sizeof fa);
        memset(flag,0,sizeof flag);
        for(int i = 1; i <= n; i++) v[i].clear();
        for(int i = 1; i <= n - 1; i++){
            int x,y;
            cin >>x >> y;
            fa[x] = y;
        }

        int root = 1;
        while(fa[root] != 0){
            root = fa[root];
        }

        for(int i = 1; i <= n; i++){
            int root = i;
            while(fa[root] != 0 && !flag[root]){
                v[fa[root]].push_back(root);
                flag[root] = 1;
                root = fa[root];
            }
        }

        dp[root] = 1;
        dfs(root,0);

        cout << root << endl;

        for(int i = 1; i <= n; i++) cout << dp[i] << endl;
        for(int i = 1; i <= n; i++){
            int sum = v[i].size();
            if(!sum) cout << 0 << endl;
            else{
                sort(v[i].begin(),v[i].end());
                for(int j = 0; j < v[i].size(); j++){
                    cout << v[i][j] << " ";

                }
                cout << endl;
            }
        }



    }




    return 0;
}
