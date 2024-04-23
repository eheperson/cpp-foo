#include <iostream>

using namespace std;

int main(){
    int A[3][3] = {
        {0,1,2},
        {4,5,6},
        {7,8,9}
    };
    for(int i=0; i<3 ;i++){
        for(int j=0; j<3; j++){
            cout << "A[" << i << "]" << "[" << j << "] = " << A[i][j] << endl;
        };
    };
    
    cout << endl;

    int *B[3];
    B[0] = new int[3];
    B[1] = new int[3];
    B[2] = new int[3];
    for(int i=0; i<3 ;i++){
        for(int j=0; j<3; j++){
            B[i][j] = 99;
            cout << "B[" << i << "]" << "[" << j << "] = " << B[i][j] << endl;
        };
    };
    delete B[0];
    delete B[1];
    delete B[2];
    
    int *C[2];
    C[0] = new int[2];
    C[1] = new int[3];
    cout << "Size of C: " << sizeof(C) / sizeof(int) << endl;
    cout << "Size of C[0]: " << 2 * sizeof(int) << endl;
    cout << "Size of C[1]: " << 1 / sizeof(int) << endl;
    cout << "C[0] : " << C[0] << endl;
    cout << "C[1] : " << C[1] << endl;
    cout << "C[0][0] : " << C[0][0] << endl;
    cout << "C[0][1] : " << C[0][1] << endl;
    cout << "C[1][0] : " << C[1][0] << endl;
    cout << "C[1][1] : " << C[1][1] << endl;
    cout << "C[1][2] : " << C[1][2] << endl;
    delete[] C[0];
    delete[] C[1];

    int **D;
    D = new int*[3];
    D[0] = new int[4];
    D[1] = new int[4];
    D[2] = new int[4];
    for(int i=0; i<3 ;i++){
        for(int j=0; j<4; j++){
            D[i][j] = 13;
            cout << "D[" << i << "]" << "[" << j << "] = " << D[i][j] << endl;
        };
    };
    delete[] D[0];
    delete[] D[1];
    delete[] D[2];

    return 0;
}