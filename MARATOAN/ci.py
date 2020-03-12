
n = int(input())

for j in range(1, n+1):
    n,m = input().split()

    x = input()
    y = input()

    offset = ord(y[0]) - ord(x[0])

    off = list('ABCDEFGHIJKLMNOPQRSTUVWXYZ')

    s = list(input())
    if(offset > 0):
        for i in range(len(s)):
            diff = ord(s[i]) - offset
            if(diff < 65):
                s[i] = chr(90 - (65-diff) + 1)
            else:
                s[i] = chr(diff)
    else:
        for i in range(len(s)):
            diff = ord(s[i]) - offset
            if(diff > 90):
                s[i] = chr(65 + (diff - 90) - 1)
            else:
                s[i] = chr(diff)
                
    print('Case #{}: {}'.format(j, ''.join(s) ))

