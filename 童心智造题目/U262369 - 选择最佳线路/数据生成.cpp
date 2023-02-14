#include<iostream>
#include<cstring>
#include<cmath>
#include<testlib.h>
#define randoms(a,b) ((1ll * rand())%(b-a)+a)
#define random(a,b) (xorShift128Plus() % (b - a) + a)
#define endl "\n"

using namespace std;

const int N = 1000010;

int fa[N];
int find(int x){
    if(fa[x] == x) return x;
    return fa[x] = find(fa[x]);
}

map<int,int>mp[N];
map<int,int>mp2[N];

int dd[N],anss[N];

vector<int>v[N];

int outx[N],outy[N],outz[N],Dj[N],flag[N];

int main(int argc,char *argv[]){
    registerGen(argc, argv, 1);

    int a,b,c,d,maxn = 0;
    for(int _ = 1; _ <= 10; _++){
        int k = rnd.next(1,10);

        startTest(_);
        while(k--){
            memset(flag,0,sizeof flag);
            int n,m,k;
            cout << (n = rnd.next(1,1000)) << " " << (m = rnd.next(1,20000)) << " " << rnd.next(1,n) << endl;
            for(int i = 1; i <= m; i++){
                cout << rnd.next(1,n) << " " << rnd.next(1,n) << " " << rnd.next(1,1000) << endl;
            }
            int w;
            cout << (w = rnd.next(1,n / 10)) << endl;
            for(int i = 1; i <= w; i++){
                int x = rnd.next(1,n);
                while(flag[x]) x = rnd.next(1,n);
                cout << x<< " ";
                flag[x] = 1;
            }


        }
        cout << endl;



    }


    return 0;
}
