a = int(input())
for i in range(a):
    b,c,d,e,f = map(int,input().split())
    if((b+c<=e) and (d<=f)):
        print("YES")
    elif((b+d<=e) and (c<=f)):
        print("YES")
    elif((d+c<=e) and (b<=f)):
        print("YES")
    else:
        print("NO")
