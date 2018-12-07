f = open("8.in", "r")
s = f.read()

tot = 1
max = 0
for i in range(0, 13):
    tot = tot * int(s[i])

for i in range(13, len(s) - 1):
    if int(s[i - 13]) == 0:
        tot = 1
        for j in range(i - 12, i + 1):
            tot = tot * int(s[j])
    else:
        tot = tot * int(s[i])
        tot = tot / int(s[i - 13])

    if tot > max:
        max = tot

print max
f.close()
