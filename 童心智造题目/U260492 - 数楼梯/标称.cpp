#include<stdio.h>
#include<testlib.h>
int n;
long long a[5100];

long long f(int x){
	if(x == 0) return 1;
	if(x == -1) return 0;
	if(a[x] >= 1) return a[x];
	long long sum = 0;
	sum += f(x - 1);
	sum += f(x - 2);
	a[x] = sum;
	return sum;
}

int main(){

    for(int _ = 1; _ <= 10; _++){
        endTest(_);
        scanf("%d",&n);
        printf("%lld",f(n));
    }



	return 0;
}
