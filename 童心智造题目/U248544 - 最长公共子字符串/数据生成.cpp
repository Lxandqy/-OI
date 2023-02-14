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
    for(int i = 9; i <= 9; i++){
        startTest(i);
        int x,y;
        cout << (x = (int)1e6) << " " << (y = rnd.next(1,1000)) << endl;
        int sum = 0;
        int siz = x / y;
        for(int k = 1; k <= y - 1; k++){
            int sizes = rnd.next(1,siz);
            sum += sizes;
            for(int j = 1; j <= sizes; j++){
                cout << (char('a' + rnd.next(7,25)));
            }
            cout << endl;
        }
        for(int j = 1; j <= x - sum; j++){
            cout << (char('a' + rnd.next(7,25)));
        }

    }





    return 0;
}
