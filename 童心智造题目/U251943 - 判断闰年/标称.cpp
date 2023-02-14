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
        int year;
    cin>>year;
    if(year%4==0&&!(year%100==0&&year%400!=0))
       {
           cout<<"Y";
       }
       else
       {
           cout<<"N";
       }

    }




    return 0;
}
