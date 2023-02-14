#include<stdio.h>
#include<testlib.h>

const int N  = 1e6 + 10;

int n;

int flag[N],prime[N],cnt;
void is_prime(){
	for(int i = 2; i <= n; i++){
		if(!flag[i]){
			prime[++cnt] = i;
		}
		for(int j = 1; j <= cnt && i * prime[j] <= n; j++){
			flag[i * prime[j]] = 1;
			if(i % prime[j] == 0) break;
		}
	}
}
int main(int argc,char *argv[]){
    registerGen(argc, argv, 1);
	for(int _ = 1; _ <= 10; _++){
        endTest(_);
        scanf("%d",&n);
        cnt = 0;
        is_prime();
        for(int i = 1; i <= cnt; i++){
            printf("%d\n",prime[i]);
        }
	}




	return 0;
}
