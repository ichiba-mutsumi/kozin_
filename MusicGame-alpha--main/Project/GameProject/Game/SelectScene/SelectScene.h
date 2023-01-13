#pragma once
#include <Gllibrary.h>
#include "../../Base/Base.h"
#include "../ShareNum.h"

class SelectScene :public Base {
	enum {
		//ゲームタイトルのstateを作る
		Gothic,
		Bell,
		Yuki,
		Rosa, 
	};
private:
	CImage BackGround;
	char game_title[10][100] = { "Gothic","Bell","Yuki","Rosa",/*,"ABC","ABC"*/};
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