#include<iostream>
#include<string>
#include "Reader.hpp"
// #include "Method_area.hpp"
// #include "Frame_stack.hpp"

using namespace std;

int main(int argc, char* argv[]){
	Reader* reader = new Reader();
	if (argv[1][0] == 'e' || argv[1][0] == 'E') {
		reader->run(argv[2]);
	}
	else if (argv[2][0] == 'i' || argv[2][0] == 'I') {
		cout << "Running Interpreter" << endl;
		// reader->run(argv[2]);
		// Method_area::path = "Sample.class";
		// Method_area::add_class(reader);
		// Frame_stack frame_stack(reader);
		// frame_stack.execute();
	}
	else 
		printf("Did not run anyting\n");
  
  return 0;
}
