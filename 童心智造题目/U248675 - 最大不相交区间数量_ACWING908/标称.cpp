#include<iostream>
#include<algorithm>
#include<testlib.h>

using namespace std;

const int N= 100010;
struct node{
    int l,r;
}a[N];

bool cmp(node a,node b){
    return a.l < b.l;
}

int main(){
    for(int _= 1 ; _ <= 10; _++){
        endTest(_);
        int n;
        cin >> n;

        int x,y;
        for(int i = 1; i <= n; i++){
            cin >> x >> y;
            if(x > y) swap(x,y);
            a[i].l = x,a[i].r = y;
        }

        sort(a + 1,a + n + 1,cmp);

        int maxn = a[1].r;
        int sum = 1;
        for(int i = 2; i <= n; i++){
            if(a[i].l > maxn){
                sum++;
                maxn = a[i].r;
            }else{
                maxn = min(a[i].r,maxn);
            }
        }
        cout << sum << endl;
    }



    return 0;
}
