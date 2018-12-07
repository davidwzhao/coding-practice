import math

stirling = [[None for i in xrange(3000)] for j in xrange(3000)]
stirling[0][0] = 1
for i in xrange(1, 3000):
    stirling[i][0] = 0
    stirling[i][1] = 1
    stirling[i][i] = 1

for n in xrange(3, 3000):
    for k in xrange(2, 3000):
        if k >= n:
            continue
        else:
            stirling[n][k] = (k * stirling[n - 1][k]) + stirling[n - 1][k - 1]

for i in xrange(10):
    print stirling[i][:10]

print "done"

i = 1
while True:
    p = 0
    for j in xrange(i + 1):
        p += stirling[i][j]

    # print p

    if p % 1000000 == 0:
        break

    i += 1

print i
