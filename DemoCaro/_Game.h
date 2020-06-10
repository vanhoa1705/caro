#ifndef ___GAME_H__
#define ___GAME_H__
#include"_Board.h"
#include"_Common.h"
#include "_MenuGame.h"
#include<stdio.h>
#include<conio.h>
class _Game
{
	_Board* _b;// một bàn cờ 
	bool _turn;// lượt chơi: true lượt người một & false lượt người thứ hai 
	int _x, _y; // Tọa độ hiện hành của nháy chuột 
	int _command; // phím gõ từ người dùng 
	bool _loop; // Biến quyết định thoát game hay không 
	int _firstmove;
	int comX, comY; // Lưu tòa độ của máy
public: 
	_Game(int, int, int); 
	~_Game();
	int getCommand(); 
	bool isContinue(); 
	char waitKeyBoard(); // Hàm nhận phím từ người dùng 
	char askContinue(); 
	void startGame(); // Hàm bắt đầu game 
	void exitGame(); // Hàm thoát game 
	int processFinish(char Player1[], char Player2[]);
	int processFinishCom(int pX, int pY, char Player1[], char Player2[]);
	bool processCheckBoard(int &dem1, int &dem2);
	void moveRight(); 
	void moveLeft(); 
	void moveUp();

	void moveDown();
	void Player(char player1[], char player2[]);
	void Player(char player1[]);
	void PvP();
	void PvPLoadGame();
	void FrameHelp();
	void FrameInfor();
	void FrameInfor(int turn, int dem1, int dem2, const char * ten1, const char * ten2);
	void PvE1();
	void PvE2();
	void TimKiemNuocDi();
	double DiemTanCongDuyetDoc(int i, int j);
	double DiemTanCongDuyetNgang(int i, int j);
	double DiemTanCongDuyetCheoNguoc(int i, int j);
	double DiemTanCongDuyetCheoXuoi(int i, int j);
	double DiemPhongNguDuyetDoc(int i, int j);
	double DiemPhongNguDuyetNgang(int i, int j);
	double DiemPhongNguDuyetCheoNguoc(int i, int j);
	double DiemPhongNguDuyetCheoXuoi(int i, int j);
};
#endif // !___GAME_H__


