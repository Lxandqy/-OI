#include<stdio.h>

int main(){

    int n;
    scanf("%d",&n);
    for(int i = 1; i <= n; i++){
        int a;
        scanf("%d",&a);

        if(a >= 700){
                printf("我考上了杭二中!!");
            }else if(a >= 698){
                printf("我考上了学军中学!!");
            }else if(a >= 695){
                printf("我考上了萧山中学!!");
            }else{
                printf("我好菜!我高中要继续加油!");
        }
        if(i != n) printf("\n");
    }





    return 0;
}
