#include<iostream>
#include<cstring>
#include<cmath>
#include<testlib.h>
#define randoms(a,b) ((1ll * rand())%(b-a)+a)
#define random(a,b) (xorShift128Plus() % (b - a) + a)

using namespace std;


int main(int argc,char *argv[]){
    registerGen(argc, argv, 1);

    for(int i = 1; i <= 10; i++){
        startTest(i);
        int a = rnd.next(-1000000000,1000000000);
        double b = rnd.next(-100000,100000);
        int c = rnd.next(-1000000000,1000000000);
        double d = rnd.next(-100000,100000);

        cout <<a << " " << c << " " <<b << " " <<d << endl;

    }






    return 0;
}
