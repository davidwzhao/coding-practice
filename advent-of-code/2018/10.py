import numpy as np
import matplotlib.pyplot as plt
import matplotlib.animation as ani
import re

f = open("10.in")

line_parse = re.compile("position=<\s*(-?\d+),\s*(-?\d+)> velocity=<\s*(-?\d+),\s*(-?\d+)>")

xs = []
ys = []
vels = []

fig = plt.figure()
plt.xlim(0, 300)
plt.ylim(-300, 300)

for line in f.readlines():
    l = line_parse.match(line)

    dx = int(l.group(3))
    dy = int(l.group(4))
    vels.append((dx, dy))

    x = int(l.group(1))
    xs.append(x + dx * 10110)
    y = int(l.group(2))
    ys.append((-1) * (y + dy * 10110))

ln = plt.scatter(xs, ys)

def update(frame):
    for i in range(len(xs)):
        xs[i] += vels[i][0]
        ys[i] += (-1) * vels[i][1]
    ln.set_offsets(np.array([xs, ys]).T)
    return ln,

a = ani.FuncAnimation(fig, update, frames=int(1000), interval=1000, blit=True)
plt.show()
