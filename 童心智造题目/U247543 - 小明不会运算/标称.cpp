#include<iostream>
#include<cstring>
#include<cmath>
#include<testlib.h>
#include<bits/stdc++.h>
using namespace std;



const int N = 310;

typedef long long ll;


int main(int argc,char* argv[]){
    registerGen(argc, argv, 1);


	for(int i = 1; i <= 10; i++){
        endTest(i);
        int a,b;
	cin >> a >> b;
	double n,m;
	printf("%d\n",a + b);
	printf("%d\n",a - b);
	printf("%d\n",a / b);
	printf("%d\n",a % b);
	cin >> n >> m;
	printf("%.2lf\n",n + m);
	printf("%.2lf\n",n - m);
	printf("%.2lf\n",n / m);



	}









	return 0;
}
