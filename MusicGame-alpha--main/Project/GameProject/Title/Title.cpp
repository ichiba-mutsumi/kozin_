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
	if (PUSH(CInput::eButton1)) {
		SetKill();
	}
}

void Title::Draw()
{
	m_img.Draw();
	m_title_text.Draw(750, 256, 0, 0, 0, "Mya-!!");
	title_text.Draw(100, 512, 0, 0, 0, "pushA");
}
