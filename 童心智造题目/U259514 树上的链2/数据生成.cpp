#include<iostream>
#include<cstring>
#include<cmath>
#include<testlib.h>
#define randoms(a,b) ((1ll * rand())%(b-a)+a)
#define random(a,b) (xorShift128Plus() % (b - a) + a)
#define endl "\n"

using namespace std;

const int N = 1000010;

int fa[N],flag[N];
int find(int x){
    if(fa[x] == x) return x;
    return fa[x] = find(fa[x]);
}

int main(int argc,char *argv[]){
    registerGen(argc, argv, 1);

    int a,b,c,d,maxn = 0;
    for(int _ = 13; _ <= 14; _++){
        startTest(_);
        int n,m;
        cout << (n = rnd.next(1,1000000)) << " " << (m = rnd.next(1,3)) <<endl;
        for(int i = 1; i <= n; i++) fa[i] = i,flag[i] = 0;
        for(int i = 1; i <= n; i++) cout << rnd.next(1,100000) << " ";
        cout << endl;
        for(int i = 1; i <= m; i++){
            int x = rnd.next(1,n);
            while(flag[x]){
                x = rnd.next(1,n);
            }
            flag[x] = 1;
            cout << x << " ";
        }
        cout << endl;
        for(int i = 1; i <= n -1; i++){
            cout << i <<" " << i +1 <<endl;
        }
        //cout << (n / 3 - 1 + n / 3 * 2 + 1 - n / 3 - 2 + 3 + n  - n / 3 * 2 -2) << "Asd" <<endl;
        /*for(int i = 1; i <= n / 3; i++){
            int x = rnd.next(1,n),y = rnd.next(1,n);
            cout << i << " " << i + 1 << endl;
        }
        //n / 3 ~ n/3 +1

        for(int i = n / 3 + 2; i <= n / 3 * 2 + 1; i++){
            if(i == n / 3 +2) cout << 1 << " " << i <<endl;
            else cout << i - 1  << " " << i << endl;
        }
        // 1 ~ n / 3 + 2
        //n / 3 + 2 ~ n / 3 + 3
        for(int i = n / 3 * 2 + 2; i <= n; i++){
            if(i == n / 3 * 2 + 2) cout << 1 << " " << i << endl;
            else cout << i - 1 << " " << i << endl;
        }*/
    }


    return 0;
}
