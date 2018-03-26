def solution(line):
    a=[int(x) for x in line.split(',')]
    n=len(a)
    b=[0 for x in range(n)]
    now=0
    i=1
    while i<n:
        if a[i]>a[i-1]:
            now+=1
        else:
            now=0
        b[i]=now
        i+=1
    now=0
    i=n-2
    while i>=0:
        if a[i]>a[i+1]:
            now+=1
            now=max(now,b[i])
            b[i]=now
        else:
            now=0
        i-=1
    ans=0
    for x in b:
        ans+=x
    return str(ans+n)
