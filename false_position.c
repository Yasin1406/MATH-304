#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<stdbool.h>
#define f(x) (x*x*x+4*x*x-10)
#define epsilon 10e-6
int iter;
bool root_exists(double a,double b);

void false_position(double a,double b);

int main(){
	double a,b;
	iter=1;
	printf("Enter boundary values: ");
	scanf("%lf %lf",&a,&b);
	if(!root_exists(a,b)){
		printf("Root doesn't exists in the interval (%.3lf,%.3lf)\n",a,b);
		exit(0);
	}
	printf("------------------------------------------------------------------------------------------------------\n");
   	printf("iter\ta\t\tb\t\tc\t\tf(a)\t\tf(b)\t\tf(c)\n");
   	printf("------------------------------------------------------------------------------------------------------\n");
	false_position(a,b);
	return 0;
	
}

bool root_exists(double a,double b){
	return f(a)*f(b)<=0;
}

void false_position(double a,double b){ 

	double c=(a*f(b)-b*f(a))/(f(b)-f(a)); 
	printf("%d\t%lf\t%lf\t%lf\t%lf\t%lf\t%lf\n",iter,a,b,c,f(a),f(b),f(c));
	iter++;
	if(fabs(f(c)) < epsilon){
		printf("\nRoot: %lf\n",c);
		return;
	}
	if(root_exists(a,c)){
		b=c;
		false_position(a,b);
	}
	else{
		a=c;
		false_position(a,b);
	}
	
}
