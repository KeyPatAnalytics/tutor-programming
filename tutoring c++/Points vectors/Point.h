#ifndef POINT_H
#define POINT_H
class Point{
	double px,py,pz;
	public:
		Point(double x_value=0, double y_value=0, double z_value=0);
		void print();
		
		Point movePointByVector(Vector &);
		friend class Vector;
		//friend Point Vector::movePointByVector(Point &);
		
		~Point(){
		}
};
#endif
