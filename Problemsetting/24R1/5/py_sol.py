def nearest(arr):
    stack = []
    blanck = []
    for i in range(len(arr)):
        while stack and arr[i] >= stack[-1][0]:
            stack.pop(-1)
        if stack:
            blanck.append(stack[-1][1])
        else:
            blanck.append(-1)
        stack.append([arr[i], i ])
    stack=[]
    for i in range(len(arr)-1,-1,-1):
        while stack and arr[i] >= stack[-1][0]:
            stack.pop(-1)
        if stack:
            if abs(i-stack[-1][1])<abs(i-blanck[i])or blanck[i]==-1:
                blanck[i]=stack[-1][1]
        else:
            pass
        stack.append([arr[i], i])
    print(*blanck)
    return ""


a = input()
lst = list(map(int, input().strip().split()))
print(nearest(lst))