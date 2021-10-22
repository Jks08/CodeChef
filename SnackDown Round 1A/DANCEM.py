a = int(input())
while(a):
    count=0
    b,c = map(int,input().split())
    while(b!=c):
        if(b<c):
            b+=2
            count+=1
        if(b>c):
            b-=1
            count+=1
    a-=1
    print(count)
        
