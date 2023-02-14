#include<iostream>
#include<cstring>
#include<cmath>
#include<testlib.h>
#define randoms(a,b) ((1ll * rand())%(b-a)+a)
#define random(a,b) (xorShift128Plus() % (b - a) + a)

using namespace std;


int main(int argc,char *argv[]){
    registerGen(argc, argv, 1);

    int a[10];
    for(int i = 1; i <= 10; i++){
        startTest(i);
        int n;
        cout << (n = rnd.next(1,100000)) << endl;
        for(int j = 1; j <= n; j++){
            int x = rnd.next((int)-1e9,(int)1e9);
            int y = rnd.next(x,(int)1e9);
            cout << x << " " <<y << endl;
        }
    }





    return 0;
}
