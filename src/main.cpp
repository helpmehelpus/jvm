#include<iostream>
#include<string>

#include "Reader.hpp"
#include "Method_area.hpp"
#include "Frame_stack.hpp"

using namespace std;

int main(int argc, char* argv[]){
	Reader* reader = new Reader();
	if (argv[1][0] == 'e' || argv[1][0] == 'E') {
		reader->run(argv[2]);
	}
	else if (argv[1][0] == 'i' || argv[1][0] == 'I') {
		cout << "Running Interpreter" << endl;
		reader->run(argv[2]);
		//TOOD: implementar metodo para pegar nome da classe do arv2 separado
		Method_area::path = "lookupswitch.class";
		Method_area::add_class(reader);
		// Frame_stack* frame_stack = new Frame_stack(reader);
		//frame_stack->execute();
	}
	else 
		printf("Did not run anyting\n");
  
  return 0;
}
