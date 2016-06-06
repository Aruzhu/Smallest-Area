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
	cout << "end by giving input with exit" << endl;
	
	vector< vector<int> > data(5, vector<int>(2)); //multidimensional vector
	while(input != "exit"){
		cout << "input:";
		
		getline(cin, input);
		cout << endl;
		
		//handle input: (width*length)*count
		int indexes[2] = {input.find_first_of('*'), input.find(')',0)}
		indexes[2] = input.find('*', indexes[0]);
		
		string numb;
		for(int i = 0; i<2; i++){
			findtest(indexes[i]);
			switch(i){
				case 0 : 
					int width = stringint( numb.assign(input, 1, index-1) );
					break;
				case 1 :
					int length = stringint( numb.assign(input, indexes[0], indexes[1] ) );
					break;
				case 2 :
					int count = stringint( numb.assign(input, indexes[2], input.size());
					break;
				data.push_back(vector<int> data )
			}
		}
	}
	
	// computing
	
	
}