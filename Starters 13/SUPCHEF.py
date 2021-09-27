a = int(input())
while(a):
    b,c,d = map(int,input().split())
    if((c*d)<b):
        print("YES")
    else:
        print("NO")
    a-=1
