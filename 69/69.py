def solution(line):
    a=[int(x) for x in line.split(';')[0].split(',')]
    b=[int(x) for x in line.split(';')[1].split(',')]
    a.sort(reverse=True)
    b.sort(reverse=True)
    l1=len(a)
    l2=len(b)
    j=0
    for i in range(l1):
        if j>=l2 or b[j]<a[i]:
            continue
        j+=1
    if j*2>l1:
        return '1'
    else:
        return '0'

if __name__ == '__main__':
    y = raw_input()
    print(solution(y))

