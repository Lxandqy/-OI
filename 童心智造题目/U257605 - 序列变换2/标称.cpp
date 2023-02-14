#include<iostream>
#include<cstring>
#include<testlib.h>

using namespace std;
const int N = 1e5 + 10;
int a[N],d[N];

int main(){

	for(int _ = 1; _ <= 10; _++){
        int t,s = 0;
        endTest(_);
        cin >> t;
        while(t--){
            memset(d,0,sizeof d);

            int n;
            cin >> n;
            cout << "Case #" << ++s << ":" << endl;
            for(int i = 1; i <= n; i++){
                cin >> a[i];
                a[i] -= i;
            }

            int len = 0;
            for(int i = 1; i <= n; i++){
                int l = 0,r = len;
                while(l < r){
                    int mid = l + r + 1 >> 1;
                    if(d[mid] > a[i]){
                        r = mid - 1;
                    }else l = mid;
                }
                d[r + 1] = a[i];
                len = max(len,r + 1);
            }

            cout << n - len << endl;

        }
	}



	return 0;
}
