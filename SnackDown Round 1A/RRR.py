t = int(input())
for i in range(t):
    b,c=map(int,input().split())
    ans = (2*b-c-1)//2
    print(2*ans)
