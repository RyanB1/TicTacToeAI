#ifndef TICTACTOE_H
#define TICTACTOE_H
#include <cstring>

class TicTacToe{
    private:
        char board[3][3];
        char ai;
        char human;

    public:
        TicTacToe(){
            memset(board, '\0', sizeof(board));
            ai = 'X';
            human = 'O';
        }

        void boardView();
        void updateBoard();
        void playerMove();
        void findingMove();
        int minimax(char [3][3], int, bool);
        int checkForWin(char [3][3]);
        int check(){ return checkForWin(board); }
};

#endif
