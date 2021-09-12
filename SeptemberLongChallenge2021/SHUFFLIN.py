a = int(input())# cook your dish here
while(a):
    b = int(input())
    e=0
    o=0
    l=list(map(int,input().split()))
    for i in l:
        if(i%2==1):
            o+=1
        else:
            e+=1
    res=min(e,(b+1)//2)+min(o,(b)//2)
    print(res)
    a-=1
