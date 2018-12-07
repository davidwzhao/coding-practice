import collections

N = int(input())

def diff(w, l):
    if len(l) == 1:
        return False
    for i in l:
        if i != w:
            return True
    return False

for i in range(N):
    print("Case #" + str(i + 1) + ": ", end="")

    m0 = collections.defaultdict(list)
    m1 = collections.defaultdict(list)

    n = int(input())

    num = 0

    lines = []
    for j in range(n):
        line = input()
        
        lines.append(line)
        words = line.split(" ")
        m0[words[0]].append(words[1])
        m1[words[1]].append(words[0])
    
    for l in lines:
        words = l.split(" ")
        if diff(words[1], m0[words[0]]) and diff(words[0], m1[words[1]]):
            num += 1

    print(num)
