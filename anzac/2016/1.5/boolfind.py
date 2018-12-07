def bool(s):
    if s == "true":
        return True
    elif s == "false":
        return False
    else:
        return False

N = int(input())

for i in range(N):
    n = int(input())
    
    print("READ " + '1')
    out = input()
    if out == "false":
        print("OUTPUT " + '0')
        continue
    
    print("READ " + str(n - 2))
    out = input()
    if out == "true":
        print("OUTPUT " + str(n - 2))
        continue
    
    prev = True
    for j in range(2, n - 2):
        print("READ " + str(j))
        out = input()
        
        if prev and not bool(out):
            print("OUTPUT " + str(j - 1))
            break
            
        prev = bool(out)