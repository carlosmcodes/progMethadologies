#include "pch.h";
#include <iostream>
using namespace std;

bool isWon(char playerTurn, char displayer[][3]);
bool isDraw(char[][3]);
void displayBoard(char displayer[][3]);
void makeAMove(char displayer[][3], char playerTurn);

int main() {
	//
	//	PLEASE DO NOT CHANGE function main
	//
	char board[3][3] = { { ' ', ' ', ' ' },{ ' ', ' ', ' ' },{ ' ', ' ', ' ' } };
	displayBoard(board);

	while (true) {
		// The first player makes a move
		makeAMove(board, 'X');
		displayBoard(board);
		if (isWon('X', board)) {
			cout << "X player won" << endl;
			exit(0);
		}
		else if (isDraw(board)) {
			cout << "No winner" << endl;
			exit(0);
		}

		// The second player makes a move
		makeAMove(board, 'O');
		displayBoard(board);

		if (isWon('O', board)) {
			cout << "O player won" << endl;
			exit(0);
		}
		else if (isDraw(board)) {
			cout << "No winner" << endl;
			exit(0);
		}
	}

	return 0;
}

bool isWon(char playerTurn, char displayer[][3]) {
	int k;
	// checks horizontal 
	for (int i = 0; i < 3; i++) {
		k = 0;
		for (int j = 0; j < 3; j++)
		{
			if (displayer[i][j] == playerTurn) {
				k++;
				if (k == 3)
					return true;
			}
		}

	}
	// checks vertical
	for (int i = 0; i < 3; i++) {
		k = 0;
		for (int j = 0; j < 3; j++)
		{
			if (displayer[j][i] == playerTurn) {
				k++;
				if (k == 3)
					return true;
			}
		}

	}
	if (displayer[0][0] == playerTurn && displayer[1][1] == playerTurn && displayer[2][2] == playerTurn)
		return true;
	if (displayer[0][2] == playerTurn && displayer[1][1] == playerTurn && displayer[2][0] == playerTurn)
		return true;

	return false;

}
bool isDraw(char displayer[][3]) {
	int counter = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (displayer[i][j] == 'X' || displayer[i][j] == 'O')
				counter++;
		}
	}
	if (counter == 9)
		return true;
	return false;
}
void displayBoard(char displayer[][3]) {

	cout << endl;
	for (int i = 0; i < 3; i++) {
		cout << "-------------" << endl;
		for (int j = 0; j < 3; j++) {
			cout << "| " << displayer[i][j] << " ";
		}
		cout << "|" << endl;
	}

	cout << "-------------" << endl;

}
void makeAMove(char displayer[][3], char playerTurn) {

	int row;
	cout << "Enter a row (0, 1, 2) for player " << playerTurn << "	: ";
	cin >> row;
	int col;
	cout << "Enter a column (0, 1, 2) for player " << playerTurn << "	: ";
	cin >> col;

	if (displayer[row][col] == 'O' || displayer[row][col] == 'X') {
		cout << "This cell is already occupied. Try a different cell" << endl;
		cout << "Enter a row (0, 1, 2) for player " << playerTurn << ":	";
		cin >> row;
		cout << "Enter a column (0, 1, 2) for player " << playerTurn << ":	";
		cin >> col;
		displayer[row][col] = playerTurn;
	}
	else {

		displayer[row][col] = playerTurn;
	}
}
