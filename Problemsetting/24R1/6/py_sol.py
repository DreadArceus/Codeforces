I=lambda:map(int,input().split())
_,x=I()
*C,=I()
A=[1]+[0]*7**8
for c in C:
 for i in range(x):
  A[i+c]+=A[i]
  A[i+c]%=10**9+7
print(A[x])