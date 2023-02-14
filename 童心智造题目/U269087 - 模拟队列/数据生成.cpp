#include<iostream>
#include<cstring>
#include<cmath>
#include<testlib.h>
#include<queue>
#define randoms(a,b) ((1ll * rand())%(b-a)+a)
#define random(a,b) (xorShift128Plus() % (b - a) + a)
#define endl "\n"

using namespace std;

const int N = 101000;
int fa[N],n,m,t;
int find(int x){
    if(fa[x] == x) return x;
    return fa[x] = find(fa[x]);
}

vector<int>v[N];
int pe[N];
void dfs(int x,int pre){
    pe[x] = pre;
    for(int i= 0; i < v[x].size(); i++){
            int j = v[x][i];
        if(j == pre) continue;
            dfs(j,x);
    }
}

int a[N];

map<int,int>mp[1010];
int main(int argc,char *argv[]){
    registerGen(argc, argv, 1);

    int maxn = 0;
    for(int _ = 1; _ <= 11; _++){
        startTest(_);
        memset(pe,0,sizeof pe);
        int n;
        n = rnd.next(1,100000);
        cout << n << endl;
        queue<int>q;
        for(int i = 1; i <= n; i++){
            int s = rnd.next(1,6);
            if(s <=3){
                int x = rnd.next(1,1000000000);
                cout << "push " << x << endl;
                q.push(1);
            }else if(s == 4 && q.size()){
                cout << "pop " << endl;
                q.pop();
            }else if(s == 5 && q.size()){
                cout << "query" << endl;
            }else{
                cout << "empty" << endl;
            }
        }




    }


    return 0;
}
