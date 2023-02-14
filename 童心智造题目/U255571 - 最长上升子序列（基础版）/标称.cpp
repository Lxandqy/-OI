#include<iostream>
#include<testlib.h>
using namespace std;
const int maxn = 100010;
int main(){

    for(int _ = 1; _ <= 10; _++){
        endTest(_);
        int n;
        cin >> n;
        int a[maxn] = {},q[maxn] = {};
        for(int i = 1; i <= n; i++){
            cin >> a[i];
        }
        int len = 0;
        for(int i = 1; i <= n; i++){
            int l = 0,r = len;
            while(l < r){
                int mid = (l + r + 1) >> 1;
                if(q[mid] >= a[i]){
                    r = mid - 1;
                }else l = mid;
            }
            len = max(len,r + 1);
            q[r + 1] = a[i];
        }
        cout << len << endl;
    }
	return 0;
}
