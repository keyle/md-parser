.PHONY: debug

debug:
	clang main.c -O0 -fsanitize=address -fno-omit-frame-pointer -g -Wall -o debug
