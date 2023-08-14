#include<stdio.h>
#define f(x) (x*x+1)

int main(){
    int n=10,i,j;
    double a=0.0,b=2.0;
    double h=(b-a)/n;
    double x[n+1],sumX=0;
    x[0]=0.0;
    for(i=1;i<=n;i++){
        x[i]=x[i-1]+h;
    }
    double y[n+1],sumO=0.0,sumE=0.0;
    for(i=0;i<=n;i++){
        y[i]=f(x[i]);
    }
    for(i=2;i<=n-2;i+=2){
        sumE+=y[i];
    }
    for(i=1;i<=n-1;i+=2){
        sumO+=y[i];
    }
    sumX=y[0]+y[n];
    double I=h*(sumX+4*sumO+2*sumE)/3;
    printf("Simpson's 1/3 Rule --------------\n");
    printf("Integral value = %lf\n",I);
    printf("---------------------------------\n");
    return 0;
}