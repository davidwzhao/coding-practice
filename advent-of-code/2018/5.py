f = open("5.in")

ll = f.readline().rstrip()
print(len(ll))

l = []
lens = []
for c in range(ord('a'), ord('z') + 1):
    l = list(ll)
    cc = chr(c)

    print(cc)

    l = [x for x in l if x != cc and x != cc.upper()]

    start = []
    while start != l:
        start = l.copy()
        pos = []

        for i in range(len(l) - 1):
            if i >= len(l) - 1:
                break
            if l[i] != l[i+1] and l[i].upper() == l[i+1].upper():
                # print(l[i:i+2])
                del l[i:i+2]
                i -= 1

    print(''.join(l))
    print(len(l))
    lens.append(len(l))

print(min(lens))
