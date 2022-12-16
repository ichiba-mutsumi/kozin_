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
	//falseÇÃèÍçátimeÇ™0Ç…Ç»ÇÈÇ‹Ç≈ë“ã@
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
	CImage notes[9];
	CImage criticalnotes[9];
	CImage doublenotes[9];
	CImage notes_long[9];
	CImage slide[9];
	CImage slide2[9];
	/*CImage TapA;
	CImage TapS;
	CImage TapD;
	CImage TapE;
	CImage TapQ;
	CImage TapW;
	CImage TapR;
	CImage TapF;*/
	CVector2D Q_pos;
	CVector2D W_pos;
	CVector2D E_pos;
	CVector2D R_pos;
	CVector2D A_pos;
	CVector2D S_pos;
	CVector2D D_pos;
	CVector2D F_pos;
	CVector2D m_pos;
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
};
