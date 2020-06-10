#include "_Game.h"
#include"_Common.h"


_Game::_Game(int pSize, int pLeft, int pTop) {
	_b = new _Board(pSize, pLeft, pTop);
	_loop = _turn = true;
	_command = -1; // Gán lượt và phím mặc định 
	_x = pLeft; _y = pTop;
	//_x = 5; _y = 2;
}
_Game::~_Game() { delete _b; }
int _Game::getCommand() { return _command; }
bool _Game::isContinue() { return _loop; }
char _Game::waitKeyBoard() {
	_command = toupper(_getch());
	return _command;
}
char _Game::askContinue() {
	_Common::gotoXY(0, _b->getYAt(_b->getSize() - 1, _b->getSize() - 1) + 4);
	return waitKeyBoard();
}
//Bat dau game
void _Game::startGame() {
	system("cls");
	_b->resetData(); // Khởi tạo dữ liệu gốc 
	_b->drawBoard(); // Vẽ màn hình game 
	_x = _b->getXAt(0, 0);
	_y = _b->getYAt(0, 0);
}
//Thoat game
void _Game::exitGame() {
	system("cls");
	//Có thể lưu game trước khi exit 
	_loop = false;
}

//Ham danh vao 1 o bat ky
bool _Game::processCheckBoard(int &dem1, int &dem2) {
	switch (_b->checkBoard(_x, _y, _turn)) {
	case -1:
	{
		_MenuGame::SetColor(COLOR_X);
		printf("X");
		dem1++;
		_MenuGame::SetColor(0x07);
	}
	break;
	case 1:
	{
		_MenuGame::SetColor(COLOR_O);
		printf("O");
		dem2++;
		_MenuGame::SetColor(0x01);
	}
	break;
	case 0:
		return false; // Khi đánh vào ô đã đánh rồi 
	}
	return true;
}

