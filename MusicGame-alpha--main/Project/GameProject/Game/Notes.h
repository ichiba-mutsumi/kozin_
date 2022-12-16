#pragma once
#include <Gllibrary.h>
#include "../Base/Base.h"

class Notes :public Base {
public:
	enum {
		eState_Q,
		eState_W,
		eState_E,
		eState_R,
		eState_A,
		eState_S,
		eState_D,
		eState_F,
	};
	//falseの場合timeが0になるまで待機
	bool state = false;
	int m_time;
	int NotesArea;
	int RNotesCount;
	int RNotesCountToDelete;
	int NotesRan;
	int HitCountDown;
	int ColorNum;
	double m_speed;
	CImage m_img;
	CImage Frame_img;
	CImage notes;
	CImage criticalnotes;
	CImage doublenotes;
	CImage notes_long;
	CImage slide;
	CImage slide2;
	/*CImage TapA;
	CImage TapS;
	CImage TapD;
	CImage TapE;
	CImage TapQ;
	CImage TapW;
	CImage TapR;
	CImage TapF;*/
	CVector2D Q_vec;
	CVector2D W_vec;
	CVector2D E_vec;
	CVector2D R_vec;
	CVector2D A_vec;
	CVector2D S_vec;
	CVector2D D_vec;
	CVector2D F_vec;
	CVector2D Qend;
	CVector2D Wend;
	CVector2D Eend;
	CVector2D Rend;
	CVector2D Aend;
	CVector2D Send;
	CVector2D Dend;
	CVector2D Fend;
	CVector2D m_pos;
	CVector2D m_vec;
	CVector2D gamen;
public:
	Notes(int area, int time, int speed);
	//Notes(int area, int time, int x, int y);
	void Draw();
	void Update();
	void Timer();
	void ImageSet();
	void LSpeedSet();
	void LCheckHitNotes();
	void RSizeSet();
	void RCheckHitNotes();
	void RArea(int x, int y);
	void CountDownToDelete();
	void LNotesDelete();
	void VecSet();
};
