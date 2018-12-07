import itertools

f = open("1.in")

s = 0
seen = set()

for i in itertools.cycle(f.readlines()):
    s += int(i)
    if s in seen:
        print(s)
        exit()

    seen.add(s)
