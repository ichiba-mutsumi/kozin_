#pragma once
#include "../Base/Base.h"
class FreeNotes :public Base {
private:
	int m_time;
	int NotesArea;
	int NotesCount;
	int NotesCountToDelete;
	int radius;
	int rotate;
	int TimeLimit;
	float NextAngle;
	float NotesAngle;
	bool state;
	CVector2D m_pos;
	CVector2D center;
	CImage CircleNotes;
	CImage CircleNotesFrame;
public:
	FreeNotes(/*int time*/);
	void Update();
	void Draw();
	void ImageSet();
	void SizeSet();
	void Timer();
	void NotesMove();
	void RandomArea();
	void CheckHitNotes();
	void CountDownToDelete();
};