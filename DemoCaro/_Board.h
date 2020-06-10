#ifndef ___BOARD_H__
#define ___BOARD_H__
#include"_Point.h"
#include"_MenuGame.h"
class _Board
{
private: 
	
	int _size;  
	int _left, _top;  
	_Point** _pArr; 
public: 
	_Board(int, int, int);
	~_Board();
	int getSize(); 
	int getLeft(); 
	int getTop(); 
	int getXAt(int, int); 
	int getYAt(int, int);
	void resetData(); 
	void drawBoard();
	int checkBoard(int, int, bool); 
	int testBoard(int, int,bool);
	int testNgang(int, int, int);
	int testDoc(int, int, int);
	int testCheoPhai(int, int, int);
	int testCheoTrai(int, int, int);
	string GetFileSave();
	string GetFileLoad();
	void LoadGame(string FileName, char Player1[], char Player2[]);
	void SaveGame(string FileName, char Player1[], char Player2[]);
	int testFullBoard();
	int getpArr(int i, int j);
	void setpArr(int i, int j, int data);
	bool GetCheck(int pX, int pY);
	void SetCheck(int pX, int pY,int pCheck);
};

#endif ___BOARD_H__