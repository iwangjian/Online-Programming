# a simple parser for python. use get_number() and get_word() to read
def parser():
    while 1:
        data = list(input().split(' '))
        for number in data:
            if len(number) > 0:
                yield(number)   

input_parser = parser()

def get_word():
    global input_parser
    return next(input_parser)

def get_number():
    data = get_word()
    try:
        return int(data)
    except ValueError:
        return float(data)
        
def f(n):
    if n==1:
        return 1
    if n==2:
        return 2
    f0 = 1
    f1 = 2
    f2 = 0
    for i in range(2,n):
        f2 = f0 + f1
        f0 = f1
        f1 = f2
    return f2

# numpy and scipy are available for use
import numpy
import scipy

a = get_number()
for i in range(a):
    b = get_number()
    print(f(b))
