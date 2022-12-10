#Компилятор
CC := gcc

#Опции компиляции
CFLAGS := -std=c99 -Wall -Werror -pedantic

#Общие объектные файлы
OBJS := out/cdio.o out/filter.o out/mysort.o

app.exe: $(OBJS) out/main.o
	$(CC) $^ -o $@

Debug: CFLAGS += -g3
Debug: app.exe

Release: CFLAGS += -DNDEBUG -g0
Release: app.exe

unit_tests.exe: $(OBJS) out/check_filter.o out/check_mysort.o out/check_main.o
	$(CC) $^ -o $@ -lcheck

out/%.o: src/%.c
	mkdir -p out
	$(CC) $(CFLAGS) -I inc -c $< -o $@

out/%.d: src/%.c
	mkdir -p out
	$(CC) -MM -I inc $< > $@

include out/cdio.d out/filter.d out/mysort.d out/main.d

out/%.o: unit_tests/%.c
	mkdir -p out
	$(CC) $(CFLAGS) -I unit_tests -c $< -o $@

out/%.d: unit_tests/%.c
	mkdir -p out
	$(CC) -MM -I unit_tests $< > $@

include out/check_filter.d out/check_mysort.d out/check_main.d

func_tests/a.exe: $(OBJS) out/main.o
	$(CC) $^ -o $@

func: func_tests/a.exe
	./func_tests/run_tests_makefile.bat

unit: unit_tests.exe
	./unit_tests.exe

time:
	$(CC) $(CFLAGS) -o time/time_measurement.exe time/time_measurement.c
	./time/time_measurement.exe

.PHONY: clean Debug Release func unit time
clean:
	$(RM) *.o *.exe *.d