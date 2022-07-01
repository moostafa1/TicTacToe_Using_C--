#include <iostream>
using namespace std;

const int people = 2;
const int SIZE = 4;

class TicTacToe
{
    char gameSpace[SIZE][SIZE];
    string name[people];
    char x_o[people]; // = {'x', 'o'};
    int score[people];


public:
    TicTacToe();
    void setNameVal();
    void setValue();
    string getNameAndValue();
    int fourInRow();
    int fourInCol();
    int fourInDiagonal1();
    int fourInDiagonal2();
    int fourToWin(int z);
    void clearBoard();
    void printInfo();
    void showScore(int z);
};


TicTacToe::TicTacToe()
{
    for (int i=0; i<SIZE; i++)
    {
        for (int j=0; j<SIZE; j++)
        {
            gameSpace[i][j] = '-';
        }
    }

    for (int i=0; i<people; i++)
    {
        score[i] = 0;
    }

}



void TicTacToe::setNameVal()
{
    for (int i=0; i<people; i++)
    {
        cout << "Enter player" << i+1 << " name: ";
        cin>>name[i];
        cout << "Enter player" << i+1 << " play with (x, o, n, etc...): ";
        cin>>x_o[i];

    }
}



void TicTacToe::setValue()
{
    int x;
    int y;
    int z=0;
    int stop = 0;

    for (int i=0; i<SIZE; i++)
    {
        for (int j=0; j<SIZE; j++)
        {
            string player = name[z];
            cout << player << "'s turn " << "(" << x_o[z] << ")\n";

            cout << "Enter where you want to play (input <= "<< SIZE << "): ";
            cin>>x>>y;


            int check = 1;
            while (check)
            {
                if (gameSpace[x-1][y-1] == '-')
                {
                    gameSpace[x-1][y-1] = x_o[z];
                    check=0;
                }
                else
                {
                    cout<<"\nPlease input in an empty square.\n";
                    cout << "Enter where you want to play (input <= 4): ";
                    cin>>x>>y;
                }
            }

            cout << "\n\n";
            printInfo();

            int flag = fourToWin(z);

            if (flag == 1)
            {
                cout<<player<<" wins!\n";
                stop = 1;
                break;
            }
            else if (i==SIZE-1 && j==SIZE-1 && flag == 0)
            {
                cout<<"DRAW....\n\n";

                char again;
                cout<< "\n\nPlay again? (y\\n): ";
                cin>>again;
                if (again == 'y')
                {
                    clearBoard();
                    setValue();
                }
                else
                {
                    break;
                }
                }

            z++;
            if(z > people-1)
            {
                z=0;
            }
        }
        if (stop == 1)
        {
            char again;
            cout<< "\n\nPlay again? (y\\n): ";
            cin>>again;
            if (again == 'y')
            {
                clearBoard();
                setValue();
            }
            else
            {
                break;
            }
        }
    }
}



void TicTacToe::clearBoard()
{
    for (int i=0; i<SIZE; i++)
    {
        for (int j=0; j<SIZE; j++)
        {
            if (gameSpace[i][j] != '-')
            {
                gameSpace[i][j] = '-';
            }
        }
    }
}


int TicTacToe::fourInRow()
{
    for (int i=0; i<SIZE; i++)
    {
        int win = 0;
        int compare = 1;
        for (int j=0; j<SIZE; j++)
        {
            if (gameSpace[i][compare] != '-')
            {
                if (gameSpace[i][j] == gameSpace[i][compare])
                {
                    win++;
                    compare++;
                }

                if (compare>SIZE-1)
                {
                    compare = 1;
                }
            }
        }

        if (win==SIZE)
        {
            return true;
        }
    }
    return false;
}



int TicTacToe::fourInCol()
{
    for (int i=0; i<SIZE; i++)
    {
        int win = 0;
        int compare = 1;
        for (int j=0; j<SIZE; j++)
        {
            if (gameSpace[compare][i] != '-')
            {
                 if (gameSpace[j][i] == gameSpace[compare][i])
                {
                    win++;
                    compare++;

                }
                if (compare>SIZE-1)
                {
                    compare = 1;
                }
            }
        }

        if (win==SIZE)
        {
            return true;
        }
    }
    return false;
}


int  TicTacToe::fourInDiagonal1()
{
    int win = 0;
    for (int i=0; i<SIZE; i++)
    {
        int compare = 1;
        for (int j=0; j<SIZE; j++)
        {
            if (i==j)
            {
                if (gameSpace[compare][compare] != '-')
                {
                    if (gameSpace[i][j] == gameSpace[compare][compare])
                    {
                        win++;
                        compare++;
                    }
                    if (compare>SIZE-1)
                    {
                        compare = 1;
                    }
                }
            }
        }

        if (win==SIZE)
        {
            return true;
        }
    }
    return false;
}


int  TicTacToe::fourInDiagonal2()
{
    int win = 0;
    for (int i=0; i<SIZE; i++)
    {
        for (int j=SIZE-1; j>=0; j--)
        {
            int compare_i = i;
            int compare_j = j;

            if(i+j == SIZE-1)
            {
                if (gameSpace[compare_i][compare_j] != '-')
                {
                    if (compare_i==SIZE-1)
                    {
                        compare_i = 0;
                        compare_j = SIZE-1;
                    }
                    if (gameSpace[i][j] == gameSpace[compare_i][compare_j])
                    {
                        win++;
                    }
                }
            }
        }

        if (win==SIZE)
        {
            return true;
        }
    }
    return false;
}



int TicTacToe::fourToWin(int z)
{
    int flag = 0;
    if(fourInRow() == 1)
    {
        cout<< name[z] <<" got four "<< x_o[z] <<"'s in a row! \n";
        showScore(z);
        flag=1;
    }

    else if(fourInCol() == 1)
    {
        cout<< name[z] <<" got four "<< x_o[z] <<"'s in a column! \n";
        showScore(z);
        flag=1;
    }

    else if(fourInDiagonal1() == 1)
    {
        cout<< name[z] <<" got four "<< x_o[z] <<"'s in the main diagonal! \n";
        showScore(z);
        flag=1;
    }

    else if(fourInDiagonal2() == 1)
    {
        cout<< name[z] <<" got four "<< x_o[z] <<"'s in the secondary diagonal! \n";
        showScore(z);
        flag=1;
    }
    return flag;
}



void TicTacToe::printInfo()
{
    for (int i=0; i<SIZE; i++)
    {
        for (int j=0; j<SIZE; j++)
        {
            cout << "|" << gameSpace[i][j];
        }
        cout << "|\n";
    }
}


void TicTacToe::showScore(int z)
{
    score[z] += 1;
    for (int i=0; i<people; i++)
    {
        cout << name[i] <<" (" << x_o[i] << "): " << score[i] << "\n";
    }
}
