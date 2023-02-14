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
        for(int i = 1; i <= 8; i++){
                cout << rnd.next(-100000,100000) << " ";
                if(i % 3 == 0) cout << endl;
        }

    }






    return 0;
}
