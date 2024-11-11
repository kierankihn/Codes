import sys

cnt = []

def solve(A, B):
    a = 0
    b = 0
    for i in range(9, 0, -1):
        if cnt[i] != 0:
            A -= 1
            cnt[i] -= 1
            a += i * (10 ** A)
            break

    for i in range(9, 0, -1):
        if cnt[i] != 0:
            B -= 1
            cnt[i] -= 1
            b += i * (10 ** B)
            break

    for i in range(9, 0, -1):
        for _ in range(1, cnt[i] + 1):
            if A == 0:
                B -= 1
                b += i * (10 ** B)
                continue
            if B == 0:
                A -= 1
                a += i * (10 ** A)
                continue
            if b * i * (10 ** (A - 1)) >= a * i * (10 ** (B - 1)):
                A -= 1
                a += i * (10 ** A)
            else:
                B -= 1
                b += i * (10 ** B)
    
    return a * b

sys.stdin = open("math.in", 'r')
sys.stdout = open("math.out", "w")

t = int(input())
for i in range(1, t + 1):
    A, B = map(int, input().split())

    if A > B:
        C = A
        A = B
        B = C

    cnt = [0] + list(map(int, input().split()))

    print(solve(A, B))