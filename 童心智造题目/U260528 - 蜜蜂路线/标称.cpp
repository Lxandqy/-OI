#include <cstdio>
#include <testlib.h>
using namespace std;
int n,m,len=1;
int f[1005][1005];
void pluss(int x)
{
	for(int i=1;i<=len;i++)
	  f[x][i]=f[x-1][i]+f[x-2][i];
	for(int i=1;i<=len;i++)
	  if(f[x][i]>9)
	  {
	  	f[x][i+1]+=f[x][i]/10;
	  	f[x][i]%=10;
	  }
	if(f[x][len+1]) len++;
}
int main ()
{
    for(int _ = 1; _ <= 10; _++){
        endTest(_);
        memset(f,0,sizeof f);
        len = 1;
        scanf("%d%d",&m,&n);
        f[1][1]=1,f[2][1]=2;
        for(int i=3;i<=n-m;i++) pluss(i);
        for(int i=len;i;i--) printf("%d",f[n-m][i]);
    }
	return 0;
}
