#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define EPS 10e-6
int main(){
    int i,j,k,n,p;
    printf("Enter dimension of the matrix: ");
    scanf("%d",&n);
    double aug[n][n+1],m,inverse[n][n];
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
        for(j=0;j<=n;j++){
            scanf("%lf",&aug[i][j]);
        }
    }
    for(i=0;i<n-1;i++){
        for(p=i;p<n;p++){
            if(!(fabs(aug[p][i])<EPS)){
                break;
            }
        }
        if(p==n){
            printf("Solution doesn't exist!\n");
            return 0;
        }
        // if(fabs(aug[i][i])<EPS){
        //     double temp[n],tempB,tempI[n];
        //     for(j=0;j<n;j++){
        //         temp[j]=aug[i][j];
        //         tempI[j]=inverse[i][j];
        //     }
        //     tempB=aug[i][j];
        //     for(j=0;j<n;j++){
        //         aug[i][j]=aug[p][j];
        //         inverse[i][j]=inverse[p][j];
        //     }
        //     aug[i][j]=aug[p][j];
        //     for(j=0;j<n;j++){
        //         aug[p][j]=temp[j];
        //         inverse[p][j]=tempI[j];
        //     }
        //     aug[p][j]=tempB;
        // }
        if(fabs(aug[i][i]<EPS)){
            double temp;
            for(k=0;k<n+1;k++){
                temp=aug[i][k];
                aug[i][k]=aug[p][k];
                aug[p][k]=temp;
                if(k!=n){
                    temp=aug[i][k];
                    aug[i][k]=aug[p][k];
                    aug[p][k]=temp;
                }
            }
        }
        for(int j=i+1; j<n; j++)
        {
            double m= aug[j][i]/ aug[i][i];
            for(int k=0; k<n+1; k++)
            {
                aug[j][k] = aug[j][k]- (m* aug[i][k]);
                if(k!=n)
                {
                    inverse[j][k]= inverse[j][k]- (m* inverse[i][k]);
                }
                if(fabs(aug[j][k]) < EPS)
                {
                    aug[j][k]= 0;
                }
            }
        }
    }
    if(fabs(aug[n-1][n-1])<EPS){
        printf("Solution doesn't exist!\n");
        return 0;
    }
    printf("After Gauss elimiation:\n");
    for(i=0;i<n;i++){
        for(j=0;j<n+1;j++){
            printf("%.2lf\t",aug[i][j]);
        }
        printf("\n");
    }
    double det=1;
    for(i=0;i<n;i++){
        det*=aug[i][i];
    }
    printf("Determinant: %.2lf\n",det);
   for(int i=n-1; i>=0; i--)
    {
        double pivot= aug[i][i];
        for(int j=i-1; j>=0; j--)
        {
            double ratio = aug[j][i]/ pivot;
            for(int k=0; k<n+1; k++)
            {
                aug[j][k] = aug[j][k]- (ratio* aug[i][k]);
                if(k!=n)
                {
                    inverse[j][k]= inverse[j][k]- (ratio* inverse[i][k]);
                }
                if(fabs(aug[j][k]) < EPS)
                {
                    aug[j][k]= 0;
                }
            }
        }
    }
    for(i=0;i<n;i++){
        m=aug[i][i];
        for(j=0;j<n;j++){
            aug[j][i]/=m;
            inverse[j][i]/=m;
        }
        aug[i][j]/=m;
    }
    printf("After Gauss-Jordan:\n");
    for(i=0;i<n;i++){
        for(j=0;j<=n;j++){
            printf("%.2lf\t",aug[i][j]);
        }
        printf("\n");
    }
    printf("Inverse of the matrix:\n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%.3lf\t",inverse[i][j]);
        }
        printf("\n");
    }
    return 0;
}