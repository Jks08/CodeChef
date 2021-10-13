from collections import defaultdict
T = int(input())
for t in range(T):
    n = int(input())
    s = list(map(int, list(input())))
    p=0
    d=defaultdict(int)
    d1=defaultdict(int)
    for i in range(n):
        d[s[i]+i] += 1
        d1[s[i]-i] += 1
    m1, m2 = 0,0
    for v in d.values():
        m1 += (v*(v-1)//2)
    for v in d1.values():
        m2 += (v*(v-1)//2)
    print(m1+m2)
