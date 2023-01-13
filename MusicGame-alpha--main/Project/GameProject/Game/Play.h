#pragma once
#include <Gllibrary.h>
#include "../Base/Base.h"
class Play :public Base {
private:
	enum {
		eNum_Gothic,
		eNum_Bell,
		eNum_Yuki,
		eNum_Michikusa,
	};
	CImage m_img;
	CImage gamen;
	CImage TapA;
	CImage TapS;
	CImage TapD;
	CImage TapE;
	CImage TapQ;
	CImage TapW;
	CImage TapR;
	CImage TapF;
	CImage m_NotesBar;
	CImage NotesBar;
	CImage NotesBarBlue[4];
	CImage LeftClick;
	CVideo* video;
	CFont score_text;
	int CountDownToStart;//このカウントが終わったら音楽が始まる
	int CountUpToEnd;//曲の長さ、秒数＊６０でセレクト画面に戻る
	int SoundNum;//選んだ曲名で因数を指定（代入）
	int PushCount[8];
	float OneNotes;//八分音符一個分のフレーム
	float NotesCount;
	bool PushKey[8];
public:
	Play(int ChoiceSound);
	~Play();
	void ImageSet();
	void Draw();
	void Update();
	void Gothic();
	void Bell();
	void Yuki();
	void Michikusa();
	void NotesSet();//プリセットを配置している
	void NotesPreSet(int SetNum);//一小節ごとのケース
};