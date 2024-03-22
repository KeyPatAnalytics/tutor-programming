#include<iostream>
using namespace std;

#include "Point.h"

Point::Point(double x_value=0, double y_value=0, double z_value=0){
			px=x_value;
			py=y_value;
			pz=z_value;
		}
		
void Point::print(){
	cout<<"x = "<<px<<", y = "<<py<<", z = "<<pz<<endl;
}

Point Point::movePointByVector(Vector &Vt){
	return Point(px+Vt.vx,py+Vt.vy,pz+Vt.vz);
}


Point::~Point(){
}
