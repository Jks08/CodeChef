def find(n):
    cnt = 0
    while n > 0 and n % 2 != 1:
        cnt += 1
        n //= 2        
    return cnt
    
for _ in range(int(input())):
    n = int(input())
    l = list(map(int, input().split()))
    e = 0
    o = 0
    m = 1000000000
    for i in l:
        if i % 2 == 1: o += 1
        else:
            m = min(m, find(i))
            e += 1    
    if o == 0: print(m)
    else: print(0)
