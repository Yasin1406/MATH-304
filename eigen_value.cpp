#include<iostream>
#include<cstdlib>
#include<time.h>
#include<math.h>
#include<climits>
using namespace std;
#define MAX1 100
#define EPS 10e-6

double A[MAX1][MAX1],B[MAX1][MAX1],C[MAX1][MAX1],V[MAX1][MAX1];
double Q[MAX1][MAX1],Qinverse[MAX1][MAX1];
int row,column;

void Inputmatrix(){
	srand(time(0));
	int i,j,k;
	
	again:
	cout <<"Enter matrix dimension(Row X Column):";
	cin >> row >> column;
	if(row!=column){
		cout << "Wrong input!It has to be square matrix!\nTry again!!"<<endl;
		goto again;
	}
	
	cout << "Enter your matrix-\n";
	for(int i=0;i<row;i++)
	   for(int j=0;j<=i;j++){
	      A[i][j]=(rand()%10)+1;
	      A[j][i]=A[i][j];
	    }   
	cout << "Matrix-A="<< endl;
	for(int i=0;i<row;i++){
	   for(int j=0;j<row;j++)
	     cout << A[i][j]<<" ";
	   cout << endl;
	}	      
}
string getMAX(){
	string s;
	double max=INT_MIN;
	
	for(int i=0;i<row;i++)
	   for(int j=0;j<row;j++)
	      if(i!=j && fabs(A[i][j])>max){
	      	max=fabs(A[i][j]);
	      	s=to_string(i)+to_string(j);
	      }      	
    
	return s;      
}
bool allZero(){
	for(int i=0;i<row;i++)
	    for(int j=0;j<row;j++)
	        if(i!=j){
	            if(fabs(A[i][j])>EPS)
	               return false;	
		    else
		       A[i][j]=0;
		}       
	return true;

}

void reintialize(double arr[MAX1][MAX1]){
	for(int i=0;i<row;i++)
	    for(int j=0;j<row;j++)
	    	arr[i][j]=INT_MIN;
}
void fix(double arr[MAX1][MAX1]){
	for(int i=0;i<row;i++)
	    for(int j=0;j<row;j++){
	    	if(arr[i][j]==INT_MIN){
	    		if(i==j)
	    		   arr[i][j]=1;
	    		else
	    		   arr[i][j]=0;    	
	    	}
	    		
	    }	
	    	
}
void makeInverse(double arr[MAX1][MAX1]){
	for(int i=0;i<row;i++)
	    for(int j=0;j<row;j++)
	    	Qinverse[i][j]=arr[j][i];
}
void print(double arr[MAX1][MAX1]){
	for(int i=0;i<row;i++){
	    for(int j=0;j<row;j++)
	    	cout <<arr[i][j]<<" ";
	    cout<<endl;
	}    	
}
void store(double arr[MAX1][MAX1]){
	for(int i=0;i<row;i++)
	    for(int j=0;j<row;j++)
	    	C[i][j]=arr[i][j];    	
}
void multiply(int p){
	double sum;
	for(int i=0;i<row;i++)  
	   for(int j=0;j<row;j++){
	     sum=0;	   
	     for(int k=0;k<row;k++)
	     	   sum+=(Qinverse[i][k]*A[k][j]);	
	     B[i][j]=sum;
	   }
	for(int i=0;i<row;i++)  
	  for(int j=0;j<row;j++){
	     sum=0;	   
	     for(int k=0;k<row;k++)
	     	   sum+=(B[i][k]*Q[k][j]);	
	     A[i][j]=sum;
	   } 
	if(p==1)
	   store(Q);  
	if(p>1){
	   for(int i=0;i<row;i++)  
	     for(int j=0;j<row;j++){
		     sum=0;	   
	   	     for(int k=0;k<row;k++)
	     	        sum+=(C[i][k]*Q[k][j]);	
	     	V[i][j]=sum;
	     }
	   store(V);  
	}     
	     
}
void printOutput(){
	cout<<"Eigenvalue and corresponding eigenvectors for the matrix A:"<<endl;
	for(int i=0;i<row;i++){
		cout<<"λ"<<i+1<<"="<<A[i][i]<<endl;
		cout<<"v"<<i+1<<"=(";
		for(int j=0;j<row;j++){
			cout <<V[j][i];
			if(j<row-1)
			  cout <<",";	
		}	
		cout <<")"<<endl;
	}

}
void jacobi(){
	int p=1,i,j;
	double x,theta;
	while(!allZero()){
		string max=getMAX();
		i=max[0]-'0';
		j=max[1]-'0';
		x=(2*A[i][j])/(A[i][i]-A[j][j]);
	   	theta=0.5*atan(x);
	   	
	   	reintialize(Q);				//making the rotational matrix
		Q[i][i]=cos(theta);
		Q[j][j]=cos(theta);
		Q[i][j]=-sin(theta);
		Q[j][i]=sin(theta);
		fix(Q);
		makeInverse(Q);
		multiply(p);
		p++;	
	}

}
void eigenValue(){
	Inputmatrix();
	jacobi();
	printOutput();
}