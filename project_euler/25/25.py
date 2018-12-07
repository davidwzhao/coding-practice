import math

f = []
f.append(0)
f.append(1)

i = 2
while True:
    f.append(f[i - 1] + f[i - 2])
    if math.log(f[i], 10) >= 999:
        break
    i += 1

# print f

print i
