from random import randint
if __name__ == '__main__':
    print 1
    print "1000 100000"
    print reduce(
        lambda x, y: (str(x) + ' ' + str(y)),
        (randint(1, 1000) for _ in xrange(1000))
    )
    for _ in xrange(100000):
        s = randint(1, 1000)
        t = randint(1, 1000)
        if s == t:
            t += 1
        print "{0} {1}".format(min(s, t), max(s,t))
    print 1000
