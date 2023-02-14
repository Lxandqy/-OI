#include<iostream>
#include<cstring>
#include<testlib.h>

using namespace std;

const int N = 1e3 + 10;
int b[N][N];
int dp[N],fa[N];
int n;
void dfs(int x,int pre){
    for(int i = 1; i <= n; i++){
        if(i == pre) continue;
        if(b[x][i]){
            dp[i] = dp[x] + 1;
            dfs(i,x);
        }
    }
}

int main(){
    for(int _= 1; _ <= 10;_++){
        endTest(_);
        cin >> n;
        memset(b,0,sizeof b);
        memset(fa,0,sizeof fa);
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
            while(fa[root] != 0){
                b[fa[root]][root] = 1;
                root = fa[root];
            }
        }

        dp[root] = 1;
        dfs(root,0);

        cout << root << endl;

        for(int i = 1; i <= n; i++) cout << dp[i] << endl;
        for(int i = 1; i <= n; i++){
            int sum = 0;
            for(int j = 1; j <= n; j++){
                if(b[i][j]){
                    sum++;
                }
            }
            if(!sum) cout << 0 << endl;
            else{
               for(int j = 1; j <= n; j++){
                    if(b[i][j]){
                        cout << j << " ";
                    }
                }
                cout << endl;
            }
        }



    }




    return 0;
}
