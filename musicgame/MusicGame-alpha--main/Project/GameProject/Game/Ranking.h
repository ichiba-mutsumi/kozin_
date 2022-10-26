#pragma once
#include "../Base/Base.h"

class Ranking :public Base {
public:
	enum {
		eState_LeanOn,
		eState_Baby,
		eState_Bones,
	};
	int max;
	int SoundNum;
	int m_score[10];
	CImage m_img[11];
	CFont Ranking_text;
	std::string data[9999];
public:
	//データの読み取り、並び替え
	Ranking(int state);
	//void TempData();
	//m_scoreを[0]から順番に10個出力
	void Draw();
	//数字画像の読み込み、切り取り、サイズセット
	void ImageSet();
	void LeanOn();
	void Baby();
	void Bones();
	void Update();
};