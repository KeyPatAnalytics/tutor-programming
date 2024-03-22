#include <iostream> // DEV C++
#include <fstream>
#include <string>

using namespace std;
int maxWordsNumber = 100;

void leave_space(){
	cout<<"                          ";
}

int search_word_index(string from_lan, string word)
{
	int index=-1;
	bool found=false;
	ifstream from_file((from_lan + ".txt").c_str());
	if (from_file.is_open())
	{
		string line;
		index = 0;
		while (!found && (index < maxWordsNumber) && getline (from_file,line))
		{
		 //leave_space();
		 //cout<<"index: "<<index<<" Line: "<<line<<" Word: "<<word<<endl;
		  if(line == word){
		  	found = true;
		  	//leave_space();
			//cout<<"Found: Yes"<<endl;	  	
		  }
		  else{
		  	index++;
		  }
		}
		if(found)
			return index;
		else
			return -1;
		from_file.close();
	}
	else{
		leave_space();
		cout << "Unable to open "<<from_lan<<" dictionnary"<<endl;
	}
	return index;
}

	
		
string find_translation(string to_lan,int word_index){
	string line;
	if(word_index<0){
		return "Word not found";
	}
	else{
		ifstream to_file((to_lan + ".txt").c_str());
		if (to_file.is_open())
		{
			int index=0;
			getline (to_file,line);
			while ( index != word_index && getline (to_file,line))
			{
			  index++;
			}
		}
	}
	return line;
}



void translation_process(string from_lan){
	string to_lan, word, translated_word;
	int word_index;
	bool continue_trans = false;
	
	if (from_lan == "en"){
		to_lan = "rus";
	}
	else{
		to_lan = "en";
	}
	leave_space();
	cout<<"Enter the word: "<<endl;
	leave_space();
	cin>>word;
	while(word != "0" && word != "1"){ // WE WILL USE 0 AND 1 AS KEYS TO ACTIVATE OTHER PROCESSES
		word_index = search_word_index(from_lan,word);
		translated_word = find_translation(to_lan,word_index);
		leave_space();
		cout<<translated_word<<endl;
		leave_space();
		cin>>word;
	}
	if(continue_trans){
		translation_process(from_lan);
	}
	leave_space();
	cout<<"process finished !"<<endl;
}
// This function greets the user and take from the initial language 
string Welcome(){
	leave_space();
	cout<<"\n\n" ;
	leave_space();
	cout<<"                   WELCOME IN YADA - TRANSLATOR                    "<<endl;
	leave_space();
	cout<<"================================================================="<<endl<<endl;
	leave_space();
	cout<<"This is an anlgo-russian tranlator: "<<endl;
	leave_space();
	cout<<"Start by choosing your language (en or rus) "<<endl;
	
	string from_lan, to_lan;
	leave_space();
	cin>>from_lan;
	while(from_lan != "en" && from_lan != "rus" ){
		leave_space();
		cout<<"Invalid language, enter again the right language (en or rus)"<<endl;
		leave_space();
		cin>>from_lan;
	}
	
	if (from_lan == "en"){
		to_lan = "rus";
	}
	else{
		to_lan = "en";
	}
	leave_space();
	cout<<"\n\n";
	leave_space();
	cout<<"Translation  "<<from_lan<<" ===> "<<to_lan<<endl;
	
	return from_lan;
}


int main()
{
	string from_lan;
	from_lan = Welcome();
	translation_process(from_lan);
	return 0;
}



