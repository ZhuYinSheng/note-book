/*
#include <stdio.h>

double cuboid (double l, double w, double h)
{
    return l * w * h;
}

int main(void)
{
    double l, w, h;
    printf("长： "); scanf("%lf", &l);
    printf("宽： "); scanf("%lf", &w);
    printf("高： "); scanf("%lf", &h);
    printf("体积：%.2lf。\n", cuboid (l, w, h));
    return 0;
}
*/


/* 实现计算第n项斐波拉契数列的函数。
#include <stdio.h>

int fib(int n)
{
    int i;
    int x1 = 1;
    int x2 = 1;
    int x = 1;
    if(n == 1)
        return 1;
    else if(n == 2)
        return 1;
    else
        for( i =3; i <= n; i ++)
        {
            x = x1 + x2;
            x1 = x2;
            x2 = x;
        }
    return x;
}
 
int main(void)
{
    int n;
    printf("请输入菲波拉契数列所需项数："); scanf("%d", &n);
    printf("第%d项数列为：%d\n", n, fib(n));
    return 0;
}
*/


/* 实现计算三个数中最大值的函数。(没有写出来)
#include <stdio.h>
int max(int a, int b, int c)
{
    int m;
    m = a;
    if(m < b)
        m = b;
    if(m < c)
        m = c;
    return m;
}

int main(void)
{
    int a, b, c;
    printf("请输入三个数："); scanf("%d %d %d", &a, &b, &c);
    printf("最大值：%d\n", max(a, b, c));
    return 0;
}
*/
