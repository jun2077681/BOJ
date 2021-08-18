def next_generation(board, n, t=5):
    if t == 0:
        return max([max(i) for i in board])

    ret = 0

    board_right = [[0 for i in range(n)] for i in range(n)]
    board_left = [[0 for i in range(n)] for i in range(n)]
    board_up = [[0 for i in range(n)] for i in range(n)]
    board_down = [[0 for i in range(n)] for i in range(n)]

    # right
    for i in range(n):
        index = 0
        buf = 0
        for j in board[i][::-1]:
            if j == 0:
                continue
            if j == buf:
                board_right[i][n - 1 - index] = j + buf
                index += 1
                buf = 0
            else:
                if buf == 0:
                    buf = j
                else:
                    board_right[i][n - 1 - index] = buf
                    index += 1
                    buf = j

        board_right[i][n - 1 - index] = buf

    ret = max(next_generation(board_right, n, t - 1), ret)

    # left
    for i in range(n):
        index = 0
        buf = 0
        for j in board[i]:
            if j == 0:
                continue
            if j == buf:
                board_left[i][index] = j + buf
                index += 1
                buf = 0
            else:
                if buf == 0:
                    buf = j
                else:
                    board_left[i][index] = buf
                    index += 1
                    buf = j

        board_left[i][index] = buf

    ret = max(next_generation(board_left, n, t - 1), ret)

    # up
    for i in range(n):
        index = 0
        buf = 0
        for j in [k[i] for k in board]:
            if j == 0:
                continue
            if j == buf:
                board_up[index][i] = j + buf
                index += 1
                buf = 0
            else:
                if buf == 0:
                    buf = j
                else:
                    board_up[index][i] = buf
                    index += 1
                    buf = j
        board_up[index][i] = buf

    ret = max(next_generation(board_up, n, t - 1), ret)

    # down
    for i in range(n):
        index = 0
        buf = 0
        for j in [k[i] for k in board][::-1]:
            if j == 0:
                continue
            if j == buf:
                board_down[n - 1 - index][i] = j + buf
                index += 1
                buf = 0
            else:
                if buf == 0:
                    buf = j
                else:
                    board_down[n - 1 - index][i] = buf
                    index += 1
                    buf = j
        board_down[n - 1 - index][i] = buf

    ret = max(next_generation(board_down, n, t - 1), ret)

    return ret


n = int(input())
l = []
for i in range(n):
    l.append([int(i) for i in input().split()])

print(next_generation(l, n))
