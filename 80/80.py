def solution(line):
  n = int(line)
  m = n

  count1 = 0
  count2 = 0
  if n == 0 or n == 1:
    return 'Bad'

  if n == 2:
    return 'Good'

  t = 1
  while n > 1:
    n /= 2
    t *= 2
  if m == t:
    return 'Normal'
  elif t < m:
    if t+1 == m:
      count1 = 1
    if t*2-1 == m:
      count2 = 1

  if count1 == 1 and count2 == 1:
    return 'Very Good'
  elif count1 == 1:
    return 'Good'
  elif count2 == 1:
    return 'Bad'

  return 'Normal'

if __name__ == '__main__':
    line = raw_input()
    print solution(line);
