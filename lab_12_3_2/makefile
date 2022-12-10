#Компилятор
CC := gcc

#Опции компиляции
CFLAGS := -std=c99 -Wall -Werror

#Объектные файлы динамической библиотеки
DYNLIBOBJS := out/lib_arr.o

libarr.dll: CFLAGS += -D ARR_EXPORTS
libarr.dll: $(DYNLIBOBJS)
	$(CC) -shared -Wl,--subsystem,windows -o libarr.dll 	$(DYNLIBOBJS)

unit_tests.exe: out/check_lib_arr.o out/check_main.o libarr.dll
	$(CC) out/check_main.o out/check_lib_arr.o -L. -larr -o $@ -lcheck

out/%.o: src/%.c inc/*.h
	mkdir -p out
	$(CC) $(CFLAGS) -I inc -c $< -o $@

out/%.o: unit_tests/%.c inc/*.h
	mkdir -p out
	$(CC) $(CFLAGS) -I inc -c $< -o $@

func: libarr.dll
	./func_tests/run_tests.bat

unit: unit_tests.exe
	./unit_tests.exe

.PHONY: clean func unit

clean:
	$(RM) out/*.o *.exe *.dll func_tests/*.exe