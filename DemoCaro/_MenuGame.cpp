#include "_MenuGame.h"
#include "_Board.h"


_MenuGame::_MenuGame()
{
}
_MenuGame::~_MenuGame()
{

}

void _MenuGame::Help()
{
	int Width = 127;
	int Height = 31;
	drawRectangle((Width - 40) / 2, (Height - 18) / 2, 40, 18, 1);
	_Common::gotoXY(57, 8);
	printf("Huong Dan:\n");
	_Common::gotoXY(47, 11);
	printf("W,A,S,D: Cac phim di chuyen.\n");
	_Common::gotoXY(47, 13);
	printf("Enter hoac Space: De lua chon.\n");
	_Common::gotoXY(47, 15);
	printf("ESC: Exit.\n");
	_Common::gotoXY(47, 17);
	printf("F1: Help.\n");
	_Common::gotoXY(47, 19);
	printf("F2: rePlay.\n");
	_Common::gotoXY(47, 21);
	printf("F3: Save game.\n");
	_Common::gotoXY(47, 22);

}

void _MenuGame::About()
{
	int Width = 127;
	int Height = 31;
	drawRectangle((Width - 35) / 2, (Height - 15) / 2, 35, 15, 1);
	_Common::gotoXY(60, 10);
	printf("Author:\n");
	_Common::gotoXY(50, 13);
	printf("1712430: Le Van Hiep\n");
	_Common::gotoXY(50, 15);
	printf("1712431: Bui Le Hieu\n");
	_Common::gotoXY(50, 17);
	printf("1712448: Nguyen Van Hoa\n");

	_Common::gotoXY(58, 20);
	printf("%c CopyRight\n", 184);
	_Common::gotoXY(48, 21);
}

void _MenuGame::MenuGame(int & N, int x, int y)
{
	system("cls");
	_MenuGame::HidePoiter();
	int color = 8;
	//carovakhung();
	_MenuGame::SetColor(14);
	_MenuGame::Logo(45, 10);
	_MenuGame::Frame(30, 7);
	_Common::gotoXY(arrow_begin_x, arrow_begin_y);
	_MenuGame::Mode(x, y);
	_MenuGame::SetColor(79);
	printf(">>      1. New Game    <<");
	int mode = 1;
	while (1) {
		while (1)
		{
			_MenuGame::DecorateMenu();
			_MenuGame::SetColor(color);
			_MenuGame::Logo(45, 10);
			_MenuGame::Frame(30, 7);
			if (_kbhit())
				break;
			Sleep(40);
			color++;
			if (color == 16)
				color = 8;
		}
		_MenuGame::SetColor(14);
		char k = _getch();
		if (k == 'w' || k == 0x48) {
			mode += 4;
		}
		if (k == 's' || k == 0x50) {
			mode += 1;
		}
		if (k == 13) { //Enter
			N = mode % 5;
			break;
		}
		_MenuGame::Mode(x, y);
		_MenuGame::SetColor(79);
		_Common::gotoXY(arrow_begin_x + 5, (mode - 1) % 5 + arrow_begin_y);
		if (mode % 5 == 1)
			printf(">>      1. New Game    <<");
		else if (mode % 5 == 2)
			printf(">>      2. Load Game   <<");
		else if (mode % 5 == 3)
			printf(">>      3. Help        <<");
		else if (mode % 5 == 4)
			printf(">>      4. About       <<");
		else if (mode % 5 == 0)
			printf(">>      5. Exit        <<");
		_MenuGame::HidePoiter();
	}
}

