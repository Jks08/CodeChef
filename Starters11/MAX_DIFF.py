a = int(input())# cook your dish here
while(a):
    n,s=map(int,input().split())
    if(s<=n):
        ans=s-0
    else:
        crr=s-n
        ans=n-crr
    print(ans)
    a-=1
