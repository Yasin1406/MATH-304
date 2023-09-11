#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define EPS 10e-6
int main(){
    int n,i,j,p,k;
    printf("Enter the number of equations: ");
    scanf("%d",&n);
    double matA[n][n],matB[n];
    double m;
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
            double temp[n],temp_B;
            for(j=0;j<n;j++){
                temp[j]=matA[i][j];
                temp_B=matB[i];
            }
            for(j=0;j<n;j++){
                matA[i][j]=matA[p][j];
                matB[i]=matB[p];
            }
            for(j=0;j<n;j++){
                matA[p][j]=temp[j];
                matB[p]=temp_B;
            }
        }
        for(j=i+1;j<n;j++){
            m=matA[j][i]/matA[i][i];
            for(k=0;k<n;k++){
                matA[j][k]-=m*matA[i][k];
                if(fabs(matA[j][k])<EPS){
                    matA[j][k]=0;
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
    for(i=n-1;i>0;i--){
        for(j=i-1;j>=0;j--){
            m=matA[j][i]/matA[i][i];
            for(k=0;k<n;k++){
                matA[j][k]-=m*matA[i][k];
                if(fabs(matA[j][k])<EPS){
                    matA[j][k]=0;
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
    return 0;
}