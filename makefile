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

all: src/main.cpp src/Constant_pool.cpp 
	g++ -o bin/main src/main.cpp src/Reader.cpp src/Constant_pool.cpp src/Displayer.cpp
run: all
	bin/main E exp/Jogador.class