//被4整除的年份是闰年，但是00结尾的年份被400整除才是闰年。
//2018/11/14 更新
#include <stdbool.h>

bool isRunYear(int year){
    if (!(year%100)){
        return !(year%400);
    }
    else{
        return !(year%4);
    }
}

int main() {
    //to do sth
}
