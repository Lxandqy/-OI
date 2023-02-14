#include<iostream>
#include<testlib.h>

using namespace std;

const int N = 1e5+10;
int a[N];

int main(){

    for(int _ = 1; _<= 10; _++){
        endTest(_);
        int n;
        cin >> n;
        for(int i = 1; i <= n; i++){
            cin >> a[i];
        }
        for(int i = 1; i <= n; i++) a[i] += a[i - 1];
        int m;

        cin >> m;
        for(int i = 1; i <= m; i++){
            int x,y;
            cin >>x >>y;
            cout << a[y] - a[x - 1] <<endl;
        }
    }


    return 0;
}
