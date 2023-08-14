#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<stdbool.h>
#define f(x) (x*x*x+4*x*x-10)
#define epsilon 10e-6
int iter;
bool root_exists(double a,double b);

void secant(double a,double b);

int main(){
	double x0,x1;
	iter=1;
	printf("Enter boundary values: ");
	scanf("%lf %lf",&x0,&x1);
	
	printf("------------------------------------------------------------------------------------------------------\n");
   	printf("iter\tx0\t\tx1\t\tx2\t\tf(x0)\t\tf(x1)\t\tf(x2)\n");
   	printf("------------------------------------------------------------------------------------------------------\n");
	secant(x0,x1);
	return 0;
	
}

bool root_exists(double a,double b){
	return f(a)*f(b)<=0;
}

void secant(double a,double b){ 

	double c=(a*f(b)-b*f(a))/(f(b)-f(a)); 
	printf("%d\t%lf\t%lf\t%lf\t%lf\t%lf\t%lf\n",iter,a,b,c,f(a),f(b),f(c));
	iter++;
	if(fabs(f(c)) < epsilon){
		printf("\nRoot: %lf\n",c);
		return;
	}
	secant(b,c);
	
}
