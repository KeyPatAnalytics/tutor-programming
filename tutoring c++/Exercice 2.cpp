#include <iostream>

using namespace std;

int const Lim = 50;

class Stack{
	int length;
	int massif[Lim];
	
	public:
		Stack(){
			length = 0;
		};
		
		void reset();
		bool push(int);
		int pop();
		void print();
		
		~Stack(){
		};	
};

void Stack::reset(){
	for(int i=0;i<length; i++)
		massif[i]=0;
	length =0;
}

bool Stack::push(int newNumber){
	if(length<Lim){
		massif[length] = newNumber;
		length++;
		return true;
	}else{
		return false;
	}
}

int Stack::pop(){
	if(length<1){
		return false;
	}else{
		length--;
		return massif[length];
	}
}

void Stack::print(){
	if(length<1){
		cout<<"No data to print!";
	}else{
		cout<<"there is "<<length<<" numbers: ";
		for(int i=0; i<length; i++){
			cout<<massif[i]<<" ";
		}
		cout<<endl;
	}
}

int main(){
	Stack massif_A;
	
	int N;
	cout<<"How many numbers? ";
	cin>>N;
	
	cout<<"Enter your "<<N<<" numbers!"<<endl;
	
	int numb;
	for(int i=0;i<N; i++){
		cin>>numb;
		massif_A.push(numb);
	}
	
	cout<<"\n Great! Well done, you entered all your numbers:)\n\n";
	
	cout<<"\n In your stack ";
	massif_A.print();
	
	massif_A.pop();
	massif_A.pop();
	
	cout<<"\n Now in your stack ";
	massif_A.print();
	
	massif_A.reset();
	
	cout<<"\n Your stack was reset and now ";
	massif_A.print();
	return 0;
}


