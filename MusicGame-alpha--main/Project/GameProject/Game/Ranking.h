#pragma once
#include "../Base/Base.h"

class Ranking :public Base {
public:
	enum {
		eState_Gothic,
		eState_Bell,
		eState_Tutorial,
		eState_Michikusa,
	};
	int max;
	int SoundNum;
	int m_score[10000];
	CImage m_img[11];
	CFont Ranking_text;
	std::string data[10000];
public:
	//データの読み取り、並び替え
	Ranking(int state);
	//void TempData();
	//m_scoreを[0]から順番に10個出力
	void Draw();
	//数字画像の読み込み、切り取り、サイズセット
	void ImageSet();
	void Gothic();
	void Bell();
	void Tutorial();
	void Michikusa();
	void Update();
};