//求解一元二次方程的根
//查阅sqrt()函数
//注意有没有解

#include <stdio.h>
#include <math.h>

int main() {
    int A,B,C;
    printf("Ax + By + C = 0\n");
    if(scanf("%d %d %d",&A,&B,&C)-3)
        return -1;
    long delta=pow(B,2) - 4*A*C;
    if (delta<0){
        printf("no real roots.\n");
    }
    else if (delta==0) {
        printf("x=%lf\n",(double)-B/(2*(double)A));
    }
    else {
        printf("x1=%lf x2=%lf\n",((double)-B+sqrt(delta))/(2*(double)A),((double)-B-sqrt(delta))/(2*(double)A));
    }
    return 0;
}
