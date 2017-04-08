# -*- encoding:utf8 -*-
# N이 주어졌을 때, fibonacci(N)을 호출했을 때 0과 1이 각각 몇 번
# 출력되는지 구하는 프로그램을 작성하시오. (N <= 40)

def fibonacci(n):
    if n == 0:
        return 0
    if n == 1:
        return 1
    a, b = 0, 1
    for _ in xrange(n):
        a, b = a+b, a
    return a

def func(n):
    if n == 0:
        return "1 0"
    else:
        return "{0} {1}".format(fibonacci(n-1), fibonacci(n))

if __name__ == '__main__':
    for _ in xrange(int(raw_input())):
        print func(int(raw_input()))