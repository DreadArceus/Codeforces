def shovel(a,b):
    return min(a,b,(a+b)//4)


t=int(input())
for i in range(t):
    a,b=map(int,input().strip().split())
    print(shovel(a,b))