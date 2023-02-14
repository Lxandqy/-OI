#include<iostream>
#include<cstring>
#include<testlib.h>

using namespace std;

const int N = 1e3 + 10;
int a[N][N];
int dp[N];
int n;
void dfs(int x,int pre){
    for(int i = 1; i <= n; i++){
        if(i == pre) continue;
        if(a[x][i]){
            dp[i] = dp[x] + 1;
            dfs(i,x);
        }
    }
}

int main(){
    for(int _= 1; _ <= 10;_++){
        endTest(_);
        cin >> n;
        memset(a,0,sizeof a);
        for(int i = 1; i <= n - 1; i++){
            int x,y;
            cin >> x >> y;
            a[x][y] = 1;
            a[y][x] = 1;
        }


        dp[1] = 1;
        dfs(1,0);

        for(int i = 1; i <= n; i++){
            cout << dp[i] << endl;
        }

    }




    return 0;
}
