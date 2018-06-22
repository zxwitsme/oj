
def solution(line):
    a=[x for x in line.split(':')]

    m = int(a[1])
    s = int(a[2])
    h_s = [int(x) for x in a[0].split('d')]
    gone = h_s[0] * 24
    if h_s[1] == m:
      gone += h_s[1]
      if s == 59:
        gone += 1
    elif h_s[1] <= m:
      gone += h_s[1] + 1
    else:
      gone += h_s[1]

    total = ((h_s[0] * 24 + h_s[1]) * 60 + m) * 60 + s

    total -= gone

    day = 24 * 60 * 60
    hour = 60 * 60
    minute = 60

    h_s[0] = total / day
    total %= day
    h_s[1] = total / hour
    total %= hour
    m = total / minute
    total %= minute
    s = total

    return "%d"%(h_s[0]) + 'd' +  "%02d"%(h_s[1]) + ':' + "%02d"%(m) + ':' + "%02d"%(s)

if __name__ == '__main__':
    y = raw_input()
    print(solution(y))

