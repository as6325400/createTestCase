all: input inputv output

input: input.cpp
	g++ -std=c++17 input.cpp -o _input.exe

gen_input: input
	./_input.exe

output: output.cpp
	g++ -std=c++17 output.cpp -o _output.exe

gen_output:
	./_output.exe

inputv: input_validator.cpp
	g++ -std=c++17 input_validator.cpp -o _input_validator.exe

check:
	./_input_validator.exe

gen: gen_input check gen_output

clean:
	rm _input.exe
	rm _output.exe
	rm _input_validator.exe
