#include "_Board.h"
#include"_Common.h"


//Khoi tao Board
_Board::_Board(int pSize, int pX, int pY) {
	_size = pSize;
	_left = pX + 3;
	_top = pY + 1;
	_pArr = new _Point*[pSize];
	for (int i = 0; i < pSize; i++)
		_pArr[i] = new _Point[pSize];
}
//Huy Board
_Board::~_Board() {
	for (int i = 0; i < _size; i++)
		delete[] _pArr[i];
	delete[] _pArr;
}
//Lay size cuar Board
int _Board::getSize() { return _size; }
//Lay ben trai
int _Board::getLeft() { return _left; }
//Lay ben tren
int _Board::getTop() { return _top; }
//Lay X tai diem i j
int _Board::getXAt(int i, int j) {
	return _pArr[i][j].getX();
}
//Lay Y tai diem i j
int _Board::getYAt(int i, int j) {
	return _pArr[i][j].getY();
}
//Xoa du lieu cua Board
void _Board::resetData() {
	if (_size == 0)
		return; // Phải gọi constructor trước khi resetData 
	for (int i = 0; i < _size; i++) {
		for (int j = 0; j < _size; j++) {
			_pArr[i][j].setX(4 * j + _left + 2); // Trùng với hoành độ màn hình bàn cờ 
			_pArr[i][j].setY(2 * i + _top + 1); // Trùng với tung độ màn hình bàn cờ 
			_pArr[i][j].setCheck(0);
		}
	}
}
//Ve bang choi 14x14
void _Board::drawBoard() {
	if(_pArr == NULL)
		return; // phải gọi constructor trước
	
	_MenuGame::SetColor(14);
	if (_pArr == NULL)
		return; // phải gọi constructor trước 

	_Common::gotoXY(2, 0);
	for (int i = 1; i < 15; i++)
		printf("%4d", i);
	for (int i = 1; i < 15; i++) {
		_Common::gotoXY(1, i + 1 * i);
		printf("%c", 'A' + i - 1);
	}
	for (int i = 0; i < 29; i++) {
		_Common::gotoXY(3, i + 1);
		for (int j = 0; j < 57; j++)
		{
			if (i == 0 && j == 56) { printf("%c", 191); continue; }
			if (i == 28 && j == 0) { printf("%c", 192); continue; }
			if (i == 28 && j == 56) { printf("%c", 217); continue; }
			if (i == 0 && j == 0) { printf("%c", 218); continue; }
			if (j == 0 && i % 2 == 0)printf("%c", 195);
			else {
				if (j == 56 && i % 2 == 0)printf("%c", 180);
				else {
					if (i == 28 && j % 4 == 0)printf("%c", 193);
					else {
						if (i == 0 && j % 4 == 0)printf("%c", 194);
						else {
							if (i % 2 == 0) {
								if (j % 4 == 0)printf("%c", 197);
								else printf("%c", 196);
							}
							else {
								if (j % 4 == 0)printf("%c", 179);
								else printf(" ");
							}
						}
					}
				}
			}
		}
		printf("\n");

	}
	_Common::gotoXY(0, 0);// di chuyển vào ô đầu */
	_Common::gotoXY(_pArr[0][0].getX(), _pArr[0][0].getY());// di chuyển vào ô đầu 
}
//Kiem tra board
int _Board::checkBoard(int pX, int pY, bool pTurn) {
	for (int i = 0; i < _size; i++) {
		for (int j = 0; j < _size; j++) {
			if (_pArr[i][j].getX() == pX && _pArr[i][j].getY() == pY && _pArr[i][j].getCheck() == 0) {
				if (pTurn) _pArr[i][j].setCheck(-1);// Nếu lượt hiện hành là true: c = -1 
				else _pArr[i][j].setCheck(1);// Nếu lượt hiện hành là false: c = 1 
				return _pArr[i][j].getCheck();
			}
		}
	}
	return 0;
}
//Kiem tra toan bo Board
int _Board::testBoard(int pX, int pY, bool pTurn)
{
	int CheckPerson;
	if (pTurn) CheckPerson = -1;//Nếu lượt hiện hành là true thì c = -1 (người đánh đánh chữ X)
	else CheckPerson = 1;//Nếu lượt hiện hành là true thì c = 1 (người đánh đánh chữ O)
	int Ngang = testNgang(pX, pY, CheckPerson);
	int Doc = testDoc(pX, pY, CheckPerson);
	int CheoPhai = testCheoPhai(pX, pY, CheckPerson);
	int CheoTrai = testCheoTrai(pX, pY, CheckPerson);
	//Kiểm tra số quân cờ nằm hàng ngang nếu đúng theo luật caro thì trả về người chơi hiện hành thắng
	if (Ngang == CheckPerson)
		return CheckPerson;
	//Kiểm tra số quân cờ nằm hàng dọc nếu đúng theo luật caro thì trả về người chơi hiện hành thắng
	if (Doc == CheckPerson)
		return CheckPerson;
	//Kiểm tra số quân cờ nằm đường chéo phải nếu đúng theo luật caro thì trả về người chơi hiện hành thắng
	if (CheoPhai == CheckPerson)
		return CheckPerson;
	//Kiểm tra số quân cờ nằm đường chéo trái nếu đúng theo luật caro thì trả về người chơi hiện hành thắng
	if (CheoTrai == CheckPerson)
		return CheckPerson;
	return testFullBoard();
}
//Ham kiem tra ngang
int _Board::testNgang(int pX, int pY, int _Check)
{
	int i, j, RightPos = 0, LeftPos = 0;
	//Tìm vị trí người chơi vừa đánh
	for (i = 0; i < _size; i++) {
		int temp = 0;
		for (j = 0; j < _size; j++) {
			if (_pArr[i][j].getX() == pX && _pArr[i][j].getY() == pY) {
				temp = 1;
				break;
			}
		}
		if (temp)break;
	}
	//Đếm số cờ giống theo hàng ngang bên phải
	while (j + RightPos <= _size - 1 && _pArr[i][j + RightPos].getCheck() == _Check)RightPos++;
	//Đếm số cờ giống theo hàng ngang bên trái
	while (j - LeftPos >= 0 && _pArr[i][j - LeftPos].getCheck() == _Check)LeftPos++;
	//Đếm số lượng cờ theo luật caro để xét thắng thua
	int countPos = RightPos + LeftPos - 1;
	//Xử lý chặn hai đầu trong luật caro
	if (j + RightPos <= _size - 1 && j - LeftPos >= 0 &&
		_pArr[i][j + RightPos].getCheck() == (-_Check) &&
		_pArr[i][j - LeftPos].getCheck() == (-_Check)) {
		countPos--;
	}//*/
	if (countPos >= 5)
		return _Check;//Trả về người chơi vừa đánh thắng
	return 2;//Trả về hòa
}
//Kiem tra doc
int _Board::testDoc(int pX, int pY, int _Check)
{
	int i, j, UpPos = 0, BottomPos = 0;
	//Tìm vị trí người chơi vừa đánh
	for (i = 0; i < _size; i++) {
		int temp = 0;
		for (j = 0; j < _size; j++) {
			if (_pArr[i][j].getX() == pX && _pArr[i][j].getY() == pY) {
				temp = 1;
				break;
			}
		}
		if (temp)break;
	}
	while (i - UpPos >= 0 && _pArr[i - UpPos][j].getCheck() == _Check)UpPos++;
	while (i + BottomPos <= _size - 1 && _pArr[i + BottomPos][j].getCheck() == _Check)BottomPos++;
	//Đếm số lượng cờ theo luật caro để xét thắng thua
	int countPos = UpPos + BottomPos - 1;
	//Xử lý chặn hai đầu trong luật caro
	if (i - UpPos >= 0 && i + BottomPos <= _size - 1 &&
		_pArr[i - UpPos][j].getCheck() == (-_Check) &&
		_pArr[i + BottomPos][j].getCheck() == (-_Check)) {
		countPos--;
	}
	if (countPos >= 5)
		return _Check;//Trả về người chơi vừa đánh thắng
	return 2;//Trả về hòa
}
//Kiem tra cheo ben phai
int _Board::testCheoPhai(int pX, int pY, int _Check)
{
	int i, j, iPos = 0, jPos = 0;
	//Tìm vị trí vừa đánh
	for (i = 0; i < _size; i++) {
		int temp = 0;
		for (j = 0; j < _size; j++) {
			if (_pArr[i][j].getX() == pX && _pArr[i][j].getY() == pY) {
				temp = 1;
				break;
			}
		}
		if (temp)break;
	}

	//Kiểm tra đường chéo phải bên dưới vị trí vừa đánh, xử lý chặn biên.
	while (i + iPos <= _size - 1 && j + iPos <= _size - 1
		&& _pArr[i + iPos][j + iPos].getCheck() == _Check)
		iPos++;
	//Kiểm tra vị trí chéo phải phía trên vị trí vừa đánh, xử lý chặn biên.
	while (i - jPos >= 0 && j - jPos >= 0 && _pArr[i - jPos][j - jPos].getCheck() == _Check)
		jPos++;
	//Đếm số lượng cờ theo luật caro để xét thắng thua
	int countPos = iPos + jPos - 1;
	//Xử lý cờ bị chặn 2 đầu
	if (i + iPos <= _size - 1 && j + iPos <= _size - 1 &&
		i - jPos >= 0 && j - jPos >= 0 &&
		_pArr[i + iPos][j + iPos].getCheck() == (-_Check) &&
		_pArr[i - jPos][j - jPos].getCheck() == (-_Check)) {
		countPos--;
	}//*/
	if (countPos >= 5)
		return _Check;//Trả về người chơi vừa đánh là thắng
	return 2;//trả về hòa
}
//Kiem tra cheo ben trai
int _Board::testCheoTrai(int pX, int pY, int _Check)
{
	int i, j, iPos = 0, jPos = 0;
	//Tìm vị trí vừa đánh
	for (i = 0; i < _size; i++) {
		int temp = 0;
		for (j = 0; j < _size; j++) {
			if (_pArr[i][j].getX() == pX && _pArr[i][j].getY() == pY) {
				temp = 1;
				break;
			}
		}
		if (temp)break;
	}
	//Kiểm tra đường chéo trái bên dưới vị trí vừa đánh, xử lý chặn biên
	while (i + iPos <= _size - 1 && j - iPos >= 0
		&& _pArr[i + iPos][j - iPos].getCheck() == _Check)
		iPos++;
	//Kiểm tra vị trí chéo trái phía trên vị trí vừa đánh, xử lý chặn biên.
	while (i - jPos >= 0 && j + jPos <= _size - 1 && _pArr[i - jPos][j + jPos].getCheck() == _Check)
		jPos++;
	//Đếm số lượng cờ theo luật caro để xét thắng thua
	int countPos = iPos + jPos - 1;
	//Xử lý cờ bị chặn 2 đầu
	if (i + iPos <= _size - 1 && j - iPos >= 0
		&& i - jPos >= 0 && j + jPos <= _size - 1 &&
		_pArr[i + iPos][j - iPos].getCheck() == (-_Check) &&
		_pArr[i - jPos][j + jPos].getCheck() == (-_Check)) {
		countPos--;
	}//*/
	if (countPos >= 5)
		return _Check;//Trả về người chơi vừa đánh là thắng
	return 2;//trả về hòa
}
//Lay ten file muon luu
string _Board::GetFileSave()
{
	system("cls");

	_MenuGame::DecorateMenu();
	_MenuGame::SetColor(14);
	_MenuGame::Logo(45, 10);
	_MenuGame::Frame(30, 7);

	_Common::gotoXY(35, 20);
	printf("Enter file name: ");
	string temp;
	getline(cin, temp);
	temp += ".txt";
	return temp;
}
//Luu game
void _Board::SaveGame(string FileName, char Player1[], char Player2[])
{
	FILE* f;
	fopen_s(&f, FileName.c_str(), "wt");
	for (int i = 0; i < _size; i++) {
		for (int j = 0; j < _size; j++) {
			fprintf(f, "%3d", _pArr[i][j].getCheck());
		}
		fprintf(f, "\n");
	}
	fprintf(f, "%s\n%s\n", Player1, Player2);
	fclose(f);
}

