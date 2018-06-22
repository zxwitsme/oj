
def solution(line):
    a, b = line.strip().split()
    return str(int(a) + int(b))

if __name__ == '__main__':
    y = raw_input()
    print(solution(y));
