def solution(line):
    a = [int(x) for x in line.split(',')]
    l = len(a)
    b = [1 for x in range(l)]

    for y in range(l):
        for x in range(l):
            if x-1>=0 and a[x]>a[x-1]:
                if b[x] <= b[x-1]:
                    b[x] = b[x-1]+1
            if x+1<=l-1 and a[x]>a[x+1]:
                if b[x] <= b[x+1]:
                    b[x] = b[x+1]+1
    return sum(b)


if __name__ == '__main__':
    line = raw_input()
    print solution(line);