//Kiem tra xem ket thuc hay chua
int _Game::processFinish(char Player1[], char Player2[]) {
	// Nhảy tới vị trí thích hợp để in chuỗi thắng/thua/hòa   
	//_Common::gotoXY(0, _b->getYAt(_b->getSize() - 1, _b->getSize() - 1) + 2); 
	int pWhoWin = _b->testBoard(_x, _y, _turn);
	switch (pWhoWin) {
	case -1:
	{
		//printf("Nguoi choi %d da thang va nguoi choi %d da thua\n", true, false); 
		_MenuGame::MenuWinGame(Player1, pWhoWin);
	}

	break;
	case 1:
		//	printf("Nguoi choi %d da thang va nguoi choi %d da thua\n", false, true); 
		_MenuGame::MenuWinGame(Player2, pWhoWin);
		break;
	case 0:
		//printf("Nguoi choi %d da hoa nguoi choi %d\n", false, true);
		_MenuGame::MenuWinGame("XOXOXO", pWhoWin);
		break;
	case 2:
		_turn = !_turn; // Đổi lượt nếu không có gì xảy ra 
	}
	_Common::gotoXY(_x, _y);// Trả về vị trí hiện hành của con trỏ màn hình bàn cờ 
	return pWhoWin;
}
int _Game::processFinishCom(int pX, int pY, char Player1[], char Player2[]) {
	// Nhảy tới vị trí thích hợp để in chuỗi thắng/thua/hòa   
	//_Common::gotoXY(0, _b->getYAt(_b->getSize() - 1, _b->getSize() - 1) + 2); 
	int pWhoWin = _b->testBoard(pX, pY, _turn);
	switch (pWhoWin) {
	case -1:
	{
		//printf("Nguoi choi %d da thang va nguoi choi %d da thua\n", true, false); 
		_MenuGame::MenuWinGame(Player1, pWhoWin);
	}

	break;
	case 1:
		//	printf("Nguoi choi %d da thang va nguoi choi %d da thua\n", false, true); 
		_MenuGame::MenuWinGame(Player2, pWhoWin);
		break;
	case 0:
		//printf("Nguoi choi %d da hoa nguoi choi %d\n", false, true);
		_MenuGame::MenuWinGame("XOXOXO", pWhoWin);
		break;
	case 2:
		_turn = !_turn; // Đổi lượt nếu không có gì xảy ra 
	}
	_Common::gotoXY(_x, _y);// Trả về vị trí hiện hành của con trỏ màn hình bàn cờ 
	return pWhoWin;
}
//Di chuyen qua phai
void _Game::moveRight() {
	if (_x < _b->getXAt(_b->getSize() - 1, _b->getSize() - 1)) {
		_x += 4;
		_Common::gotoXY(_x, _y);
	}
}
//Di chuyen qua trai
void _Game::moveLeft() {
	if (_x > _b->getXAt(0, 0)) {
		_x -= 4;
		_Common::gotoXY(_x, _y);
	}
}
//Di chuyen xuong duoi
void _Game::moveDown() {
	if (_y < _b->getYAt(_b->getSize() - 1, _b->getSize() - 1)) {
		_y += 2;
		_Common::gotoXY(_x, _y);
	}
}
//Ham lay ten nguoi choi
void _Game::Player(char player1[], char player2[])
{
	system("cls");

	_MenuGame::DecorateMenu();
	_MenuGame::SetColor(14);
	_MenuGame::Logo(45, 10);
	_MenuGame::Frame(30, 7);

	_Common::gotoXY(35, 20);
	printf("Enter the first player's name: ");
	gets_s(player1, 100);
	_Common::gotoXY(35, 21);

	printf("Enter the second player's name: ");
	fflush(stdin);
	gets_s(player2, 100);
}
//Ham lay ten ng choi
void _Game::Player(char player1[])
{
	system("cls");

	_MenuGame::DecorateMenu();
	_MenuGame::SetColor(14);
	_MenuGame::Logo(45, 10);
	_MenuGame::Frame(30, 7);

	_Common::gotoXY(35, 20);
	printf("Enter the your name: ");
	gets_s(player1, 100);
}
//Ham danh voi nguoi
void _Game::PvP()
{
	char Player1[100], Player2[100];
	Player(Player1, Player2);
rePlay://Flag rePlay
	int dem1 = 0, dem2 = 0;//dem so co da danh
	startGame();
	FrameInfor();
	FrameHelp();
	while (isContinue()) {

		FrameInfor(_turn, dem1, dem2, Player1, Player2);
		_Common::gotoXY(_x, _y);
		waitKeyBoard();
		if (getCommand() == 27) break;
		else {
			if (GetAsyncKeyState(VK_F1))//F1
			{
				system("cls");
				_MenuGame::Help();
				system("pause");
				system("cls");
				_b->drawBoard();
				FrameHelp();
				FrameInfor();
				for (int i = 0; i < 14; i++)
				{
					for (int j = 0; j < 14; j++)
					{
						if (_b->getpArr(i, j) == -1)
						{
							_Common::gotoXY(j * 4 + 5, i * 2 + 2);
							_MenuGame::SetColor(COLOR_X);
							printf("X");
							_MenuGame::SetColor(0x07);
						}
						else if (_b->getpArr(i, j) == 1)
						{
							_Common::gotoXY(j * 4 + 5, i * 2 + 2);
							_MenuGame::SetColor(COLOR_O);
							printf("O");
							_MenuGame::SetColor(0x01);
						}
					}
				}
			}
			if (GetAsyncKeyState(VK_F2)) //F2
			{
				system("cls");
				goto rePlay;

			}
			if (GetAsyncKeyState(VK_F3))
			{
				_b->SaveGame(_b->GetFileSave(), Player1, Player2);
				break;
			} //F3
			switch (getCommand()) {
			case 'A': case 0x4B://di chuyen sang trai
				moveLeft();
				break;
			case 'W': case 0x48://di chuyen len tren
				moveUp();
				break;
			case 'S': case 0x50://di chuyen xuong duoi
				moveDown();
				break;
			case 'D': case 0x4D://di chuyen sang phai
				moveRight();
				break;
			case 13: case 32:
				//Đánh dấu bàn cờ, sau đó kiểm tra và xử lý thắng/thua/hòa/tiếp tục 
				if (processCheckBoard(dem1, dem2)) {
					switch (processFinish(Player1, Player2)) {
						/*case -1: case 1: case 0:
							if (askContinue() != 'Y') exitGame();
							else startGame();//*/
					case 1: goto rePlay; break;
					case 0: exitGame(); break;
					}
				}
			}
		}

	}
}

