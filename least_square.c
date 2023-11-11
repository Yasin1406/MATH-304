#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define EPS 1e-6
int row,column;

int main(){
    freopen("least_square.txt","r",stdin);
    // printf("Enter number of rows and columns: ");
    int i,j,k,p;
    scanf("%d %d",&row,&column);
    double mat[row][column],t_mat[column][row],const_col[row],pivot,ratio;
    double new_mat[column][column],new_const_col[column],temp;
    // printf("Enter the augmented matrix: ");
    for(i=0;i<row;i++){
        for(j=0;j<column;j++){
            scanf("%lf",&mat[i][j]);
            t_mat[j][i]=mat[i][j];
        }
        scanf("%lf",&const_col[i]);
        new_const_col[i]=0;
    }
    printf("The augmented matrix:\n");
    for(i=0;i<row;i++){
        for(j=0;j<column;j++){
            printf("%4.2lf\t",mat[i][j]);
        }
        printf("| %.2lf\n",const_col[i]);
    }
    for(i=0;i<column;i++){
        for(j=0;j<column;j++){
            new_mat[i][j]=0;
        }
    }
    for(i=0;i<column;i++){
        for(j=0;j<column;j++){
            for(k=0;k<row;k++){
                new_mat[i][j]+=t_mat[i][k]*mat[k][j];
            }
        }
    }
    for(i=0;i<column;i++){
        for(j=0;j<row;j++){
            new_const_col[i]+=t_mat[i][j]*const_col[j];
        }
    }
    printf("\nNew augmented matrix:\n");
    for(i=0;i<column;i++){
        for(j=0;j<column;j++){
            printf("%4.2lf\t",new_mat[i][j]);
        }
        printf("| %.2lf\n",new_const_col[i]);
    }
    for(i=0;i<column-1;i++){
        if(fabs(new_mat[i][i])<EPS){
            for(p=i+1;p<column;p++){
                if(!(fabs(new_mat[p][i])<EPS)){
                    break;
                }
            }
            if(p==column){
                printf("Solution doesn't exist!\n");
                exit(1);
            }
            for(j=0;j<column;j++){
                temp=new_mat[i][j];
                new_mat[i][j]=new_mat[p][j];
                new_mat[p][j]=temp;
            }
            temp=new_const_col[i];
            new_const_col[i]=new_const_col[p];
            new_const_col[p]=temp;
        }
        pivot=new_mat[i][i];
        for(j=i+1;j<column;j++){
            ratio=new_mat[j][i]/pivot;
            for(k=0;k<column;k++){
                new_mat[j][k]-=ratio*new_mat[i][k];
            }
            new_const_col[j]-=ratio*new_const_col[i];
        }
    }
    if(fabs(new_mat[column-1][column-1])<EPS){
        printf("Solution doesn't exist!\n");
        exit(1);
    }
    for(i=column-1;i>0;i--){
        pivot=new_mat[i][i];
        for(j=i-1;j>=0;j--){
            ratio=new_mat[j][i]/pivot;
            for(k=0;k<column;k++){
                new_mat[j][k]-=ratio*new_mat[i][k];
            }
            new_const_col[j]-=ratio*new_const_col[i];
        }
    }
    printf("\nAfter Gauss-Jordan:\n");
    for(i=0;i<column;i++){
        for(j=0;j<column;j++){
            printf("%4.2lf\t",new_mat[i][j]);
        }
        printf("| %.2lf\n",new_const_col[i]);
    }
    for(i=0;i<column;i++){
        new_const_col[i]/=new_mat[i][i];
        new_mat[i][i]/=new_mat[i][i];
    }
    printf("\nThe least squares solution of the system is (");
    printf("%.2lf",new_const_col[0]);
    for(i=1;i<column;i++){
        printf(", %.2lf",new_const_col[i]);
    }
    printf(")^T\n");
    return 0;
}