void _MenuGame::MenuNewGame(int & N, int x, int y)
{
	system("cls");
	_MenuGame::HidePoiter();
	int color = 8;
	//carovakhung();
	_MenuGame::SetColor(14);
	_MenuGame::Logo(45, 10);
	_MenuGame::Frame(30, 7);
	_Common::gotoXY(arrow_begin_x, arrow_begin_y);
	_MenuGame::ModeNewGame(x, y);
	_MenuGame::SetColor(79);
	printf(">>      1. PvP    <<");
	int mode = 1;
	while (1) {
		while (1)
		{
			_MenuGame::DecorateMenu();
			_MenuGame::SetColor(color);
			_MenuGame::Logo(45, 10);
			_MenuGame::Frame(30, 7);
			if (_kbhit())
				break;
			Sleep(40);
			color++;
			if (color == 16)
				color = 8;
		}
		_MenuGame::SetColor(14);
		char k = _getch();
		if (k == 'w' || k == 0x48) {
			mode += 2;
		}
		if (k == 's' || k == 0x50) {
			mode += 1;
		}
		if (k == 13) { //Enter
			N = mode % 3;
			break;
		}
		_MenuGame::ModeNewGame(x, y);
		_MenuGame::SetColor(79);
		_Common::gotoXY(arrow_begin_x + 5, (mode - 1) % 3 + arrow_begin_y);
		if (mode % 3 == 1)
			printf(">>      1. PvP          <<");
		else if (mode % 3 == 2)
			printf(">>      2. PvE          <<");
		else if (mode % 3 == 0)
			printf(">>      3. Go Back      <<");
	}
}


void _MenuGame::MenuPvE(int & N, int x, int y)
{
	system("cls");
	_MenuGame::HidePoiter();
	int color = 8;
	_MenuGame::SetColor(14);
	_MenuGame::Logo(45, 10);
	_MenuGame::Frame(30, 7);
	_Common::gotoXY(arrow_begin_x, arrow_begin_y);
	_MenuGame::ModePvE(x, y);
	_MenuGame::SetColor(79);
	printf(">>      1. Easy          <<");
	int mode = 1;
	while (1) {
		while (1)
		{
			_MenuGame::DecorateMenu();
			_MenuGame::SetColor(color);
			_MenuGame::Logo(45, 10);
			_MenuGame::Frame(30, 7);
			if (_kbhit())
				break;
			Sleep(40);
			color++;
			if (color == 16)
				color = 8;
		}
		_MenuGame::SetColor(14);
		char k = _getch();
		if (k == 'w' || k == 0x48) {
			mode += 2;
		}
		if (k == 's' || k == 0x50) {
			mode += 1;
		}
		if (k == 13) { //Enter
			N = mode % 3;
			break;
		}
		_MenuGame::ModePvE(x, y);
		_MenuGame::SetColor(79);
		_Common::gotoXY(arrow_begin_x + 5, (mode - 1) % 3 + arrow_begin_y);
		if (mode % 3 == 1)
			printf(">>      1. Easy          <<");
		else if (mode % 3 == 2)
			printf(">>      2. Normal        <<");
		else if (mode % 3 == 0)
			printf(">>      3. Go Back       <<");

		_MenuGame::HidePoiter();
	}
}


void _MenuGame::HidePoiter()
{
	HANDLE hOut;
	CONSOLE_CURSOR_INFO ConCurInf;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	ConCurInf.dwSize = 10;
	ConCurInf.bVisible = FALSE;
	SetConsoleCursorInfo(hOut, &ConCurInf);
}


void _MenuGame::ShowPointer()
{
	HANDLE hOut;
	CONSOLE_CURSOR_INFO ConCurInf;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	ConCurInf.dwSize = 10;
	ConCurInf.bVisible = TRUE;
	SetConsoleCursorInfo(hOut, &ConCurInf);
}


void _MenuGame::Logo(int x, int y)
{
	int t = 219;
	int v = 220;
	int u = 223;
	_Common::gotoXY(x, y);
	printf("%c%c%c%c%c%c     %c%c%c     %c%c%c%c     %c%c%c%c   \n", v, t, u, u, u, v, v, u, v, t, u, u, v, v, u, u, v);
	_Common::gotoXY(x, y + 1);
	printf("%c         %c   %c    %c  %c%c   %c    %c        \n", t, t, t, t, v, u, t, t);
	_Common::gotoXY(x, y + 2);
	printf("%c         %c%c%c%c%c    %c%c%c%c    %c    %c       \n", t, t, u, u, u, t, t, u, u, v, t, t);
	_Common::gotoXY(x, y + 3);
	printf("%c%c%c%c%c%c    %c   %c    %c   %c%c   %c%c%c%c     \n", u, t, v, v, v, u, t, t, t, u, v, u, v, v, u);

}


