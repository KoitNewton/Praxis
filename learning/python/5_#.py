theBoard = {'1-1': ' ', '1-2': ' ', '1-3': ' ',
            '2-1': ' ', '2-2': ' ', '2-3': ' ',
            '3-1': ' ', '3-2': ' ', '3-3': ' '}
def printBoard(board):
    print(board['1-1'] + '|' + board['1-2'] + '|' + board['1-3'])
    print('-+-+-')
    print(board['2-1'] + '|' + board['2-2'] + '|' + board['2-3'])
    print('-+-+-')
    print(board['3-1'] + '|' + board['3-2'] + '|' + board['3-3'])
print(theBoard.keys())
turn = 'X'
over = 0
for i in range(9): 
    print('Step '+str(i+1))
    if(turn == 'X'):
        print('P1ayer1 choose your move:')
    else:
        print('P1ayer2 choose your move:')
    printBoard(theBoard)
    print('Turn for ' + turn + '. Move on which space?')
    move = input()
    while(theBoard[move] != ' '): 
        print('That space is already taken. choose another one.')
        move = input()

    theBoard[move] = turn
    if turn == 'X':                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              
        turn = 'O'
    else:
        turn = 'X'
    printBoard(theBoard)
    if(theBoard['1-1'] == theBoard['1-2']==theBoard['1-3']):
        if(theBoard['1-1']=='X'):
            print('Player 1 wins!')
            break
        elif(theBoard['1-1']=='O'):
            print('Player 2 wins!')
            break
    elif(theBoard['2-1'] == theBoard['2-2']==theBoard['2-3']):
        if(theBoard['2-1']=='X'):
            print('Player 1 wins!')
            break
        elif(theBoard['2-1']=='O'):
            print('Player 2 wins!')
            break    
    elif(theBoard['3-1'] == theBoard['3-2']==theBoard['3-3']):
        if(theBoard['3-1']=='X'):
            print('Player 1 wins!')
            break
        elif(theBoard['3-1']=='O'):
            print('Player 2 wins!')
            break 
    elif(theBoard['1-1'] == theBoard['2-1']==theBoard['3-1']):
        if(theBoard['3-1']=='X'):
            print('Player 1 wins!')
            break
        elif(theBoard['3-1']=='O'):
            print('Player 2 wins!')
            break   
    elif(theBoard['1-2'] == theBoard['2-2']==theBoard['3-2']):
        if(theBoard['1-2']=='X'):
            print('Player 1 wins!')
            break
        elif(theBoard['1-2']=='O'):
            print('Player 2 wins!')
            break  
    elif(theBoard['1-3'] == theBoard['2-3']==theBoard['3-3']):
        if(theBoard['1-3']=='X'):
            print('Player 1 wins!')
            break
        elif(theBoard['1-3']=='O'):
            print('Player 2 wins!')
            break 
    elif(theBoard['1-1'] == theBoard['2-2']==theBoard['3-3']):
        if(theBoard['2-2']=='X'):
            print('Player 1 wins!')
            break
        elif(theBoard['2-2']=='O'):
            print('Player 2 wins!')
            break 
    elif(theBoard['1-3'] == theBoard['2-2']==theBoard['3-1']):
        if(theBoard['2-2']=='X'):
            print('Player 1 wins!')
            break
        elif(theBoard['2-2']=='O'):
            print('Player 2 wins!')
            break 
    else:
        if(i==8):
            print('Tie!')
        else:
            continue
