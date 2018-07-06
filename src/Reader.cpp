#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Reader.hpp"
#include "Displayer.hpp"
#include "Constant_pool.hpp"
#include "Field_info.hpp"
#include "Method_info.hpp"
// #include "flags.h"
// #include "interfaces.h"
// #include "methods.h"
// #include "attributes.h"
using namespace std;

int Reader::run(char* file_name){
  printf("Running reader...\n");
  read(file_name);
  return 0;
}

int Reader::read(char* file_name){
  this->file_name = file_name;
  
  fp = fopen(file_name, "rb");
  magic_number = read_U4(fp);
  if(!check_magic_number(magic_number)){
    exit(1);
  }

  min_version = read_U2(fp);
  max_version = read_U2(fp);
  Displayer::display_version(min_version, max_version);
  
  cp_length = read_U2(fp);	
  cp = new Constant_pool(cp_length,fp);
  Displayer::display_cp(cp,cp_length);

  access_flags = read_U2(fp);
  Displayer::display_access_flags(access_flags);
  
  this_class = read_U2(fp);
  super_class = read_U2(fp);
  Displayer::display_class_names(this_class,super_class, cp->cp_vector);
  printf("__________________________________________________________________________________________________________\n\n");
	
  interfaces_count = read_U2(fp);
  interfaces = Interface::read_interfaces(fp,interfaces_count);
  Displayer::display_interfaces(interfaces, cp->cp_vector);

	fields_count = read_U2(fp);
  fields = Field_info::read_fields(fp, cp->cp_vector, fields_count);
  Displayer::display_fields(fields, cp->cp_vector, fields_count);

  methods_count = read_U2(fp);  
	methods = Method_info::read_methods(fp, cp->cp_vector, methods_count);
  Displayer::display_methods(methods, cp->cp_vector, methods_count);

  // verificar sequela
	// attributes_count = read_U2(fp);
	// attributes = Attribute_info::read_attributes(fp, cp->cp_vector, attributes_count);
  // Displayer::display_attributes(attributes, cp->cp_vector, attributes_count);
  
  if(has_main()){
    cout << "Main found" << endl;
  }
  else{
    cout << "Main not found" << endl;
  }
  if(has_clinit()){
    cout << "Clinit found" << endl;
  }
  else{
    cout << "Clinit not found" << endl;
  }

	fclose(fp);
	fp = NULL;

  this->has_been_loaded = true;
  return 0;
}

int Reader::show(){
  return 0;
} 

U1 Reader::read_U1(FILE *fp){
  unsigned char res;
  fread(&res, 1, 1, fp);
  return res;
}

U2 Reader::read_U2(FILE* fp){
  unsigned short res = 0;
  unsigned char temp;

  fread(&res, 1, 1, fp);
  fread(&temp, 1, 1, fp);
  
  res = res << 8;
  res |= temp;
  return res;
}

U4 Reader::read_U4(FILE* fp){
  unsigned int res = 0;
  unsigned char temp;

  for (int i = 0; i < 4; i++){
   res = res << 8;
   fread(&temp, 1, 1, fp);
   res |= temp;  
  }  
  
  return res;
}
vector<U1> Reader::read_UTF8(FILE* fp, int size) {

  std::vector<U1> res(size);
  for(int i = 0; i < size; i++){
    res[i] = read_U1(fp);
  }
  return res;
} 

// TODO: colocar em util
int Reader::check_magic_number(U4 val){
  return val == 0xcafebabe;
}

bool Reader::has_main(){
  bool found = false;
  for(int i = 0; i < this->methods_count; i++){
    string name = Displayer::dereference_index(cp->cp_vector, methods[i].name_index);
    if (name != "main") continue;

    string desc = Displayer::dereference_index(cp->cp_vector, methods[i].descriptor_index);
    if (desc != "([Ljava/lang/String;)V") continue;
    
    unsigned char flags =  methods[i].access_flags;
    if ((flags & 0x09) != 0x09) continue;

    this->main_index = i;
    found = true;
    break;

  }

  return found;
}

bool Reader::has_clinit(){
  bool found = false;
  for(int i = 0; i < this->methods_count; i++){
    string name = Displayer::dereference_index(cp->cp_vector, methods[i].name_index);
    if(name!="<init>") continue;
    this->clinit_index = i;
    found = true;
    break;
  }

  return found;
}

// string Reader::get_path() {
// 	string path= "", auxFilename(this->file_name);
// 	string result;
	
//   //TODO: Tratar caminho do arquivo
//   return "Jogador.class";
// }

Method_info Reader::get_main() {
  return methods[main_index];
}

Method_info Reader::get_clinit() {
  return methods[clinit_index];
}

Method_info Reader::get_method(string name, string descriptor){

	for(int i = 0; i < methods_count; i++){
		string method_name = Displayer::dereference_index(cp->cp_vector, methods[i].name_index);
		string method_desc = Displayer::dereference_index(cp->cp_vector, methods[i].descriptor_index);

		if(descriptor == method_desc && name == method_name) 
		{
			return methods[i];
		}
	}

	if(super_class == 0) {
		throw runtime_error("Super classe nao lida corretamente");
	}
	else {
  	Static_class* static_class = Method_area::get_class(Displayer::dereference_index(cp->cp_vector, super_class));
   	Reader* reader = static_class->reader_class;
  	return reader->get_method(name, descriptor);
	}
}

Reader* Reader::get_searched_method_class(string name, string descriptor){
	for(int i = 0; i < methods_count; i++)
	{
		string method_name = Displayer::dereference_index(cp->cp_vector, methods[i].name_index);
		string method_desc = Displayer::dereference_index(cp->cp_vector, methods[i].descriptor_index);

  	if(descriptor == method_desc && name == method_name) 
		{
			return this;
		}
	}

	if(super_class) 
	{
		return NULL;
	}
	else {
		Reader* r = Method_area::get_class(Displayer::dereference_index(cp->cp_vector, super_class))->reader_class;
		return r->get_searched_method_class(name, descriptor);
	}
}

string Reader::extract_file_name (string &input_path){
    int slash_position;
    string class_path, file_name;

    slash_position = input_path.find_last_of("/\\");
    class_path = input_path.substr(0,slash_position);
    
    return file_name = input_path.substr(slash_position+1);
}

