#include<iostream>
#include<testlib.h>


using namespace std;

int a[1111111];
int sum[1000000];

int main(){


   for(int _ = 1; _ <= 10; _++){
        endTest(_);
        int n,k,sum = 0;
        cin >> n;
        for(;n > 0;){
            cout <<n % 10 << " ";
            n /= 10;
        }
   }









    return 0;
}
