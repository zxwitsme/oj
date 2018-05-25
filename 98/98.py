def solution(line):
    a=[int(x) for x in line.split(' ')]
    a.sort(reverse=False)
    l = len(a)
    m = l
    max = 0
    for i in range(l):
        if a[i] * m > max:
            max = a[i] * m
        m -= 1
    return max

if __name__ == '__main__':
    y = raw_input()
    print(solution(y))

