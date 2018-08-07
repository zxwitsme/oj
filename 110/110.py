def solution(line):
    n = [str(x) for x in line.split(' ')]
    idata = n[0]
    l = len(idata)
    f = 1;
    mid = 0
    for i in range(l):
      if (idata[l-1-i] >= '0' and idata[l-1-i] <= '9'):
        mid += f * (ord(idata[l-1-i]) - ord('0'))
      elif (idata[l-1-i] >= 'a' and idata[l-1-i] <= 'f'):
        mid += f * (10 + ord(idata[l-1-i]) -ord('a'))
      f *= int(n[1])

    odata = []
    while True:
      d = int(n[2])
      odata.append(mid%d)
      if (mid/d == 0):
        break;
      mid /= d

    output = ""
    l = len(odata)
    for i in range(l):
      if (odata[l-1-i] >= 0 and odata[l-1-i] <= 9):
        output = output + str(odata[l-1-i])
      elif (odata[l-1-i] >= 10 and odata[l-1-i] <= 15):
        output = output + chr(ord('a') + (odata[l-1-i] - 10))

    return output

if __name__ == '__main__':
    y = raw_input()
    print(solution(y))

