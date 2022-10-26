#include "SelectScene.h"
#include "../Ranking.h"
#include "../ShareNum.h"
#include "../Play.h"

SelectScene::SelectScene() :Base(eType_Scene)
, title_text("C:\\Windows\\Fonts\\msgothic.ttc", 64)
, select_title_text("C:\\Windows\\Fonts\\msgothic.ttc", 80)
, PushEnter_Text("C:\\Windows\\Fonts\\msgothic.ttc", 50) {
	glClearColor(1.0, 1.0, 1.0, 1.0);
	ShareNum::GameNum = 0;
	ShareNum::debug = false;
	Base::Add(new Ranking(0));
	ImageSet();
	SoundPlay();
}
SelectScene::~SelectScene() {
	SoundStop();
}
void SelectScene::Draw() {
	BackGround.Draw();
	PushEnter_Text.Draw(1500, 1000, 1, 1, 1, "Push EnterKey");
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
			SoundStop();
			SoundPlay();
		}
	}
	if (PUSH(CInput::eDown)) {
		if (ShareNum::GameNum < ShareNum::MaxGame - 1) {
			ShareNum::GameNum++;
			SoundStop();
			SoundPlay();
		}
	}
	if (PUSH(CInput::eButton10)) {
		Base::KillAll();
		switch (ShareNum::GameNum) {
		case LeanOn:
			Base::Add(new Play(LeanOn));
			break;
		case Baby:
			Base::Add(new Play(Baby));
			break;
		case Bones:
			Base::Add(new Play(Bones));
			break;
		}
	}
}
void SelectScene::SoundPlay() {
	switch (ShareNum::GameNum) {
	case LeanOn:
		SOUND("LeanOn")->Play();
		break;
	case Baby:
		SOUND("Baby")->Play();
		break;
	case Bones:
		SOUND("Bones")->Play();
		break;
	}
}
void SelectScene::SoundStop() {
		SOUND("LeanOn")->Stop();
		SOUND("Baby")->Stop();
		SOUND("Bones")->Stop();
}
void SelectScene::ImageSet() {
	BackGround = COPY_RESOURCE("FoxLandcape", CImage);
	BackGround.SetRect(0, 300, 1024, 900);
	BackGround.SetSize(1920, 1080);
}