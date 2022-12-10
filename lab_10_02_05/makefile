#Компилятор
CC := gcc

#Опции компиляции
CFLAGS := -std=c99 -Wall -Werror

#Общие объектные файлы
OBJS := out/list.o out/list_node.o

app.exe: out/main.o $(OBJS)
	$(CC) -o $@ $^

out/%.o: src/%.c inc/*.h
	mkdir -p out
	$(CC) $(CFLAGS) -I inc -c $< -o $@

Debug: CFLAGS += -g3
Debug: app.exe

Release: CFLAGS += -DNDEBUG -g0
Release: app.exe

unit_tests.exe: $(OBJS) out/check_list.o out/check_list_node.o out/check_main.o
	$(CC) -o $@ $^ -lcheck

out/%.o: unit_tests/%.c unit_tests/*.h
	mkdir -p out
	$(CC) $(CFLAGS) -I unit_tests -c $< -o $@

.PHONY: clean func unit Release Debug

unit: unit_tests.exe
	./unit_tests.exe

func_tests/app.exe: out/main.o $(OBJS)
	$(CC) -o $@ $^

func: func_tests/app.exe
	./func_tests/run_tests.bat

clean:
	mkdir -p out
	$(RM) out/*.o *.exe unit_tests/*.o
