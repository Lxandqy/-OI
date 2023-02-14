#include<iostream>
#include<testlib.h>


using namespace std;

int sum[1000000];

int main(){

    for(int _ = 1; _ <= 10; _++){
        endTest(_);
        int x;
        double m,k;
        scanf("%d %lf %lf",&x,&m,&k);
        printf("%.3lf",pow(x,m / k));
    }








    return 0;
}