//Ham load lai game 
void _Game::PvPLoadGame()
{
	system("cls");
	int dem1 = 0, dem2 = 0;//dem so co da danh
	char Player1[100], Player2[100];

	_b->LoadGame(_b->GetFileLoad(), Player1, Player2);
	int a[14][14];
	for (int i = 0; i < 14; i++)
	{
		for (int j = 0; j < 14; j++)
		{
			a[i][j] = _b->getpArr(i, j);
		}
	}

	startGame();
	FrameInfor();
	FrameHelp();
	for (int i = 0; i < 14; i++)
	{
		for (int j = 0; j < 14; j++)
		{
			if (a[i][j] == -1)
			{
				_Common::gotoXY(j * 4 + 5, i * 2 + 2);
				_MenuGame::SetColor(COLOR_X);
				printf("X");
				dem1++;
				_MenuGame::SetColor(0x07);
				_b->setpArr(i, j, -1);
			}
			else if (a[i][j] == 1)
			{
				_Common::gotoXY(j * 4 + 5, i * 2 + 2);
				_MenuGame::SetColor(COLOR_O);
				printf("O");
				dem2++;
				_MenuGame::SetColor(0x01);
				_b->setpArr(i, j, 1);
			}

		}
	}

	if (dem1 = dem2) _turn = true;
	if (dem1 > dem2) _turn = false;
rePlay://Flag rePlay


	while (isContinue())
	{

		FrameInfor(_turn, dem1, dem2, Player1, Player2);
		_Common::gotoXY(_x, _y);
		waitKeyBoard();
		if (getCommand() == 27) break;
		else
		{
			if (GetAsyncKeyState(VK_F1))//F1
			{
				system("cls");
				_MenuGame::Help();
				system("pause");
				system("cls");
				_b->drawBoard();
				FrameHelp();
				FrameInfor();
				for (int i = 0; i < 14; i++)
				{
					for (int j = 0; j < 14; j++)
					{
						if (_b->getpArr(i, j) == -1)
						{
							_Common::gotoXY(j * 4 + 5, i * 2 + 2);
							_MenuGame::SetColor(COLOR_X);
							printf("X");
							_MenuGame::SetColor(0x07);
						}
						else if (_b->getpArr(i, j) == 1)
						{
							_Common::gotoXY(j * 4 + 5, i * 2 + 2);
							_MenuGame::SetColor(COLOR_O);
							printf("O");
							_MenuGame::SetColor(0x01);
						}
					}
				}
			}
			if (GetAsyncKeyState(VK_F2)) //F2
			{
				system("cls");
				startGame();
				FrameInfor();
				FrameHelp();
				dem1 = 0; dem2 = 0;
				goto rePlay;

			}
			if (GetAsyncKeyState(VK_F3))
			{
				_b->SaveGame(_b->GetFileSave(), Player1, Player2);
				break;
			} //F3
			switch (getCommand())
			{
			case 'A': case 0x4B://di chuyen sang trai
				moveLeft();
				break;
			case 'W': case 0x48://di chuyen len tren
				moveUp();
				break;
			case 'S': case 0x50://di chuyen xuong duoi
				moveDown();
				break;
			case 'D': case 0x4D://di chuyen sang phai
				moveRight();
				break;
			case 13: case 32:
				//Đánh dấu bàn cờ, sau đó kiểm tra và xử lý thắng/thua/hòa/tiếp tục 
				if (processCheckBoard(dem1, dem2)) {
					switch (processFinish(Player1, Player2)) {
						//case -1: case 1: case 0:
					case 1:
					{
						startGame();
						FrameInfor();
						FrameHelp();
						dem1 = 0; dem2 = 0;
						goto rePlay;
					} break;
					case 0: exitGame(); break;
					}
				}
			}
		}

	}
}

