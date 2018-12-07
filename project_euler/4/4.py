def palin(i):
    s = str(i)
    for i in range(0, (len(s) / 2)):
        if s[i] != s[len(s) - i - 1]:
            return False
    return True

for i in range(900, 1000):
    for j in range(900, 1000):
        if palin(i * j):
            print i, "*", j, (i * j)
            break
