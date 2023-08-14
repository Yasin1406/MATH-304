#include<stdio.h>
#include<math.h>
#include<stdlib.h>

#define f(x) ((x*x*x)+(4*x*x)-10.0)
#define g(x) sqrt((10.0-x*x*x)/4)
#define EPS 10.0e-6
int iter;
void fixedPoint(double a);

int main(){
    double a;
    iter=1;
    printf("Enter starting point: ");
    scanf("%lf",&a);
    printf("-----------------------------------------------------------------\n");
    printf("iter\tx0\t\tx1\t\tf(x0)\t\tf(x1)\n");
    printf("-----------------------------------------------------------------\n");
    fixedPoint(a);
}

void fixedPoint(double a){
    double b=g(a);
    printf("%d\t%lf\t%lf\t%lf\t%lf\n",iter,a,b,f(a),f(b));
    iter++;
    if(fabs(f(b))<=EPS){
        printf("Root: %lf\n",b);
        return;
    }
    fixedPoint(b);
}
