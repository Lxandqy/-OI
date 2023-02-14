#include<iostream>
#include<cstring>
#include<cmath>
#include<testlib.h>
#define randoms(a,b) ((1ll * rand())%(b-a)+a)
#define random(a,b) (xorShift128Plus() % (b - a) + a)
#define endl "\n"

using namespace std;

const int N = 100010;

int m;
int e[N], l[N], r[N], idx;

// 在节点a的右边插入一个数x
void insert(int a, int x)
{
    e[idx] = x;
    l[idx] = a, r[idx] = r[a];
    l[r[a]] = idx, r[a] = idx ++ ;
}

// 删除节点a
void remove(int a)
{
    l[r[a]] = l[a];
    r[l[a]] = r[a];
}

map<int,int>mp;

int main(int argc,char *argv[]){
    registerGen(argc, argv, 1);

    int a,b,c,d,maxn = 0;
    for(int _ = 1; _ <= 10; _++){
        startTest(_);
        idx = 0;
        int ans = -1;
        int n;
        mp.clear();
        cout << (n = rnd.next(1,100000)) <<endl;
        for(int i = 1; i <= n; i++){
            string op;
            int k, x;
            if(idx <= ans +1){
                op = "L";
                cout << op << " " << (x = rnd.next(1,1000000000)) << endl;
            }else{
                int s = rnd.next(1,5);
                if(s == 1){
                    op = "L";
                    cout << op << " " << (x = rnd.next(1,1000000000)) << endl;
                }else if(s == 2){
                    op = "R";
                    cout << op << " " << (x = rnd.next(1,1000000000)) << endl;
                }else if(s == 3){
                    op = "D";
                    ++ans;
                    k = rnd.next(1,idx);
                    while(mp[k]){
                        k = rnd.next(1,idx);
                    }
                    mp[k] = 1;
                    cout << op << " " << k << endl;
                }else if(s == 4){
                    op = "IL";
                    k = rnd.next(1,idx);
                    while(mp[k]){
                        k = rnd.next(1,idx);
                    }
                    cout << op << " " << k << " " << (x = rnd.next(1,1000000000)) << endl;
                }else{
                    op = "IR";
                    k = rnd.next(1,idx);
                    while(mp[k]){
                        k = rnd.next(1,idx);
                    }
                    cout << op << " " << k << " " << (x = rnd.next(1,1000000000)) << endl;
                }
            }
            if (op == "L")
            {
                insert(0, x);
            }
            else if (op == "R")
            {
                insert(l[1], x);
            }
            else if (op == "D")
            {
                remove(k + 1);
            }
            else if (op == "IL")
            {
                insert(l[k + 1], x);
            }
            else
            {
                insert(k + 1, x);
            }


        }

    }





    return 0;
}
