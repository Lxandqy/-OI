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
    for(int i = 2; i <= 2; i++){
        startTest(i);
        int x;
        cout <<(x = (int)3e5) << endl;
        for(int j = 1; j <= x; j++){
            cout << 'a';
        }
        cout << endl;
        cout << 10 << endl;
        for(int j = 1; j <= 10; j++){
            cout << char('b');
        }
        cout << endl;

        cout << rnd.next(0,5) << endl;
    }





    return 0;
}
