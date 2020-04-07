#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const char X = 'X';
const char O = 'O';
const char EMPTY = ' ';
const char TIE = 'T';
const char NO_ONE = 'N';

void instructions();
char askYesNo(string question);
int askNumber(string question, int high, int low = 0);
char humanPiece();
char opponent(char piece);
void displayBoard(const vector<char>* const pBoard);
char winner(const vector<char>* const pBoard);
bool isLegal(const vector<char>* const pBoard, int move);
int humanMove(const vector<char>* const pBoard, char human);
int computerMove(vector<char> board, char computer);
void announceWinner(char winner, char computer, char human);

int main()
{
    setlocale(LC_ALL, "");
    int move;
    const int NUM_SQUARES = 9;
    vector<char> board(NUM_SQUARES, EMPTY);

    instructions();
    char human = humanPiece();
    char computer = opponent(human);
    char turn = X;
    displayBoard(&board);

    while (winner(&board) == NO_ONE)
    {
        if (turn == human)
        {
            move = humanMove(&board, human);
            board[move] = human;
        }
        else
        {
            move = computerMove(board, computer);
            board[move] = computer;
        }
        displayBoard(&board);
        turn = opponent(turn);
    }

    announceWinner(winner(&board), computer, human);

    return 0;
}


void instructions()
{
    cout << " *** Игра в крестики-нолики ***  \n\n";
    cout << "Делать ход нужно согласно доске, введя число от 0 до 8: \n\n";

    cout << "       0 | 1 | 2\n";
    cout << "       ---------\n";
    cout << "       3 | 4 | 5\n";
    cout << "       ---------\n";
    cout << "       6 | 7 | 8\n\n";
}

char askYesNo(string question)
{
    char response;
    do
    {
        cout << question << " (y/n): ";
        cin >> response;
    } while (response != 'y' && response != 'n');

    return response;
}

int askNumber(string question, int high, int low)
{
    int number;
    do
    {
        cout << question << " (" << low << " - " << high << "): ";
        cin >> number;
    } while (number > high || number < low);

    return number;
}

char humanPiece()
{
    char go_first = askYesNo(" Желаете делать первый ход?");
    if (go_first == 'y')
    {
        return X;
    }
    else
    {
        return O;
    }
}

char opponent(char piece)
{
    if (piece == X)
    {
        return O;
    }
    else
    {
        return X;
    }
}

void displayBoard(const vector<char>* const pBoard)
{
    cout << "\n\t" << (*pBoard)[0] << " | " << (*pBoard)[1] << " | " << (*pBoard)[2];
    cout << "\n\t" << "---------";
    cout << "\n\t" << (*pBoard)[3] << " | " << (*pBoard)[4] << " | " << (*pBoard)[5];
    cout << "\n\t" << "---------";
    cout << "\n\t" << (*pBoard)[6] << " | " << (*pBoard)[7] << " | " << (*pBoard)[8];
    cout << "\n\n";
}

char winner(const vector<char>* const pBoard)
{
    // все выигрышные позиции
    const int WINNING_ROWS[8][3] = { { 0, 1, 2 },
    { 3, 4, 5 },
    { 6, 7, 8 },
    { 0, 3, 6 },
    { 1, 4, 7 },
    { 2, 5, 8 },
    { 0, 4, 8 },
    { 2, 4, 6 } };
    const int TOTAL_ROWS = 8;

    // если есть три одинаково заполненных выигрышных позиции, то есть победитель
    for (int row = 0; row < TOTAL_ROWS; ++row)
    {
        if (((*pBoard)[WINNING_ROWS[row][0]] != EMPTY) &&
            ((*pBoard)[WINNING_ROWS[row][0]] == (*pBoard)[WINNING_ROWS[row][1]]) &&
            ((*pBoard)[WINNING_ROWS[row][1]] == (*pBoard)[WINNING_ROWS[row][2]]))
        {
            return (*pBoard)[WINNING_ROWS[row][0]];
        }
    }

    // проверка на ничью, если он путсых квадратов
    if (count(pBoard->begin(), pBoard->end(), EMPTY) == 0)
        return TIE;

    return NO_ONE;
}

inline bool isLegal(int move, const vector<char>* pBoard)
{
    return ((*pBoard)[move] == EMPTY);
}

int humanMove(const vector<char>* const pBoard, char human)
{   
    cout << " *** Ваш ход *** \n";
    int move = askNumber(" Куда будете ходить?", (pBoard->size() - 1));
    while (!isLegal(move, pBoard))
    {
        cout << "\nЭта позиция занята.\n";
        move = askNumber("\nКуда будете ходить?", (pBoard->size() - 1));
    }
    return move;
}

int computerMove(vector<char> board, char computer)
{
    unsigned int move = 0;
    bool found = false;
    cout << " *** Ход компьютера ***\n";
    //если компьютер может выиграть на след. ходу
    while (!found && move < board.size())
    {
        if (isLegal(move, &board))
        {
            //попытка хода
            board[move] = computer;
            //проверка на возможный выигрышь
            found = winner(&board) == computer;
            //отмена хода
            board[move] = EMPTY;
        }
        if (!found)
        {
            ++move;
        }
    }

    //если игрок может выиграть на след. ходу,то компьютер пытается помешать
    if (!found)
    {
        move = 0;
        char human = opponent(computer);

        while (!found && move < board.size())
        {
            if (isLegal(move, &board))
            {
                //попытка хода
                board[move] = human;
                //проверка на возможный выигрышь
                found = winner(&board) == human;
                //отмена хода
                board[move] = EMPTY;
            }
            if (!found)
            {
                ++move;
            }
        }
    }

    // выбор лучшего открытого квадрата для компьютера
    if (!found)
    {
        move = 0;
        unsigned int i = 0;

        const int BEST_MOVES[] = { 4, 0, 2, 6, 8, 1, 3, 5, 7 };
        while (!found && i < board.size())
        {
            move = BEST_MOVES[i];
            if (isLegal(move, &board))
            {
                found = true;
            }
            ++i;
        }
    }
    return move;
}

void announceWinner(char winner, char computer, char human)
{
    if (winner == computer)
    {
        cout <<" *** Компьютер выиграл! ***\n";

    }
    else if (winner == human)
    {
        cout <<" *** Вы выиграли! ***\n";
    }
    else
    {
        cout << " *** Ничья ***\n";
    }
}