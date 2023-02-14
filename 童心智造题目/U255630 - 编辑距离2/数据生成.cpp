#include<iostream>
#include<cstring>
#include<cmath>
#include<testlib.h>
#define randoms(a,b) ((1ll * rand())%(b-a)+a)
#define random(a,b) (xorShift128Plus() % (b - a) + a)
#define endl "\n"

using namespace std;

const int N = 100010;

int main(int argc,char *argv[]){
    registerGen(argc, argv, 1);

    int a,b,c,d,maxn = 0;
    for(int _ = 1; _ <= 10; _++){
        startTest(_);
        cout << (a = rnd.next(1,1000)) << " " << (b = rnd.next(1,1000)) << endl;
        for(int i = 1; i <= a; i++){
            for(int k = 0; k < rnd.next(1,9); k++){
                cout << char(rnd.next(0,25) + 'a');
            }
            cout << endl;
        }
        for(int i = 1; i <= b; i++){
            int x;
            for(int k = 0; k < (x = rnd.next(1,9)); k++){
                cout << char(rnd.next(0,25) + 'a');
            }
            cout << " " << rnd.next(1,x);
            cout << endl;
        }
    }


    return 0;
}
