#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define EPS 10e-6
int main(){
    int n,i,j,p,k;
    printf("Enter the number of equations: ");
    scanf("%d",&n);
    double matA[n][n],matB[n],inverse[n][n];
    double m;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(i==j){
                inverse[i][j]=1;
            }
            else{
                inverse[i][j]=0;
            }
        }
    }
    printf("Enter the augmented matrix:\n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%lf",&matA[i][j]);
        }
        scanf("%lf",&matB[i]);
    }
    for(i=0;i<n-1;i++){
        for(p=i;p<n;p++){
            if(!(fabs(matA[p][i])<EPS)){
                break;
            }
        }
        if(p==n){
            printf("Solution doessn't exist!\n");
            return 0;
        }
        if(fabs(matA[i][i])<EPS){
            double temp[n],temp_B,temp_I[n];
            for(j=0;j<n;j++){
                temp[j]=matA[i][j];
                temp_B=matB[i];
                temp_I[j]=inverse[i][j];
            }
            for(j=0;j<n;j++){
                matA[i][j]=matA[p][j];
                matB[i]=matB[p];
                inverse[i][j]=inverse[p][j];
            }
            for(j=0;j<n;j++){
                matA[p][j]=temp[j];
                matB[p]=temp_B;
                inverse[p][j]=temp_I[j];
            }
        }
        for(j=i+1;j<n;j++){
            m=matA[j][i]/matA[i][i];
            for(k=0;k<n;k++){
                matA[j][k]-=m*matA[i][k];
                if(fabs(matA[j][k])<EPS){
                    matA[j][k]=0;
                }
                inverse[j][k]-=m*inverse[i][k];
                if(fabs(inverse[j][k])<EPS){
                    inverse[j][k]=0;
                }
            }
            matB[j]-=m*matB[i];
            if(fabs(matB[j])<EPS){
                matB[j]=0;
            }
        }
    }
    if(fabs(matA[n-1][n-1])<EPS){
        printf("Solution doessn't exist!\n");
        return 0;
    }
    printf("After Gauss elimination:\n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%.2lf\t",matA[i][j]);
        }
        printf("%.2lf\n",matB[i]);
    }
    for(i=n-1;i>0;i--){
        for(j=i-1;j>=0;j--){
            m=matA[j][i]/matA[i][i];
            for(k=0;k<n;k++){
                matA[j][k]-=m*matA[i][k];
                if(fabs(matA[j][k])<EPS){
                    matA[j][k]=0;
                }
                inverse[j][k]-=m*inverse[i][k];
                if(fabs(inverse[j][k])<EPS){
                    inverse[j][k]=0;
                }
            }
            matB[j]-=m*matB[i];
            if(fabs(matB[j])<EPS){
                matB[j]=0;
            }
        }
    }
    for(i=0;i<n;i++){
        m=matA[i][i];
        for(j=0;j<n;j++){
            matA[j][i]/=m;
        }
        matB[i]/=m;
    }
    for(i=0;i<n;i++){
        printf("%c= %.2lf\n",123-n+i,matB[i]);
    }
    printf("Inverse:\n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%.3lf\t",inverse[i][j]);
        }
        printf("\n");
    }
    return 0;
}