# -*- encoding:utf8 -*-
def pointLiesInside(x, y, cx, cy, r):
    if (cx-x)**2 + (cy-y)**2 < r**2:
        return True
    return False

def func(sx, sy, tx, ty, planets):
    count = 0
    for cx, cy, r in planets:
        s_is_inside = pointLiesInside(sx, sy, cx, cy, r)
        t_is_inside = pointLiesInside(tx, ty, cx, cy, r)
        if s_is_inside is not t_is_inside:
            count += 1
    return count

if __name__ == '__main__':
    for _ in xrange(int(raw_input())):
        sx, sy, tx, ty = map(lambda x:float(x), raw_input().split())
        planets = []
        for _ in xrange(int(raw_input())):
            planets.append(map(lambda x:float(x), raw_input().split()))
        print func(sx, sy, tx, ty, planets)