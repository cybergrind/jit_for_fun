
.PHONY: pow_test

pow_test:
	clang -std=gnu11 -g pow/main.c -o pow.bin
	./pow.bin

pow_asm:
	fasm pow/edi.fasm
	./dis pow/edi.bin
