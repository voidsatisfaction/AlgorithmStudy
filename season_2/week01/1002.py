# -*- coding: utf8 -*-
# https://www.acmicpc.net/problem/1002
# 이석원은 조규현과 백승환에게 상대편 마린(류재명)의 위치를 계산하라는 
# 명령을 내렸다. 조규현과 백승환은 각각 자신의 터렛 위치에서 현재 적까
# 지의 거리를 계산했다.
# 조규현의 좌표 (x1, y1)와 백승환의 좌표 (x2, y2)가 주어지고, 조규현이
# 계산한 류재명과의 거리 r1과 백승환이 계산한 류재명과의 거리 r2가 주어
# 졌을 때, 류재명이 있을 수 있는 좌표의 수를 출력하는 프로그램을 작성하
# 시오.
from sys import stdin
from math import sqrt

e = 0.00001

def equal(x, y):
    if -e < x - y < e:
        return True
    else:
        return False

def func(x1, y1, r1, x2, y2, r2):
    d1, d2 = max(r1, r2) + min(r1, r2), max(r1, r2) - min(r1, r2)
    distance_xy = sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2))
    if equal(distance_xy, 0) and equal(d2, 0): # same
        return -1
    if equal(distance_xy, d1): # circles lie on each other
        return 1
    if equal(distance_xy, d2): # a circle lies inside the other
        return 1
    if distance_xy > d1: # too far
        return 0
    if distance_xy < d2: # too close
        return 0
    return 2

if __name__ == '__main__':
    for _ in xrange(int(raw_input())):
        args = map(lambda x:float(x), raw_input().split(' '))
        print func(*args)