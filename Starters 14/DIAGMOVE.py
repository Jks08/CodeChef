a = int(input())
while(a):
    x,y=map(int,input().split())
    s = x+y
    if(s%2==0):
        print("yes")
    else:
        print("no")
    a-=1
