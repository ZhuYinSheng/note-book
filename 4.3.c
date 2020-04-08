#include <stdio.h>
#include <stdlib.h>

int text(int *num, int arraysize)
{
    int i, j, count;
    for(i = 0; i <arraysize; i++)
    {
        count = 0;
        for(j = 0; j < arraysize; j++)
        {
            if(i != j)
            {
                if(num[i] == num[j])
                {
                    count++;
                }
                if(count == 1){
                    break;
                }
                if(count==0){
                    return 1;
                }
            }
        }
    }
    return 0;
}

int main()
{
    int a[5]={1, 1, 2, 3, 3};
    int b = test(a, sizeof(a)/sizeof(a[0]));
    printf("%d\n",b); 
}
