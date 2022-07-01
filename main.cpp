#include "main.hpp"


int main()
{
    TicTacToe game;




    cout<<"HI, You are going to play TicTacToe with your friend....Enjoy!\n";
    cout<<"\tI want to tell you that the board is 4x4\n";
    cout<<"\tThis will help you to choose where to play.\n";
    cout<<"\tFor example: 1st row 3rd column is: 1 3\n";
    cout<<"\tBy default, player1 plays with 'x', while player2 plays with 'o'\n\n";
    game.setNameVal();
    game.setValue();




    return 0;
}


