#include<iostream>
#include<cstring>
#include<testlib.h>
using namespace std;
const int maxn = 1e2 + 10;
int a[maxn][maxn],dp[maxn][maxn];
int main(){
    for(int _ = 1; _ <= 11; _++){
        endTest(_);
        int t;
        cin >> t;
        while(t--){
            memset(dp,0,sizeof dp);
            int n,m;
            cin >> n >> m;
            for(int i = 1; i <= n; i++){
                for(int j = 1; j <= m; j++){
                    cin >> a[i][j];
                }
            }
            for(int i = 1; i <= n; i++){
                for(int j = 1; j <= m; j++){
                    dp[i][j] = max(dp[i][j - 1] + a[i][j],dp[i - 1][j] + a[i][j]);
                }
            }
            cout << dp[n][m] << endl;
        }
    }







	return 0;
}