//Ham ve khung Help
void _Game::FrameHelp()
{
	for (int i = 2; i < 29; i++)
	{
		_Common::gotoXY(64, i);
		printf("%c", 179);
	}

	_MenuGame::HidePoiter();
	for (int i = 69; i < 114; i++)
	{
		_Common::gotoXY(i, 22);
		printf("%c", 196);
		_Common::gotoXY(i, 28);
		printf("%c", 196);
	}

	for (int i = 22; i < 29; i++)
	{
		_Common::gotoXY(70, i);
		printf("%c", 179);
		_Common::gotoXY(112, i);
		printf("%c", 179);
	}


	_Common::gotoXY(75, 24);
	printf("F1: Help");

	_Common::gotoXY(93, 24);
	printf("F2: rePlay");

	_Common::gotoXY(75, 26);
	printf("F3: Save");

	_Common::gotoXY(93, 26);
	printf("ESC: Exit");
}
// Ve khung infor
void _Game::FrameInfor()
{
	//Ke Khung
	_MenuGame::HidePoiter();
	for (int i = 69; i < 114; i++)
	{
		_Common::gotoXY(i, 2);
		printf("%c", 196);
		_Common::gotoXY(i, 12);
		printf("%c", 196);
	}

	for (int i = 2; i < 13; i++)
	{
		_Common::gotoXY(70, i);
		printf("%c", 179);
		_Common::gotoXY(112, i);
		printf("%c", 179);
	}
	_MenuGame::SetColor(13);
	_Common::gotoXY(86, 15);
	printf("DO AN CA-RO\n");
	_Common::gotoXY(84, 17);
	printf("NHOM 4 - 17CTT3\n");
	_Common::gotoXY(76, 19);
	printf("TRUONG DAI HOC KHOA HOC TU NHIEN\n");
	_MenuGame::SetColor(14);
}
//Thong tin trong khung infor
void _Game::FrameInfor(int turn, int dem1, int dem2, const char* ten1, const char* ten2)
{


	//Infor
	if (turn == 1)
	{
		_MenuGame::LogoX(88, 4);
		_Common::gotoXY(82, 9);
		_MenuGame::SetColor(7);
		printf("Toi luot: %s\n", ten1);
		_Common::gotoXY(82, 10);
		printf("So co da danh: %d", dem1);
	}
	if (turn == 0)
	{
		_MenuGame::LogoO(88, 4);
		_Common::gotoXY(82, 9);
		_MenuGame::SetColor(7);
		printf("Toi luot: %s\n", ten2);
		_Common::gotoXY(82, 10);
		printf("So co da danh: %d", dem2);
	}
	_MenuGame::ShowPointer();
}
//Di chuyen len tren
void _Game::moveUp() {
	if (_y > _b->getYAt(0, 0)) {
		_y -= 2;
		_Common::gotoXY(_x, _y);
	}
}
//Danh voi may de
void _Game::PvE1()
{
	char Player1[100], Player2[100] = "BOT";
	Player(Player1);
rePlay://Flag rePlay
	_turn = true;
	_firstmove = 0;
	int dem1 = 0, dem2 = 0;//dem so co da danh
	startGame();
	FrameInfor();
	FrameHelp();
	while (isContinue()) {

		FrameInfor(_turn, dem1, dem2, Player1, Player2);
		_Common::gotoXY(_x, _y);
		waitKeyBoard();
		if (getCommand() == 27) break;
		else {
			if (GetAsyncKeyState(VK_F1))//F1
			{
				system("cls");
				_MenuGame::Help();
				system("pause");
				system("cls");
				_b->drawBoard();
				FrameHelp();
				FrameInfor();
				for (int i = 0; i < 14; i++)
				{
					for (int j = 0; j < 14; j++)
					{
						if (_b->getpArr(i, j) == -1)
						{
							_Common::gotoXY(j * 4 + 5, i * 2 + 2);
							_MenuGame::SetColor(COLOR_X);
							printf("X");
							_MenuGame::SetColor(0x07);
						}
						else if (_b->getpArr(i, j) == 1)
						{
							_Common::gotoXY(j * 4 + 5, i * 2 + 2);
							_MenuGame::SetColor(COLOR_O);
							printf("O");
							_MenuGame::SetColor(0x01);
						}
					}
				}
			}
			if (GetAsyncKeyState(VK_F2)) //F2
			{
				system("cls");
				goto rePlay;

			}
			if (GetAsyncKeyState(VK_F3))
			{
				_b->SaveGame(_b->GetFileSave(), Player1, Player2);
				break;
			} //F3
			switch (getCommand()) {
			case 'A': case 0x4B://di chuyen sang trai
				moveLeft();
				break;
			case 'W': case 0x48://di chuyen len tren
				moveUp();
				break;
			case 'S': case 0x50://di chuyen xuong duoi
				moveDown();
				break;
			case 'D': case 0x4D://di chuyen sang phai
				moveRight();
				break;
			case 13: case 32:
				//Đánh dấu bàn cờ, sau đó kiểm tra và xử lý thắng/thua/hòa/tiếp tục 
				if (processCheckBoard(dem1, dem2)) {
					switch (processFinish(Player1, Player2)) {
						/*case -1: case 1: case 0:
							if (askContinue() != 'Y') exitGame();
							else startGame();//*/
					case 1: goto rePlay; break;
					case 0: exitGame(); break;
					}
					{
						if (_firstmove != 1)
						{
							comX = _x;
							comY = _y;
							_firstmove = 1;
						}
						int X[3] = { 0,-4,4 };
						int Y[3] = { 0,-2,2 };
						int temp1, temp2 = 0;
						bool temp3;
						do
						{
							temp1 = rand() % 3;
							if (temp1 == 0)
								do
								{
									temp2 = rand() % 3;
								} while (temp2 == 0);
								temp3 = _b->GetCheck(comX + X[temp1], comY + Y[temp2]);
						} while (temp3 == false);
						comX += X[temp1];
						comY += Y[temp2];
						_Common::gotoXY(comX, comY);
						_MenuGame::SetColor(COLOR_O);
						printf("O");
						dem2++;
						_MenuGame::SetColor(0x01);
						_b->SetCheck(comX, comY, 1);
						switch (processFinishCom(comX, comY, Player1, Player2)) {
							/*case -1: case 1: case 0:
								if (askContinue() != 'Y') exitGame();
								else startGame();//*/
						case 1: goto rePlay; break;
						case 0: exitGame(); break;
						}
					}
				}
			}
		}

	}
}
//Dùng cho việc tính điểm khi duyệt mảng cờ dựa trên số quân người và máy
long MangDiemTanCong[7] = { 0, 3,24,192,1536,12288,98304 };
long MangDiemPhongNgu[7] = { 0, 3,9,81,729,6561,59049 };
//Danh voi may kho
void _Game::PvE2()
{
	char Player1[100], Player2[100] = "BOT";
	Player(Player1);
rePlay://Flag rePlay
	_turn = true;
	_firstmove = 0;
	int dem1 = 0, dem2 = 0;//dem so co da danh
	startGame();
	FrameInfor();
	FrameHelp();
	while (isContinue()) {

		FrameInfor(_turn, dem1, dem2, Player1, Player2);
		_Common::gotoXY(_x, _y);
		waitKeyBoard();
		if (getCommand() == 27) break;
		else {
			if (GetAsyncKeyState(VK_F1))//F1
			{
				system("cls");
				_MenuGame::Help();
				system("pause");
				system("cls");
				_b->drawBoard();
				FrameHelp();
				FrameInfor();
				for (int i = 0; i < 14; i++)
				{
					for (int j = 0; j < 14; j++)
					{
						if (_b->getpArr(i, j) == -1)
						{
							_Common::gotoXY(j * 4 + 5, i * 2 + 2);
							_MenuGame::SetColor(COLOR_X);
							printf("X");
							_MenuGame::SetColor(0x07);
						}
						else if (_b->getpArr(i, j) == 1)
						{
							_Common::gotoXY(j * 4 + 5, i * 2 + 2);
							_MenuGame::SetColor(COLOR_O);
							printf("O");
							_MenuGame::SetColor(0x01);
						}
					}
				}
			}
			if (GetAsyncKeyState(VK_F2)) //F2
			{
				system("cls");
				goto rePlay;

			}
			if (GetAsyncKeyState(VK_F3))
			{
				_b->SaveGame(_b->GetFileSave(), Player1, Player2);
				break;
			} //F3
			switch (getCommand()) {
			case 'A': case 0x4B://di chuyen sang trai
				moveLeft();
				break;
			case 'W': case 0x48://di chuyen len tren
				moveUp();
				break;
			case 'S': case 0x50://di chuyen xuong duoi
				moveDown();
				break;
			case 'D': case 0x4D://di chuyen sang phai
				moveRight();
				break;
			case 13: case 32:
				//Đánh dấu bàn cờ, sau đó kiểm tra và xử lý thắng/thua/hòa/tiếp tục 
				if (processCheckBoard(dem1, dem2)) {
					switch (processFinish(Player1, Player2)) {
						/*case -1: case 1: case 0:
							if (askContinue() != 'Y') exitGame();
							else startGame();//*/
					case 1: goto rePlay; break;
					case 0: exitGame(); break;
					}
					{
						_Game::TimKiemNuocDi();
						_Common::gotoXY(comX, comY);
						_MenuGame::SetColor(COLOR_O);
						printf("O");
						dem2++;
						_MenuGame::SetColor(0x01);
						_b->SetCheck(comX, comY, 1);
						switch (processFinishCom(comX, comY, Player1, Player2))
						{
							/*case -1: case 1: case 0:
								if (askContinue() != 'Y') exitGame();
								else startGame();//*/
						case 1: goto rePlay; break;
						case 0: exitGame(); break;
						}
					}
				}
			}
		}

	}
}
//Tim kiem nuoc di
void _Game::TimKiemNuocDi() // Tìm nước đi hợp lí cho máy
{
	{
		double DiemMax = 0;
		for (int i = 0; i < _b->getSize(); i++)
		{
			for (int j = 0; j < _b->getSize(); j++)
			{
				if (_b->getpArr(i, j) == 0)
				{
					double DiemTanCong = DiemTanCongDuyetDoc(i, j) +DiemTanCongDuyetNgang(i, j) + DiemTanCongDuyetCheoNguoc(i, j) + DiemTanCongDuyetCheoXuoi(i, j);
					double DiemPhongNgu = DiemPhongNguDuyetDoc(i, j) +DiemPhongNguDuyetNgang(i, j) + DiemPhongNguDuyetCheoNguoc(i, j) + DiemPhongNguDuyetCheoXuoi(i, j);
					double temp = DiemTanCong > DiemPhongNgu ? DiemTanCong : DiemPhongNgu;
					if (temp > DiemMax)
					{
						DiemMax = temp;     //Tìm ô cờ có số điểm cao nhất
						comX = _b->getXAt(i, j); //Lấy tọa đô _x của ô cờ
						comY = _b->getYAt(i, j); //Lấy tọa độ _y của ô cờ
					}
				}
			}
		}
	}
}
// TIm diem tan cong doc
double _Game::DiemTanCongDuyetDoc(int i, int j)
{
	double DiemTong = 0;
	int SoQuanTa = 0;
	int SoQuanDich = 0;
	for (int dem = 1; dem < 6 && i + dem < _b->getSize(); dem++) //Duyệt mảng từ trên xuống bắt đầu từ ô cờ đang xét
	{
		if (_b->getpArr(i + dem, j) == 1)
			SoQuanTa++;
		else if (_b->getpArr(i + dem, j) == -1)
		{
			SoQuanDich++;
			break;
		}
		else break;
	}
	for (int dem = 1; dem < 6 && i - dem >= 0; dem++) //Duyệt mảng từ dưới lên bắt đầu từ ô cờ đang xét
	{
		if (_b->getpArr(i - dem, j) == 1)
			SoQuanTa++;
		else if (_b->getpArr(i - dem, j) == -1)
		{
			SoQuanDich++;
			break;
		}
		else break;
	}//*/
	if (SoQuanDich == 2) return 0;  
	if (SoQuanTa >= 4)
	{
		DiemTong += MangDiemTanCong[SoQuanTa + 1] * 1.5;
	}
	else if (SoQuanTa == 3 && SoQuanDich == 0)
	{
		DiemTong += MangDiemTanCong[SoQuanTa + 1];
	}
	else
	DiemTong += MangDiemTanCong[SoQuanTa];
	return DiemTong;
}
//Tim diem tan cong 
double _Game::DiemTanCongDuyetNgang(int i, int j)
{
	double DiemTong = 0;
	int SoQuanTa = 0;
	int SoQuanDich = 0;
	for (int dem = 1; dem < 6 && j + dem < _b->getSize(); dem++) // Duyệt mảng từ trái sang phải bắt đầu từ ô cờ đang xét
	{
		if (_b->getpArr(i, j + dem) == 1)
			SoQuanTa++;
		else if (_b->getpArr(i, j + dem) == -1) 
		{
			SoQuanDich++;
			break;
		}
		else break;
	}
	for (int dem = 1; dem < 6 && j - dem >= 0; dem++) // Duyệt mảng từ phải sang trái bắt đầu từ ô cờ đang xét
	{
		if (_b->getpArr(i, j - dem) == 1)
			SoQuanTa++;
		else if (_b->getpArr(i, j - dem) == -1)
		{
			SoQuanDich++;
			break;
		}
		else break;
	}
	if (SoQuanDich == 2) return 0;
	if (SoQuanTa >= 4)
	{
		DiemTong += MangDiemTanCong[SoQuanTa + 1] * 1.5;
	}
	else if (SoQuanTa == 3 && SoQuanDich == 0)
	{
		DiemTong += MangDiemTanCong[SoQuanTa + 1];
	}
	else
		DiemTong += MangDiemTanCong[SoQuanTa];
	return DiemTong;
}

