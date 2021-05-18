from collections import Counter
def f(a):
    c=Counter(a)
    mx=max(sorted(c.items(),key=lambda s:s[0]),key=lambda s:s[1])
    return mx


a=input()
print(*f(input()))