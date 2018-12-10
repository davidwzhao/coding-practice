import re
import collections

line_parse = re.compile("\[.*:(\d+)\] (.*)")
guard_parse = re.compile("Guard #(\d+) begins shift")
f = open("4.in")

lines = f.readlines()
lines.sort()

guards = collections.defaultdict(list)

current_guard = 0
current_sleep = 0

for line in lines:
    l = line_parse.match(line.rstrip())

    minute = int(l.group(1))
    event = l.group(2).rstrip()

    g = guard_parse.match(event)
    if g:
        current_guard = int(g.group(1))
    elif event == "falls asleep":
        current_sleep = minute
    elif event == "wakes up":
        guards[current_guard].append((current_sleep, minute))

# find most asleep guard
max_hours = 0
max_guard = 0
for (k, v) in guards.items():
    s = sum([i[0] + i[1] for i in v])
    if s > max_hours:
        max_hours = s
        max_guard = k

# find most asleep minute
mins = collections.defaultdict(int)
for (start, end) in guards[max_guard]:
    for i in range(start, end):
        mins[i] += 1
print(max_guard * max(mins, key=mins.get))

# find most asleep guard per minute
mins = collections.defaultdict((lambda: (0, 0)))
for (k, v) in guards.items():
    cur_mins = collections.defaultdict(int)
    for (start, end) in v:
        for i in range(start, end):
            cur_mins[i] += 1

    for m in cur_mins.keys():
        if cur_mins[m] > mins[m][1]:
            mins[m] = (k, cur_mins[m])

max_min = max(mins, key=(lambda i: mins[i][1]))
print(max_min * mins[max_min][0])
