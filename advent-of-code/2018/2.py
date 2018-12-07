import collections

f = open("2.in")
l = f.readlines()

counts = collections.defaultdict(int)

for box in l:
    letters = collections.defaultdict(int)

    for c in box:
        letters[c] += 1

    if 2 in letters.values():
        counts[2] += 1

    if 3 in letters.values():
        counts[3] += 1

print(counts[2] * counts[3])

for (i, box) in enumerate(l):
    for box2 in l[:i]:
        num_diff = 0
        for (x, y) in zip(box, box2):
            if x != y:
                num_diff += 1
            if num_diff > 1:
                break

        if num_diff == 1:
            print(box.rstrip())
            print(box2.rstrip())
            exit(0)
