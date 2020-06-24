
all: compile

compile:
	nvcc -o trab3 analise_genoma_cuda.cu -lm

clean:
	rm -rf ?
