#include<iostream>
using namespace std;

#include "Vector.h"
#include "Point.h"

Point movePointByVector(Point &Pt, Vector &Vt){
	return Pt.movePointByVector(Vt);
}

int main(){
	Point A(2,1,3);
	cout<<"This is a point: ";
	A.print();
	
	Vector Vec(2,-1,0);
	cout<<"This is a Vector: ";
	Vec.print();
	
	Point newPoint;
	newPoint = movePointByVector(A,Vec);
	
	cout<<"This is new point: ";
	newPoint.print();
	
	return 0;
}
