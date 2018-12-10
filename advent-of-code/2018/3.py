import re

claim_pattern = re.compile("#(\d+) @ (\d+),(\d+): (\d+)x(\d+)")
f = open("3.in")

claims = []
grid = [[0 for i in range(1000)] for j in range(1000)]

for line in f.readlines():
    match = claim_pattern.match(line)

    num = int(match.group(1))
    left = int(match.group(2))
    top = int(match.group(3))
    width = int(match.group(4))
    height = int(match.group(5))

    claims.append((num, left, top, width, height))

    for i in range(left, width + left):
        for j in range(top, height + top):
            grid[i][j] += 1

count = 0
for i in range(1000):
    for j in range(1000):
        if grid[i][j] > 1:
            count += 1

print(count)

for c in claims:
    found = True
    for i in range(c[1], c[3] + c[1]):
        for j in range(c[2], c[4] + c[2]):
            if grid[i][j] > 1:
                found = False
                continue
        if not found:
            continue

    if found:
        print(c[0])
        break
