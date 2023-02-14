#include<iostream>
#include<testlib.h>

using namespace std;

const int N = 3010;
int a[N],b[N],dp[N][N];

int main(){

    for(int _ = 1; _ <= 11; _++){
        endTest(_);
        int n;
        cin >> n;
        for(int i = 1; i <= n; i++){
            cin >> a[i];
        }

        for(int j = 1; j <= n; j++){
            cin >> b[j];
        }

        for(int i = 1; i <= n; i++){
            int maxn = 1;
            for(int j = 1; j <= n; j++){
                dp[i][j] = dp[i - 1][j];
                if(a[i] == b[j]) dp[i][j] = max(dp[i][j],maxn);
                if(a[i] > b[j]) maxn = max(maxn,dp[i - 1][j] + 1);
            }
        }

        int ans = 0;
        for(int i = 1; i <= n; i++) ans = max(ans,dp[n][i]);
        cout << ans << endl;
    }



}
