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
	//�f�[�^�̓ǂݎ��A���ёւ�
	Ranking(int state);
	//void TempData();
	//m_score��[0]���珇�Ԃ�10�o��
	void Draw();
	//�����摜�̓ǂݍ��݁A�؂���A�T�C�Y�Z�b�g
	void ImageSet();
	void LeanOn();
	void Baby();
	void Bones();
	void Update();
};