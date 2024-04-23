#include <stdio.h>
#include <stdlib.h>

/**
 * Row wise formula: index = i*n+j
 * Column wise formula: index = j*n+i
 * To make index start from '1', Row wise: (i-1)*n+j-1
 * To make index start from '1', Columns wise: (j-1)*n+i-1
*/
struct Matrix{
    int *A;
    int n;
};

struct Matrix Create(int n){
    struct Matrix m;
    m.n = n;
    m.A = (int *)malloc(m.n*m.n*sizeof(int));
    return m;
}

void Set(struct Matrix *m, int i, int j, int x){
    m->A[(i - 1) * m->n + j-1] = x; //  row major start index from 1
}

int Get(struct Matrix m, int i, int j){
    return m.A[(i - 1) * m.n + j];
}

void Display(struct Matrix m){
    int i, j;
    for (i = 0; i < m.n; i++){
        for (j = 0; j < m.n; j++){
                printf("%5d ", m.A[m.n*i + j]); 
        }
        printf("\n");
    }
}

void SetDiagonal(struct Matrix *m, int i, int j, int x){
    if (i == j)
        m->A[i - 1] = x;
}

int GetDiagonal(struct Matrix m, int i, int j){
    if (i == j)
        return m.A[i - 1];
    else
        return 0;
}

void DisplayDiagonal(struct Matrix m) {
    int i, j;
    for (i = 0; i < m.n; i++) {
        for (j = 0; j < m.n; j++) {
            if (i == j)
                printf("%5d ", m.A[i * m.n + j]);
            else
                printf("%5d ", 0);
        }
        printf("\n");
    }
}


void DisplayLowerTriangle(struct Matrix m) {
    int i, j;
    for (i=0; i < m.n; i++) {
        for (j=0; j < m.n; j++) {
            if (i >= j)
                printf("%5d ",m.A[i * m.n + j]);
            else
                printf("%5d ", 0);
        }
        printf("\n");
    }
}


int main(){
    struct Matrix m;
    m = Create(4);
    // printf("%d \n", m.n);
    // m.n = 4;
    for(int i = 0; i<m.n; i++){
        for(int j = 0; j<m.n; j++){
            Set(&m, i+1, j+1, 4*i + j + 1);
        }
    }
    Display(m);
    printf("\n");
    DisplayDiagonal(m);
    printf("\n");
    DisplayLowerTriangle(m);

    return 0;
}
