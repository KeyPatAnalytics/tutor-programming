#include<iostream>
using namespace std;

#include "Vector.h"


Vector::Vector(double x_value=0, double y_value=0, double z_value=0){
			vx=x_value;
			vy=y_value;
			vz=z_value;
		}
Vector::print(){
	cout<<"x = "<<vx<<", y = "<<vy<<", z = "<<vz<<endl;
}

Vector::~Vector(){
}