double _Game::DiemTanCongDuyetCheoNguoc(int i, int j)
{
	double DiemTong = 0;
	int SoQuanTa = 0;
	int SoQuanDich = 0;
	for (int dem = 1; dem < 6 && i - dem >= 0 && j + dem < _b->getSize(); dem++) // Chéo ngược đi lên 
	{
		if (_b->getpArr(i - dem, j + dem) == 1)
			SoQuanTa++;
		else if (_b->getpArr(i - dem, j + dem) == -1)
		{
			SoQuanDich++;
			break;
		}
		else break;
	}
	for (int dem = 1; dem < 6 && i + dem < _b->getSize() && j - dem >= 0; dem++) // Chéo ngược đi xuống
	{
		if (_b->getpArr(i + dem, j - dem) == 1)
			SoQuanTa++;
		else if (_b->getpArr(i + dem, j - dem) == -1)
		{
			SoQuanDich++;
			break;
		}
		else break;
	}
	if (SoQuanDich == 2) return 0;
	if (SoQuanTa >= 4)
	{
		DiemTong += MangDiemTanCong[SoQuanTa + 1] * 1.5;
	}
	else if (SoQuanTa == 3 && SoQuanDich == 0)
	{
		DiemTong += MangDiemTanCong[SoQuanTa + 1];
	}
	else
		DiemTong += MangDiemTanCong[SoQuanTa];
	return DiemTong;
}

