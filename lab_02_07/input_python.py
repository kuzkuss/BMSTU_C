from random import randint
with open ('input_07.txt', 'w') as elements_file:
    n = int(input('Input the number of elements: '))
    elements_file.write(str(n) + '\n')
    for i in range(n - 1):
        element = randint(-100, 100)
        elements_file.write(str(element) + ' ')
    element = randint(-100, 100)
    elements_file.write(str(element))