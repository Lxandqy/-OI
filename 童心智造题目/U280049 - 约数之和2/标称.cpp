#include <iostream>
#include <algorithm>
#include <cstdio>
#include<testlib.h>
#include <cstring>
using namespace std;
#define Mod 9901
int a,b;
int ksm(int a,int b)//快速幂函数
{
    int ans=1;
    a%=Mod;
    while(b)
    {
        if (b&1)
            ans=ans%Mod*a;
        a=a%Mod*a%Mod;
        b>>=1;
    }
    return ans;
}
long long sum(int p,int c)
{
    if (c==0)
        return 1;
    if(c&1)
        return ((1+ksm(p,(c+1)>>1))*sum(p,(c-1)>>1))%Mod;//奇数的情况下
    else
        return ((1+ksm(p,c>>1))*sum(p,(c>>1)-1)+ksm(p,c))%Mod;//偶数的情况下
}
int main()
{
    for(int _ = 1; _ <= 11; _++){
        endTest(_);
        cin>>a>>b;
        int ans=1;
        for (int i=2;i<=a;i++)
        {
            int s=0;
            while(a%i==0)
            {
                s++;
                a/=i;
            }
            if (s)//这句话剪枝.然后就TLE变成了AC.by POJ
                ans=ans*sum(i,s*b)%Mod;
        }
        if (a==0)
            cout<<0<<endl;//特判的情况，这里非常的阴毒，出题人用心险恶
        else
            cout<<ans<<endl;
    }

    return 0;
}
