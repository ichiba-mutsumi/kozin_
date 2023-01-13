#pragma once
#include "../Base/Base.h"

class Ranking :public Base {
public:
	enum {
		eState_Gothic,
		eState_Bell,
		eState_Yuki,
		eState_Rosa,
	};
	int max;
	int SoundNum;
	int m_score[10000];
	CImage m_img[11];
	CFont Ranking_text;
	std::string data[10000];
public:
	//�f�[�^�̓ǂݎ��A���ёւ�
	Ranking(int state);
	//void TempData();
	//m_score��[0]���珇�Ԃ�10�o��
	void Draw();
	//�����摜�̓ǂݍ��݁A�؂���A�T�C�Y�Z�b�g
	void ImageSet();
	void Gothic();
	void Bell();
	void Yuki();
	void Rosa();
	void Update();
};