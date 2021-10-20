a = int(input())
while(a):
    b,c,d=map(int,input().split())
    e = b-c
    if((c*3-e) >= d):
        print("PASS")
    else:
        print("FAIL")
    a-=1
