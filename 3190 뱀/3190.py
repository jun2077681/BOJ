from collections import deque


def change_direction(cur, lr):
    if lr == 'D':
        if cur[1] == 0:
            cur[0], cur[1] = cur[1], -cur[0]
        else:
            cur[0], cur[1] = cur[1], cur[0]

    if lr == 'L':
        if cur[0] == 0:
            cur[0], cur[1] = -cur[1], cur[0]
        else:
            cur[0], cur[1] = cur[1], cur[0]


n = int(input())
k = int(input())
board = [[0 for _ in range(n)] for _ in range(n)]
board[0][0] = 1
head = [0, 0]
snake = deque([(0, 0)])
direction = [1, 0]
second = 0

# 사과
for i in range(k):
    x1, y1 = map(int, input().split())
    board[x1 - 1][y1 - 1] = 2

l = int(input())

change_direction_list = deque()
for i in range(l):
    x, c = input().split()
    x = int(x)
    change_direction_list.append((x, c))

while True:
    dx, dy = (head[0] + direction[0], head[1] + direction[1])
    if dx >= n or dy >= n or dx < 0 or dy < 0:
        break
    if board[dx][dy] == 1:
        break

    snake.appendleft((dx, dy))
    if board[dx][dy] != 2:
        tail = snake.pop()
        board[tail[0]][tail[1]] = 0

    board[dx][dy] = 1

    if change_direction_list[0][0] == second:
        change_direction(direction, change_direction_list[0][1])
        change_direction_list.popleft()

    second += 1

print(second)
