#include <stdio.h>
#include <stdlib.h>

int main(){
    int *p, *q;

    p = (int *)malloc(5 * sizeof(int));
    p[0] = 3;
    p[1] = 7;
    p[2] = 9;
    p[3] = 10;
    p[4] = 6;

    printf("p: ");
    for (int i=0; i<5; i++){
        printf("%d ", p[i]);
    }

    q = (int *)malloc(10 * sizeof(int));
    
    for (int i=0; i<5; i++){
        q[i] = p[i];
    }

    free(p);
    p = q;
    q = NULL;

    printf("\np increased size: ");
    for (int i=0; i<10; i++){
        printf("%d ", p[i]);
    }

    return 0;
}