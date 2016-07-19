#include <iostream>
#include <string>
#include <sstream>
#include <stdlib.h>
#include <vector>
#include <math.h>
#include <algorithm>

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
		exit(0);
	}
}
int diff(int a, int b){
	return sqrt( pow(a-b,2));
}
int main(){
	//get input
	string input;
	cout << "input format: (width*length)*count" << endl;
	cout << "and remember the parenteces" << endl;
	cout << "end by giving input with exit" << endl;
	
	vector<int> width(1);
	vector<int> length(1);
	vector<int> count(1);
	int suma = 0;
	while(input != "exit"){
		cout << "input:";
		
		getline(cin, input);
		cout << endl;
		if(input == "exit"){break;}
		
		//handle input: (width*length)*count
		int indexes[2] = {input.find_first_of('*'), input.find(')',0)};
		for(int i = 0; i<2; i++){
			findtest(indexes[i]);
		}
		
		int tow = stringint( input.substr(1, indexes[0]-1) );
		int tol = stringint( input.substr(indexes[0]+1, indexes[1]-1));
		int toc = stringint( input.substr(indexes[1]+2, input.size()) );
		suma += tow*tol*toc;
		
		length.push_back(tol);
		width.push_back(tow);
		count.push_back(toc);
	
	}
	//more workable
	int countsum = 0;
	for(int i = 1; i<count.size(); i++){
		countsum += count.at(i);
		cout << count.at(i) << endl;
	}
	int data[countsum][2];
	int i = 0;
	for(int b = 0; b<count.size(); b++){
		cout << "here" << endl;
		for(int c = 0; c<count.at(b); c++){
			cout << width.at(b) << "	" << length.at(b) << endl;
			
			data[i][0] = width.at(b);
			data[i][1] = length.at(b);
			i += 1;
		}
	}

	random_shuffle(&data[0], &data[countsum]); // variation, in the computing
	
	// calculations
	int reca = pow( (int) sqrt(suma) , 2);
	cout << "total area: " << suma << endl;
	
	int combN = 1; // without doubles, with=without*16
	int combW = 1; // with
	int comb;
	int tol, tow; // y
	for(int i = 0; i<countsum; i += 2){
		tow = data[i][0];
		tol = data[i][1];
		
		if((tow != tol)&& (data[i-1][0] != data[i-1][1]) ){
			comb = 2*(tow + tol + data[i-1][0] + data[i-1][1]) + 4;
			combN *= comb;
			combW *= comb*16;
		}
		if((tow == tol) && (data[i-1][0] == data[i-1][1])){
			combN *= tow+tol+3;
			combW *= 16*(tol*tow-1)+4;
		}
		if((tow != tol) && (data[i-1][0] == data[i-1][1]) ){
			comb = 8*(data[i-1][0]+1)+4*(tow+tol);
			combN *= comb;
			combW *= comb*16;
		}
		if((tow == tol) && (data[i-1][0] == data[i-1][1])){
			 combN *= data[i-1][0]+data[i-1][1]+2*tow-2;
		}
	}
	cout << "combinations: " << combW << "	" << combN << endl;
	
	// calculate that shit
	int longest = 0;
	for(int i = 0; i<countsum; i += 1){
		longest += (data[i][0]>data[i][1]) ? data[i][0] : data[i][1];
	}
	cout << "longest: " << longest << endl;
	int map[longest*2][longest*2];
	
	return 0;
}