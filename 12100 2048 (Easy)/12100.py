def next_generation(board, n):
    board_right = [[0 for i in range(n)] for i in range(n)]

    for i in range(n):
        buf = 0
        index = 0
        for j in board[i][::-1]:
            if j == buf and j != 0:
                board_right[i][n - 1 - index] = j + buf
                buf = 0
                index += 1
            else:
                board_right[i][n - 1 - index] = buf            
                buf = j
                index += 1

    return board_right

n = int(input())

