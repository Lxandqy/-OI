# include <iostream>
#include<testlib.h>
#include<cstring>
using namespace std;

const int N = 100010;
int a[N], s[N];

int main()
{
    for(int _ = 1; _ <= 11; _++){
        endTest(_);
        int n, r = 0;
        memset(s,0,sizeof s);
        cin >> n;

        for (int i = 0, j = 0; i < n; ++ i)
        {
            cin >> a[i];
            ++ s[a[i]];
            while (s[a[i]] > 1) -- s[a[j++]]; // 先减次数后右移
            r = max(r, i - j + 1) ;
        }
        cout << r;
    }


    return 0;
}
