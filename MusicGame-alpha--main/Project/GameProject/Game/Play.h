#pragma once
#include <Gllibrary.h>
#include "../Base/Base.h"
class Play :public Base {
private:
	enum {
		eNum_Gothic,
		eNum_Tir,
		eNum_Bones,
		eNum_Tutorial,
	};
	CImage gamen;
	CImage m_NotesBar;
	CImage NotesBar;
	CImage NotesBarBlue[4];
	CImage LeftClick;
	CVideo* video;
	CFont score_text;
	int CountDownToStart;
	int CountUpToEnd;
	int SoundNum;
	int PushCount[8];
	float OneNotes;
	float NotesCount;
	bool PushKey[8];
public:
	Play(int ChoiceSound);
	~Play();
	void ImageSet();
	void Draw();
	void Update();
	void Gothic();
	void Tir();
	void Tutorial();
	void Bones();
	void NotesSet();
	void NotesPreSet(int SetNum);
};