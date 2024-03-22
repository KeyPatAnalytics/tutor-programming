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
		//friend Point Point::movePointByVector(Vector &);
		//Point movePointByVector(Point &);
	
		
		~Vector(){
		}
};

void Vector::print(){
	cout<<"x = "<<vx<<", y = "<<vy<<", z = "<<vz<<endl;
}

/*Point Vector::movePointByVector(Point &Pt){
	return Point(Pt.px+vx,Pt.py+vy,Pt.pz+vz);
}
*/

// POINT CLASS
class Point{
	double px,py,pz;
	public:
		Point(double x_value=0, double y_value=0, double z_value=0){
			px=x_value;
			py=y_value;
			pz=z_value;
		}
		
		void print();
		
		Point movePointByVector(Vector &);
		friend class Vector;
		//friend Point Vector::movePointByVector(Point &);
		
		~Point(){
		}
};

void Point::print(){
	cout<<"x = "<<px<<", y = "<<py<<", z = "<<pz<<endl;
}

Point Point::movePointByVector(Vector &Vt){
	return Point(px+Vt.vx,py+Vt.vy,pz+Vt.vz);
}


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
