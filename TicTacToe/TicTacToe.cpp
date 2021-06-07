#include "TicTacToe.h"
#include <iostream>
#include <limits>

using namespace std;

void TicTacToe::boardView(){
    cout << "1 | 2 | 3" << endl;
    cout << "---------" << endl;
    cout << "4 | 5 | 6" << endl;
    cout << "---------" << endl;
    cout << "7 | 8 | 9" << endl;
    cout << "When choosing a square, pick a number between 1 and 9 if it's available." << endl << endl;
}

void TicTacToe::updateBoard(){
    cout << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
    cout << "---------" << endl;
    cout << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
    cout << "---------" << endl;
    cout << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl << endl;
}

void TicTacToe::playerMove(){
    int space;
    cout << endl << "Enter which space you want to play: ";
    cin >> space;

    if(space >= 1 && space <= 9){
        if(space <= 3){
            board[0][space-1] = 'O';
        }else if(space <= 6){
            board[1][space-4] = 'O';
        }else{
            board[2][space-7] = 'O';
        }
    }
}

void TicTacToe::findingMove(){
    int bestScore = numeric_limits<int>::min();
    int bestMove[2] = {};

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(board[i][j] == '\0'){
                board[i][j] = ai;
                int score = minimax(board, 0, false);
                board[i][j] = '\0';
                if(score > bestScore){
                    bestScore = score;
                    bestMove[0] = i;
                    bestMove[1] = j;
                }
            }
        }
    }
    board[bestMove[0]][bestMove[1]] = 'X';
}

int TicTacToe::minimax(char board[][3], int depth, bool isMaximum){
    int winner = checkForWin(board);

    if(winner != 0){
        return winner-depth;
    }

    if(isMaximum){
        int bestScore = numeric_limits<int>::min();
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                if(board[i][j] == '\0'){
                    board[i][j] = ai;
                    int score = minimax(board, depth + 1, !isMaximum);
                    bestScore = max(score, bestScore);
                    board[i][j] = '\0';
                }
            }
        }
        return bestScore;
    }else{
        int bestScore = numeric_limits<int>::max();
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                if(board[i][j] == '\0'){
                    board[i][j] = human;
                    int score = minimax(board, depth + 1, !isMaximum);
                    bestScore = min(score, bestScore);
                    board[i][j] = '\0';
                }
            }
        }
        return bestScore;
    }
}

int TicTacToe::checkForWin(char board[][3]){
    //Rows
    for(int i = 0; i < 3; i++){
        if(board[i][0] == board[i][1] && board[i][1] == board[i][2]){
            if(board[i][0] == ai){
                return 1;
            }else if(board[i][0] == human){
                return -1;
            }
        }
    }
    //Columns
    for(int i = 0; i < 3; i++){
        if(board[0][i] == board[1][i] && board[1][i] == board[2][i]){
            if(board[0][i] == ai){
                return 1;
            }else if(board[0][i] == human){
                return -1;
            }
        }
    }
    //Diagonals
    if(board[0][0] == board[1][1] && board[1][1] == board[2][2]){
        if(board[0][0] == ai){
            return 1;
        }else if(board[0][0] == human){
            return -1;
        }
    }

    if(board[0][2] == board[1][1] && board[1][1] == board[2][0]){
        if(board[0][2] == ai){
            return 1;
        }else if(board[0][2] == human){
            return -1;
        }
    }

    return 0;
}