//Lay ten file muon load
string _Board::GetFileLoad()
{
	system("cls");

	_MenuGame::DecorateMenu();
	_MenuGame::SetColor(14);
	_MenuGame::Logo(45, 10);
	_MenuGame::Frame(30, 7);
	_MenuGame::ShowPointer();
	_Common::gotoXY(35, 20);
	printf("Enter file name: ");
	string temp;
	getline(cin, temp);
	temp += ".txt";
	return temp;
}
//Load game
void _Board::LoadGame(string FileName, char Player1[], char Player2[])
{
	FILE* f;
	do
	{
		fopen_s(&f, FileName.c_str(), "rt");
		if (f == NULL)
		{
			_Common::gotoXY(35, 21);
			printf("Ten file khong dung! Nhap lai:\n");
			_getch();
			FileName = GetFileLoad();
		}

	} while (f == NULL);
	for (int i = 0; i < _size; i++) {
		for (int j = 0; j < _size; j++) {
			int temp;
			fscanf_s(f, "%3d", &temp);
			_pArr[i][j].setCheck(temp);
		}
		fscanf_s(f, "\n");
	}
	fgets(Player1, 100, f);
	fgets(Player2, 100, f);
	fclose(f);
}



int _Board::testFullBoard()
{
	for (int i = 0; i < _size; i++) {
		for (int j = 0; j < _size; j++) {
			//Nếu có vị trí nào còn trống thì trả về 2 tiếp tục đánh
			if (_pArr[i][j].getCheck() == 0)
				return 2;
		}
	}
	return 0;
}

//tra ve vi tri i j hien tai da co ng danh hay chua
int _Board::getpArr(int i, int j)
{
	return _pArr[i][j].getCheck();
}

//Set tai vi tri i j gia tri data
void _Board::setpArr(int i, int j, int data)
{
	_pArr[i][j].setCheck(data);
}

bool _Board::GetCheck(int pX, int pY)
{
	for (int i = 0; i < _size; i++) {
		for (int j = 0; j < _size; j++) {
			if (_pArr[i][j].getX() == pX && _pArr[i][j].getY() == pY && _pArr[i][j].getCheck() == 0)
				return true;
		}
	}
	return false;
}
void _Board::SetCheck(int pX, int pY, int pCheck)
{
	for (int i = 0; i < _size; i++) {
		for (int j = 0; j < _size; j++) {
			if (_pArr[i][j].getX() == pX && _pArr[i][j].getY() == pY)
				_pArr[i][j].setCheck(pCheck);
		}
	}
}
