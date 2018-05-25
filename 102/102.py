def solution(line):
    while line.find('mi') >= 0:
        line = line.replace('mi', '');
    return line

if __name__ == '__main__':
    y = raw_input()
    print(solution(y))

