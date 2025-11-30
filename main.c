#include <ctype.h>
#include <stdio.h>
#define SIZE 3

void clear()
{
    int c;
    while ((c = getchar()) != EOF && c != '\n')
    {
    }
}

void resetBoard(char Board[SIZE][SIZE])
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            Board[i][j] = ' ';
        }
    }
}

void printBoard(char Board[SIZE][SIZE])
{
    puts("\n   1   2   3");
    for (int i = 0; i < SIZE; i++)
    {
        printf("%d  %c | %c | %c \n", i + 1, Board[i][0], Board[i][1], Board[i][2]);
        if (i == SIZE - 1)
        {
            puts("  ---+---+---");
        }
    }
    putchar('\n');
}

int checkWinner(char Board[SIZE][SIZE], char player)
{
    for (int i = 0; i < SIZE; i++)
    {
        if (Board[i][0] == player && Board[i][1] == player && Board[i][2] == player)
        {
            return 1;
        }
        if (Board[0][i] == player && Board[1][i] == player && Board[2][i] == player)
        {
            return 1;
        }
    }
    if (Board[0][0] == player && Board[1][1] == player && Board[2][2] == player)
    {
        return 1;
    }
    if (Board[2][0] == player && Board[1][1] == player && Board[0][2] == player)
    {
        return 1;
    }
    return 0;
}

int isDraw(const char board[SIZE][SIZE])
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (board[i][j] == ' ') return 0;
        }
    }
    return 1;
}

void move(char board[SIZE][SIZE], const char player)
{
    int row = -1, col = -1;
    printf("Player %c, make your move: ", player);
    while (1)
    {
        if (scanf("%d %d", &row, &col) != 2)
        {
            printf("Wrong input\n");
            clear();
            continue;
        }
        clear();

        if (row < 1 || row > SIZE || col < 1 || col > SIZE)
        {
            printf("OUT OF BOUND\n");
            continue;
        }
        row--;
        col--;
        if (board[row][col] != ' ')
        {
            printf("ALREADY OCCUPIED");
            continue;
        }
        board[row][col] = player;
        break;
    }
}

int prompt(char* message)
{
    while (1)
    {
        printf("%s (y/n): ", message);
        char c = getchar();
        clear();
        c = tolower((unsigned char)c);
        if (c == 'y') return 1;
        if (c == 'n') return 0;
        puts("Type 'y' or 'n'.");
    }
}

int main(void)
{
    char board[SIZE][SIZE];
    int run = 1;
    while (run)
    {
        resetBoard(board);
        char currentPlayer = 'X';
        int finished = 0;
        while (!finished)
        {
            printBoard(board);
            move(board, currentPlayer);
            if (checkWinner(board, currentPlayer))
            {
                printBoard(board);
                printf("PLAYER %c WINS!: ", currentPlayer);
                finished = 1;
                continue;
            }
            if (isDraw(board))
            {
                printBoard(board);
                puts("IT'S A DRAW!");
                finished = 1;
                continue;
            }
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }
        run = prompt("Would you like to play again?");
    }
    puts("EXITING............");
    return 0;
}
