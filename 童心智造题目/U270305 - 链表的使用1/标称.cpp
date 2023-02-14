#include<iostream>
#include<testlib.h>
using namespace std;
const int maxn = 2000010;
int a[maxn],to[maxn],last[maxn];
int cnt = 0;
int main(){
    for(int _ = 1; _ <= 11; _++){
        endTest(_);
        int n;
        cin >>n;
        for(int i = 1; i <= n; i++){
            cin >> a[i];
        }
        for(int i = 0; i <= 2000003; i++) to[i] = last[i] = -1;
        for(int i = 1; i <= n - 1; i++) to[a[i]] = a[i + 1];
        for(int i = 2 ; i <= n; i++) last[a[i]] = a[i - 1];

        int q;
        cin >> q;
        while(q--){
            int x,y;
            cin >>x >> y;
            to[y] = to[x];
            last[to[y]] = y;
            last[y] = x;
            to[x] = y;
        }

        int head = a[1];
        while(to[head] != -1){
            cout << head << " ";
            head = to[head];
        }
        cout << endl;
    }


    return 0;
}
