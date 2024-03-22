#include <iostream>
using namespace std;

class length{
	private:
		int feet;
		int inches;
	public:
		length operator + (length ob);
		void readData();
		void showData();
//	friend length add(length ob1, length ob2); // friend function
};
void length::readData()
	{
		cout << "\n Enter the length";
		cout << "\n Feet :";
		cin >> feet;
		cout << " Inches :";
		cin >> inches;
	  }
	  
void length::showData()
	{
		cout << "\n Feet :" << feet;
		cout << "\n Inches :" << inches;
	}
/*
length add(length ob1, length ob2)// friend function
	{
		length tmpOb; // create a temporary object
		tmpOb.feet = ob1.feet + ob2.feet;
		tmpOb.inches = ob1.inches + ob2.inches;
		if(tmpOb.inches>12){
			tmpOb.inches -= 12;
			tmpOb.feet++;
		}
		return tmpOb;
	}
*/
length length::operator +(length ob)
	{
		length tmpOb; // create a temporary object
		tmpOb.feet = feet + ob.feet;
		tmpOb.inches = inches + ob.inches;
		if(tmpOb.inches>=12){
			tmpOb.inches -= 12;
			tmpOb.feet++;
		}
		return tmpOb;
	}
int main()
	{
		length ob1, ob2, ob3;
		cout << "\n The first object:";
		ob1.readData();
		cout << "\n The second object:";
		ob2.readData();
		
		ob3 = ob1 + ob2;
		cout << "\n The third object:";
		ob3.showData();
		
		return 0;
	}
	
	
	
	
	
	
	
	
	
	
