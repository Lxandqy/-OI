#include<stdio.h>
#include<testlib.h>

int main(){
    for(int _ = 1; _ <= 10; _++){
        endTest(_);
        int n,k;
        scanf("%d %d",&n,&k);
        if(i % 19 != 0){
            printf("NO");
            return 0;
        }
        int x = i;
        int sum = 0;
        for(;x > 0;){
            if(x % 10 == 1) sum++;
            x /= 10;
        }
        if(sum == 3){
            printf("NO");
        }else{
            printf("YES");
        }
    }





	return 0;
}
