#include<iostream>
#include<cstring>
#include<testlib.h>
using namespace std;
const int N = 1005,INF = 0x3f3f3f;
int dp[N][N];
char a[N][N];
int main(){
    for(int _ = 1; _ <= 10; _++){
        endTest(_);
        int n,m;
        cin >> n >> m;
        for(int i = 1; i <= n; i++){
            scanf("%s",a[i] + 1);
        }
        char b[N];
        while(m--){
            int c;
            scanf("%s%d",b + 1,&c);
            int lb = strlen(b + 1);
            int sum = 0;
            for(int i = 1; i <= n; i++){
                int la = strlen(a[i] + 1);
                for(int j = 1; j <= la; j++){
                    for(int k = 1; k <= lb; k++){
                        dp[j][k] = INF;
                    }
                }
                for(int j = 0; j <= la; j++){
                    dp[j][0] = j;
                }
                for(int j = 0; j <= lb; j++){
                    dp[0][j] = j;
                }
                for(int j = 1; j <= la; j++){
                    for(int k = 1; k <= lb; k++){
                        dp[j][k] = min(dp[j][k - 1],dp[j - 1][k]) + 1;
                        if(a[i][j] == b[k]){
                            dp[j][k] = min(dp[j - 1][k - 1],dp[j][k]);
                        }else dp[j][k] = min(dp[j - 1][k - 1] + 1,dp[j][k]);
                    }
                }
                if(dp[la][lb] <= c) sum++;
            }
            cout << sum << endl;
        }
    }




    return 0;
}
