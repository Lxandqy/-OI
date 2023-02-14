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

int outx[N],outy[N],outz[N],Dj[N];

int main(int argc,char *argv[]){
    registerGen(argc, argv, 1);

    int a,b,c,d,maxn = 0;
    for(int _ = 1; _ <= 3; _++){
        startTest(_);
        int n,m;

        int T,R,P,S;
        int cnt = 0;
        T = 25000;
        R = 50000;
        P = 50000;
        S = rnd.next(1,T);
        cout <<T << " " <<R << " " << P << " " <<S << endl;
        for(int i = 1; i <= T; i++) mp[i].clear(),fa[i] = i,mp2[i].clear(),v[i].clear();

        int G = 1000;
        for(int i = 1; i <= T; i++){
            Dj[i] = rnd.next(1,T / G);
            v[Dj[i]].push_back(i);
        }

        cnt = 0;
        for(int i = 1; i <= P; i++){
            int x = rnd.next(1,T),y = rnd.next(1,T);
            while(Dj[x] <= Dj[y] || mp[x][y]){
                x = rnd.next(1,T),y = rnd.next(1,T);
            }
            mp[x][y] = rnd.next(-10000,10000);
            outx[i] = x;
            outy[i] = y;
            outz[i] = mp[x][y];
        }

        for(int i = 1; i <= R; i++){
            int s = rnd.next(1,T / G);
            while(v[s].size() < 2){
                s = rnd.next(1,T / G);
            }
            int x = rnd.next(0,(int)v[s].size() - 1),y = rnd.next(0,(int)v[s].size() - 1);
            while(x == y) y = rnd.next(0,(int)v[s].size() - 1);
            cout << v[s][x] << " " <<v[s][y] << " " <<rnd.next(1,10000) << endl;
        }


        for(int i = 1; i <= P; i++){

            cout <<outx[i] << " " <<outy[i] << " " << outz[i] <<endl;
        }

    }


    return 0;
}
