ans=''
def find(a,b,now,n,g):
    global ans
    if now==n:
        if ans!='':
            ans+=';'
        ans+=g
        return
    if g!='':
        g+=','
    for i in range(n):
        if b[i]>0:
            continue
        b[i]=1
        find(a,b,now+1,n,g+str(a[i]))
        b[i]=0
        
def solution(line):
    a=[int(x) for x in line.split(',')]
    a.sort()
    n=len(a)
    b=[0 for x in range(n)]
    global ans
    ans=''
    find(a,b,0,n,'')
    return ans
