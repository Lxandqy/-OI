#include<bits/stdc++.h>
#include<testlib.h>
using namespace std;
const int maxn = 100100;
int son[maxn * 32][2],idx = 2;
int a[maxn];
void insert(int s){
    int p = 1;
    for(int i = 30; i >= 0; i--){
    	int k = s >> i & 1;
    	if(!son[p][k]) son[p][k] = ++idx;
    	p = son[p][k];
	}
}
int query(int s){
    int p = 1;
    int ans = 0;
    for(int i = 30; i >= 0; i--){
    	int k = s >> i & 1;
    	if(son[p][k ^ 1]){
            p = son[p][k ^ 1];
            ans |= 1 << i;
        }else p = son[p][k];
	}
    return ans;
}
int main(){

    for(int _ = 1; _ <= 11; _++){
        endTest(_);
        memset(son,0,sizeof son);
        idx = 2;
        int n;
        cin >> n;
        int res = 0;
        for(int i = 1; i <= n; i++){
            scanf("%d",&a[i]);
            insert(a[i]);
            res = max(res,query(a[i]));
        }

        cout << res << endl;
    }

    return 0;
}
