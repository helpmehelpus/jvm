#ifndef BASETYPES
#define BASETYPES

#include<stdint.h>


typedef uint8_t U1;
typedef uint16_t U2;
typedef uint32_t U4;


typedef struct {
  int* dimensions;
  int* array;
} Array;

typedef struct attribute_info Attribute_info;

typedef struct {
	U2 constantvalue_index;
} Constant_value_attribute;

typedef struct {
	U2 start_pc;
	U2 end_pc;
	U2 handler_pc;
	U2 catch_type;
} T_exception_table;

typedef struct {
	U2 max_stack;
	U2 max_locals;
	U4 code_length;
	U2* code;
	U2 exception_table_length;
	T_exception_table** exception_table;
	U2 attribute_count;
	struct attribute_info* attributes;
} Code_attribute;

typedef struct {
	U2 number_of_exceptions;
	U2* exception_index_table;
} Exception_attribute;

typedef union {
	Constant_value_attribute constantvalue;
	Code_attribute code;
	Exception_attribute exception;
} T_info;

 struct attribute_info{
	U2 name_index;
	U4 length;

	T_info* info;
};

typedef struct {
	uint16_t access_flags;
	uint16_t name_index;
	uint16_t descriptor_index;
	uint16_t attributes_count;
	Attribute_info *attributes;
} Method_info;


typedef struct {
	unsigned char accessFlags;
	unsigned char name_index;
	unsigned char descriptor_index;
	unsigned char attributes_count;
	Attribute_info *attributes;
} Field_info;


#endif



