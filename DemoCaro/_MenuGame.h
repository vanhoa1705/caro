#ifndef ___MENUGAME_H__
#define ___MENUGAME_H__

#define name_max 50
// arrow_begin_y = chose_begin_y , arrow_begin_x = chose_begin_x - 4
#define arrow_begin_x 47 // Toa do x bat dau ve mui ten
#define arrow_begin_y 20  // Toa do y bat dau ve mui ten
#define chose_begin_x 52 // Toa do x bat dau liet ke lua chon
#define chose_begin_y 20 // Toa do y bat dau liet ke lua chon

//Kích thước hình chữ nhật hiện lúc thắng,hòa game để chọn tiếp tục chơi hay dừng lại
#define WIDTH_RECTANGLE 50
#define HEIGHT_RECTANGLE 12
#include "_Common.h"



const WORD COLOR_X = 0x04;
const WORD COLOR_O = 0x01;


class _MenuGame
{
public:
	_MenuGame();
	~_MenuGame();
	static void Help();
	static void About();

	static void MenuGame(int &N, int x, int y);//menu luc vao game
	static void MenuNewGame(int &N, int x, int y);
	static void MenuPvE(int & N, int x, int y);
	//menu luc chon new game
	static void HidePoiter();//An con tro
	static void ShowPointer();//Hien con tro
	static void SetColor(WORD color);//doi mau
	static void Logo(int x, int y);//logo caro
	static void Frame(int x, int y);
	static void ModePvE(int x, int y);
	//khung caro
	static void ModeNewGame(int x, int y);//chon che do trong new game
	static void Mode(int x, int y);//chon che do luc vao game
	static void LogoX(int x, int y);//in logo chu X
	static void LogoO(int x, int y);//in logo chu O
	static void LogoWin(int x, int y);//in logo chu WIN
	static void LogoDraw(int x, int y);//in logo chu WIN
	static void FrameContinue(int x, int y);//in khung có chữ continue
	static void FrameExit(int x, int y);//in khung có chữ exit
	static void DecorateMenu();//Trang tri menu
	//Hiệu ứng thắng thua
	static void drawRectangle(int x, int y, int width, int height, bool draw);
	static void showWhoWin(int x, int y, string NamePlayerWin,int pChose);
	static void MenuWinGame(string NamePlayerWin, int &chose);
};

#endif