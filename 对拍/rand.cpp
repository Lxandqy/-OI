#include<bits/stdc++.h>
using namespace std;
#define randoms(a,b) ((a)+rand()%((b)-(a)+1))

stringstream ss;
int flag[1100];

int main( int argc, char *argv[] ){
freopen("data.in","w",stdout);
	int seed=time(NULL);
	if(argc){
		ss.clear();
		ss<<argv[1];
		ss>>seed;
	}
	srand(seed);
	//����Ϊ�������ʼ���������޸�
	//random(a,b)����[a,b]���������

	//����д���Լ����������ɴ���

	int n = 10;
	for(int i = 1; i <= 5; i++){
        int x = randoms(1,2);
        if(x == 1) cout << "c";
        else cout << "a";
	}

	return 0;
}
