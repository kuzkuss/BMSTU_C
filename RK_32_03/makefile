#Компилятор
CC := gcc

#Опции компиляции
CFLAGS := -std=gnu99 -Wall -Werror

#Общие объектные файлы
OBJS := out/list.o out/list_node.o out/student.o out/errors.o

app.exe: $(OBJS) out/main.o
	$(CC) -o $@ $^

out/%.o: src/%.c inc/*.h
	mkdir -p out
	$(CC) $(CFLAGS) -I inc -c $< -o $@

.PHONY: clean

clean:
	mkdir -p out
	$(RM) out/*.o *.exe