void _MenuGame::Frame(int x, int y)
{
	int u = 179, v = 196;
	int i, j, k, l;
	for (i = x + 1; i <= x + 60; i++)
	{
		_Common::gotoXY(i, y);
		printf("%c", v);
	}
	printf("%c", 197);
	for (j = y; j <= y + 9; j++)
	{
		_Common::gotoXY(i, j + 1);
		printf("%c", u);
	}
	_Common::gotoXY(i, j);
	printf("%c", 197);
	for (k = i - 1; k >= x + 1; k--)
	{
		_Common::gotoXY(k, j);
		printf("%c", v);
	}
	_Common::gotoXY(k, j);
	printf("%c", 197);
	for (l = j - 1; l > y; l--)
	{
		_Common::gotoXY(x, l);
		printf("%c", u);
	}
	_Common::gotoXY(x, l);
	printf("%c", 197);
}

void _MenuGame::ModePvE(int x, int y)
{
	_Common::gotoXY(x, y);
	printf("          1. Easy                \n");

	_Common::gotoXY(x, y + 1);
	printf("          2. Normal              \n");

	_Common::gotoXY(x, y + 2);
	printf("          3. Go Back             \n");
	_Common::gotoXY(arrow_begin_x + 5, arrow_begin_y);
}

void _MenuGame::ModeNewGame(int x, int y)
{
	_Common::gotoXY(x, y);
	printf("          1. PvP               \n");

	_Common::gotoXY(x, y + 1);
	printf("          2. PvE               \n");

	_Common::gotoXY(x, y + 2);
	printf("          3. Go Back           \n");

	_Common::gotoXY(arrow_begin_x + 5, arrow_begin_y);
}

void _MenuGame::Mode(int x, int y)
{
	_Common::gotoXY(x, y);
	printf("         1. New Game          \n");
	_Common::gotoXY(x, y + 1);
	printf("         2. Load Game         \n");
	_Common::gotoXY(x, y + 2);
	printf("         3. Help              \n");
	_Common::gotoXY(x, y + 3);
	printf("         4. About             \n");
	_Common::gotoXY(x, y + 4);
	printf("         5. Exit               ");
	_Common::gotoXY(arrow_begin_x + 5, arrow_begin_y);
}

void _MenuGame::LogoX(int x, int y)
{
	_MenuGame::SetColor(COLOR_X);
	_Common::gotoXY(x, y);
	printf("%c%c    %c%c", 223, 220, 220, 223);
	_Common::gotoXY(x, y + 1);
	printf("  %c%c%c%c  ", 223, 220, 220, 223);
	_Common::gotoXY(x, y + 2);
	printf("  %c%c%c%c  ", 220, 223, 223, 220);
	_Common::gotoXY(x, y + 3);
	printf("%c%c    %c%c", 220, 223, 223, 220);
}

