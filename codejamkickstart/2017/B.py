import math

t = int(input())

def wmed(l, w):
    p = []
    for (ll, ww) in zip(l, w):
        p += [ll] * int(ww)
    p.sort()

    return p[len(p) // 2]


for i in range(t):
    n = int(input())

    x = []
    y = []
    w = []

    for j in range(n):
        xx, yy, ww = list(map(float, input().split()))
        x.append(xx)
        y.append(yy)
        w.append(ww)


    xx = wmed(x, w)
    yy = wmed(y, w)

    dist = 0.0
    for j in range(n):
        dist += w[j] * max(abs(xx - x[j]), abs(yy - y[j]))

    print("Case #" + str(i + 1) + ": " + str(dist))


