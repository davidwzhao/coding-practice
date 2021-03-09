f = open("12.in")
n = 100
cur_zero = 0

def pad(s):
    global cur_zero
    while s.index('#') < 4:
        s = '.' + s
        cur_zero += 1

    while s[::-1].index('#') < 4:
        s = s + '.'

    return s

init = f.readline().rstrip()
s = list(pad(init.replace(' ', '').split(":")[1]))

# get rid of blank line
f.readline()

transforms = {}
for line in f.readlines():
    l = line.split()
    transforms[l[0]] = l[2]

print("0 : ", ''.join(s))
# print(transforms)

for j in range(n):
    # next_s = s.copy()
    next_s = ['.' for _ in s]
    for i in range(len(s) - 2):
        cur = ''.join(s[i:i+5])
        # print(cur)
        if cur in transforms:
            next_s[i+2] = transforms[cur]
        else:
            next_s[i+2] = '.'

    s = list(pad(''.join(next_s)))
    print(j + 1, ': ', ''.join(s[35:]))

    total = 0
    count = 0
    for (idx, c) in enumerate(s):
        if c == '#':
            count += 1
            total += idx - cur_zero

    print(total, count)
