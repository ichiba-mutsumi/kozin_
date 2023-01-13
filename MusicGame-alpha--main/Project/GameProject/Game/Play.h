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
	int CountDownToStart;//���̃J�E���g���I������特�y���n�܂�
	int CountUpToEnd;//�Ȃ̒����A�b�����U�O�ŃZ���N�g��ʂɖ߂�
	int SoundNum;//�I�񂾋Ȗ��ň������w��i����j
	int PushCount[8];
	float OneNotes;//������������̃t���[��
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
	void NotesSet();//�v���Z�b�g��z�u���Ă���
	void NotesPreSet(int SetNum);//�ꏬ�߂��Ƃ̃P�[�X
};