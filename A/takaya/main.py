#!/Users/yataka/.pyenv/shims/ python3
def main():
    X, T, S = map(int, input().split())
    N = int(input())
    List = [input() for _ in range(N)]
    ans = X
    for s in List:
        if s == "nobiro":
            ans = max(ans + T, 0)
        elif s == "tidime":
            ans = max(ans + S, 0)
        else:
            ans = 0

    print(ans)

if __name__ == '__main__':
    main()
