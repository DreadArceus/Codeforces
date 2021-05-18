from sys import  stdin
input=stdin.readline
def mst(edges,n):
    tree_id=[i for i in range(0,n+1)]
    edges=sorted(edges,key=lambda s:s[2],reverse=True)
    cost=0
    result=[]
    for edge in edges:
        if tree_id[edge[0]]!=tree_id[edge[1]]:
            cost+=edge[2]
            result.append(edge)
            oldid=tree_id[edge[0]]
            newid=tree_id[edge[1]]
            for i in range(1,n+1):
                if tree_id[i]==oldid:
                    tree_id[i]=newid
    ans=1
    for i in result:
        ans=(ans*i[2])%(10**9+7)
    return ans



n,m=map(int,input().strip().split())
g=[]
for i in range(m):
    lst=list(map(int,input().strip().split()))
    g.append(lst)
print(mst(g,n))