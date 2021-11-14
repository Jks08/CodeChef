for _ in range(int(input())):
    a,b,c,d,e = map(int, input().split())
    p= a + (c * e)
    d = b + (d * e)
    if (p < d):
        print("PETROL")
    elif (d < p):
        print("DIESEL")
    else:
        print("SAME PRICE")# cook your dish here
