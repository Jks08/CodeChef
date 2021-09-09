x = int(input())
while(x):
    n,a,b = map(int,input().split(' '))
    s = input()
    res = s.count('0')*a + s.count('1')*b
    print(res)
    x-=1
