//输入整数，将每位数字打印出来（从左向右打印，空格区分）
//2018/11/14 更新
#include <stdio.h>
#include <math.h>
int main() {
    int a;
    scanf("%d",&a);
    int expcount=0;
    for (int i=1;a/i;i*=10){
        expcount++;
    }
    int j=expcount;
    for (int j=0;j<expcount;j++){
        printf("%ld ",(a%(long)pow(10,expcount-j))/(long)pow(10,expcount-j-1));
    }
}
