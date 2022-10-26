#pragma once
#include "../Base/Base.h"

class Score :public Base {
public:
	CImage m_img[11];
	int score;
	int Temp;
public:
	Score();
	void Update();
	void ScorePlus();
	void Draw();
	void ImageSet();
};
