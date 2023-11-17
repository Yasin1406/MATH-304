#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<stdbool.h>
#define n 3
#define EPS 1e-6

double mat[n][n]={{9,22,18},{8,10,9},{19,9,6}},t_mat[n][n],S[n][n],D[n][n],t_S[n][n],temp[n][n];
double eigen_value[n];
double eigen_vector[n][n];
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
                eigen_vector[i][j]=1;
            }
            else{
                eigen_vector[i][j]=0;
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
    
    while(1){
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                if(i==j){
                    S[i][j]=1;
                }
                else{
                    S[i][j]=0;
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
        S[inI][inJ]=-sin(theta);
        S[inJ][inI]=sin(theta);
        S[inI][inI]=cos(theta);
        S[inJ][inJ]=cos(theta);
        transpose_S();
        multiplication1();
        multiplication2();
        multiplication3();
        if(is_diagonal()){
            for(j=0;j<n;j++){
                for(i=0;i<n;i++){
                    eigen_vector[i][j]/=eigen_vector[n-1][j];
                    // D[i][j]/=D[n-1][j];
                }
            }
            break;
        }
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
            t_S[i][j]=S[j][i];
        }
    }
}

void multiplication1(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            temp[i][j]=0;
            for(int k=0;k<n;k++){
                temp[i][j]+=t_S[i][k]*D[k][j];
            }
        }
    }
}

void multiplication2(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            D[i][j]=0;
            for(int k=0;k<n;k++){
                D[i][j]+=temp[i][k]*S[k][j];
            }
        }
    }
}

void multiplication3(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            temp[i][j]=0;
            for(int k=0;k<n;k++){
                temp[i][j]+=eigen_vector[i][k]*S[k][j];
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            eigen_vector[i][j]=temp[i][j];
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