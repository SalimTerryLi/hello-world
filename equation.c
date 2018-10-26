//求解如下方程组
//ax + by = c
//dx + ey = f
//注意输入/输出，数据类型

#include <stdio.h>

int main(int argc,char **argv) {
    int a,b,c;
    int d,e,f;
    int ret;
    printf("ax + by = c\ndx + ey = f\n");
    fflush(stdin);
    if(scanf("%d %d %d %d %d %d",&a,&b,&c,&d,&e,&f)-6)
        return -1;
    long A=a*e-b*d;
    if (A){
        long D1=a*f-c*d;
        long D2=c*e-b*f;
        printf("%dx + %dy = %d\n%dx + %dy = %d\n",a,b,c,d,e,f);
        printf("x=%lf y=%lf\n",(double)D2/(double)A,(double)D1/(double)A);
        return 0;
    }
    printf("no real roots or too many roots.\n");
    return 0;
}
