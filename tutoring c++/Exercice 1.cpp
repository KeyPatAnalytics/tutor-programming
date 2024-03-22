#include <iostream>

using namespace std;

class Numbers{
	double value1, value2, value3;
	
	public:
		
		Numbers(double val1=0,double val2=0, double val3=0){
			value1 = val1;
			value2 = val2;
			value3 = val3;
		};
		void set_values(double,double,double);
		void print();
		void isEqual(Numbers &);
		~Numbers(){
		};
};


void Numbers::set_values(double val1,double val2, double val3){
	value1 = val1;
	value2 = val2;
	value3 = val3;
}

void Numbers::print(){
	cout<<value1<<" "<<value2<<" "<<value3<<endl;
}

void Numbers::isEqual(Numbers &Number2){
	if(value1 == Number2.value1 && value2 == Number2.value2 && value3 == Number2.value3){
		cout<<"Numbers 1 and Numbers 2 are equal\n";
	}
	else{
		cout<<"Numbers 1 and Numbers 2 are not equal\n";
	}
}



int main(){
	cout<<"Hello Lopez!"<<endl;
	
	Numbers firstNumbers(4,2,-3);
	
	cout<<"First numbers: ";
	firstNumbers.print();
	
	Numbers secondNumbers;
	cout<<"Default second numbers: ";
	secondNumbers.print();
	
	secondNumbers.set_values(8,4,6);
	cout<<"Second numbers: ";
	secondNumbers.print();
	
	firstNumbers.isEqual(secondNumbers);
	
	
	return 0;
}
