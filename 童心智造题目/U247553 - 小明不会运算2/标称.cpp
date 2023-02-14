#include<iostream>
#include<cstring>
#include<cmath>
#include<testlib.h>
#include<bits/stdc++.h>
using namespace std;



const int N = 310;

typedef long long ll;


int main(int argc,char* argv[]){
    registerGen(argc, argv, 1);

    long long a[10];
	for(int i = 1; i <= 10; i++){
        endTest(i);
        for(int j = 1; j <= 8; j++) cin >> a[j];
        cout << (a[1] + a[2]) * a[3] << endl;
        cout << (a[4] + a[5]) / a[6] << endl;
        cout << a[7] / a[8] << " " << a[7] % a[8] << endl;
	}









	return 0;
}
