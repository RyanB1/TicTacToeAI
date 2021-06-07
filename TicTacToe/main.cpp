#include <iostream>
#include "TicTacToe.h"

using namespace std;

int main(){
    TicTacToe game;
    int aiMoves = 0;

    game.boardView();

    while(true){
        cout << "The AI goes: " << endl;
        game.findingMove();
        game.updateBoard();
        aiMoves++;

        if(game.check() == 1){
            cout << "X wins.\n";
            return 0;
        }else if(game.check() == -1){
            cout << "O wins.\n";
            return 0;
        }

        if(aiMoves == 5){
            break;
        }

        game.playerMove();
    }

    cout << "Tie Game\n";
    return 0;
}
