sums = [1 for x in xrange(30000)]

def divsum():
    sums[0] = 0
    sums[1] = 0
    sums[2] = 1
    i = 2
    while i < 30000:
        for j in xrange(i + i, 30000, i):
            sums[j] += i
        i += 1

divsum()

abundant = []
for i in xrange(30000):
    if sums[i] > i:
        abundant.append(i)

possibilities = []
for i in xrange(len(abundant)):
    for j in xrange(i, len(abundant)):
        possibilities.append(abundant[i] + abundant[j])

possibilites = sorted(list(set(possibilities)))

sum = 0
x = 0
for i in xrange(1, 30000):
    if i == possibilites[x]:
        x += 1
        continue
    sum += i

print sum
