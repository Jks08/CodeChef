import sys
sys.setrecursionlimit(10**8)
for _ in range(int(input())):
    s=input()
    dic={}
    def do(ini,s):
        idx,maxx,minn,sign=ini+1,0,0,True
        while s[idx]!=')':
            char = s[idx]
            if(char=='?'):
                if sign:maxx+=1
                else:minn+=1
            elif char=='+':sign=True
            elif char=='-':sign=False
            elif char=='(':
                arr=do(idx,s)
                if sign:
                    maxx+=arr[0]
                    minn+=arr[1]
                else:
                    maxx+=arr[1]
                    minn+=arr[0]
                idx=arr[2]
            idx+=1
        dic[ini]=maxx
        return [maxx,minn,idx]
    do(0,s)
    
    ques=int(input())
    ans=[]
    for _ in range(ques):
        ini,fin=map(int,input().split())
        if ini==fin:ans.append(1)
        else: ans.append(dic[ini-1])
    print(*ans)
