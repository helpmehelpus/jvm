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
  
  int found_main, found_clinit;
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
	attributes_count = read_U2(fp);
	attributes = Attribute_info::read_attributes(fp, cp->cp_vector, attributes_count);
  Displayer::display_attributes(attributes, cp->cp_vector, attributes_count);
  
	fclose(fp);
	fp = NULL;


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


