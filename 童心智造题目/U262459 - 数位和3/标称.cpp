#include<iostream>
#include<testlib.h>


using namespace std;

int sum[1000000];

int main(){

    for(int _ = 1; _ <= 10; _++){
        endTest(_);
        int x;
        scanf("%d",&x);
        int cnt = 0;
        for(;x > 9;){
            x -= 9;
            sum[++cnt] = 9;
        }
        sum[++cnt] = x;

        for(int i = cnt; i >= 1; i--){
            printf("%d",sum[i]);
        }
    }








    return 0;
}
