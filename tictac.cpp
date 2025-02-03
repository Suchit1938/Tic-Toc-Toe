#include <iostream>

using namespace std;

char board[3][3] = { {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'} };
char currentMarker;
int currentPlayer;

void drawBoard() {
    cout << "Tic-Tac-Toe\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << " " << board[i][j] << " ";
            if (j < 2) cout << "|";
        }
        cout << "\n";
        if (i < 2) cout << "---|---|---\n";
    }
}

bool placeMarker(int slot) {
    int row = (slot - 1) / 3;
    int col = (slot - 1) % 3;
    
    if (board[row][col] != 'X' && board[row][col] != 'O') {
        board[row][col] = currentMarker;
        return true;
    }
    return false;
}

int checkWinner() {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) return currentPlayer;
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) return currentPlayer;
    }
    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) return currentPlayer;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) return currentPlayer;
    
    return 0;
}

void swapPlayerAndMarker() {
    currentMarker = (currentMarker == 'X') ? 'O' : 'X';
    currentPlayer = (currentPlayer == 1) ? 2 : 1;
}

void playGame() {
    currentMarker = 'X';
    currentPlayer = 1;
    int winner = 0, turns = 0;

    drawBoard();
    while (turns < 9 && winner == 0) {
        int slot;
        cout << "Player " << currentPlayer << " (" << currentMarker << "), enter your move (1-9): ";
        cin >> slot;

        if (slot < 1 || slot > 9 || !placeMarker(slot)) {
            cout << "Invalid move! Try again.\n";
            continue;
        }

        drawBoard();
        winner = checkWinner();
        if (winner == 0) swapPlayerAndMarker();
        turns++;
    }

    if (winner) {
        cout << "Congratulations! Player " << winner << " wins!\n";
    } else {
        cout << "It's a draw!\n";
    }
}

int main() {
    playGame();
    return 0;
}