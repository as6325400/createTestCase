all: input_gen input_valid_gen output_gen

CC = g++
flag = -std=c++17

input_gen: input
	./$<

input: input.cpp
	$(CC) $< $(flag) -o $@

input_valid_gen: input_valid
	./$<

input_valid: input_valid.cpp
	$(CC) $< $(flag) -o $@

output_gen: output
	./$<

output: output.cpp
	$(CC) $< $(flag) -o $@

clean: 
	rm input output input_valid ../data/secret/*