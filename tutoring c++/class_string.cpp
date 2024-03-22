#include <iostream>
using namespace std;

class String{
	private:
		string str;
	public:
		String(string given_str=""){str = given_str;} //Constructor
		
		string operator () (int index, int length); // overloading operator ()
};

string String::operator() (int index, int length){
		return str.substr(index,length);
}


int main(){
	String name("Antonio is my name");
	cout << name(0,7); 
	return 0;
}
