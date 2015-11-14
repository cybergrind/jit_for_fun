
.PHONY: pow_test

pow_test:
	clang -std=gnu11 -I include -g pow/main.c helpers/hexdump.c -o pow.bin
	./pow.bin

pow_asm:
	fasm pow/edi.fasm
	./dis pow/edi.bin
	hexdump pow/edi.bin
