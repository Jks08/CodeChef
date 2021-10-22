def gcd(a,b):
    if(b==0):
        return a
    return gcd(b,a%b)
def lcm(a,b):
    return (a//gcd(a,b))*b
t = int(input())
while(t):
    count=0
    b,c=map(int,input().split())
    up =b*c
    print(lcm(b,2*b),"",lcm(up-1,up))
    t-=1
