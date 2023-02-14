#include<iostream>
#include<cmath>
#include<algorithm>
#include<testlib.h>

using namespace std;

const int N = 100010;
int a[N];

int main(){
    for(int _ = 1; _ <= 11; _++){
        endTest(_);
        int n;
        cin >> n;
        int  sum = 0;
        for(int i = 1; i <= n; i++){
            cin >> a[i];
        }

        sort(a + 1,a + n + 1);

        int l = 1,r = n;
        while(l <= r){
            if(l != r) sum += a[r] - a[l];
            --r,++l;
        }


        cout << sum << endl;
    }


	return 0;
}
