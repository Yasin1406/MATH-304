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
    double y[n+1],sumY=0.0;
    for(i=0;i<=n;i++){
        y[i]=f(x[i]);
        sumY+=y[i];
    }
    sumY-=(y[0]+y[n]);
    sumX=y[0]+y[n];
    double I=h*(sumX+2*sumY)/2;
    printf("Trapizoidal Rule --------------\n");
    printf("Integral value = %lf\n",I);
    printf("-------------------------------\n");
    return 0;
}