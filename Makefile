
.PHONY: pow_test model

pow_test:
	clang -std=gnu11 -I include -g pow/main.c helpers/hexdump.c -o pow.bin
	./pow.bin

pow_asm:
	fasm pow/edi.fasm
	./dis pow/edi.bin
	hexdump pow/edi.bin

model:
	clang -g -O0 -mcmodel=small -std=gnu11 model/model.c -o model.o
	objdump -dS model.o
	readelf -rs model.o
