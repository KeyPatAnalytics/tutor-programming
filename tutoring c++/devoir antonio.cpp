#include<iostream>
using namespace std;

//Example of function
int antonio_function(int x){
	return x*x + 2*x -1;
}

//template of function deep
template <typename T>

T deep ( T (*f)(T), int n, T x){
	T result = f(x);
	for(int i=1;i<n;i++){
		result = f(result);
	}
	
	return result;
}


int main(){
	
	// test of the template
	cout<<deep(antonio_function, 3, 0)<<endl;
	
	return 0;
}
