a = int(input())
while(a):
    t=0
    n,p,x,y=map(int,input().split())
    arr = list(map(int,input().split()))
    for i in range(p):
        if(arr[i]==0):
            t+=x
        if(arr[i]==1):
            t+=y
    print(t)
    a-=1
