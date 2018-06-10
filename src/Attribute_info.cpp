#include "Attribute_info.hpp"
#include "Reader.hpp"
#include "Displayer.hpp"

vector<Attribute_info> Attribute_info::read_attributes(FILE* fp, vector<Cp_info> cp_vector, int length) {
  vector<Attribute_info> attributes;

  for(int i = 0; i < length; i++ ) {
    attributes.push_back(read_attribute(fp,cp_vector));
  }
  return attributes;
}

Attribute_info Attribute_info::read_attribute(FILE* fp, vector<Cp_info> cp_vector) {
  Attribute_info attr;

  attr.name_index = Reader::read_U2(fp);
  attr.length = Reader::read_U4(fp);
  // attr.info = read_attribute_info(fp, cp_vector, attr.name_index, attr.length);

  return attr;
}

T_exception_table Attribute_info::read_exception_handler(FILE* fp) {
  
  T_exception_table  exception_table_entry;

  exception_table_entry.start_pc = Reader::read_U2(fp);
  exception_table_entry.end_pc = Reader::read_U2(fp);
  exception_table_entry.handler_pc = Reader::read_U2(fp);
  exception_table_entry.catch_type = Reader::read_U2(fp);

  return exception_table_entry;
}

// T_info Attribute_info::read_attribute_info(FILE* fp, vector<Cp_info> cp_vector, unsigned short index, unsigned short length) {

  // T_info info;
  
  // string attribute_name = Displayer::dereference_index(cp_vector, index);

  // if(attribute_name == "ConstantValue") {
  //   info.constant_value.constant_value_index = Reader::read_U2(fp);
  // }

  // else if(attribute_name == "Code") {
  //   info.code.max_stack = Reader::read_U2(fp);
  //   info.code.max_locals = Reader::read_U2(fp);
  //   info.code.code_length = Reader::read_U4(fp);

  //   vector<U2> code_list;
  //   for(int i = 0; i < info.code.code_length; i++ ) {
  //     code_list[i] = Reader::read_U1(fp);
  //   }
  //   info.code.code = code_list;    

  //   info.code.exception_table_length = Reader::read_U2(fp);

  //   vector <T_exception_table> e_table;
  //   for(int i = 0; i < info.code.exception_table_length; i++ ) {
  //     //e_table[i] = read_exception_handler(fp);
  //     info.code.exception_table.push_back(read_exception_handler(fp));
  //   }
    //info.code.exception_table = e_table;

//     info.code.attribute_count = Reader::read_U2(fp);

//     //Attribute_info* attributes = (Attribute_info*) malloc(sizeof(Attribute_info) * info.code.attribute_count);
//     for(int i = 0; i < info.code.attribute_count; i++ ) {
//       //attributes[i] = read_attribute(fp, cp_vector);
//       info.code.attributes.push_back(read_attribute(fp,cp_vector));
//     }
//     //info.code.attributes = attributes;
//   }

//   else if(attribute_name == "Exceptions") {
//     info.exception.number_of_exceptions = Reader::read_U2(fp);

//     unsigned short* exceptions = (unsigned short*) malloc(sizeof(unsigned short) * info.exception.number_of_exceptions);
//     for(int i = 0; i < info.exception.number_of_exceptions; i++ ) {
//       exceptions[i] = Reader::read_U2(fp);
//     }
//     info.exception.exception_index_table = exceptions;
//   }

//   else {
//     for(int i = 0; i < length; i++ ) {
//       Reader::read_U1(fp);
//     }
//   }

//   return info;
// }




// void Attribute_info::display_attributes(Attribute_info* attributes, vector<Cp_info>  cp_vector, int length)
// {
//   for(int i = 0; i < length; i++ ) {
//     printf("\tAttribute: %d  \n",i);
//     display_attribute(attributes[i], cp_vector);
//   }
// }

