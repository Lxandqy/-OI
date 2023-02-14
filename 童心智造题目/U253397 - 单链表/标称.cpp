#include<iostream>
#include<testlib.h>
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
int main(){

        for(int _ = 8; _ <= 8; _++){
                endTest(_);
            int t;
            cin >> t;
            cnt = 0;
            head = -1;
            memset(next1,0,sizeof next1);
            char ch;int x,y;
            for(int i = 1; i <= t; i++){
                cin >> ch;
                if(ch == 'H'){
                    cin >> x;
                    add1(x);
                }else if(ch == 'D'){
                    cin >> x;
                    if(!x) head = next1[head];
                    delte(x - 1);
                }else{
                    cin >> x >> y;
                    add2(x - 1,y);
                }
            }
            for(int i = head;i != -1; i = next1[i]){
                cout << w[i] << " ";
            }

        }


    return 0;
}
