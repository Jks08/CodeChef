for _ in range(int(input())):
    a=int(input())# cook your dish here
    if(a%2==0):
        n=[-1]*a
        for i in range(a):
            print(*n)
    else:
        for i in range(a):
            for j in range(a):
                if(i==j):
                    print(-1,end=" ")
                else:
                    print(1,end=" ")
            print()
#The Grid fill problem solution.