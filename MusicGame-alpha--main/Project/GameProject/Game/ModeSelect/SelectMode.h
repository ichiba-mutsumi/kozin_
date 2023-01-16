#pragma once
#include <Gllibrary.h>
#include "../../Base/Base.h"
#include "../ShareNum.h"

class SelectMode :public Base {
	enum {
		//ゲームタイトルのstateを作る
		eMode_Normal,
		eMode_Challenge,
	};
private:
	CImage BackGround;
	char game_title[10][100] = { "Normal","challenge" };
	CFont title_text;
	CFont select_title_text;
	CFont PushEnter_Text;
public:
	SelectMode();
	void Draw();
	void Update();
	void ImageSet();
};