void _MenuGame::LogoO(int x, int y)
{
	_MenuGame::SetColor(COLOR_O);
	_Common::gotoXY(x, y);
	printf("  %c%c%c%c  ", 220, 223, 223, 220);
	_Common::gotoXY(x, y + 1);
	printf(" %c    %c ", 219, 219);
	_Common::gotoXY(x, y + 2);
	printf(" %c    %c ", 219, 219);
	_Common::gotoXY(x, y + 3);
	printf("  %c%c%c%c  ", 223, 220, 220, 223);
}
void _MenuGame::LogoDraw(int x, int y)
{
	int lenLogoDraw = 20;
	int xLogo, yLogo;
	xLogo = x + (WIDTH_RECTANGLE - lenLogoDraw) / 2;
	yLogo = y + 5;
	_Common::gotoXY(xLogo, yLogo);
	cout << char(219) << char(223) << char(223) << char(220) << " " << char(219) << char(223) << char(220) << " " << char(220) << char(223) << char(220) << " " << char(219) << " " << char(219) << " " << char(219) << " " << char(219) << endl;
	_Common::gotoXY(xLogo, yLogo + 1);
	cout << char(219) << "  " << char(219) << " " << char(219) << char(220) << char(223) << " " << char(219) << char(220) << char(219) << "  " << char(219) << " " << char(219) << " " << char(219) << "  " << endl;
	_Common::gotoXY(xLogo, yLogo + 2);
	cout << char(219) << char(220) << char(220) << char(223) << " " << char(219) << " " << char(219) << " " << char(219) << " " << char(219) << "   " << char(219) << " " << char(219) << "   " << endl;
	//*/
}
void _MenuGame::LogoWin(int x, int y)
{
	int lenLogoWin = 14;
	int xLogo, yLogo;
	xLogo = x + (WIDTH_RECTANGLE - lenLogoWin) / 2;
	yLogo = y + 5;
	int i = 178;
	_Common::gotoXY(xLogo, yLogo);
	cout << char(i - 2) << " " << char(i - 2) << " " << char(i - 2) << " " << char(i - 2) << " " << char(i - 2) << " " << char(i - 2) << char(220) << " " << char(i - 2) << endl;
	_Common::gotoXY(xLogo, yLogo + 1);
	cout << " " << char(i - 1) << " " << char(i - 1) << " " << char(i - 1) << "  " << char(i - 1) << " " << char(i - 1) << char(i) << char(i) << char(i - 1) << endl;
	_Common::gotoXY(xLogo, yLogo + 2);
	cout << "  " << char(i) << " " << char(i) << "   " << char(i) << " " << char(i) << " " << char(223) << char(i) << endl;
	//*/
}
void _MenuGame::FrameContinue(int x, int y)
{
	int HeightFrameChil = 3;
	_Common::gotoXY(x + 6, y + HEIGHT_RECTANGLE - (HeightFrameChil));
	cout << char(201) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(187) << endl;
	_Common::gotoXY(x + 6, y + HEIGHT_RECTANGLE - (HeightFrameChil)+1);
	cout << char(186) << " Continue " << char(186) << endl;
	_Common::gotoXY(x + 6, y + HEIGHT_RECTANGLE - (HeightFrameChil)+2);
	cout << char(200) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(188) << endl;

}

void _MenuGame::FrameExit(int x, int y)
{
	int HeightFrameChil = 3;
	int WidthFrameChil = 8;
	_Common::gotoXY(x + WIDTH_RECTANGLE - (WidthFrameChil + 6),
		y + HEIGHT_RECTANGLE - (HeightFrameChil));
	cout << char(201) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(187) << endl;
	_Common::gotoXY(x + WIDTH_RECTANGLE - (WidthFrameChil + 6),
		y + HEIGHT_RECTANGLE - (HeightFrameChil)+1);
	cout << char(186) << " Exit " << char(186) << endl;
	_Common::gotoXY(x + WIDTH_RECTANGLE - (WidthFrameChil + 6),
		y + HEIGHT_RECTANGLE - (HeightFrameChil)+2);
	cout << char(200) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(188) << endl;

}

void _MenuGame::DecorateMenu()
{
	_MenuGame::LogoX(10, 5);
	_MenuGame::LogoO(10, 10);
	_MenuGame::LogoX(10, 15);
	_MenuGame::LogoO(10, 20);

	_MenuGame::LogoO(105, 5);
	_MenuGame::LogoX(105, 10);
	_MenuGame::LogoO(105, 15);
	_MenuGame::LogoX(105, 20);
}

void _MenuGame::drawRectangle(int x, int y, int width, int height, bool draw)
{
	if (draw) {
		for (int i = 0; i < width; i++)
		{
			_Common::gotoXY(x + i, y);
			cout << char(223);
			_Common::gotoXY(x + i, y + height);
			cout << char(220);
		}
		for (int i = 0; i < height + 1; i++)
		{
			_Common::gotoXY(x, y + i);
			cout << char(219);
			_Common::gotoXY(x + width, y + i);
			cout << char(219);
		}
	}
}

