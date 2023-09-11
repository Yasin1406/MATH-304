#include<stdio.h>
#include<stdlib.h>
int main(){
    int i,j,k,row1,col1,row2,col2;
    printf("Enter the dimension of the first matrix: ");
    scanf("%d %d",&row1,&col1);
    printf("Enter the dimension of the second matrix: ");
    scanf("%d %d",&row2,&col2);
    if(col1!=row2){
        printf("Cannot be multiplied!\n");
        return 0;
    }
    double mat1[row1][col1],mat2[row2][col2],mat3[row1][col2];
    printf("Enter the first matrix:\n");
    for(i=0;i<row1;i++){
        for(j=0;j<col1;j++){
            scanf("%lf",&mat1[i][j]);
        }
    }
    printf("Enter the second matrix:\n");
    for(i=0;i<row2;i++){
        for(j=0;j<col2;j++){
            scanf("%lf",&mat2[i][j]);
        }
    }
    for(i=0;i<row1;i++){
        for(j=0;j<col2;j++){
            mat3[i][j]=0;
        }
    }
    for(i=0;i<row1;i++){
        for(j=0;j<col2;j++){
            for(k=0;k<col1;k++){
                mat3[i][j]+=mat1[i][k]*mat2[k][j];
            }
        }
    }
    printf("Result:\n");
    for(i=0;i<row1;i++){
        for(j=0;j<col2;j++){
            printf("%.2lf\t",mat3[i][j]);
        }
        printf("\n");
    }
    return 0;
}
