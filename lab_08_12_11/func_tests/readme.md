# Тесты для 12 варианта лабораторной работы №8

## Входные данные
5 ключей:

app.exe action mtr_1.txt mtr_2.txt res.txt
action - выполняемая операция a - сложение или m - умножение
mtr_1.txt - имя входного файла для первой матрицы
mtr_2.txt - имя входного файла для второй матрицы
res.txt - имя выходного файла

В файлах mtr_1.txt и mtr_2.txt записана размерность и сами элементы вещественной матрицы

4 ключа:

app.exe action mtr_1.txt res.txt
action - выполняемая операция o - вычисление определителя с помощью разложения по строке
mtr_1.txt - имя входного файла для матрицы
res.txt - имя выходного файла

В файле mtr_1.txt записана размерность и сами элементы вещественной матрицы

## Выходные данные
5 ключей:
Файл res.txt, в котором записана матрица являющаяся результатом выполненной операции (сложения или умножения)

4 ключа:
Файл res.txt, в котором записан определитель матрицы

## Позитивные тесты:
5 ключа:
ключ "a":
- 01 - в матрицах только неотрицательные элементы
- 02 - в матрицах только неположительные элементы
- 03 - и положительные, и отрицательные
ключ "m":
- 04 - в матрицах только неотрицательные элементы
- 05 - в матрицах только неположительные элементы
- 06 - и положительные, и отрицательные
4 ключа (ключ "o"):
- 07 - определитель равен нулю
- 08 - определитель больше нуля
- 09 - определитель меньше нуля
- 10 - один элемент в матрице

## Негативные тесты:
- 01 - несуществующий файл mtr_1.txt ("a"/"m"/"o")
- 02 - пустой файл mtr_1.txt ("a"/"m"/"o")
- 03 - второй ключ не равен "a"/"m"/"o" ("a"/"m"/"o")
- 04 - количество ключей меньше 4 ("a"/"m"/"o")
- 05 - количество ключей больше 5 ("a"/"m"/"o")
- 06 - количество столбцов матрицы меньше 1 ("a"/"m"/"o")
- 07 - количество строк матрицы меньше 1 ("a"/"m"/"o")
- 08 - вместо кол-ва столбцов матрицы написана буква ("a"/"m"/"o")
- 09 - вместо кол-ва строк матрицы написана буква ("a"/"m"/"o")
- 10 - один или несколько элементов матрицы буква ("a"/"m"/"o")
5 ключей:
- 11 - несуществующий файл mtr_2.txt ("a"/"m")
- 12 - пустой файл mtr_2.txt ("a"/"m")
ключ "a":
- 13 - количество строк одной матрицы не равно количеству строк второй матрицы
- 14 - количество столбцов одной матрицы не равно количеству столбцов второй матрицы
ключ "m":
- 15 - количество столбцов первой матрицы не равно количеству строк второй матрицы
4 ключа (ключ "o"):
- 16 - матрица не квадратная