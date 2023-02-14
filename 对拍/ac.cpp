#include<bits/stdc++.h>

using namespace std;

int main(){
    //freopen("data.in","r",stdin);
   //freopen("ac.out","w",stdout);
    char a[1000];
    scanf("%s",a + 1);

    int sum = 0;
    for(int i = 1; i <= strlen(a + 1); i++){
        for(int j = i; j <= strlen(a + 1); j++){
            int ans = 0,C = 0;
            for(int k = j; k >= i; k--){
                if(a[k] == 'c') C++;
                else if(a[k] == 'a') ans += C;
            }
            if(ans != 0 && ans % 2 == 0){
                sum ++;
                cout << i << " " << j << endl;
            }
        }
    }

    cout << sum << endl;





    return 0;
}
