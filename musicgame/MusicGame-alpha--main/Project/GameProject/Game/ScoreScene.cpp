#include "ShareNum.h"
#include "ScoreScene.h"
#include "SelectScene/SelectScene.h"
ScoreScene::ScoreScene():Base(eType_Scene) 
, text("C:\\Windows\\Fonts\\msgothic.ttc", 80)
, PushEnter_Text("C:\\Windows\\Fonts\\msgothic.ttc", 50) {
	glClearColor(1.0, 1.0, 1.0, 1.0);
	ImageSet();
}
ScoreScene::~ScoreScene() {
	Base::KillAll();
	Base::Add(new SelectScene());
}
void ScoreScene::Draw() {
	BackGround.Draw();
	int i = 0;
	int Temp = ShareNum::score;
	while (i < 5) {
		int k;
		k = Temp % 10;
		Temp = Temp / 10;
		m_img[k].SetPos(1140 - i * 120, 500);
		m_img[k].Draw();
		i++;
	}
	text.Draw(730, 400, 0, 0, 0, "YOUR SCORE!");
	PushEnter_Text.Draw(1500, 1000, 0, 0, 0, "Push EnterKey");
}
void ScoreScene::ImageSet() {
	for (int i = 0; i < 10; i++) {
		m_img[i] = COPY_RESOURCE("BNumber", CImage);
		m_img[i].SetRect(i * 39, 0, (i + 1) * 39, 77);
		m_img[i].SetSize(100, 200);
	}
	BackGround = COPY_RESOURCE("Forest1", CImage);
	BackGround.SetRect(0,0,2048,1500);
	BackGround.SetSize(1920, 1080);
}
void ScoreScene::Update() {
	if (PUSH(CInput::eButton10)) {
		m_kill = true;
	}
}