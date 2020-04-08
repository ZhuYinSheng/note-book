/* 温度转换
# include <stdio.h>

int main(void)
{
    int f,c;
    printf("  f      c\n");
    
    for(f = 40 ; f <= 240 ; f = f + 20)
    {
        c = 5 * ( f - 32 ) / 9;
        printf("%3d%7d\n",f,c);
    }
    
    printf("%3d%7d\n",300,148);
    return 0;
}
*/


/* 尽量少的使用乘法运算完成阶乘表的打印
#include <stdio.h>

int main(void)
{
    int n;
    int factorial=1;
    printf("请输入n的值：");scanf("%d",&n);
    printf("\n");
    printf("   0!=      1\n");
    
    if(n == 0)
      return 0;
    
    for(int i=1;i <= n;i ++){
        factorial = i * factorial;
        printf("%4d!=%7d\n",i,factorial);
    }
    return 0;
}
*/


/* 输入月份输出天数
#include <stdio.h>
int main(void)
{
    int month;
    printf("请输入月份：");scanf("%d",&month);
    
    switch (month) {
        case 2: printf("%d的天数是28天。\n",month); break;
        case 4:
        case 6:
        case 9:
        case 11: printf("%d的天数是30天。\n",month);break;
        default : printf("%d的天数是31天。\n",month);break;
    }
    return 0;
}
*/


/* 输入10个字符，统计其中的英文字母、数字字符和其他字符的个数。
#include <stdio.h>

int main(void)
{
    int letter = 0;
    int digit = 0;
    int other = 0;
    int i;
    char ch;
    
    printf("请输入10个字符：");
    
    for(i = 1; i <= 10; i ++){
        ch = getchar();
        if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
            letter ++;
        else if (ch >= '0' && ch <= '9')
            digit ++;
        else
            other ++;
    }
    printf("letter=%d, digit=%d, other=%d\n", letter, digit, other);
    return 0;
}
*/


/* 判断输入的数是否为素数。
#include <stdio.h>

int main()
{
    int a,i;
    printf("请输入一个大于1的整数："); scanf("%d",&a);
    
    if(a == 2 || a == 3)
        printf("输入的整数是素数。\n");
    else {
        for(i = 2; i * i <= a; i ++) {
            if(a % i == 0) {
                printf("输入的整数不是素数。\n");
                return 0;
            }
        }
    }
    printf("输入的整数是素数。\n");
    return 0;
}
*/
