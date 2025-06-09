#include<iostream>
#define FAST_IO cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0)


using namespace std;

int player;
char board[3][3];

bool is_win(char c) {
	if (board[0][0] == c and board[0][1] == c and board[0][2] == c) return true;
	if (board[1][0] == c and board[1][1] == c and board[1][2] == c) return true;
	if (board[2][0] == c and board[2][1] == c and board[2][2] == c) return true;	
	if (board[0][0] == c and board[1][0] == c and board[2][0] == c) return true;
	if (board[0][1] == c and board[1][1] == c and board[2][1] == c) return true;
	if (board[0][2] == c and board[1][2] == c and board[2][2] == c) return true;
	if (board[0][0] == c and board[1][1] == c and board[2][2] == c) return true;
	if (board[0][2] == c and board[1][1] == c and board[2][0] == c) return true;
	return false;
}

int main(void) {
	FAST_IO;

	cin >> player;

	int cnt = 9;
	bool flag = false;
	char inp;

	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 3; ++j)
			board[i][j] = ' ';


	while (cnt--) {

		if (player % 2) inp = 'X';
		else inp = 'O';
		int y, x;
		cin >> y >> x;
		board[y - 1][x - 1] = inp;
		

		if (is_win(inp)) {
			flag = true;
			cout << (player == 1 ? 1 : 2);
			break;
		}
		player++;
		player %= 2;
	}

	if (flag == false) cout << 0;

	return 0;

}