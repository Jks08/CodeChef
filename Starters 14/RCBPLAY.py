a = int(input())
while(a):
    x,y,z = map(int,input().split())
    if(z*2>=(y-x)):
        print("yes")
    else:
        print("no")
    a-=1
