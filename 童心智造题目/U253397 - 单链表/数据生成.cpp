#include<iostream>
#include<cstring>
#include<cmath>
#include<testlib.h>
#define randoms(a,b) ((1ll * rand())%(b-a)+a)
#define random(a,b) (xorShift128Plus() % (b - a) + a)
#define endl "\n"

using namespace std;

const int maxn = 100010;
int next1[maxn],w[maxn],head = -1,cnt = 0;
void add1(int x){
    w[cnt] = x;
    next1[cnt] = head;
    head = cnt++;
}

void add2(int k,int x){
    w[cnt] = x;
    next1[cnt] = next1[k];
    next1[k] = cnt++;
}

void delte(int k){
    next1[k] = next1[next1[k]];
}

map<int,int>mp;

int main(int argc,char *argv[]){
    registerGen(argc, argv, 1);

    int a,b,c,d,maxn = 0;
    for(int _ = 8; _ <= 8; _++){
        startTest(_);
        cnt = 0;
        int ans = -1;
        int n;
        mp.clear();
        head = -1;
        memset(next1,0,sizeof next1);
        cout << (n = rnd.next(1,100000)) <<endl;
        for(int i = 1; i <= n; i++){
            char ch;
            int x;
            int k;
            if(cnt <= ans + 5){
                cout << (ch = 'H') << " " << (k = rnd.next(1,100000000)) << endl;
            }else{
                int s = rnd.next(1,5);
                if(s <= 3){
                    cout << (ch = 'H') << " " << (k = rnd.next(1,100000000)) << endl;
                }else if(s == 4){
                    int g = rnd.next(1,2);
                    if(g == 1){
                        cout << (ch = 'D') << " " << (x = 0) << endl;
                        mp[head] = 1;
                    }else{
                        x = rnd.next(1,cnt);
                        while(mp[x] || next1[x] == 0 || mp[next1[x]]){
                           x = rnd.next(1,cnt);
                        }
                        mp[x] = 1;
                        mp[next1[x]] = 1;
                        cout << (ch = 'D') << " " << x << endl;
                    }
                    ++ans;
                }else{
                    x = rnd.next(1,cnt);
                    while(mp[x]){
                        x = rnd.next(1,cnt);
                    }
                    cout << (ch = 'I') << " " << x << " " << (k = rnd.next(1,1000000000)) << endl;
                }
            }

            if(ch == 'H'){
                add1(k);
            }else if(ch == 'D'){
                if(!x) head = next1[head];
                else delte(x - 1);
            }else{
                add2(x - 1,k);
            }
        }

    }





    return 0;
}
