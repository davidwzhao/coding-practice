serial = 7989
n = 300

grid = [[0 for i in range(n+1)] for j in range(n+1)]

for x in range(1, n+1):
    for y in range(1, n+1):
        rack_id = x + 10
        power = (y) * rack_id
        power += serial
        power *= rack_id
        power = (power // 100) % 10
        power -= 5
        grid[x][y] = power

sizes = []

for size in range(1, 300):
    max_total = sum([sum(x[1:1 + size]) for x in grid[1:1 + size]])
    max_total_x = 1
    max_total_y = 1

    tot = max_total

    for y in range(1, n - size + 1):
        if y != 1:
            tot = sum([sum(x[y:y+size]) for x in grid[1:1 + size]])

            # for l in grid[1:4]:
            #     print(l[y:y+3])
            # print(tot)

            if tot > max_total:
                max_total = tot
                max_total_x = 1
                max_total_y = y

        for x in range(2, n - size + 2):
            minus = sum(grid[x-1][y:y+size])
            plus = sum(grid[x+size - 1][y:y+size])
            tot = tot - minus + plus

            # for l in grid[x:x+3]:
            #     print(l[y:y+3])
            # print(minus, plus, tot)

            if tot > max_total:
                max_total = tot
                max_total_x = x
                max_total_y = y

    sizes.append((max_total, max_total_x, max_total_y, size))

print(max(sizes, key=lambda x:x[0]))
