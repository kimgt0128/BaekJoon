import sys
input = sys.stdin.readline

n = int(input())
arr = list(map(int, input().split()))
dat = [[val, -1] for val in arr]
sta = []

for i in range(n):
    cur = arr[i]
    # 오큰수 처리
    while sta and dat[sta[-1]][0] < cur:
        dat[sta[-1]][1] = cur
        sta.pop()
    sta.append(i)

print(' '.join(str(dat[i][1]) for i in range(n)))
