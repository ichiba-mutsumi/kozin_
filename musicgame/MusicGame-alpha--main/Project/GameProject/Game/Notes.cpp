#include "Notes.h"
#include "ShareNum.h"
#include <iostream>
#include <random>
std::random_device rnd;
std::default_random_engine eng(rnd());
std::uniform_int_distribution<int> Ran(0, 4);
Notes::Notes(int area,int time,int speed) :Base(eType_Notes) {
	ImageSet();
	m_time = time + 180;
	m_speed = speed;
	NotesArea = area;
	if (m_time <= 0) {
		state = true;
	}
	switch (area) {
	case eState_Left:
		LSpeedSet();
		m_pos = Left_pos;
		m_img = SquareNotes[Ran(eng)];
		break;
	case eState_CenterLeft:
		LSpeedSet();
		m_pos = CenterLeft_pos;
		m_img = SquareNotes[Ran(eng)];
		break;
	case eState_CenterRight:
		LSpeedSet();
		m_pos = CenterRight_pos;
		m_img = SquareNotes[Ran(eng)];
		break;
	case eState_Right:
		LSpeedSet();
		m_pos = Right_pos;
		m_img = SquareNotes[Ran(eng)];
		break;
	/*case eState_RightSide:
		RNotesCount = 0;
		RArea(0, 0);
		m_img = CircleNotes;*/
	}
}
Notes::Notes(int area, int time, int x,int y) :Base(eType_Notes) {
	ImageSet();
	m_time = time + 216;
	NotesArea = area;
	if (m_time <= 0) {
		state = true;
	}
	RNotesCount = 0;
	RNotesCountToDelete = 20;
	RArea(x,y);
	ColorNum = Ran(eng);
	m_img = CircleNotes[ColorNum];
	Frame_img = CircleNotesFrame[Ran(eng)];
}
void Notes::Draw() {
	switch (NotesArea) {
	case eState_Left:
		if (state == true) {
			m_img.SetPos(m_pos);
			m_img.Draw();
			TapA.SetPos(m_pos);
			TapA.Draw();
		}
		break;
	case eState_CenterLeft:
		if (state == true) {
			m_img.SetPos(m_pos);
			m_img.Draw();
			TapS.SetPos(m_pos);
			TapS.Draw();
		}
		break;
	case eState_CenterRight:
		if (state == true) {
			m_img.SetPos(m_pos);
			m_img.Draw();
			TapD.SetPos(m_pos);
			TapD.Draw();
		}
		break;
	case eState_Right:
		if (state == true) {
			m_img.SetPos(m_pos);
			m_img.Draw();
			TapF.SetPos(m_pos);
			TapF.Draw();
		}
		break;
	case  eState_RightSide:
		if (state == true) {
			RSizeSet();
			Frame_img.Draw();
			m_img.Draw();
		}
		break;
	}
};
void Notes::Update() {
	switch (NotesArea) {
	case eState_Left:
	case eState_CenterLeft:
	case eState_CenterRight:
	case eState_Right:
		if (m_time == 0) {
			HitCountDown = ((900 - 118) / m_speed) + 1;
		}
		if (state == true) {
			HitCountDown--;
			LCheckHitNotes();
			m_pos.y += m_speed;
		}
		break;
	case  eState_RightSide:
		if (state == true) {
			RCheckHitNotes();
			CountDownToDelete();
		}
		break;
	}
	LNotesDelete();
	Timer();
}
void Notes::LCheckHitNotes() {
	/*if (HitCountDown==0) {
		SOUND("Tap")->Play();
		m_kill = true;
	}*/
	if (PUSH(CInput::eButton1)) {
		if (-10 <= HitCountDown && HitCountDown <= 10 && m_pos.x == 5) {
			//Base::Add(new Hit(m_pos));
			SOUND("Tap")->Play();
			m_kill = true;
			ShareNum::score += 250;
			if (HitCountDown == 0) {
				ShareNum::score += 250;
			}
		}
	}
	if (PUSH(CInput::eButton2)) {
		if (-10 <= HitCountDown && HitCountDown <= 10 && m_pos.x == 245) {
			//Base::Add(new Hit(m_pos));
			SOUND("Tap")->Play();
			m_kill = true;
			ShareNum::score += 250;
			if (HitCountDown == 0) {
				ShareNum::score += 250;
			}
		}
	}
	if (PUSH(CInput::eButton3)) {
		if (-10 <= HitCountDown && HitCountDown <= 10 && m_pos.x == 485) {
			//Base::Add(new Hit(m_pos));
			SOUND("Tap")->Play();
			m_kill = true;
			ShareNum::score += 250;
			if (HitCountDown == 0) {
				ShareNum::score += 250;
			}
		}
	}
	if (PUSH(CInput::eButton4)) {
		if (-10 <= HitCountDown && HitCountDown <= 10 && m_pos.x == 725) {
			//Base::Add(new Hit(m_pos));
			SOUND("Tap")->Play();
			m_kill = true;
			ShareNum::score += 250;
			if (HitCountDown == 0) {
				ShareNum::score += 250;
			}
		}
	}
}
void Notes::Timer() {
	m_time--;
	if (m_time <= 0) {
		state = true;
	}
	//std::cout << m_time << std::endl;
}
void Notes::ImageSet() {
	//座標設定
	Left_pos = CVector2D(5, 0);
	CenterLeft_pos = CVector2D(245, 0);
	CenterRight_pos = CVector2D(485, 0);
	Right_pos = CVector2D(725, 0);
	//画像を設定
	TapA = COPY_RESOURCE("TapA", CImage);
	TapS = COPY_RESOURCE("TapS", CImage);
	TapD = COPY_RESOURCE("TapD", CImage);
	TapF = COPY_RESOURCE("TapF", CImage);
	CircleNotes[0] = COPY_RESOURCE("Notes", CImage);
	DarkCircleNotes[0] = COPY_RESOURCE("DarkCircle", CImage);
	SquareNotes[0] = COPY_RESOURCE("Notes", CImage);
	CircleNotesFrame[0] = COPY_RESOURCE("Notes", CImage);
	for (int i = 1; i < 5; i++) {
		CircleNotes[i] = COPY_RESOURCE("Circle4", CImage);
		DarkCircleNotes[i] = COPY_RESOURCE("DarkCircle4", CImage);
		SquareNotes[i] = COPY_RESOURCE("Square4", CImage);
		CircleNotesFrame[i] = COPY_RESOURCE("CircleFrame", CImage);
	}
	//画像の切り取り
	CircleNotes[0].SetRect(263, 157, 596, 493);
	CircleNotesFrame[0].SetRect(1595, 0, 1920, 325);
	SquareNotes[0].SetRect(767, 445, 1154, 636);
	CircleNotes[1].SetRect(8,7,248,249);
	CircleNotes[2].SetRect(263,6,505,250);
	CircleNotes[3].SetRect(28,275,228,475);
	CircleNotes[4].SetRect(256,256,512,512); 
	DarkCircleNotes[1].SetRect(8, 7, 248, 249);
	DarkCircleNotes[2].SetRect(263, 6, 505, 250);
	DarkCircleNotes[3].SetRect(28, 275, 228, 475);
	DarkCircleNotes[4].SetRect(256, 256, 512, 512);
	SquareNotes[1].SetRect(7,8,248,248);
	SquareNotes[2].SetRect(258,2,509,255);
	SquareNotes[3].SetRect(21,272,235,499);
	SquareNotes[4].SetRect(271,272,495,496);
	CircleNotesFrame[1].SetRect(18,19,241,237);
	CircleNotesFrame[2].SetRect(270,14,499,241);
	CircleNotesFrame[3].SetRect(10,268,241,500);
	CircleNotesFrame[4].SetRect(266,268,501,501);
	//サイズの指定
	for (int i = 0; i < 5; i++) {
		SquareNotes[i].SetSize(236, 118);
		CircleNotes[i].SetSize(120, 120);
		DarkCircleNotes[i].SetSize(120, 120);
	}
}
void Notes::LSpeedSet() {
	//基準をspeed = 8とする
	if(m_speed < 8) {
		int temp= 780 / m_speed - 780 / 8;
		m_time -= temp;
	}
	else if (m_speed > 8) {
		int temp = 780 / 8 - 780 / m_speed;
		m_time +=temp;
	}
}
void Notes::RSizeSet() {
	if (RNotesCount <61) {
		RNotesCount++;
	}
	m_img.SetSize(120, 120);
	Frame_img.SetSize(180 - RNotesCount , 180 - RNotesCount );
	m_img.SetPos(m_pos);
	Frame_img.SetPos(m_pos.x-30 + RNotesCount / 2, m_pos.y-30 + RNotesCount / 2);
}
void Notes::RCheckHitNotes() {
	CVector2D mouse_pos = CInput::GetMousePoint();
	if (PUSH(CInput::eMouseL) && RNotesCount>=45) {
		if (std::pow((mouse_pos.x - m_pos.x - 60), 2.0) + std::pow((mouse_pos.y - m_pos.y - 60), 2.0) <= 3600 ) {
			SOUND("Tap")->Play();
			m_kill = true;
			ShareNum::score += 350;
			if (RNotesCount == 60) {
				ShareNum::score += 650;
			}
		}
	}
	if (std::pow((mouse_pos.x - m_pos.x - 60), 2.0) + std::pow((mouse_pos.y - m_pos.y - 60), 2.0) <= 3600 && RNotesCount >= 45) {
		m_img = DarkCircleNotes[ColorNum];
	}
	else {
		m_img = CircleNotes[ColorNum];
	}
}
void Notes::RArea(int x,int y) {
	m_pos.x = 1025 + x * 725 / 9;
	m_pos.y = 172 + y * 728 / 9;
}
void Notes::CountDownToDelete() {
	if (RNotesCount >= 60) {
		RNotesCountToDelete--;
		if (RNotesCountToDelete <= 0) {
			m_kill = true;
		}
	}
}
void Notes::LNotesDelete() {
	if (m_pos.y >= 1150) {
		m_kill = true;
	}
}