a = int(input())
while(a):
    counti = 0
    counte = 0
    b = input()
    for i in b:
        if(i=='1'):
            counti+=1
        elif(i=='2'):
            counte+=1
        elif(i=='0'):
            counte+=1
            counti+=1
    if(counti>counte):
        print("INDIA")
    elif(counte>counti):
        print("ENGLAND")
    else:
        print("DRAW")
    a-=1