void _MenuGame::showWhoWin(int x, int y, string NamePlayerWin,int pChose)
{
	int lenLogo, lenLogoX, lenLogoO;
	lenLogo = lenLogoX = lenLogoO = 8;
	if (pChose==-1) {
		_MenuGame::LogoX(x + 2, y + 2);
		_MenuGame::LogoX(x + WIDTH_RECTANGLE - (lenLogoX + 2), y + 2);
		_MenuGame::LogoWin(x, y);
	}
	else if(pChose==1)
	{
		_MenuGame::LogoO(x + 2, y + 2);
		_MenuGame::LogoO(x + WIDTH_RECTANGLE - (lenLogoO + 2), y + 2);
		_MenuGame::LogoWin(x, y);
	}
	else if (pChose == 0)
	{
		_MenuGame::LogoX(x + 2, y + 2);
		_MenuGame::LogoO(x + WIDTH_RECTANGLE - (lenLogoO + 2), y + 2);
		_MenuGame::LogoDraw(x, y);
	}
	_Common::gotoXY(x + 10 + (WIDTH_RECTANGLE - 2 * (lenLogo + 2) - strlen(">>|<< Player >>|<<")) / 2, y + 2);
	cout << ">>|<< Player >>|<<";
	int xName = x + 10 + (WIDTH_RECTANGLE - NamePlayerWin.length() - 20) / 2;//Vị trí x để in tên người chơi
	_Common::gotoXY(xName, y + 3);
	cout << NamePlayerWin << endl;

}

void _MenuGame::MenuWinGame(string NamePlayerWin,int &chose)
{

	//test*/
	int temp = chose;
	//Kích thước màn hình console
	int WidhtConsole = 127;//Chiều dài
	int HeightConsole = 31;//Chiều rộng
	int x, y;//Tọa độ vễ khung hình hiển thông báo người chơi thắng
	x = (WidhtConsole - WIDTH_RECTANGLE) / 2;
	y = (HeightConsole - HEIGHT_RECTANGLE) / 2;
	//Xóa một vùng hình chữ nhật để in ra menu thắng thua hòa
	for (int i = 1; i < WIDTH_RECTANGLE; i++)
	{
		for (int j = 1; j < HEIGHT_RECTANGLE + 1; j++)
		{
			_Common::gotoXY(x + i, y + j);
			cout << " ";
		}
	}
	_MenuGame::HidePoiter();
	int color = 8;
	_MenuGame::SetColor(14);
	_MenuGame::drawRectangle(x, y, WIDTH_RECTANGLE, HEIGHT_RECTANGLE, true);
	_MenuGame::showWhoWin(x, y, NamePlayerWin, chose);
	//_MenuGame::LogoWin(x, y);
	_MenuGame::FrameContinue(x, y);
	_MenuGame::FrameExit(x, y);
	_MenuGame::SetColor(79);
	_Common::gotoXY(x + 7, y + HEIGHT_RECTANGLE - 2);
	printf(" Continue ");
	int mode = 1;
	while (1) {
		while (1)
		{
			_MenuGame::SetColor(color);
			_MenuGame::drawRectangle(x, y, WIDTH_RECTANGLE, HEIGHT_RECTANGLE, true);
			_MenuGame::showWhoWin(x, y, NamePlayerWin, chose);
		//	_MenuGame::LogoWin(x, y);
			if (_kbhit())
				break;
			Sleep(50);
			color++;
			if (color == 16)
				color = 8;
		}
		_MenuGame::SetColor(14);
		char k = _getch();
		if (k == 'a' || k == 0x4B || k == 'A') {
			mode += 1;
		}
		if (k == 'd' || k == 0x4D || k == 'D') {
			mode += 1;
		}
		if (k == 13) { //Enter
			chose = mode % 2;
			break;
		}
		_MenuGame::FrameContinue(x, y);
		_MenuGame::FrameExit(x, y);
		_MenuGame::SetColor(79);
		_Common::gotoXY(x + 7 + ((mode - 1) % 2) * 30, y + HEIGHT_RECTANGLE - 2);
		if (mode % 2 == 1)
			printf(" Continue ");
		else if (mode % 2 == 0)
			printf(" Exit ");
		_MenuGame::HidePoiter();
	}//*/
	

}

void _MenuGame::SetColor(WORD color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
