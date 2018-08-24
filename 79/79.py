def solution(line):
  c = [int(x) for x in line.split(',')]
  l = len(c)

  if l == 1:
    return c[0]

  dp = range(l)
  dp[0] = c[0]
  dp[1] = max(dp[0], c[1])
  for i in range(l-2):
    dp[i+2] = max(dp[i+1], dp[i]+c[i+2])

  return dp[l-1]

if __name__ == '__main__':
    line = raw_input()
    print solution(line);
