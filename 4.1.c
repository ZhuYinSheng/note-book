#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main()
{
    srand((unsigned int)time(NULL));
    int a[100];
    int num[11] ={0};
    for (int i = 0; i < 100; i ++) {
        a[i] = rand() % 101;
        num [a[i]/10]++;
    }
    
    printf("\n ------分布图------\n");
    for (int j = 0; j < 11; j ++){
        printf("%3d  ", j * 10);
        for (int i = 0; i < num [j]; i ++){
            printf("*");
        }
        printf("\n");
    }
    
    
    /*
    for(int i = a[max]; i > 0; i--){
        for(int j = 0; j < 11; j ++){
            if(a[j] >= i){
                printf("*");
            } else {
                printf(" ");
            }
        }
    }
    */
    
    /*
    for (int i = 0; i < 100;) {
        printf("%4d", a[i]);
        i ++;
        if(i%10 == 0){
            printf("\n");
        }
    }
    */
    
}
