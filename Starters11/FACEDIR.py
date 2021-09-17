a = int(input())# cook your dish here
while(a):
    b=int(input())
    rem=b%4
    if(rem==0):
        print("North")
    elif(rem==1):
        print("East")
    elif(rem==2):
        print("South")
    elif(rem==3):
        print("West")
    a-=1
