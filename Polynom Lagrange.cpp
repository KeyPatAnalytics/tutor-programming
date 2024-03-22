                             // LAGRANGE APPROXIMATION 
#include<iostream>
#include<fstream>
#include<math.h>

using namespace std;

// initial function 
double init_function(double x){ 
    return sqrt(x)*sin(x)+1;
}

// i-th BASIC FUNCTION 
double basic_function(int order, double arg_x, double Xi[], int degree){// Xi here stands for the interval on which we build the approximative lagrangian function
	
	double bf_value=1.0;
	
	for(int j=0; j<degree+1; j++){
		if(j != order){
			bf_value *= ((arg_x - Xi[j])/(Xi[order] - Xi[j])); // X = X + a    <==>    X += a
		}
	}
	
	return bf_value;
}


// LAGRANGE POLYNOM 
double Lagrange(double Xi[], int degree,double arg_x){ 
	
	double lagrange = 0;
	
	for(int i=0; i<degree+1; i++){
		lagrange += init_function(Xi[i]) * basic_function(i,arg_x,Xi,degree); // X = X + A <===> X += A
	}
	
	return lagrange;
} // lagrange = a + b*x + c*x^2 + d*x^3 + e*x^4 === L(x)


int main(){
	
	ofstream init_function_file;
	ofstream lagrange_file;
	ofstream bas_func;
	
	
	init_function_file.open("Initial function.txt");
	lagrange_file.open("Lagrange approximation.txt");
	bas_func.open("Basic functions.txt");
	
	
	double h = M_PI/7;// const pi = 3.14
    double X[5] = {0.5*h,1.5*h,2.5*h,4.5*h,6.5*h};
    
    // Now let's check how our polynome approximate the function on [0,2*pi]
    // We will take our points with a step of 0.1
    for(double step=0; step<=2*M_PI; step += 0.1){
    	init_function_file<< init_function(step)<<endl; /// f(step)
    	lagrange_file<<Lagrange(X,4,step)<<endl; /// L(step)
	}
	
	for(double step=0; step<=2*M_PI; step += 0.1){
		
		for(int i=0; i<5; i++){
			bas_func<<basic_function(i,step,X,4)<<",";
		}
		bas_func<<endl;
	}
	
	
	
	return 0;
}













