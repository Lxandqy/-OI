#include<iostream>
#include<testlib.h>
using namespace std;
const int maxn = 1005;
int dp[maxn][maxn] = {};
char a[maxn],b[maxn];
int main(){
    for(int _ = 1; _ <= 10; _++){
        endTest(_);
        int n,m;
        cin >> n >> m;
        scanf("%s", a + 1);
        scanf("%s", b + 1);
        memset(dp,0,sizeof dp);
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(a[i] == b[j]){
                    dp[i][j] = max(dp[i - 1][j - 1] + 1,dp[i][j]);
                }else{
                    dp[i][j] = max(dp[i][j],max(dp[i - 1][j],dp[i][j - 1]));
                }
            }
        }
        cout << dp[n][m] << endl;
    }






    return 0;
}
