//��Ϸ����
#define _CRT_SECURE_NO_WARNINGS 

#include"game.h"

void menu() {
	printf("************************\n");
	printf("*****1.play  0.exit*****\n");
	printf("************************\n");

}
void game() {
	char board[ROW][COL] = { 0 };
	//��ʼ�����̺���
	InitBoard(board, ROW, COL);
	//��ӡ���̺���
	DisplayBoard(board, ROW, COL);
	//����
	char sz = 0;
	while (1)
	{

		//�������
		PlayerMove(board, ROW, COL);
		//�ж���Ӯ
		sz = IsWin(board, ROW, COL);
		if (sz != 'C')
		{
			break;
		}
		DisplayBoard(board, ROW, COL);
		//��������
		ComputerMove(board, ROW, COL);
		//�ж���Ӯ
		sz = IsWin(board, ROW, COL);
		if (sz != 'C') {
			break;
		}
		DisplayBoard(board, ROW, COL);
	}
	if (sz == '*') {
		printf("���Ӯ\n");
	}if (sz == '#')
	{
		printf("����Ӯ\n");
	}if (sz == 'Q') {
		printf("ƽ��\n");
	}
}
int main() {
	srand((unsigned)time(NULL));		//�����������������
	int input = 0;
	do
	{
		menu();			//��ӡ�˵�
		printf("��ѡ��:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("ѡ�����\n");
			break;
		}
	} while (input);
	return 0;
}