def solution(line):
  a = [int(x) for x in line.split(' ')]
  l = a[0]
  g = a[1]

  r1 = g - (100 + l * 10)
  r2 = g * ( 1 - 0.45)

  r1 = r1 / (602.0 + r1)
  r2 = r2 / (602.0 + r2)
  m = (100 + 85) * (1-r1)
  n = (100 + 80) * (1-r2)

  if (m > n):
    return "axe"
  elif (m < n):
    return "bow"
  else:
    return "same"

if __name__ == '__main__':
    line = raw_input()
    print solution(line);
