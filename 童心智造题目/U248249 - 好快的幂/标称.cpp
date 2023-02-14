#include<stdio.h>
#include<bits/stdc++.h>
#include<testlib.h>

using namespace std;

const int N  = 1e6 + 10;
typedef long long ll;
int n;

long long mod;

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

        long long a,b;
        cin >> a >> b;
        mod = b;
        cout << qpow(a,b - 2)  << endl;





	return 0;
}
