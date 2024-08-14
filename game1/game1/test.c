//游戏测试
#define _CRT_SECURE_NO_WARNINGS 

#include"game.h"

void menu() {
	printf("************************\n");
	printf("*****1.play  0.exit*****\n");
	printf("************************\n");

}
void game() {
	char board[ROW][COL] = { 0 };
	//初始化棋盘函数
	InitBoard(board, ROW, COL);
	//打印棋盘函数
	DisplayBoard(board, ROW, COL);
	//下棋
	char sz = 0;
	while (1)
	{

		//玩家下棋
		PlayerMove(board, ROW, COL);
		//判断输赢
		sz = IsWin(board, ROW, COL);
		if (sz != 'C')
		{
			break;
		}
		DisplayBoard(board, ROW, COL);
		//电脑下棋
		ComputerMove(board, ROW, COL);
		//判断输赢
		sz = IsWin(board, ROW, COL);
		if (sz != 'C') {
			break;
		}
		DisplayBoard(board, ROW, COL);
	}
	if (sz == '*') {
		printf("玩家赢\n");
	}if (sz == '#')
	{
		printf("电脑赢\n");
	}if (sz == 'Q') {
		printf("平局\n");
	}
}
int main() {
	srand((unsigned)time(NULL));		//设计随机数的生成起点
	int input = 0;
	do
	{
		menu();			//打印菜单
		printf("请选择:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误！\n");
			break;
		}
	} while (input);
	return 0;
}