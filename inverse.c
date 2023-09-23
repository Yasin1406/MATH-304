#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define EPS 10e-6
#define n 3
int main(){
    int i,j,k,p;
    double aug_mat[n][n+1]={{4,-1,1,8},
                            {2,5,2,3},
                            {1,2,4,1}};
    double in_mat[n][n],mul_mat[n][n],mat_copy[n][n];
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(i==j){
                in_mat[i][j]=1;
            }
            else{
                in_mat[i][j]=0;
            }
            mul_mat[i][j]=0;
            mat_copy[i][j]=aug_mat[i][j];
        }
    }
    for(i=0;i<n;i++){
        for(p=i;p<n;p++){
            if(!(fabs(aug_mat[p][i])<EPS)){
                break;
            }
        }
        if(p==n){
            printf("Solution doesn't exist!\n");
            return 0;
        }
        if(p!=i){
            double temp;
            for(j=0;j<=n;j++){
                temp=aug_mat[i][j];
                aug_mat[i][j]=aug_mat[p][j];
                aug_mat[p][j]=temp;
                if(j<n){
                    temp=in_mat[i][j];
                    in_mat[i][j]=in_mat[p][j];
                    in_mat[p][j]=temp;
                }
            }
        }
        double pivot=aug_mat[i][i];
        for(j=i+1;j<n;j++){
            double m=aug_mat[j][i]/pivot;
            for(k=0;k<n+1;k++){
                aug_mat[j][k]-=m*aug_mat[i][k];
                if(fabs(aug_mat[j][k])<EPS){
                    aug_mat[j][k]=0;
                }
                if(k<n){
                    in_mat[j][k]-=m*in_mat[i][k];
                    if(fabs(in_mat[j][k])<EPS){
                        in_mat[j][k]=0;
                    }
                }
            }
        }
    }
    if(aug_mat[n-1][n-1]==0){
        printf("Solution doesn't exist!\n");
        return 0;
    }
    double det=1;
    for(i=0;i<n;i++){
        det*=aug_mat[i][i];
    }
    printf("\nDeterminant: %.3lf\n",det);
    for(i=n-1;i>0;i--){
        double pivot=aug_mat[i][i];
        for(j=i-1;j>=0;j--){
            double m=aug_mat[j][i]/pivot;
            for(k=0;k<=n;k++){
                aug_mat[j][k]-=m*aug_mat[i][k];
                if(fabs(aug_mat[j][k])<EPS){
                    aug_mat[j][k]= 0;
                }
                if(k<n){
                    in_mat[j][k]-=m*in_mat[i][k];
                    if(fabs(in_mat[j][k])<EPS){
                        in_mat[j][k]= 0;
                    }
                }
            }
        }
    }
    for(i=0;i<n;i++){
        double pivot=aug_mat[i][i];
        for(j=0;j<=n;j++){
            aug_mat[i][j]/=pivot;
            if(j<n){
                in_mat[i][j]/=pivot;
            }
        }
    }
    printf("\nInverse:\n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%.3lf\t",in_mat[i][j]);
        }
        printf("\n");
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            for(k=0;k<n;k++){
                mul_mat[i][j]+=mat_copy[i][k]*in_mat[k][j];
            }
        }
    }
    printf("\nAfter multiplying:\n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%.3lf\t",mul_mat[i][j]);
        }
        printf("\n");
    }
    printf("\nAugmented matrix:\n");
    for(i=0;i<n;i++){
        for(j=0;j<=n;j++){
            printf("%.3lf\t",aug_mat[i][j]);
        }
        printf("\n");
    }
    return 0;
}