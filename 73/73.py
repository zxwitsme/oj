def solution(line):
  l = len(line)
  result = 0
  count = 0
  for i in range(l):
    if line[i] == '?':
      count += 1
    else:
      if i > 0:
        if line[i-1] != '?' and line[i] == line[i-1]:
          result += 1
      if count == 0:
        continue
      if count%2 == 0 and i-count-1 >= 0:
        if line[i-count-1] == line[i]:
          result += 1
      elif i-count-1 >= 0:
        if line[i-count-1] != line[i]:
          result += 1
      count = 0

  return result

if __name__ == '__main__':
    y = raw_input()
    print(solution(y))

