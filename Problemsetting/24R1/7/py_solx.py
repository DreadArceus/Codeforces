def cvowel(s):
    cnt=0
    for i in "aeiou":
        cnt+=s.count(i)
    return cnt
def f(s,q):
    s=list(s)
    for i in q:
        if i[0]=="1":
            i=list(map(int,i))
            print(cvowel(s[i[1]-1:i[2]]))
        else:
            s[int(i[1])-1]=i[2]
n=input()
s=input().strip()
q=[]
for i in range(int(input())):
    lst=list(map(str,input().strip().split()))
    q.append(lst)

f(s,q)