#include <iostream>
using namespace std;
char x_o[3][3] = { {'1','2','3'},{'4','5','6'},{'7','8','9'} };
char player = 'x';
void drow() {
	system("cls");
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++) {

			cout << "| " << x_o[i][j] << " |";
		}
		cout << "\n--------------\n";
	}
}
void play() {
	char pos;
	cout << "Choose Your Position: (" << player<<") ";
	cin >> pos;
	bool flage = false;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (x_o[i][j] == pos) {
                x_o[i][j] = player;
                flage = true;
            }
        }
    }

    if (!flage) {
        cout << "Invalid move. Try again." << endl;
        play();
    }
	if (player == 'x')
		player = 'o';
	else
	{
		player = 'x';
	}
}
char win() {
	int counter = 0;
	int Cx = 0, Co = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++) {
			if (x_o[i][j] != 'x' && x_o[i][j] != 'o') counter++;
			if (x_o[i][j] == 'x') Cx++;
			else if(x_o[i][j] == 'o') Co++;
			if (Cx == 3 || Co == 3) {
				return Cx > Co ? 'x' : 'o';
			}
		}
		Cx = 0;
		Co = 0;
	}
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++) {

			if (x_o[j][i] == 'x') Cx++;
			else if (x_o[j][i] == 'o') Co++;
			if (Cx == 3 || Co == 3) {
				return Cx > Co ? 'x' : 'o';
			}
		}
		Cx = 0;
		Co = 0;
	}
	if (x_o[0][0] == 'x' && x_o[1][1] == 'x' && x_o[2][2] == 'x') return 'x';
	else if (x_o[0][0] == 'o' && x_o[1][1] == 'o' && x_o[2][2] == 'o') return 'o';
	else if (x_o[0][2] == 'x' && x_o[1][1] == 'x' && x_o[2][0] == 'x') return 'x';
	else if (x_o[0][2] == 'x' && x_o[1][1] == 'x' && x_o[2][0] == 'x') return 'x';
	if (counter == 0) return'e';
	return'c';
}
int main()
{
	char player ='x';
	while (win() == 'c')
	{
	drow();
	play();
	}
	drow();
	if (win() == 'e')
		cout << "\n  Tide\n" << endl;
	else
		cout << "\n The Winner Is Player: " << win() << endl;


	return 0;
}
