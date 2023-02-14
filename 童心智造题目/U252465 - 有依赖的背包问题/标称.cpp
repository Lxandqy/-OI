#include<stdio.h>
int main(){
int m;
 int s;
 int t;
 scanf("%d %d %d",&m,&t,&s);
 if(t==0){
 return 0;
 }
 if(s%t==0){
        int k = m-s/t;
 if(k > 0){
    printf("%d",(m-s/t));
 }else{
     printf("%d",-(m-s/t));
 }

 }else if(s%t!=0){
 printf("%d",(m-s/t-1));
 }

 return 0;
 不知道那又错了
}
