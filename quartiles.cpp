//Program: Storing numbers using vectors, sorting the vector, then printing out the numbers in their quartiles
//Date: 19/11/11

#include <iostream>
#include <ios>
#include <string>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::sort;
using std::string;
using std::vector;

void printQuartile(vector<double> prtVec, int bottom, int top){
	
	for(;bottom<top;bottom++){
		cout << prtVec[bottom];	
	}
	cout << endl;
}

int main(){
	//Getting students name
	string name; 
	cout << "Please enter your name: ";
	cin >> name;
	cout << "Hello " << name << endl;

	//Making the user input a series of numbers which will be stored in a vector
	vector<double> numberHold;
	cout << "Please enter all the numbers: ";
	
	double x; //Variable to read numbers into
	
	//Invariant:
	//numberHold holding all current numbers entered so far
	while(cin >> x){
		numberHold.push_back(x);		
	}

	//Sorting the numbers
	sort(numberHold.begin(), numberHold.end());
	
	cout << endl << endl; //Formatting the output to make it clearer	
	
	//Check that total is greater than 3 to stop exception
	if(numberHold.size()<4){
		cout << "Not enough numbers input" << endl;
		return 1;
	}

	printQuartile(numberHold, 0, numberHold.size()/4);
	printQuartile(numberHold, numberHold.size()/4, numberHold.size()/2);
	printQuartile(numberHold, numberHold.size()/2, (numberHold.size()*0.75));
	printQuartile(numberHold, (numberHold.size()*0.75), numberHold.size());

	return 0;
}

