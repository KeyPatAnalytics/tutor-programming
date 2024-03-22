#ifndef VECTOR_H
#define VECTOR_H
class Vector{
	double vx,vy,vz;
	public:
		Vector(double x_value=0, double y_value=0, double z_value=0);
		void print();
		
		friend class Point;
		//friend Point Point::movePointByVector(Vector &);
		//Point movePointByVector(Point &);
	
		
		~Vector(){
		}
};
#endif
