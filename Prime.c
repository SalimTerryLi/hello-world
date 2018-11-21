/*满足下列条件的自然数称为超级素数:该数本身,所有数字之和,所有数字之积以及所有数字的平方和都是素数.例如113就是一个超级素数.求[100,9999]之内:(1)超级素数的个数.(2)所有超级素数之和.(3)最大的超级素数.*/
//2018/11/14 更新
#include <stdio.h>
#include <stdbool.h>

void makeSingleNum(int num,int *data){
    data[0]=num/1000;
    data[1]=(num-=data[0]*1000)/100;
    data[2]=(num-=data[1]*100)/10;
    data[3]=(num-=data[2]*10);
    return;
}

int sum_bit(int num) {
    int number[]={0,0,0,0};
    makeSingleNum(num,number);
    return number[0]+number[1]+number[2]+number[3];
}

int multi_bit(int num) {
    int number[]={0,0,0,0};
    makeSingleNum(num,number);
    return number[0]*number[1]*number[2]*number[3];
}

int square_sum_bit(int num) {
    int number[]={0,0,0,0};
    makeSingleNum(num,number);
    return number[0]*number[0]+number[1]*number[1]+number[2]*number[2]+number[3]*number[3];
}

bool isprime(int num) {
    int i=1;
    int lastj=num-1;
    while(++i<lastj){
        int j=1;
        while(true){
            j++;
            if (i*j>num){
                lastj=j;
                break;
            }
            if (i*j==num)
                return false;
        }
    }
    return true;
}

int main() {
    int count=0;
    int sum=0;
    int max=0;
    for (int i=100;i<=9999;i++){
        if(isprime(i)&&isprime(sum_bit(i))&&isprime(multi_bit(i))&&isprime(square_sum_bit(i))){
            count++;
            sum+=i;
            max=i;
        }
    }
    printf("%d %d %d",count,sum,max);
    //to do sth
}
