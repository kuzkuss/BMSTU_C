#Компилятор
CC := gcc

#Опции компиляции
CFLAGS := -std=c99 -Wall -Werror -Wpedantic -Wextra -Wvla -Wno-format-truncation

unit_tests.exe: out/my_snprintf.o out/convertation.o out/check_my_snprintf.o out/check_convertation.o out/check_main.o
	$(CC) -o $@ $^ -lcheck

out/%.o: src/%.c inc/*.h
	mkdir -p out
	$(CC) $(CFLAGS) -I inc -c $< -o $@

out/%.o: unit_tests/%.c unit_tests/*.h
	mkdir -p out
	$(CC) $(CFLAGS) -I unit_tests -c $< -o $@

.PHONY: clean unit

unit: unit_tests.exe
	./unit_tests.exe

clean:
	mkdir -p out
	$(RM) out/*.o *.exe
