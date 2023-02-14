#include<bits/stdc++.h>
#include<testlib.h>
using namespace std;

const int N = 3e5 + 10;
const int mod = 1e9 + 7;
const int p = 1e9 + 7;


char a[N],b[N];
int hasha[N];
int cal[N];
int hashb[N];

int n,m,k;

int find1(int r,int l){
	return ((hasha[r] - 1ll * hasha[l] * cal[r - l] % mod) % mod + mod) % mod;
}

int find2(int r,int l){
	return ((hashb[l] - 1ll * hashb[r] * cal[r - l] % mod) % mod + mod) % mod;
}

bool finds(int l1,int r1,int l2,int r2){
	if(find1(r1,l1) == find2(r2,l2)) return true;
	return false;
}

bool check(int x){
	for(int i = x + 1; i <= n - x; i++){
		if(finds(i - 1 - x,i - 1,i + 1,i + x + 1)) return true;
	}
	return false;
}

bool check2(int x){
	for(int i = x + 1; i <= n - x + 1; i++){
		if(finds(i - x - 1,i - 1,i,i + x)) return true;
	}
	return false;
}


int main(){

        scanf("%d",&n);
        scanf("%s",a + 1);
        cal[0] = 1;
        memset(hasha,0,sizeof hasha);
        memset(hashb,0,sizeof hashb);
        for(int i = 1; i <= n; i++){
            hasha[i] = 1ll * hasha[i - 1] * 135 % p + a[i];
            cal[i] = 1ll * cal[i - 1] * 135 % p;
        }

        for(int i = n; i >= 1; i--){
            hashb[i] = 1ll * hashb[i + 1] * 135 % p + a[i];
        }

        int l = 0,r = n;
        while(l < r){
            int mid = l + r + 1 >> 1;
            if(check(mid)) l = mid;
            else r = mid - 1;
        }

        int maxn = 1;
        maxn = max(maxn,l * 2 + 1);

        l = 0,r = n;
        while(l < r){
            int mid = l + r + 1 >> 1;
            if(check2(mid)) l = mid;
            else r = mid - 1;
        }

        maxn = max(maxn,l * 2);

        cout << maxn << endl;




	return 0;
}
