#include<stdio.h>

int main(){

    int n;
    scanf("%d",&n);
    for(int i = 1; i <= n; i++){
        int a;
        scanf("%d",&a);

        if(a >= 700){
                printf("�ҿ����˺�����!!");
            }else if(a >= 698){
                printf("�ҿ�����ѧ����ѧ!!");
            }else if(a >= 695){
                printf("�ҿ�������ɽ��ѧ!!");
            }else{
                printf("�Һò�!�Ҹ���Ҫ��������!");
        }
        if(i != n) printf("\n");
    }





    return 0;
}
