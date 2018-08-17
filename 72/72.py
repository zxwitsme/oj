def calc(x,y):
  result = 0;
  tmp = 1;
  for z in range(y):
   result += x*tmp
   tmp *= 10
  return result

def solution(line):
  l = len(line)
  left = int(line)
  num = range(l)

  for x in range(l):
    sum = 0
    for y in range(9, -1, -1):
      tmp = calc(y, l-x)
      if left - tmp >= 0:
          sum += tmp
          num[x] = y;
          break;
    left -= sum;

  if left != 0:
    return -1;

  input = 0
  tmp = 1
  for x in range(l):
    input += num[l-1-x] * tmp
    tmp *= 10

  return input

if __name__ == '__main__':
    line = raw_input()
    print solution(line)

