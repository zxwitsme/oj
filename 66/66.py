def solution(line):
    n=int(line)
    a=[0 for x in range(n)]
    a[0]=1
    a[1]=2
    j=1
    h=2
    for i in range(1,n):
        r=min(j+a[i],n)
        for k in range(j,r):
            a[k]=h
        j=j+a[i]
        h=3-h
        if j>=n:
            break
    ans=0
    for i in range(n):
        if a[i]==1:
            ans+=1
    return str(ans)
