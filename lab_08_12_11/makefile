#Компилятор
CC := gcc

#Опции компиляции
CFLAGS := -std=c99 -Wall -Werror

#Общие объектные файлы
OBJS := out/addition.o out/calc_determinant.o out/cdio.o out/multiplication.o

#Объектные файлы для модульных тестов
OBJSUT := out/check_addition.o out/check_calc_determinant.o out/check_multiplication.o out/check_main.o

app.exe: $(OBJS) out/main.o
	$(CC) -o $@ $^

Debug: CFLAGS += -g3
Debug: app.exe

Release: CFLAGS += -DNDEBUG -g0
Release: app.exe

unit_tests.exe: $(OBJS) $(OBJSUT)
	$(CC) -o $@ $^ -lcheck

out/%.o: src/%.c
	mkdir -p out
	$(CC) $(CFLAGS) -I inc -c $< -o $@

out/%.d: src/%.c
	mkdir -p out
	$(CC) -M -I inc $< > $@

include $(OBJS:.o=.d) out/main.d

out/%.o: unit_tests/%.c
	mkdir -p out
	$(CC) $(CFLAGS) -I unit_tests -c $< -o $@

out/%.d: unit_tests/%.c
	mkdir -p out
	$(CC) -M -I unit_tests $< > $@

include $(OBJSUT:.o=.d)

.PHONY: unit func clean Debug Release

func_tests/app.exe: $(OBJS) out/main.o
	$(CC) $^ -o $@

func: func_tests/app.exe
	./func_tests/run_tests.bat

unit: unit_tests.exe
	./unit_tests.exe

clean:
	mkdir -p out
	$(RM) out/*.o *.exe out/*.d


