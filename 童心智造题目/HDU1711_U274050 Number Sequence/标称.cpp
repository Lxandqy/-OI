#include<bits/stdc++.h>
#include<testlib.h>
using namespace std;

const int N = 2e6 + 10;

int a[N],pi[N];

int main(){

    for(int _ = 1; _  <= 11; _++){
        endTest(_);
        int t;
        cin >> t;
        while(t--){
            int n,m;
            cin >> n >> m;
            for(int i = 1; i <= n; i++){
                scanf("%d",&a[m + 1 + i]);
            }
            a[m + 1] = 100000000;
            for(int i = 1; i <= m; i++){
                scanf("%d",&a[i]);
            }

            pi[0] = 0;
            pi[1] = 0;
            for(int i = 2; i <= n + m + 1; i++){
                int j = pi[i - 1];
                while(j != 0 && a[j + 1] != a[i]){
                    j = pi[j];
                }
                if(a[j + 1] == a[i]) pi[i] = j + 1;
                else pi[i] = 0;
            }

            int id = -1;
            for(int i = m + 2; i <= n + m + 1; i++){
                if(pi[i] == m){
                    id = i - (m + 1) - (m - 1);
                    break;
                }
            }

            printf("%d\n",id);
        }
    }







	return 0;
}
