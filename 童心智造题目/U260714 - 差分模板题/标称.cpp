#include<iostream>
#include<testlib.h>

using namespace std;

const int N = 1e5+10;
long long a[N],b[N];

int main(){

    for(int _ = 1; _<= 10; _++){
        endTest(_);
        int n;
        cin >> n;
        for(int i = 1; i <= n; i++){
            cin >> a[i];
        }

        for(int i = 1; i <= n; i++){
            b[i] = a[i] - a[i - 1];
        }

        int m;
        cin >> m;
        for(int i = 1; i <= m; i++){
            int x,y,z;
            cin >> x >> y >> z;
            b[x] += z;
            b[y + 1] -= z;
        }

        for(int i = 1; i <= n; i++){
            b[i] += b[i - 1];
        }
        for(int i = 1; i <= n; i++){
            b[i] += b[i - 1];
        }

        int x,y;
        cin >> x >>y;
        cout << b[y] - b[x - 1] << endl;
    }


    return 0;
}
