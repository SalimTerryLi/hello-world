//回文数：正读与反读相等的数
//2018/11/14 更新
#include <stdbool.h>
#include <stdio.h>
#include <math.h>

bool isRollNum(int num){
    int a=num;
    int expcount=0;
    for (int i=1;a/i;i*=10){
        expcount++;
    }
    int j=expcount;
    while (j--){
        if((a%(long)pow(10,j+1))/(long)pow(10,j)!=(a%(long)pow(10,expcount-j))/(long)pow(10,expcount-j-1)){
            return false;
        }
    }
    return true;
}

int main() {
    //to do sth
    printf("%d",isRollNum(124321)?1:0);
    return 0;
}
