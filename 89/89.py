def solution(line):
    n = int(line)
    m = 0;
    while n >= 5:
        m += n/5
        n /= 5

    return m

if __name__ == '__main__':
    y = raw_input()
    print(solution(y))

