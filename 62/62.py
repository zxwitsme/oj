def solution(line):
    a = list(line)
    l = len(a)
    switch = 0

    for i in range(l):
        if a[i] == '1':
            a[i] = '0'
            switch += 1
            s = i + 1 + i + 1
            while s <= l:
                if (a[s-1] == '0'):
                    a[s-1] = '1'
                else:
                    a[s-1] = '0'
                s += i + 1;

    return switch

if __name__ == '__main__':
    y = raw_input()
    print(solution(y))