double _Game::DiemTanCongDuyetCheoXuoi(int i, int j)
{
	double DiemTong = 0;
	int SoQuanTa = 0;
	int SoQuanDich = 0;
	for (int dem = 1; dem < 6 && i + dem < _b->getSize() && j + dem < _b->getSize(); dem++) //Chéo xuôi đi xuống
	{
		if (_b->getpArr(i + dem, j + dem) == 1)
			SoQuanTa++;
		else if (_b->getpArr(i + dem, j + dem) == -1)
		{
			SoQuanDich++;
			break;
		}
		else break;
	}
	for (int dem = 1; dem < 6 && i - dem >= 0 && j - dem >= 0; dem++) //Chéo xuôi đi lên
	{
		if (_b->getpArr(i - dem, j - dem) == 1)
			SoQuanTa++;
		else if (_b->getpArr(i - dem, j - dem) == -1)
		{
			SoQuanDich++;
			break;
		}
		else break;
	}
	if (SoQuanDich == 2) return 0;
	if (SoQuanTa >= 4)
	{
		DiemTong += MangDiemTanCong[SoQuanTa + 1] * 1.5;
	}
	else if (SoQuanTa == 3 && SoQuanDich == 0)
	{
		DiemTong += MangDiemTanCong[SoQuanTa + 1];
	}
	else
		DiemTong += MangDiemTanCong[SoQuanTa];
	return DiemTong;
}//*/
// Duyệt điểm phòng ngự tương tự như tấn công
double _Game::DiemPhongNguDuyetDoc(int i, int j)
{
	double DiemTong = 0;
	int SoQuanTa = 0;
	int SoQuanDich = 0;
	int temp1 = 0; //quân địch bên trên
	int temp2 = 0; //Quân địch bên dưới
	for (int dem = 1; dem < 6 && i + dem < _b->getSize(); dem++)
	{
		if (_b->getpArr(i + dem, j) == 1)
		{
			SoQuanTa++;
			break;
		}
		else if (_b->getpArr(i + dem, j) == -1)
		{
			SoQuanDich++;
			temp2++;
		}
		else break;
	}
	for (int dem = 1; dem < 6 && i - dem >= 0; dem++)
	{
		if (_b->getpArr(i - dem, j) == 1)
		{
			SoQuanTa++;
			temp1++;
			break;
		}
		else if (_b->getpArr(i - dem, j) == -1)
		{
			SoQuanDich++;
		}
		else break;
	}//*/
	if (SoQuanTa == 2) return 0;
	if ((temp1 >= 3 && temp2 >= 1) || (temp2 >= 3 && temp1 >= 1))
	{
		DiemTong += MangDiemPhongNgu[SoQuanDich + 1] * 3;
	}
	else if ((SoQuanDich == 3 && SoQuanTa == 0) || (SoQuanDich == 4 && SoQuanTa == 1))
	{
		DiemTong += MangDiemPhongNgu[SoQuanDich + 1] * 2.5;
	}
	else if (SoQuanDich == 3 && SoQuanTa == 1)
	{
		DiemTong += MangDiemPhongNgu[SoQuanDich] * 0, 75;
	}
	else
		DiemTong += MangDiemPhongNgu[SoQuanDich];
	return DiemTong;
}

