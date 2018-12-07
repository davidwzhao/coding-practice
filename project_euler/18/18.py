f = open("18.in")
lines = f.readlines()
array = [[int(x) for x in line.split()] for line in lines]

paths = [None for i in xrange(15)]
paths[0] = [array[0][0]]

i = 0
for i in xrange(1, 15):
    paths[i] = [None for x in xrange(i+1)]
    paths[i][0] = paths[i-1][0] + array[i][0]
    for j in xrange(1, i):
        paths[i][j] = max(paths[i-1][j-1], paths[i-1][j]) + array[i][j]
    paths[i][i] = paths[i-1][i-1] + array[i][i]

print max(paths[14])
