p = [True for j in xrange(2000000)]

def primes():
    i = 2
    while i < 2000000:
        for j in xrange(i + i, 2000000, i):
            p[j] = False
        for j in xrange(i + 1, 2000000):
            if p[j]:
                i = j - 1
                break
        i = i + 1

# for i in range(0, 2000000):
#     p[i] = True

primes()

sum = 0
for i in xrange(2, 2000000):
    if p[i]:
        sum = sum + i

print sum
