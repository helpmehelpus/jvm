#include<iostream>
#include<string>
#include "Reader.hpp"

using namespace std;

int main(int argc, char* argv[]){
	Reader reader;
	if (argv[1][0] == 'e' || argv[1][0] == 'E') {
		reader.run(argv[2]);
	}
	else if (argv[2][0] == 'i' || argv[2][0] == 'I') {
		cout << "Running Interpreter" << endl;
	}
	else 
		printf("Didnt run annyting\n");
  
  return 0;
}
