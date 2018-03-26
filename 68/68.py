def solution(line):
    a=[int(x) for x in line.split(',')]
    n=len(a)
    a.sort()
    i=0
    while i<n:
        if i<n-1 and a[i]!=a[i+1]:
            return a[i]
        i+=3
    return a[n-1]
