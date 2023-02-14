#include<iostream>
#include<cstring>
#include<cmath>
#include<testlib.h>
#include<bits/stdc++.h>
using namespace std;


const int N = 310;

typedef long long ll;

ll a[N],b[N],dp[N][N],s[N][N];

int main(int argc,char* argv[]){
    registerGen(argc, argv, 1);

    for(int _ =1; _ <= 10; _++){
        endTest(_);
        int n,m;
        cin >> n >> m;
        for(int i = 1; i <= n; i++){
            cin >> a[i];
        }

        ll sums = 0;
        for(int i = 1; i <= n; i++){
            b[i] = a[i] - a[i - 1];
            if(b[i] > 0) sums += b[i];
            // cout << b[i] << " ";
        }
        // cout << endl;

        b[n + 1] = -a[n];

        for(int i = 1; i <= n; i++){
            ll sum = 0,sum2 = 0;
            for(int j = i; j <= n + 1; j++){
                if(b[j] > 0) sum += b[j];
                if(b[j] < 0) sum2 += b[j];
                s[i][j] = min(abs(sum),abs(sum2));
            }
        }

        // cout << s[1][3] << endl;

        memset(dp,0,sizeof dp);
        ll ans = 0;
        for(int i = 0; i <= m; i++){
            for(int j = 0; j <= n + 1; j++){
                dp[i][j] = max(dp[i][j - 1],dp[i][j]);
                for(int k = j + 2; k <= n + 1 && k <= j + m - i + 1; k++){
                    // if(j == 0 && k == 6){
                        // cout << s[j + 1][k] << endl;
                    // }
                    dp[i + k - j - 1][k] = max(dp[i + k - j - 1][k],dp[i][j] + s[j + 1][k]);
                    // cout << i << " " << j << " " << k << " " << i + k - j - 1 << " "<< dp[i + k - j - 1][k] << endl;
                    ans = max(ans,dp[i + k - j - 1][k]);
                }
            }
        }

        cout << sums - ans << endl;

    }










	return 0;
}
