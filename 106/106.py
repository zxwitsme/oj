def solution(line):
    n = line.split(';')[0]
    v = [int(x) for x in line.split(';')[1].split(' ')]
    m = int(line.split(';')[2])

    for i in range(m):
      s = [int(x) for x in line.split(';')[3+i].split(' ')]
      r = 0
      for j in range(s[0],s[1]):
        if (v[j] < v[s[2]]):
              r += 1
      if (i == 0):
        result = str(r)
      else:
        result = result + ' ' + str(r)
    return result

if __name__ == '__main__':
    y = raw_input()
    print(solution(y))

