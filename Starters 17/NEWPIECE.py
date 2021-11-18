a = int(input())
while(a):
    b,c,d,e=map(int,input().split())
    res = abs(b-d)+abs(c-e)
    if res:
        if res%2==0:
            print(2)
        else:
            print(1)
    else:
        print(0)
    a-=1
