#include <iostream>
using namespace std;

// VECTOR CLASS
class Vector{
	double vx,vy,vz;
	public:
		Vector(double x_value=0, double y_value=0, double z_value=0){
			vx=x_value;
			vy=y_value;
			vz=z_value;
		}
		void print();
		friend class Point;		
		~Vector(){
		}
};

void Vector::print(){
	cout<<"vx = "<<vx<<", vy = "<<vy<<", vz = "<<vz<<endl;
}

// POINT CLASS
class Point{
	double px,py,pz;
	public:
		Point(double x_value=0, double y_value=0, double z_value=0){
			px=x_value;
			py=y_value;
			pz=z_value;
		}
		Point operator + (Vector&);
		Point operator - (Vector&);
		void print();	
		~Point(){
		}
};
Point Point::operator + (Vector& Vect){
	return Point(px + Vect.vx,py + Vect.vy,pz + Vect.vz);
}
Point Point::operator - (Vector& Vect){
	return Point(px - Vect.vx,py - Vect.vy,pz - Vect.vz);
}

void Point::print(){
	cout<<"px = "<<px<<", py = "<<py<<", pz = "<<pz<<endl;
}


int main(){
	Point A(2,1,3);
	cout<<"This is a point: ";
	A.print();
	
	Vector Vec(2,-1,0);
	cout<<"This is a Vector: ";
	Vec.print();
	
	Point newPoint = A + Vec;
	
	cout<<"This is new point: ";
	newPoint.print();
	
	return 0;
}
