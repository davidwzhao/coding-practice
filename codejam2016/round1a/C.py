T = int(input())

for i in range(T):
    n = int(input())

    adj = [[] for j in range(n+1)]

    bff = [int(x) for x in input().split(' ')]

    for j in range(len(bff)):
        adj[j+1].append(bff[j])
        # adj[bff[j]].append(j+1)

    maxl = 0

    # dfs
    for s in range(1, len(adj)):
        seen = [False for j in range(n+1)]

        l = 0
        curl = 1
        st = [s]

        while len(st) > 0:
            cur = st.pop()
            seen[cur] = True

            add = False
            for a in adj[cur]:
                if not seen[a]:
                    add = True
                    st.append(a)

            if add:
                curl += 1
            else:
                if curl > l:
                    l = curl
                curl -= 1

        if l > maxl:
            maxl = l

    print("Case #" + str(i+1) + ": ", end = '')
    print(maxl)
