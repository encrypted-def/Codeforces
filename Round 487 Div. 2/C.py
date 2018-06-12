import sys
A,B,C,D = map(int,input().split())
board = [['A']*50 for i in range(33)]
for i in range(24,33):
  for j in range(50):
    board[i][j] ='B'

A -= 1
for i in range(1,24,2):
  for j in range(1,50,2):
    # B는 1개 남겨두기
    if B > 1:
      board[i][j] = 'B'
      B -= 1
    elif C > 0:
      board[i][j] = 'C'
      C -= 1
    elif D > 0:
      board[i][j] = 'D'
      D -= 1
board[23][49] = 'B'
for i in range(25,33,2):
  for j in range(1,50,2):
    if A > 0:
      board[i][j] = 'A'
      A -= 1
sys.stdout.write("33 50\n")
for i in range(33):
  sys.stdout.write(''.join(board[i]))
  if i != 32:
    sys.stdout.write('\n')
