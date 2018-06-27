# all: src/main.c src/reader.c src/constantpool.c src/displayer.c src/flags.c src/interfaces.c src/fields.c src/methods.c src/attributes.c
# 	gcc -o bin/main src/main.c src/reader.c src/constantpool.c src/displayer.c src/flags.c src/interfaces.c src/fields.c src/methods.c src/attributes.c -lm

# run: all
# 	bin/main

# ladeira: all
# 	bin/main exp/Jogador.class
# teste: all
# 	bin/main exp/vetor2-Eclipses.class

# long: all
# 	bin/main exp/vetor2-Eclipses.class

all: src/main.cpp src/Constant_pool.cpp src/Interface.cpp src/Field_info.cpp src/Attribute_info.cpp src/Method_info.cpp src/Method_area.cpp src/Frame_stack.cpp src/Operand_stack.cpp src/Heap.cpp src/Static_class.cpp src/Instance_class.cpp src/Operations.cpp src/Local_variable.cpp
	g++ src/main.cpp src/Reader.cpp src/Constant_pool.cpp src/Displayer.cpp src/Interface.cpp src/Field_info.cpp src/Attribute_info.cpp src/Method_info.cpp src/Method_area.cpp src/Frame_stack.cpp src/Operand_stack.cpp src/Heap.cpp src/Static_class.cpp src/Instance_class.cpp src/Operations.cpp src/Local_variable.cpp -o bin/main 

working: src/main.cpp src/Constant_pool.cpp src/Interface.cpp src/Field_info.cpp src/Attribute_info.cpp src/Method_info.cpp
	g++ src/main.cpp src/Reader.cpp src/Constant_pool.cpp src/Displayer.cpp src/Interface.cpp src/Field_info.cpp src/Attribute_info.cpp src/Method_info.cpp -o bin/main 

run: working
	bin/main E exp/Jogador.class

eclipse: working
	bin/main E exp/vetor2-Eclipses.class
negativo: working
	bin/main E exp/Negativo.class

sample: working
	bin/main E exp/Sample.class
lookup-i: all
	bin/main i exp/lookupswitch.class
sample-i: all
	bin/main i exp/sample.class