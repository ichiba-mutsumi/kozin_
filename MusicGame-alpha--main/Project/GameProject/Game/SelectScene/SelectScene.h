#pragma once
#include <Gllibrary.h>
#include "../../Base/Base.h"
#include "../ShareNum.h"

class SelectScene :public Base {
	enum {
		//�Q�[���^�C�g����state�����
		LeanOn,
		Baby,
		Bones,
	};
private:
	CImage BackGround;
	char game_title[10][100] = { "LeanOn","Baby","Bones"/*,"ABC","ABC"*/};
	CFont title_text;
	CFont select_title_text;
	CFont PushEnter_Text;
public:
	SelectScene();
	~SelectScene();
	void Draw();
	void Update();
	void ImageSet();
	void SoundPlay();
	void SoundStop();
};