// void Attribute_info::display_attribute (Attribute_info a, vector<Cp_info> cp_vector) {
//   string attribute_name = Displayer::dereference_index(cp_vector, a.name_index);
//   cout << "\t\tName: " << attribute_name << endl;

//   cout << "\t\tSize: " << a.length << endl;

//   if(attribute_name == "ConstantValue") {
//     printf("\t\tConstant Value: %d \n", a.info.constant_value.constant_value_index);
//   }

//   else if(attribute_name == "Code") {
//     printf("\t\tMax Stack: %d \n", a.info.code.max_stack);
//     printf("\t\tMax Locals: %d \n", a.info.code.max_locals);
//     printf("\t\tCode Length: %d \n", a.info.code.code_length);

//     int i = 0;
//     while(i < a.info.code.code_length) {
//       printf("\t\tCode  %d: %s ", i, getMnemonic(a.info.code.code[i]));
//       getOpcodeParams(a.info.code.code, &i);
//       printf("\n");
//     }

//     printf("\t\tException Table Length: %d\n", a.info.code.exception_table_length);

//     for(int i = 0; i < a.info.code.exception_table_length; i++ ) {
//       printf("\t\tStart   PC: %d \n", a.info.code.exception_table[i].start_pc);
//       printf("\t\tEnd     PC: %d \n", a.info.code.exception_table[i].end_pc);
//       printf("\t\tHandler PC: %d \n", a.info.code.exception_table[i].handler_pc);
//       printf("\t\tCatch Type: %d \n", a.info.code.exception_table[i].catch_type);
//     }

//     printf("\t\tAttribute Count: %d \n", a.info.code.attribute_count);

//     for(int i = 0; i < a.info.code.attribute_count; i++ ) {
//       display_attribute(a.info.code.attributes[i],cp_vector);
//     }
//   }

//   else if(attribute_name == "Exceptions") {
    
//     printf("\t\tNumber of Exceptions: %d\n", a.info.exception.number_of_exceptions);

//     for(int i = 0; i < a.info.exception.number_of_exceptions; i++ ) {
      
//       printf("\t\tException Index: %d \n", a.info.exception.exception_index_table[i]); 
//     }
//   }
// }

