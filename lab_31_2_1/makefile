#Компилятор
CC := gcc

#Опции компиляции
CFLAGS := -std=c99 -Wall -Werror

#Общие объектные файлы
OBJS := out/matrix.o out/check_prime.o

app.exe: $(OBJS) out/main.o
	$(CC) -o $@ $^

out/%.o: src/%.c inc/*.h
	mkdir -p out
	$(CC) $(CFLAGS) -I inc -c $< -o $@

.PHONY: clean

clean:
	mkdir -p out
	$(RM) out/*.o *.exe
