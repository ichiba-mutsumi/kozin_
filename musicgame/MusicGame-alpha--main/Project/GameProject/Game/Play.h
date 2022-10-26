#pragma once
#include <Gllibrary.h>
#include "../Base/Base.h"
class Play :public Base {
private:
	enum {
		eNum_LeanOn,
		eNum_Baby,
		eNum_Bones,
	};
	CImage Lane;
	CImage m_NotesBar;
	CImage NotesBar;
	CImage NotesBarBlue[4];
	CImage LeftClick;
	CVideo* video;
	CFont score_text;
	int CountDownToStart;
	int CountUpToEnd;
	int SoundNum;
	int PushCount[4];
	float OneNotes;
	float NotesCount;
	bool PushKey[4];
public:
	Play(int ChoiceSound);
	~Play();
	void ImageSet();
	void Draw();
	void Update();
	void LeanOn();
	void Baby();
	void Bones();
	void NotesSet();
	void NotesPreSet(int SetNum);
};