string Attribute_info::get_mnemonic(int opcode) {
  switch(opcode) {
    case(0x00): return  "nop";
    case(0x01): return  "aconst_null";
    case(0x02): return  "iconst_m1";
    case(0x03): return  "iconst_0";
    case(0x04): return  "iconst_1";
    case(0x05): return  "iconst_2";
    case(0x06): return  "iconst_3";
    case(0x07): return  "iconst_4";
    case(0x08): return  "iconst_5";
    case(0x09): return  "lconst_0";
    case(0x0a): return  "lconst_1";
    case(0x0b): return  "fconst_0";
    case(0x0c): return  "fconst_1";
    case(0x0d): return  "fconst_2";
    case(0x0e): return  "dconst_0";
    case(0x0f): return  "dconst_1";
    case(0x10): return  "bipush";
    case(0x11): return  "sipush";
    case(0x12): return  "ldc";
    case(0x13): return  "ldc_w";
    case(0x14): return  "ldc2_w";
    case(0x15): return  "iload";
    case(0x16): return  "lload";
    case(0x17): return  "fload";
    case(0x18): return  "dload";
    case(0x19): return  "aload";
    case(0x1a): return  "iload_0";
    case(0x1b): return  "iload_1";
    case(0x1c): return  "iload_2";
    case(0x1d): return  "iload_3";
    case(0x1e): return  "lload_0";
    case(0x1f): return  "lload_1";
    case(0x20): return  "lload_2";
    case(0x21): return  "lload_3";
    case(0x22): return  "fload_0";
    case(0x23): return  "fload_1";
    case(0x24): return  "fload_2";
    case(0x25): return  "fload_3";
    case(0x26): return  "dload_0";
    case(0x27): return  "dload_1";
    case(0x28): return  "dload_2";
    case(0x29): return  "dload_3";
    case(0x2a): return  "aload_0";
    case(0x2b): return  "aload_1";
    case(0x2c): return  "aload_2";
    case(0x2d): return  "aload_3";
    case(0x2e): return  "iaload";
    case(0x2f): return  "laload";
    case(0x30): return  "faload";
    case(0x31): return  "daload";
    case(0x32): return  "aaload";
    case(0x33): return  "baload";
    case(0x34): return  "caload";
    case(0x35): return  "saload";
    case(0x36): return  "istore";
    case(0x37): return  "lstore";
    case(0x38): return  "fstore";
    case(0x39): return  "dstore";
    case(0x3a): return  "astore";
    case(0x3b): return  "istore_0";
    case(0x3c): return  "istore_1";
    case(0x3d): return  "istore_2";
    case(0x3e): return  "istore_3";
    case(0x3f): return  "lstore_0";
    case(0x40): return  "lstore_1";
    case(0x41): return  "lstore_2";
    case(0x42): return  "lstore_3";
    case(0x43): return  "fstore_0";
    case(0x44): return  "fstore_1";
    case(0x45): return  "fstore_2";
    case(0x46): return  "fstore_3";
    case(0x47): return  "dstore_0";
    case(0x48): return  "dstore_1";
    case(0x49): return  "dstore_2";
    case(0x4a): return  "dstore_3";
    case(0x4b): return  "astore_0";
    case(0x4c): return  "astore_1";
    case(0x4d): return  "astore_2";
    case(0x4e): return  "astore_3";
    case(0x4f): return  "iastore";
    case(0x50): return  "lastore";
    case(0x51): return  "fastore";
    case(0x52): return  "dastore";
    case(0x53): return  "aastore";
    case(0x54): return  "bastore";
    case(0x55): return  "castore";
    case(0x56): return  "sastore";
    case(0x57): return  "pop";
    case(0x58): return  "pop2";
    case(0x59): return  "dup";
    case(0x5a): return  "dup_x1";
    case(0x5b): return  "dup_x2";
    case(0x5c): return  "dup2";
    case(0x5d): return  "dup2_x1";
    case(0x5e): return  "dup2_x2";
    case(0x5f): return  "swap";
    case(0x60): return  "iadd";
    case(0x61): return  "ladd";
    case(0x62): return  "fadd";
    case(0x63): return  "dadd";
    case(0x64): return  "isub";
    case(0x65): return  "lsub";
    case(0x66): return  "fsub";
    case(0x67): return  "dsub";
    case(0x68): return  "imul";
    case(0x69): return  "lmul";
    case(0x6a): return  "fmul";
    case(0x6b): return  "dmul";
    case(0x6c): return  "idiv";
    case(0x6d): return  "ldiv";
    case(0x6e): return  "fdiv";
    case(0x6f): return  "ddiv";
    case(0x70): return  "irem";
    case(0x71): return  "lrem";
    case(0x72): return  "frem";
    case(0x73): return  "drem";
    case(0x74): return  "ineg";
    case(0x75): return  "lneg";
    case(0x76): return  "fneg";
    case(0x77): return  "dneg";
    case(0x78): return  "ishl";
    case(0x79): return  "lshl";
    case(0x7a): return  "ishr";
    case(0x7b): return  "lshr";
    case(0x7c): return  "iushr";
    case(0x7d): return  "lushr";
    case(0x7e): return  "iand";
    case(0x7f): return  "land";
    case(0x80): return  "ior";
    case(0x81): return  "lor";
    case(0x82): return  "ixor";
    case(0x83): return  "lxor";
    case(0x84): return  "iinc";
    case(0x85): return  "i2l";
    case(0x86): return  "i2f";
    case(0x87): return  "i2d";
    case(0x88): return  "l2i";
    case(0x89): return  "l2f";
    case(0x8a): return  "l2d";
    case(0x8b): return  "f2i";
    case(0x8c): return  "f2l";
    case(0x8d): return  "f2d";
    case(0x8e): return  "d2i";
    case(0x8f): return  "d2l";
    case(0x90): return  "d2f";
    case(0x91): return  "i2b";
    case(0x92): return  "i2c";
    case(0x93): return  "i2s";
    case(0x94): return  "lcmp";
    case(0x95): return  "fcmpl";
    case(0x96): return  "fcmpg";
    case(0x97): return  "dcmpl";
    case(0x98): return  "dcmpg";
    case(0x99): return  "ifeq";
    case(0x9a): return  "ifne";
    case(0x9b): return  "iflt";
    case(0x9c): return  "ifge";
    case(0x9d): return  "ifgt";
    case(0x9e): return  "ifle";
    case(0x9f): return  "if_icmpeq";
    case(0xa0): return  "if_icmpne";
    case(0xa1): return  "if_icmplt";
    case(0xa2): return  "if_icmpge";
    case(0xa3): return  "if_icmpgt";
    case(0xa4): return  "if_icmple";
    case(0xa5): return  "if_acmpeq";
    case(0xa6): return  "if_acmpne";
    case(0xa7): return  "goto";
    case(0xa8): return  "jsr";
    case(0xa9): return  "ret";
    case(0xaa): return  "tableswitch";
    case(0xab): return  "lookupswitch";
    case(0xac): return  "ireturn";
    case(0xad): return  "lreturn";
    case(0xae): return  "freturn";
    case(0xaf): return  "dreturn";
    case(0xb0): return  "areturn";
    case(0xb1): return  "return";
    case(0xb2): return  "getstatic";
    case(0xb3): return  "putstatic";
    case(0xb4): return  "getfield";
    case(0xb5): return  "putfield";
    case(0xb6): return  "invokevirtual";
    case(0xb7): return  "invokespecial";
    case(0xb8): return  "invokestatic";
    case(0xb9): return  "invokeinterface";
    case(0xba): return  "invokedynamic";
    case(0xbb): return  "new";
    case(0xbc): return  "newarray";
    case(0xbd): return  "anewarray";
    case(0xbe): return  "arraylength";
    case(0xbf): return  "athrow";
    case(0xc0): return  "checkcast";
    case(0xc1): return  "instanceof";
    case(0xc2): return  "monitorenter";
    case(0xc3): return  "monitorexit";
    case(0xc4): return  "wide";
    case(0xc5): return  "multianewarray";
    case(0xc6): return  "ifnull";
    case(0xc7): return  "ifnonnull";
    case(0xc8): return  "goto_w";
    case(0xc9): return  "jsr_w";
    case(0xca): return  "breakpoint";
    case(0xfe): return  "impdep1";
    case(0xff): return  "impdep2";
    default:    return NULL;
  }
}

