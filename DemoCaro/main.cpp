#include"_Game.h"
#include "_MenuGame.h"
//xét chặn 2 đầu
//Thêm hiệu ứng thắng thua menugame.h và .cpp
//sửa hàm game .cpp
void main() {
	int chose = 0;
	int N;
	_Common::fixConsoleWindow();
	MenuGame:_MenuGame::MenuGame(N, 47, 20);//flag MenuGame
	if (N == 1)
	{
		MenuNewGame:_MenuGame::MenuNewGame(N, 47, 20);//Fag MenuNewGame
		_MenuGame::ShowPointer();
		if (N == 0) goto MenuGame;//Quay lai MenuGame
		if (N == 1) //Choi voi nguoi
		{
			_Game g(14, 0, 0); // Sinh viên tự định nghĩa các hằng số
			g.PvP();
			goto MenuGame;
		}
		if (N == 2)
		{
			_MenuGame::MenuPvE(N, 47, 20);
			if (N == 1)//Choi Easy
			{
				_Game g(14, 0, 0); // Sinh viên tự định nghĩa các hằng số
				g.PvE1();
				goto MenuGame;
			}
			if (N == 2)//Choi Normal
			{
				_Game g(14, 0, 0); // Sinh viên tự định nghĩa các hằng số
				g.PvE2();
				goto MenuGame;
			}
			if (N == 0) goto MenuNewGame;//Quay lai MenuNewGame
		}
	}
	if (N == 2)
	{
		_Game g(14, 0, 0); // Sinh viên tự định nghĩa các hằng số
		g.PvPLoadGame();
		goto MenuGame;


	}

	if (N == 3)
	{
		system("cls");
		_MenuGame::Help();
		system("pause");
		goto MenuGame;
	}
	if (N == 4)
	{
		system("cls");
		_MenuGame::About();
		system("pause");
		goto MenuGame;
	}

/*
	_Game g(14, 0, 0); // Sinh viên tự định nghĩa các hằng số
	g.startGame();
	while (g.isContinue()) {
		g.waitKeyBoard();
		if (g.getCommand() == 27) g.exitGame();
		else {
			switch (g.getCommand()) {
			case 'A':
				g.moveLeft();
				break;
			case 'W':
				g.moveUp();
				break;
			case 'S':
				g.moveDown();
				break;
			case 'D':
				g.moveRight();
				break;
			case 13:
				//Đánh dấu bàn cờ, sau đó kiểm tra và xử lý thắng/thua/hòa/tiếp tục
				if (g.processCheckBoard()) {
					switch (g.processFinish()) {
					case -1: case 1: case 0:
						if (g.askContinue() != 'Y') g.exitGame();
						else g.startGame();
					}
				}
			}
		}
	}//*/

	system("pause");
}
