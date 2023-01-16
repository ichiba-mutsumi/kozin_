#include "SelectMode.h"
#include "../ShareNum.h"
#include "../Play.h"
#include <iostream>

SelectMode::SelectMode() :Base(eType_Scene)
, title_text("C:\\Windows\\Fonts\\msgothic.ttc", 64)
, select_title_text("C:\\Windows\\Fonts\\msgothic.ttc", 80)
, PushEnter_Text("C:\\Windows\\Fonts\\msgothic.ttc", 50) {
	ShareNum::ModeNum = 0;
	std::cout << "mode lode" << std::endl;
	ImageSet();
}
void SelectMode::Draw() {
	BackGround.Draw();
	PushEnter_Text.Draw(1500, 950, 1, 1, 1, "Push EnterKey");
	//選択中のタイトルを大きく表示
	for (int i = 0; i < ShareNum::MaxGame; i++) {
		if (ShareNum::ModeNum != i) {
			title_text.Draw(274, 214 + i * 150, 1, 1, 1, game_title[i]);
		}
		else {
			select_title_text.Draw(274, 214 + i * 150, 1, 1, 1, game_title[i]);
		}
	}
}
void SelectMode::Update() {
	if (PUSH(CInput::eUp)) {
		if (ShareNum::ModeNum > 0) {
			ShareNum::ModeNum--;
		}
	}
	if (PUSH(CInput::eDown)) {
		if (ShareNum::ModeNum < ShareNum::MaxMode - 1) {
			ShareNum::ModeNum++;
		}
	}
	if (PUSH(CInput::eButton10)) {
		std::cout << "mode push" << std::endl;
		Base::KillAll();
		Base::Add(new Play(ShareNum::GameNum));
		switch (ShareNum::ModeNum) {
		case eMode_Normal:
			//Base::Add(new ミニゲームのクラス);
			break;
		case eMode_Challenge:
			break;
		}
	}
}

void SelectMode::ImageSet(){
	BackGround = COPY_RESOURCE("mode",CImage);
	BackGround.SetRect(0, 0, 1918, 1078);
	BackGround.SetSize(1920, 1080);
}
