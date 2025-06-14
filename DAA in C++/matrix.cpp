#include <iostream>
using namespace std;

#define n 2 // Define the size of square matrix

void multiplyMatrix(int A[n][n], int B[n][n], int C[n][n])
{

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            C[i][j] = 0;
            for (int k = 0; k < n; k++)
            {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void printMatrix(int C[n][n]){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<C[i][j]<<" ";
        }
        cout<<endl;
    }

}

int main()
{
    int A[n][n]={ {1,2},
                  {3,4}
                };
    
    int B[n][n]={ {5,6},
                  {4,5}
                };

    int C[n][n];

    multiplyMatrix(A,B,C);

    printMatrix(C);

    return 0;
}