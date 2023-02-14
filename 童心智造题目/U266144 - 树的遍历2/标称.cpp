#include<iostream>
#include<cstring>
#include<testlib.h>
#include<vector>

using namespace std;

const int N = 1e6 + 10;
vector<int>v[N];
int dp[N];
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
        for(int i = 1; i <= n; i++) v[i].clear();
        for(int i = 1; i <= n - 1; i++){
            int x,y;
            cin >> x >> y;
            v[x].push_back(y);
            v[y].push_back(x);
        }


        dp[1] = 1;
        dfs(1,0);

        for(int i = 1; i <= n; i++){
            cout << dp[i] << endl;
        }

    }




    return 0;
}