U4 Attribute_info::get_n_bytes_value(U1 n, vector<U2> code, int* index) {
  U4 value = code[(*index)++];

  for(int i = 1; i < n; i++) {
    value = (value << 8) | code[(*index)++]; 
  }
  return value;
}

void Attribute_info::get_opcode_params(vector<U2> code, int* index)
{
  switch(code[(*index)++]) {
      case(0x10): //"bipush";
      case(0x15): //"iload";
      case(0x16): //"lload";
      case(0x17): //"fload";
      case(0x18): //"dload";
      case(0x19): //"aload";
      case(0x36): //"istore";
      case(0x37): //"lstore";
      case(0x38): //"fstore";
      case(0x39): //"dstore";
      case(0x3a): //"astore";
      case(0xbc): //"newarray";
      case(0xa9): //"ret";
        printf(" %d", get_n_bytes_value(1,code,index));
        break;

      case(0x11): //"sipush";
      case(0x99): //"ifeq";
      case(0x9a): //"ifne";
      case(0x9b): //"iflt";
      case(0x9c): //"ifge";
      case(0x9d): //"ifgt";
      case(0x9e): //"ifle";
      case(0x9f): //"if_icmpeq";
      case(0xa0): //"if_icmpne";
      case(0xa1): //"if_icmplt";
      case(0xa2): //"if_icmpge";
      case(0xa3): //"if_icmpgt";
      case(0xa4): //"if_icmple";
      case(0xa5): //"if_acmpeq";
      case(0xa6): //"if_acmpne";
      case(0xa7): //"goto";
      case(0xa8): //"jsr";    
      case(0xbd): //"anewarray";
      case(0xc0): //"checkcast";
      case(0xc6): //"ifnull";
      case(0xc7): //"ifnonnull";
        printf(" %d", get_n_bytes_value(2,code,index));
      break;

      case(0x12): //"ldc";
        printf(" #%d", get_n_bytes_value(1,code,index));
        break;

      case(0x13): //"ldc_w";
      case(0x14): //"ldc2_w";
      case(0xb2): //"getstatic";
      case(0xb3): //"putstatic";
      case(0xb4): //"getfield";
      case(0xb5): //"putfield";
      case(0xbb): //"new";
      case(0xb6): //"invokevirtual";
      case(0xb7): //"invokespecial";
      case(0xb8): //"invokestatic";
      case(0xc1): //"instanceof";
        printf(" # %d", get_n_bytes_value(2,code,index));
        break;

      case(0x84): //"iinc";
        printf("# %d", get_n_bytes_value(1,code,index));
        printf(" %d", get_n_bytes_value(1,code,index));
        break;

      case(0xc5): //"multianewarray";
        printf("# %d", get_n_bytes_value(2,code,index));
        printf("  %d", get_n_bytes_value(1,code,index));
        break;

      case(0xc8): //"goto_w";
      case(0xc9): //"jsr_w";
        printf("  %d", get_n_bytes_value(4,code,index));
        break;

      case(0xb9): //"invokeinterface";
      case(0xba): //"invokedynamic";
        printf("# %d", get_n_bytes_value(2,code,index));
        printf("  %d", get_n_bytes_value(1,code,index));
        printf("  %d", get_n_bytes_value(1,code,index));
        break;      

      case(0xc4): //"wide";

        switch(code[(*index)++]) {
          case(0x15): //"iload"; 
          case(0x16): //"lload"; 
          case(0x17): //"fload"; 
          case(0x18): //"dload"; 
          case(0x19): //"aload"; 
          case(0x36): //"istore"; 
          case(0x37): //"lstore"; 
          case(0x38): //"fstore"; 
          case(0x39): //"dstore"; 
          case(0x3a): //"astore"; 
          case(0xa9): //"ret"; 
            printf("#  %d", get_n_bytes_value(2,code,index));
            break;

          case(0x84): //"iinc";
            printf("# %d", get_n_bytes_value(2,code,index));
            printf("  %d", get_n_bytes_value(2,code,index));
            break;
        }
        break;

      case(0xaa): //"tableswitch";
        {
          if((*index) % 4 != 0) {
            (*index) = *index + (4 - (*index % 4));
          }

          U4 defaultvalue = get_n_bytes_value(4,code,index);
          printf("  %d", defaultvalue);

          U4 low = get_n_bytes_value(4,code,index);
          printf("  %d", low);

          U4 high = get_n_bytes_value(4,code,index);
          printf("  %d", high);

          for(int i = 0; i < high - low + 1; i++) {
            printf("  %d", get_n_bytes_value(4,code,index)); 
          }
        }
        break;
        
      case(0xab): {//"lookupswitch";
        
          if((*index) % 4 != 0)
            *index = *index + (4 - (*index % 4));
          
          printf("  %d", get_n_bytes_value(4,code,index));

          U4 npairs = get_n_bytes_value(4,code,index);
          printf("  %d", npairs); 

          for(int i = 0; i < npairs; i++) {
            printf("  %d", get_n_bytes_value(4,code,index));
            printf("  %d", get_n_bytes_value(4,code,index)); 
          }
        }
        break;

      default:
        break;
  }
}