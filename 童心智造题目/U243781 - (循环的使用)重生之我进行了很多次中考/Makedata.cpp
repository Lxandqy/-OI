#include<bits/stdc++.h>
#define randoms(a,b) ((1ll * rand())%(b-a)+a)
#define random(a,b) (xorShift128Plus() % (b - a) + a)
using namespace std;

ofstream outfile("./data/game6.in", ios::trunc);

int mod;
unsigned long long k1 =32141221ull, k2 = 2421421ll;
unsigned long long xorShift128Plus() {
    unsigned long long k3 = k1, k4 = k2;
    k1 = k4;
    k3 ^= k3 << 23;
    k2 = k3 ^ k4 ^ (k3 >> 17) ^ (k4 >> 26);
    return k2 + k4;
}


int main(){
    srand((int)time(0));
    k1 = rand(),k2 = rand();
    int x;
    outfile << 1 <<endl;
    outfile << 700 << endl;
    /*outfile <<(x = randoms(10,100)) << endl;
    for(int i = 1; i <= x; i++){
        outfile << randoms(690,710) << endl;
    }*/


	return 0;
}

