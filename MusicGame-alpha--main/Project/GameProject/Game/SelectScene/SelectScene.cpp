#include "SelectScene.h"
#include "../ModeSelect/SelectMode.h"
#include "../Ranking.h"
#include "../ShareNum.h"
#include "../Play.h"
#include <iostream>

SelectScene::SelectScene() :Base(eType_Scene)
, title_text("C:\\Windows\\Fonts\\msgothic.ttc", 64)
, select_title_text("C:\\Windows\\Fonts\\msgothic.ttc", 80)
, PushEnter_Text("C:\\Windows\\Fonts\\msgothic.ttc", 50) {
	glClearColor(1.0, 1.0, 1.0, 1.0);
	ShareNum::GameNum = 0;
	ShareNum::debug = false;
	Base::Add(new Ranking(0));
	ImageSet();
}
SelectScene::~SelectScene() {
}
void SelectScene::Draw() {
	BackGround.Draw();
	PushEnter_Text.Draw(1500, 950, 1, 1, 1, "Push EnterKey");
	//選択中のタイトルを大きく表示
	for (int i = 0; i < ShareNum::MaxGame; i++) {
		if (ShareNum::GameNum != i) {
			title_text.Draw(274, 214 + i * 150, 1, 1, 1, game_title[i]);
		}
		else {
			select_title_text.Draw(274, 214 + i * 150, 1, 1, 1, game_title[i]);
		}
	}
}
void SelectScene::Update() {
	if (PUSH(CInput::eUp)) {
		if (ShareNum::GameNum > 0) {
			ShareNum::GameNum--;
		}
	}
	if (PUSH(CInput::eDown)) {
		if (ShareNum::GameNum < ShareNum::MaxGame - 1) {
			ShareNum::GameNum++;
		}
	}
	if (PUSH(CInput::eButton10)) {
		std::cout << "select fin" << std::endl;
		GameChoice = true;
	}
	if (GameChoice) {
		NextSceneCount--;
		if (NextSceneCount < 0) {
			Base::KillAll();
			Base::Add(new SelectMode());
		}
	}
}
void SelectScene::ImageSet() {
	BackGround = COPY_RESOURCE("select", CImage);
	BackGround.SetRect(0, 0, 1918, 1078);
	BackGround.SetSize(1920, 1080);
}