#include "Title.h"
#include"../Game/SelectScene/SelectScene.h"
Title::Title() :Base(eType_Scene),
m_title_text("C:\\Windows\\Fonts\\msgothic.ttc", 130),
title_text("C:\\Windows\\Fonts\\msgothic.ttc", 64)
{
	m_img = COPY_RESOURCE("Title", CImage);
}

Title::~Title()
{
	Base::Add(new SelectScene());
}

void Title::Update()
{
	if (PUSH(CInput::eButton10)) {
		SetKill();
	}
}

void Title::Draw()
{
	m_img.Draw();
	m_title_text.Draw(380, 256, 1, 1, 1, "Amamai");
	title_text.Draw(200, 650, 1, 1, 1, "push Enter");
}
