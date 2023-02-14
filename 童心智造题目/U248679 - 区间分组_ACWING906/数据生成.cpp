#include<iostream>
#include<cstring>
#include<cmath>
#include<testlib.h>
#define randoms(a,b) ((1ll * rand())%(b-a)+a)
#define random(a,b) (xorShift128Plus() % (b - a) + a)
#define endl "\n"

using namespace std;


int main(int argc,char *argv[]){
    registerGen(argc, argv, 1);

    int a[10];
    for(int _ = 1; _ <= 10; _++){
        startTest(_);
        int n;
        int s,t;
        cout << (rnd.next((int)-1e6,(int)1e6)) << " " << ( rnd.next(s,(int)1e6)) << endl;
        int blocks = 10000;

        cout << (n = rnd.next(100000,100000)) << endl;
        int sz = 1e7 / blocks;

        int start = -2e6,ed = start + sz / 5;

        for(int i = 1; i <= blocks - 1; i++){
            for(int j = 1; j <= n / blocks / 5; j++){
                    int x,y;
                cout << (x = rnd.next(start,ed)) << " " << (y = rnd.next(x,ed)) <<endl;

            }start += sz / 5;
                ed += sz / 5;
            for(int j = 1; j <= n / blocks / 5; j++){
                    int x,y;
                cout << (x = rnd.next(start,ed)) << " " << (y = rnd.next(x,ed)) <<endl;

            }start += sz / 5;
                ed += sz / 5;
            for(int j = 1; j <= n / blocks / 5; j++){
                    int x,y;
                cout << (x = rnd.next(start,ed)) << " " << (y = rnd.next(x,ed)) <<endl;

            }start += sz / 5;
                ed += sz / 5;
            for(int j = 1; j <= n / blocks / 5; j++){
                    int x,y;
                cout << (x = rnd.next(start,ed)) << " " << (y = rnd.next(x,ed)) <<endl;

            }start += sz / 5;
                ed += sz / 5;
            for(int j = 1; j <= n / blocks - n / blocks / 5 * 4; j++){
                    int x,y;
                cout << (x = rnd.next(start,ed)) << " " << (y = rnd.next(x,ed)) <<endl;

            }start += sz / 5;
                ed += sz / 5;
        }

        int sum = n - n / blocks * (blocks - 1);
        for(int j = 1; j <= sum / 5; j++){
                    int x,y;
                cout << (x = rnd.next(start,ed)) << " " << (y = rnd.next(x,ed)) <<endl;

            }start += sz / 5;
                ed += sz / 5;
            for(int j = 1; j <= sum / 5; j++){
                    int x,y;
                cout << (x = rnd.next(start,ed)) << " " << (y = rnd.next(x,ed)) <<endl;

            }start += sz / 5;
                ed += sz / 5;
            for(int j = 1; j <= sum / 5; j++){
                    int x,y;
                cout << (x = rnd.next(start,ed)) << " " << (y = rnd.next(x,ed)) <<endl;

            }start += sz / 5;
                ed += sz / 5;
            for(int j = 1; j <= sum / 5; j++){
                    int x,y;
                cout << (x = rnd.next(start,ed)) << " " << (y = rnd.next(x,ed)) <<endl;

            }start += sz / 5;
                ed += sz / 5;
            for(int j = 1; j <= sum - sum / 5 * 4; j++){
                    int x,y;
                cout << (x = rnd.next(start,ed)) << " " << (y = rnd.next(x,ed)) <<endl;

            }start += sz / 5;
                ed += sz / 5;


    }





    return 0;
}
