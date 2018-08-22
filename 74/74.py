def solution(line):
  a = [int(x) for x in line.split(',')]
  n = a[0]
  k = a[1]
  m = a[2]

  if k < m:
    return 0

  t = (k-m)/8
  if t%2:
    return 0
  else:
    return 1

if __name__ == '__main__':
    line = raw_input()
    print solution(line);
