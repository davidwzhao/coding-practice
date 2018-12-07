dam = 0
num_c = 0

def swap_last_c(s):
    global dam, num_c
    c_passed = 0
    for i in range(len(s) - 1, -1, -1):
        if s[i] == 'C':
            if i == len(s) - 1:
                c_passed += 1
                continue
            if s[i+1] == 'S':
                l = list(s)
                l[i], l[i+1] = l[i+1], l[i]
                s = ''.join(l)
#                 print("num c: ", num_c, "passed c: ", c_passed)

                dam -= ((2 ** (num_c - c_passed)) - (2 ** (num_c - c_passed - 1)))
#                 print(dam)
                return s
            c_passed += 1
    return False

def init(s):
    global dam, num_c
    cur = 1
    for c in s:
        if c == 'C':
            cur *= 2
            num_c += 1
        elif c == 'S':
            dam += cur

t = int(input())

for i in range(t):
    dam = 0
    num_c = 0
    inp = input()
    d, s = inp.split()
    d = int(d)

    init(s)

#     print(dam)

    # find last C with S following
    it = 0
    imp = False
    while (dam > d):
        s = swap_last_c(s)
        if not s:
            imp = True
            break
        it += 1

    if imp:
        print("Case #" + str(i+1) + ": IMPOSSIBLE")
    else:
        print("Case #" + str(i+1) + ": " +  str(it))

