from random import randint

size = 3

if __name__ == '__main__':
    print 1
    print "{0} 100".format(size)
    for _ in xrange(2):
        print reduce(
            lambda x, y: str(x) + ' ' + str(y),
            [
                randint(10, 90) for _ in xrange(size)
            ]
        )
