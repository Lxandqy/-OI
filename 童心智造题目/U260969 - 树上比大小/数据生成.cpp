#include<iostream>
#include<cstring>
#include<cmath>
#include<testlib.h>
#define randoms(a,b) ((1ll * rand())%(b-a)+a)
#define random(a,b) (xorShift128Plus() % (b - a) + a)
#define endl "\n"

using namespace std;

const int N = 10000010;

int fa[N];
int find(int x){
    if(fa[x] == x) return x;
    return fa[x] = find(fa[x]);
}

int main(int argc,char *argv[]){
    registerGen(argc, argv, 1);

    int a,b,c,d,maxn = 0;
    for(int _ = 1; _ <= 10; _++){
        startTest(_);
        int n;
        cout << (n = rnd.next(1,200000)) <<endl;
        for(int i = 1; i <= n; i++) fa[i] = i;
        int pre;
        cout << (pre = rnd.next(1,10000)) << " ";
        for(int i = 2; i <= n; i++){
            int x = rnd.next(1,5);
            if(x == 1){
                cout << pre << " ";
            }else if(x == 2 && 1ll * pre * 2 <= 1e9){
                cout << pre * 2 << " ";
                pre *= 2;
            }else if(x == 3 && 1ll * pre * 3 <= 1e9){
                cout << pre * 3 << " ";
                pre *= 3;
            }else if(x == 4 && pre % 2 == 0){
                cout << pre / 2 << " ";
                pre /= 2;
            }else if(x == 5 && pre % 3 == 0){
                cout << pre / 3 << " ";
                pre /= 3;
            }else{
                if(1ll * pre * 2 <= 1e9){
                    cout << pre * 2 << " ";
                    pre *= 2;
                }else if(pre % 2 == 0){
                    cout << pre / 2 << " ";
                    pre /= 2;
                }else{
                    cout << pre << " ";
                }
            }
        }
        cout << endl;
        for(int i = 1; i <= n - 1; i++){
            int x = rnd.next(1,n),y = rnd.next(1,n);
            while(find(x) == find(y)){
                x = rnd.next(1,n),y = rnd.next(1,n);
            }
            fa[find(x)] = find(y);
            cout << x << " " <<y << endl;
        }
        int m;
        cout << (m = rnd.next(1,200000))<<endl;
        for(int i = 1; i <= m; i++){
            cout << rnd.next(1,n) << endl;
        }
    }


    return 0;
}
