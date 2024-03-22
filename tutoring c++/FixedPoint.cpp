#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

class FixedPoint
	{
		private:
			int _int;
			int _dec;
		public:
			FixedPoint(int integer = 0, int decimal = 0)
			{
				_int = integer;
				_dec = decimal;
			}
			
			float To_float();
			friend FixedPoint float_To_FixedPoint(float);
			friend ostream& operator << (ostream&, FixedPoint&);
			friend istream& operator >> (istream&, FixedPoint&);
			FixedPoint operator + (FixedPoint );
			FixedPoint operator - (FixedPoint );
	};

float FixedPoint::To_float(){
	float float_num;
	if(_int<0)
		float_num = _int*1.0 - _dec/100.0;
	else
		float_num = _int*1.0 + _dec/100.0;
		
	return float_num;
}

FixedPoint float_To_FixedPoint(float float_num)
	{
		float_num = floor(float_num*100 + 0.5) / 100;
		
		int float_int = floor(float_num);
		int float_dec = floor((float_num-float_int)*100);
		
		return FixedPoint(float_int,float_dec);
	}

ostream& operator << (ostream& stream, FixedPoint& fpt)
	{
		double float_num = fpt.To_float();
					
		printf("%.2f",float_num);
		return stream;
	}
	
istream& operator >> (istream& stream, FixedPoint& fpt)
	{
		float float_num;
		stream >> float_num;
		
		fpt = float_To_FixedPoint(float_num);
		
		return stream;
	}
	
FixedPoint FixedPoint::operator + (FixedPoint fpt)
	{
		return float_To_FixedPoint(this->To_float() + fpt.To_float());
	}
	
FixedPoint FixedPoint::operator - (FixedPoint fpt)
	{
		return float_To_FixedPoint(this->To_float() - fpt.To_float());
	}

int main()
	{
		FixedPoint a(3, 80);
		cout << a << '\n';   //  3.80
		FixedPoint b(-3, 90);
		cout << b << '\n';   // -3.90
		
		FixedPoint sum = a+b;
		FixedPoint dif = a-b;
		
		cout << sum << '\n'; // -0.10
		cout << dif << '\n'; //  7.70
		
		FixedPoint c;
		cin >> c;          // 11.999999
		cout << c << '\n';   // 12.00

	}
