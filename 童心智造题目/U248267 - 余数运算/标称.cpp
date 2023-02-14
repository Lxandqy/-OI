#include<stdio.h>
#include<bits/stdc++.h>
#include<testlib.h>

using namespace std;

const int N  = 1e6 + 10;
typedef long long ll;
int n;

const int mod = 1e9 + 7;

ll qpow(ll a,ll b){
	ll s = 1;
	while(b){
		if(b & 1) s = s * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return s;
}


int main(){


        for(int kk = 1; kk <= 10; kk++){
            endTest(kk);
            int a,b;
            cin >> a >>b;
            long long ans = 1;
            for(int j = 1; j <= b; j++){
                printf("%lld\n",ans * a % mod);
                ans *= a;
                ans %= mod;
            }
        }





	return 0;
}
