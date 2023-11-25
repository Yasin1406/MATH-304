#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<stdbool.h>
#define m(x) (sqrt(x)-x*x)
//#define f(x) (x*x*x+4*x*x-10)
#define epsilon 10e-6
bool root_exists(double a,double b);

double bisection(double a,double b);

int main(){
	double a=bisection(1,2.5);
    int n=10,i,j;
    double h=a/n;
    double x[n+1],sumX=0;
    x[0]=0.0;
    for(i=1;i<=n;i++){
        x[i]=x[i-1]+h;
    }
    double y[n+1],sumY=0.0;
    for(i=0;i<=n;i++){
        y[i]=m(x[i]);
        sumY+=y[i];
    }
    sumY-=(y[0]+y[n]);
    sumX=y[0]+y[n];
    double I=h*(sumX+2*sumY)/2;
    printf("Trapizoidal Rule --------------\n");
    printf("Area = %lf\n",I);
    printf("-------------------------------\n");
	return 0;
	
}

bool root_exists(double a,double b){
	return m(a)*m(b)<=0;
}

double bisection(double a,double b){ 

	double c=(a+b)/2;
	if(fabs(m(c)) < epsilon){
		return c;
	}
	if(root_exists(a,c)){
        bisection(a,c);
    }
    else{
        bisection(c,b);
    }
	
}
