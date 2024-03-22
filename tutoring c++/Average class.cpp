#include <iostream>
using namespace std;

class Average
	{
		private:
			int N; //number of operations
			int average; // average of numbers
		public:
			Average(int numb=0, double avrg=0.0){ // CONSTRUCTOR
				N = numb;
				average = avrg;
			}
			friend Average operator + (Average&, Average&); //overloading operator +
			friend Average operator + (Average, int); //overloading operator +
			Average operator += (int); //overloading operator +=
			friend ostream& operator << (ostream&, const Average&); // overloading operator <<
	};

ostream& operator << (ostream& stream, const Average& Avr)
	{
		stream << Avr.average << Avr.N;
	
		return stream;
	}
	
Average operator + (Average& Avr1, Average& Avr2)
	{
		int new_N = Avr1.N + Avr2.N;
		int new_average = (Avr1.average*Avr1.N + Avr2.average*Avr2.N)/new_N;
		
		return Average(new_N,new_average);
	}

Average operator + (Average Avr1, int numb)
	{
		int new_N = Avr1.N + 1;
		int new_average = (Avr1.average*Avr1.N + numb)/new_N;
		
		return Average(new_N,new_average);
	}
	
	
Average Average::operator += (int numb)
	{
		average = (average * N + numb) / (N+1);
		N++;
		
		return *this;
	}

int main(){
	Average avg1, avg2;

	avg1 += 5;
	cout << avg1 << '\n'; // 5
	
	avg1 += 9;
	cout << avg1 << '\n'; // 7
	
	avg1 += 19;
	cout << avg1 << '\n'; // 11
	
	avg1 += -9;
	cout << avg1 << '\n'; // 6
	
	//(avg1 += 7) += 11;
	avg1 += 7;
	avg1 += 11;
	cout << avg1 << '\n'; // 6
	
	avg2 = avg1;
	cout << avg2 << '\n'; // 6
	
	avg2 = avg2 + avg1 + 20;
	cout << avg2 << '\n'; // 7

	return 0;
}
