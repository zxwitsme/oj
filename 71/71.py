def solution(line):
    a = [int(x) for x in line.split(';')[1].split(',')]
    s = int(line.split(';')[0])
    l = len(a)

    for y in range(l):
        for x in range(l-y):
            if sum(a[x:x+y+1])>=s:
                    return y+1
    return 0

if __name__ == '__main__':
    line = raw_input()
    print solution(line);