double _Game::DiemPhongNguDuyetNgang(int i, int j)
{
	double DiemTong = 0;
	int SoQuanTa = 0;
	int SoQuanDich = 0;
	int temp1 = 0; //quân địch bên trái
	int temp2 = 0; //Quân địch bên phải
	for (int dem = 1; dem < 6 && j + dem < _b->getSize(); dem++)
	{
		if (_b->getpArr(i, j + dem) == 1)
		{
			SoQuanTa++;
			break;
		}
		else if (_b->getpArr(i, j + dem) == -1)
		{
			SoQuanDich++;
			temp2++;
		}
		else break;
	}
	for (int dem = 1; dem < 6 && j - dem >= 0; dem++)
	{
		if (_b->getpArr(i, j - dem) == 1)
		{
			SoQuanTa++;
			break;
		}
		else if (_b->getpArr(i, j - dem) == -1)
		{
			SoQuanDich++;
			temp1++;
		}
		else break;
	}
	if (SoQuanTa == 2) return 0;
	if ((temp1 >= 3 && temp2 >= 1) || (temp2 >= 3 && temp1 >= 1))
	{
		DiemTong += MangDiemPhongNgu[SoQuanDich + 1] * 3;
	}
	else if ((SoQuanDich == 3 && SoQuanTa == 0) || (SoQuanDich == 4 && SoQuanTa == 1))
	{
		DiemTong += MangDiemPhongNgu[SoQuanDich + 1] * 2.5;
	}
	else if (SoQuanDich == 3 && SoQuanTa == 1)
	{
		DiemTong += MangDiemPhongNgu[SoQuanDich] * 0, 75;
	}
	else
		DiemTong += MangDiemPhongNgu[SoQuanDich];
	return DiemTong;
}

