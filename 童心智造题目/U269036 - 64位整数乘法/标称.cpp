#include <iostream>
#include <cstdio>
#include<testlib.h>
#define ll long long
using namespace std;
int main()
{
    for(int _ = 1; _ <= 11; _++){
        endTest(_);
        ll a,b,p,res;
        scanf("%lld %lld %lld",&a,&b,&p);
        res=0;
        while(b)
        {
            if(b&1)
                res=(res+a)%p;
            b>>=1;
            a=2*a%p;
        }
        cout<<res<<endl;
    }

    return 0;
}
