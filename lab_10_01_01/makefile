#Компилятор
CC := gcc

#Опции компиляции
CFLAGS := -std=gnu99 -Wall -Werror -pedantic

#Общие объектные файлы
OBJS := out/list.o out/list_node.o out/grocery.o

app.exe: out/main.o $(OBJS)
	$(CC) -o $@ $^

out/%.o: src/%.c inc/*.h
	mkdir -p out
	$(CC) $(CFLAGS) -I inc -c $< -o $@

Release: CFLAGS += -DNDEBUG -g0
Release: app.exe

Debug: CFLAGS += -g3
Debug: app.exe

unit_tests.exe: $(OBJS) out/check_main.o out/check_list.o out/check_list_node.o out/check_grocery.o
	$(CC) -o $@ $^ -lcheck

out/%.o: unit_tests/%.c unit_tests/*.h
	mkdir -p out
	$(CC) $(CFLAGS) -c $< -I unit_tests -o $@

.PHONY: clean Release Debug unit func

unit: unit_tests.exe
	./unit_tests.exe

func_tests/app.exe: out/main.o $(OBJS)
	$(CC) -o $@ $^

func: func_tests/app.exe
	./func_tests/run_tests.bat

clean:
	$(RM) out/*.o *.exe func_tests/*.exe
	