double _Game::DiemPhongNguDuyetCheoNguoc(int i, int j)
{
	double DiemTong = 0;
	int SoQuanTa = 0;
	int SoQuanDich = 0;
	int temp1 = 0; //quân địch bên trái
	int temp2 = 0; //Quân địch bên phải
	for (int dem = 1; dem < 6 && i - dem >= 0 && j + dem < _b->getSize(); dem++)
	{
		if (_b->getpArr(i - dem, j + dem) == 1)
		{
			SoQuanTa++;
			break;
		}
		else if (_b->getpArr(i - dem, j + dem) == -1)
		{
			SoQuanDich++;
			temp2++;
		}
		else break;
	}
	for (int dem = 1; dem < 6 && i + dem < _b->getSize() && j - dem >= 0; dem++)
	{
		if (_b->getpArr(i + dem, j - dem) == 1)
		{
			SoQuanTa++;
			break;
		}
		else if (_b->getpArr(i + dem, j - dem) == -1)
		{
			SoQuanDich++;
			temp1++;
		}
		else break;
	}
	if (SoQuanTa == 2) return 0;
	if ((temp1 >= 3 && temp2 >= 1) || (temp2 >= 3 && temp1 >= 1))
	{
		DiemTong += MangDiemPhongNgu[SoQuanDich + 1] * 3;
	}
	else if ((SoQuanDich == 3 && SoQuanTa == 0) || (SoQuanDich == 4 && SoQuanTa == 1))
	{
		DiemTong += MangDiemPhongNgu[SoQuanDich + 1] * 2.5;
	}
	else if (SoQuanDich == 3 && SoQuanTa == 1)
	{
		DiemTong += MangDiemPhongNgu[SoQuanDich] * 0, 75;
	}
	else
		DiemTong += MangDiemPhongNgu[SoQuanDich];
	return DiemTong;
}

double _Game::DiemPhongNguDuyetCheoXuoi(int i, int j)
{
	double DiemTong = 0;
	int SoQuanTa = 0;
	int SoQuanDich = 0;
	int temp1 = 0; //quân địch bên trái
	int temp2 = 0; //Quân địch bên phải
	for (int dem = 1; dem < 6 && i + dem < _b->getSize() && j + dem < _b->getSize(); dem++)
	{
		if (_b->getpArr(i + dem, j + dem) == 1)
		{
			SoQuanTa++;
			break;
		}
		else if (_b->getpArr(i + dem, j + dem) == -1)
		{
			SoQuanDich++;
			temp2++;
		}
		else break;
	}
	for (int dem = 1; dem < 6 && i - dem >= 0 && j - dem >= 0; dem++)
	{
		if (_b->getpArr(i - dem, j - dem) == 1)
		{
			SoQuanTa++;
			break;
		}
		else if (_b->getpArr(i - dem, j - dem) == -1)
		{
			SoQuanDich++;
			temp1++;
		}
		else break;
	}
	if (SoQuanTa == 2) return 0;
	if ((temp1 >= 3 && temp2 >= 1) || (temp2 >= 3 && temp1 >= 1))
	{
		DiemTong += MangDiemPhongNgu[SoQuanDich + 1] * 3;
	}
	else if ((SoQuanDich == 3 && SoQuanTa == 0) || (SoQuanDich == 4 && SoQuanTa == 1))
	{
		DiemTong += MangDiemPhongNgu[SoQuanDich + 1] * 2.5;
	}
	else if (SoQuanDich == 3 && SoQuanTa == 1)
	{
		DiemTong += MangDiemPhongNgu[SoQuanDich] * 0, 75;
	}
	else
		DiemTong += MangDiemPhongNgu[SoQuanDich];
	return DiemTong;
}//*/