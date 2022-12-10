#Компилятор
CC := gcc

#Опции компиляции
CFLAGS := -std=gnu99 -Wall -Werror

#Общие объектные файлы
OBJS := out/subject.o out/subjects_array.o

#Объектные файлы для модульных тестов
OBJSUT := out/check_subject.o out/check_subjects_array.o out/check_main.o

app.exe: $(OBJS) out/main.o
	$(CC) -o $@ $^

Debug: CFLAGS += -g3
Debug: app.exe

Release: CFLAGS += -DNDEBUG -g0
Release: app.exe

out/%.o: src/%.c inc/*.h
	mkdir -p out
	$(CC) $(CFLAGS) -c $< -I inc -o $@

unit_tests.exe: $(OBJSUT) $(OBJS)
	$(CC) -o $@ $^ -lcheck

out/%.o: unit_tests/%.c unit_tests/*.h
	mkdir -p out
	$(CC) $(CFLAGS) -c $< -o $@ -I unit_tests

.PHONY: clean Debug Release func unit

unit: unit_tests.exe
	./unit_tests.exe

func_tests/app.exe: $(OBJS) out/main.o
	$(CC) -o $@ $^

func: func_tests/app.exe
	./func_tests/run_tests.bat

clean:
	mkdir -p out
	$(RM) out/*.o *.exe