#pragma once
#include <Gllibrary.h>
#include "../Base/Base.h"

class Notes :public Base {
public:
	enum {
		eState_Left,
		eState_CenterLeft,
		eState_CenterRight,
		eState_Right,
		eState_RightSide,
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
	CImage notes[5];
	CImage criticalnotes[5];
	CImage doublenotes[5];
	CImage notes_long[5];
	CImage slide[5];
	CImage slide2[5];
	/*CImage TapA;
	CImage TapS;
	CImage TapD;
	CImage TapE;
	CImage TapQ;
	CImage TapW;
	CImage TapR;
	CImage TapF;*/
	CVector2D Right_pos;
	CVector2D CenterRight_pos;
	CVector2D CenterLeft_pos;
	CVector2D Left_pos;
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
