#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<stdbool.h>
#define n 3
#define EPS 1e-6

double mat[n][n]={{9,22,18},{8,10,9},{19,9,6}},t_mat[n][n],S1[n][n],D[n][n],t_S1[n][n],temp[n][n];
double eigen_value[n];
double S[n][n];
bool is_diagonal();

void get_eigen_value();
void transpose_S();
void multiplication1();
void multiplication2();
void multiplication3();
void multiplication4();

int main(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j){
                S[i][j]=1;
            }
            else{
                S[i][j]=0;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            t_mat[i][j]=mat[j][i];
        }
    }
    multiplication4();
    get_eigen_value();

}

void get_eigen_value(){
    int inI,inJ,i,j;
    double max,theta;
    for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                if(i==j){
                    S1[i][j]=1;
                }
                else{
                    S1[i][j]=0;
                }
            }
        }
    while(1){
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                if(i==j){
                    S1[i][j]=1;
                }
                else{
                    S1[i][j]=0;
                }
            }
        }
        max=-1;
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                if(i!=j){
                    if(fabs(D[i][j])>max){
                        max=fabs(D[i][j]);
                        inI=i;
                        inJ=j;
                    }
                }
            }
        }
        // theta=0.5*atan((2*A[inI][inJ])/fabs(A[inI][inI]-A[inJ][inJ]));
        if(D[inI][inI]==D[inJ][inJ]){
            theta=0.5*asin(1);
            if(D[inI][inI]<0){
                theta=-theta;
            }
        }
        else{
            theta=0.5*atan((2*D[inI][inJ])/fabs(D[inI][inI]-D[inJ][inJ]));
        }
        S1[inI][inJ]=-sin(theta);
        S1[inJ][inI]=sin(theta);
        S1[inI][inI]=cos(theta);
        S1[inJ][inJ]=cos(theta);
        transpose_S();
        multiplication1();
        multiplication2();
        multiplication3();
        if(is_diagonal()){
            for(j=0;j<n;j++){
                for(i=0;i<n;i++){
                    S[i][j]/=S[n-1][j];
                    // D[i][j]/=D[n-1][j];
                }
            }
            break;
        }
    }
    printf("D:\n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%.2f ",D[i][j]);
        }
        printf("\n");
    }
    printf("Eigenvalues: ");
    for(i=0;i<n;i++){
        printf("%.2f ",D[i][i]);
    }
    printf("\n");
}

void transpose_S(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            t_S1[i][j]=S1[j][i];
        }
    }
}

void multiplication1(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            temp[i][j]=0;
            for(int k=0;k<n;k++){
                temp[i][j]+=t_S1[i][k]*D[k][j];
            }
        }
    }
}

void multiplication2(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            D[i][j]=0;
            for(int k=0;k<n;k++){
                D[i][j]+=temp[i][k]*S1[k][j];
            }
        }
    }
}

void multiplication3(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            temp[i][j]=0;
            for(int k=0;k<n;k++){
                temp[i][j]+=S[i][k]*S1[k][j];
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            S[i][j]=temp[i][j];
        }
    }
}

bool is_diagonal(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i!=j){
                if(fabs(D[i][j])>EPS){
                    return false;
                }
            }
        }
    }
    return true;
}

void multiplication4(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                D[i][j]+=t_mat[i][k]*mat[k][j];
            }
        }
    }
}