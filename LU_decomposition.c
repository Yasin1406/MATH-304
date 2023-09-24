#include<stdio.h>
#include<stdlib.h>
#define EPS 10e-6
#define n 3

double aug_mat[n][n+1]={{4,-1,1,8},
                        {2,5,2,3},
                        {1,2,4,1}};
double L[n][n]={{1,0,0},
                {0,1,0},
                {0,0,1}};
double U[n][n]={{4,-1,1},
                {2,5,2},
                {1,2,4}};

void decompose();

int main(){
    int i,j,k;
    decompose();
    double mul_mat[n][n]={{0,0,0},
                          {0,0,0},
                          {0,0,0}};
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            for(k=0;k<n;k++){
                mul_mat[i][j]+=L[i][k]*U[k][j];
            }
        }
    }
    printf("\nL matrix:\n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%.2lf\t",L[i][j]);
        }
        printf("\n");
    }
    printf("\nU matrix:\n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%.2lf\t",U[i][j]);
        }
        printf("\n");
    }
    printf("\nAfter multiplying:\n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%.2lf\t",mul_mat[i][j]);
        }
        printf("\n");
    }
    return 0;
}

void decompose(){
    int i,j,k;
    for(i=0;i<n-1;i++){
        double pivot=U[i][i];
        for(j=i+1;j<n;j++){
            double m=U[j][i]/pivot;
            L[j][i]=m;
            for(k=0;k<n;k++){
                U[j][k]-=m*U[i][k];
            }
        }
    }
}
