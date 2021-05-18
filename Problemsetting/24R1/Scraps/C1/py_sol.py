from math import gcd
def brute(a,b):
    for i in range(1,a+b):
        for j in range(1,a+b):
            if (i+j)==(a+b) and i!=a and b!=j and gcd(i,j)==1:
                return i,j
    return -1,''



for i in range(int(input())):
    a,b=map(int,input().strip().split())
    print(*brute(a,b))