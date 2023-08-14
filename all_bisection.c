#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<stdbool.h>
#define f(x) (x*x*x+4*x*x-5)
#define epsilon 10e-6
int iter;
bool root_exists(double a,double b);

void bisection(double a,double b);

int main(){
	double a=-5,b=5;
	int i;
	double interval=(b-a)/6;
	for(i=0;i<6;i++){
			bisection(a,a+interval);
			a+=interval;
			
	}
	return 0;
	
}

bool root_exists(double a,double b){
	return f(a)*f(b)<=0;
}

void bisection(double a,double b){ 
	if(!root_exists(a,b)){
		printf("Root doesn't exists in the interval (%.3lf,%.3lf)\n",a,b);
		return;
	}
	double c=(a+b)/2; 
	if(fabs(f(c)) < epsilon){
		printf("\nRoot= %lf\n",c);
		return;
	}
	if(root_exists(a,c)){
		bisection(a,c);
	}
	else{
		bisection(c,b);
	}
    	
	
}

