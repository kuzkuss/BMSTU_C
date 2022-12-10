#Компилятор
CC := gcc

#Опции компиляции
CFLAGS := -std=c99 -Wall -Werror

#Объектные файлы статической библиотеки
STATLIBOBJS := out/process_array_stat.o out/input_output_stat.o

#Объектные файлы динамической библиотеки
DYNLIBOBJS := out/process_array_dyn.o out/input_output_dyn.o

#Общие объектные файлы
OBJS := out/create_delete.o

app_stat.exe: $(OBJS) out/main_stat.o libarr.a
	$(CC) $(OBJS) out/main_stat.o -L. -larr -o $@

app_dyn_link.exe: $(OBJS) out/main_dyn_link.o libarr.dll
	$(CC) $(OBJS) out/main_dyn.o -L. -larr -o $@

app_dyn_load.exe: $(OBJS) out/main_dyn_load.o libarr.dll
	$(CC) $(OBJS) out/main_dyn_load.o -o $@

libarr.a: $(STATLIBOBJS)
	ar rc libarr.a $(STATLIBOBJS)
	ranlib libarr.a

libarr.dll: CFLAGS += -D ARR_EXPORTS
libarr.dll: $(DYNLIBOBJS)
	$(CC) -shared -Wl,--subsystem,windows -o libarr.dll 	$(DYNLIBOBJS)

Debug: CFLAGS += -g3
Debug: app.exe

Release: CFLAGS += -DNDEBUG -g0
Release: app.exe

unit_tests_stat.exe: $(OBJS) out/check_process_array.o out/check_main.o libarr.a
	$(CC) $(OBJS) out/check_main.o 	out/check_process_array.o -L. -larr -o $@ -lcheck

unit_tests_dyn.exe: $(OBJS) out/check_process_array.o out/check_main.o libarr.dll
	$(CC) $(OBJS) out/check_main.o 	out/check_process_array.o -L. -larr -o $@ -lcheck

out/%.o: src/%.c inc/*.h
	mkdir -p out
	$(CC) $(CFLAGS) -I inc -c $< -o $@

out/%.o: unit_tests_stat/%.c unit_tests_stat/*.h
	mkdir -p out
	$(CC) $(CFLAGS) -I unit_tests_stat -c $< -o $@

out/%.o: unit_tests_dyn/%.c unit_tests_dyn/*.h
	mkdir -p out
	$(CC) $(CFLAGS) -I unit_tests_dyn -c $< -o $@

func_stat: libarr.a $(OBJS) out/main_stat.o
	$(CC) $(OBJS) out/main_stat.o -L. -larr -o 	func_tests/a.exe
	./func_tests/run_tests_makefile.bat

func_dyn_link: libarr.dll $(OBJS) out/main_dyn_link.o 
	$(CC) $(OBJS) out/main_dyn_link.o -L. -larr -o 	func_tests/a.exe
	./func_tests/run_tests_makefile.bat

func_dyn_load: libarr.dll $(OBJS) out/main_dyn_load.o
	$(CC) $(OBJS) out/main_dyn_load.o -o func_tests/a.exe
	./func_tests/run_tests_makefile.bat

unit_stat: unit_tests_stat.exe
	./unit_tests_stat.exe

unit_dyn: unit_tests_dyn.exe
	./unit_tests_dyn.exe

.PHONY: clean Debug Release func_stat func_dyn_link func_dyn_load unit_stat unit_dyn_link unit_dyn_load

clean:
	$(RM) out/*.o *.exe *.a *.dll func_tests/*.exe