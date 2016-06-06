#include <iostream>
#include <string>
#include <sstream>
#include <stdlib.h>
using namespace std;
int stringint(string a){
	stringstream stream;
	int b;
	stream << a;
	stream >> b;
	return b;
}
int findtest(int index){
	if(index == -1){
		cout << "(width*length)*count" << endl;
		exit(EXIT_FAILURE);
	}
}
int main(){
	//get input
	string input;
	cout << "input format: (width*length)*count" << endl;
	cout << "and remember the parenteces" << endl;
	cout << "end giving input with exit" << endl;
	
	while(input != "exit"){
		cout << "input:";
		
		getline(cin, input);
		cout << endl;
		
		//handle input: (width*length)*count
		int indexes[2] = {input.find_first_of('*'), input.find(')',0)}
		indexes[2] = input.find('*', indexes[0]);
		
		for(int i = 0; i<2; i++){
			findtest(indexes[i]);
		}
		findtest(index);
		findtest(index2);
		
		string numb;
		numb.assign(input, 1, index-1);
		int width = stringint(numb.assign(input, 1, index-1));
		
	}
	
}