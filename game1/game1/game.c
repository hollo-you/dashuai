//函数实现
#define _CRT_SECURE_NO_WARNINGS 
#include"game.h"
void InitBoard(char board[ROW][COL], int row, int col) {
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			board[i][j] = ' ';
		}
	}
}

void DisplayBoard(char board[ROW][COL], int row, int col) {
	int i = 0;

	/*for (i = 0; i < row; i++) {
		打印信息
		printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
	}*/

	for (i = 0; i < row; i++) {
		int j = 0;
		for (j = 0; j < col; j++) {
			printf(" %c ", board[i][j]);
			if (j < COL - 1) {
				printf("|");
			}
		}
		printf("\n");
		//打印分割行
		/*if (i < ROW-1) {
			printf("___|___|___\n");
		}*/
		if (i < ROW - 1) {
			int j = 0;
			for (j = 0; j < col; j++) {
				printf("___");
				if (j < COL - 1) {
					printf("|");
				}
			}
			printf("\n");
		}
	}
}

void PlayerMove(char board[ROW][COL], int row, int col) {
	printf("玩家请下棋：>\n");
	while (1)
	{
		printf("玩家请输入坐标：");
		int x = 0;
		int y = 0;
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col) {
			if (board[x - 1][y - 1] == ' ') {
				board[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("该坐标被占用，不能下棋,请选择其他位置！\n");
			}
		}
		else
		{
			printf("非法输入！\n");
		}
	}
}

void ComputerMove(char board[ROW][COL], int row, int col) {
	printf("电脑下棋:>\n");
	while (1)
	{
		int x = 0;
		int y = 0;
		x = rand() % row;//0-2
		y = rand() % col;//0-2
		if (board[x][y] == ' ') {
			board[x][y] = '#';
			break;
		}
	}
}

int IsFull(char board[ROW][COL], int row, int col) {
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			if (board[i][j] == ' ') {
				return 0;
			}
		}
	}
	return 1;
}

char IsWin(char board[ROW][COL], int row, int col) {
	//行
	int i = 0;
	for (i = 0; i < row; i++) {
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ') {
			return board[i][1];
		}
	}
	//列
	int j = 0;
	for (j = 0; j < col; j++) {
		if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[1][j] != ' ') {
			return board[1][j];
		}
	}
		//对角线
		if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ') {
			return board[1][1];
		}
		if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' ') {
			return board[1][1];
		}
		//没人赢，平局
		if (IsFull(board, ROW, COL)) {
			return 'Q';
			
		}
		//没平局，即游戏继续
		return 'C';
}