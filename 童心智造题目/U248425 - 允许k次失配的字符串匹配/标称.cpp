#include<stdio.h>
#include<testlib.h>

const int N = 3e5 + 10;
const int mod = 1e9 + 7;
const int p = 131;


char a[N],b[N];
int hasha[N],hashb[N];
int cal[N];

int n,m,k;
bool check(int l1,int r1,int l2,int r2){
	if(((hasha[r1] - 1ll * hasha[l1 - 1] * cal[r1 - l1 + 1] % mod) + mod) % mod == ((hashb[r2] - 1ll * hashb[l2 - 1] * cal[r2 - l2 + 1] % mod) + mod) % mod)
		return true;
	return false;
}



int main(){

    for(int _ = 1; _ <= 10; _++){
        endTest(_);
        scanf("%d",&n);
        scanf("%s",a + 1);
        scanf("%d",&m);
        scanf("%s",b + 1);
        scanf("%d",&k);

        //cout << a + 1 << endl;
        //cout << b + 1 << endl;
        cal[0] = 1;
        for(int i = 1; i <= n; i++){
            hasha[i] = 1ll * hasha[i - 1] * 131 % mod + a[i];
            cal[i] = 1ll * cal[i - 1] * 131 % mod;
        }

        for(int i = 1; i <= m; i++){
            hashb[i] = 1ll * hashb[i - 1] * 131 % mod + b[i];
        }

        int sum = 0;
        for(int i = 1; i <= n - m + 1; i++){
            int l1 = i,r1 = i + m - 1,l2 = 1,r2 = m,times = 0;
            while(!check(l1,r1,l2,r2) && l1 <= r1 && times <= k){
                times++;
                int l = l1,r = r1;
                while(l < r){
                    int mid = l + r + 1 >> 1;
                    if(check(l,mid,l2,l2 + mid - l)){
                        l = mid;
                    }else r = mid - 1;
                }
                if(check(l1,l,l2,l2 + l - l1)){
                    l2 = l2 + (l + 2 - l1);
                    l1 = l + 2;
                }else{
                    l2 = l2 + (l + 1 - l1);
                    l1 = l + 1;
                }
            }
            if(times <= k) sum++;
        }

        printf("%d\n",sum);
    }







	return 0;
}
