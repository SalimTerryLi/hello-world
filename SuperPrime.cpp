#include <stdio.h>

class Prime {
public:
    Prime(int num):mNum(num){}
    ~Prime()=default;

    bool isPrime();
protected:
    const int mNum;
};

class SuperPrime : public Prime {
public:
    SuperPrime(int num):Prime(num){}
    ~SuperPrime()=default;

    bool isPrime();

    Prime sumBit();
    Prime multiBit();
    Prime sqaureSumBit();
};

void makeSingleNum(int num,int *data);

bool Prime::isPrime(){
    int i=1;
    int lastj=mNum-1;
    while(++i<lastj){
        int j=1;
        while(true){
            j++;
            if (i*j>mNum){
                lastj=j;
                break;
            }
            if (i*j==mNum)
                return false;
        }
    }
    return true;
}

bool SuperPrime::isPrime(){
    return Prime::isPrime()&&sumBit().isPrime()&&multiBit().isPrime()&&sqaureSumBit().isPrime();
}

void makeSingleNum(int num,int *data){
    data[0]=num/1000;
    data[1]=(num-=data[0]*1000)/100;
    data[2]=(num-=data[1]*100)/10;
    data[3]=(num-=data[2]*10);
    return;
}

Prime SuperPrime::multiBit(){
    int number[]={0,0,0,0};
    makeSingleNum(mNum,number);
    return Prime(number[0]*number[1]*number[2]*number[3]);
}

Prime SuperPrime::sqaureSumBit(){
    int number[]={0,0,0,0};
    makeSingleNum(mNum,number);
    return Prime(number[0]*number[0]+number[1]*number[1]+number[2]*number[2]+number[3]*number[3]);
}

Prime SuperPrime::sumBit(){
    int number[]={0,0,0,0};
    makeSingleNum(mNum,number);
    return Prime(number[0]+number[1]+number[2]+number[3]);
}

int main()
{

    int count=0;
    int sum=0;
    int max=0;
    for (int i=100;i<=200;i++){
        if(SuperPrime(i).isPrime()){
            count++;
            sum+=i;
            max=i;
        }
    }
    printf("%d %d %d",count,sum,max);
}
