#include<iostream>
#include<algorithm>
#include<testlib.h>
#include<queue>
#define first x
#define second y

using namespace std;

const int N = 10000;

typedef pair<int,int> PII;

int b[N];

int main(){

    for(int _ = 1; _<= 10; _++){
            endTest(_);
        int a,b;char c;
        cin >> a >> b >> c;
        if(c == '+'){
            cout <<a + b <<endl;
        }else if(c == '-'){
             cout <<a - b << endl;
        }else if(c == '*'){
            cout << a *b << endl;
        }else if(c == '/'){
            if(b == 0){
                cout << "Divided by zero!" << endl;
            }else cout << a / b <<endl;
        }else{
            cout << "Invalid operator!" << endl;
        }

    }




    return 0;
}
