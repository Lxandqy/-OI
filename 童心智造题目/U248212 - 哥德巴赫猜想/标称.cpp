#include<cstdio>
#include<algorithm>
#include<cmath>

const int N = 1000010;
bool st[N];
int prime[N / 10], cnt, n;

//线性筛100万内的所有素数
void get_prime(){
    for(int i = 2; i < N; i++){
        if(!st[i]) prime[cnt++] = i;
        for(int j = 0; prime[j] <= N / i; j++){
            st[prime[j] * i] = true;
            if(i % prime[j] == 0) break;
        }
    }
}

int main(){
    get_prime();
    while(scanf("%d", &n), n){

        bool flag = false;

        for(int i = 0; i < cnt; i++){

            if(!st[n - prime[i]]){
                int k = prime[i],kk = n - prime[i];
    if(k < kk) std::swap(k,kk);
                printf("%d = %d + %d\n", n, k, kk);
                flag = true;
                break;
            }
        }

        if(!flag) puts("Goldbach's conjecture is wrong.");
    }
    return 0;
}
