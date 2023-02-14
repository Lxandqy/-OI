#include<stdio.h>
#include <testlib.h>

int main(){
    for(int _ = 1; _ <= 10; _++){
        endTest(_);
        int n;
        scanf("%d",&n);
        int sum = 0;
        for(int i = 1; i <= n; i = i + 1){
            int x = i;
            for(;x > 0;){
                if(x % 10 == 1) sum++;
                x /= 10;
            }
        }
        printf("%d",sum);

    }





	return 0;
}
