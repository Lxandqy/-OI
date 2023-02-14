#include<iostream>
#include<algorithm>
#include<testlib.h>
#include<queue>
#define first x
#define second y

using namespace std;

const int N = 10000;

typedef pair<int,int> PII;
const int maxn = 1e3 + 10;
const int mod = 1e9 + 7;
int b[N];

int main(){

    long long a[N];
    for(int _ = 1; _<= 10; _++){
        endTest(_);

        int n,m;
        cin >> n >> m;
        int v[maxn] = {},w[maxn] = {},dp[maxn] = {},count[maxn] = {};
        for(int i = 1; i <= n; i++){
            cin >> v[i] >> w[i];
        }
        for(int i = 0; i <= m; i++){
            count[i] = 1;
        }
        for(int i = 1; i <= n; i++){
            for(int j = m; j >= v[i]; j--){
                if(dp[j] == dp[j - v[i]] + w[i]){
                    count[j] = (count[j] + count[j - v[i]]) % mod;
                }else if(dp[j] < dp[j - v[i]] + w[i]){
                    dp[j] = dp[j - v[i]] + w[i];
                    count[j] = count[j - v[i]] % mod;
                }
            }
        }
        cout << count[m] << endl;




    }




    return 0;
}
