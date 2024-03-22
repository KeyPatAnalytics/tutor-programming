
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	string line;
	
	//==========Writing in a file=============================//
	ofstream to_file ("example.txt");
	if (to_file.is_open())
	{
		to_file << "This is a line.\n";
		to_file << "This is another line.\n";
		to_file.close();
	}
	else cout << "Unable to open file";
	
	//============Reading from a file ======================//
	ifstream from_file ("example.txt");
	if (from_file.is_open())
	{
		while ( getline (from_file,line) )
		{
		  cout << line << '\n';
		}
		from_file.close();
	}
	else cout << "Unable to open file";
	
	//============================================//
	
	return 0;
}
