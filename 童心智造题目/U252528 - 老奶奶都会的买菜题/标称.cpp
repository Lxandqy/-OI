#include<iostream>
#include<algorithm>
#include<testlib.h>
#include<queue>
#define first x
#define second y

using namespace std;


const int N = 1e4 + 10;

int dp[N];

int a[N], b[N];

int main(){

    for(int _ = 1; _<= 10; _++){
        endTest(_);
        memset(dp,0,sizeof dp);
        int n,m;
        cin >> n >> m;
        for(int i = 1; i <= n; i++){
            cin >> a[i] >> b[i];
            a[i] /= 100;
        }

        m /= 100;
        for(int i = 1; i <= n; i++){
            for(int j = m; j >= a[i]; j--){
                dp[j] = max(dp[j],dp[j - a[i]] + b[i]);
            }
        }

        cout << dp[m] << endl;

    }




    return 0;
}
