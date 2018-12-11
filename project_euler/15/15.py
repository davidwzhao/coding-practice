n = 20

M = [[0 for i in range(n)] for i in range(n)]

M[0] = [i + 2 for i in range(n)]
for i in range(1, n):
    M[i][0] = i + 2

for i in range(1, n):
    for j in range(1, n):
        M[i][j] = M[i-1][j] + M[i][j-1]

print(M)
