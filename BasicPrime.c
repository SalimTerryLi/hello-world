//素数是只有1和本身是因子的数
//2018/11/14 更新
#include <stdbool.h>

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
    //to do sth
}

