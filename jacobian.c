#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<stdbool.h>
#define n 3
#define EPS 10e-6

int iter=0;
double col_new[n],col_old[n]={0,0,0};
double aug_mat[n][n+1]={{4,-1,1,8},
                        {2,5,2,3},
                        {1,2,4,1}};

bool check_dominant();
void jacobian();
double get_sum(int i);

int main(){
    if(!check_dominant){
        printf("Cannot get solution!\n");
        return 0;
    }
    jacobian();
    printf("Iteration: %d\n",iter);
    for(int i=0;i<n;i++){
        printf("%.3lf\n",col_new[i]);
    }
    return 0;
}
bool check_dominant(){
    for(int i=0;i<n;i++){
        double sum=0;
        for(int j=0;j<n;j++){
            if(i!=j){
                sum+=fabs(aug_mat[i][j]);
            }
        }
        if(fabs(aug_mat[i][i])<sum){
            return false;
        }
    }
    return true;
}

void jacobian(){
    iter++;
    bool flag=false;
    for(int i=0;i<n;i++){
        col_new[i]=(aug_mat[i][n]-get_sum(i))/aug_mat[i][i];
    }
    for(int i=0;i<n;i++){
        if(fabs(col_new[i]-col_old[i])>EPS){
            flag=true;
            break;
        }
    }
    if(flag){
        for(int i=0;i<n;i++){
            col_old[i]=col_new[i];
        }
        jacobian();
    }
    else{
        return;
    }
}

double get_sum(int i){
    double sum=0;
    for(int j=0;j<n;j++){
        if(i!=j){
            sum+=aug_mat[i][j]*col_old[j];
        }
    }
    return sum;
}