#include "Notes.h"
#include "ShareNum.h"
#include <iostream>
#include <random>
#define SCREEN_WIDTH 1920
#define SCREEN_HEIGHT 1080

std::random_device rnd;
std::default_random_engine eng(rnd());
std::uniform_int_distribution<int> Ran(0, 4);
//コンストラクタ
Notes::Notes(int area, int time, int speed) :Base(eType_Notes) {
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

		m_img = doublenotes[Ran(eng)];
		break;
	case eState_CenterLeft:
		LSpeedSet();
		
		m_img = doublenotes[Ran(eng)];
		break;
	case eState_CenterRight:
		LSpeedSet();
		
		m_img = doublenotes[Ran(eng)];
		break;
	case eState_Right:
		LSpeedSet();
		
		m_img = doublenotes[Ran(eng)];
		break;
		/*case eState_RightSide:
			RNotesCount = 0;
			RArea(0, 0);
			m_img = CircleNotes;*/

	}

}
//Notes::Notes(int area, int time, int x, int y) :Base(eType_Notes) {
//	ImageSet();
//	m_time = time + 216;
//	NotesArea = area;
//	if (m_time <= 0) {
//		state = true;
//	}
//	RNotesCount = 0;
//	RNotesCountToDelete = 20;
//	RArea(x, y);
//	ColorNum = Ran(eng);
//	m_img = note[ColorNum];
//	Frame_img = note_long[Ran(eng)];
//}
void Notes::Draw() {
	switch (NotesArea) {
	case eState_Left:
		if (state == true) {
			m_img.SetPos(m_pos);
			m_img.Draw();
			/*TapA.SetPos(m_pos);
			TapA.Draw();*/
		}
		break;
	case eState_CenterLeft:
		if (state == true) {
			m_img.SetPos(m_pos);
			m_img.Draw();
			/*TapS.SetPos(m_pos);
			TapS.Draw();*/
		}
		break;
	case eState_CenterRight:
		if (state == true) {
			m_img.SetPos(m_pos);
			m_img.Draw();
			/*TapD.SetPos(m_pos);
			TapD.Draw();*/
		}
		break;
	case eState_Right:
		if (state == true) {
			m_img.SetPos(m_pos);
			m_img.Draw();
			/*TapE.SetPos(m_pos);
			TapE.Draw();*/
		}
		break;
	case  eState_RightSide:
		if (state == true) {
			RSizeSet();
			m_img.SetPos(m_pos);
			m_img.Draw();
		}
		break;
	}
};
void Notes::Update() {
	if (state == true) {
		float ang = DtoR(45) * NotesArea;
		m_pos +=
			CVector2D(sin(ang), cos(ang)) * m_speed;

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
	if (PUSH(CInput::eButton5)) {
		if (-10 <= HitCountDown && HitCountDown <= 10 && m_pos.x == 965) {
			//Base::Add(new Hit(m_pos));
			SOUND("Tap")->Play();
			m_kill = true;
			ShareNum::score += 250;
			if (HitCountDown == 0) {
				ShareNum::score += 250;
			}
		}
	}
	if (PUSH(CInput::eButton6)) {
		if (-10 <= HitCountDown && HitCountDown <= 10 && m_pos.x == 1205) {
			//Base::Add(new Hit(m_pos));
			SOUND("Tap")->Play();
			m_kill = true;
			ShareNum::score += 250;
			if (HitCountDown == 0) {
				ShareNum::score += 250;
			}
		}
	}
	if (PUSH(CInput::eButton7)) {
		if (-10 <= HitCountDown && HitCountDown <= 10 && m_pos.x == 1445) {
			//Base::Add(new Hit(m_pos));
			SOUND("Tap")->Play();
			m_kill = true;
			ShareNum::score += 250;
			if (HitCountDown == 0) {
				ShareNum::score += 250;
			}
		}
	}
	if (PUSH(CInput::eButton8)) {
		if (-10 <= HitCountDown && HitCountDown <= 10 && m_pos.x == 1685) {
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
	m_pos = CVector2D(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
	//画像を設定
	/*TapA = COPY_RESOURCE("TapA", CImage);
	TapS = COPY_RESOURCE("TapS", CImage);
	TapD = COPY_RESOURCE("TapD", CImage);
	TapE = COPY_RESOURCE("TapE", CImage);
	TapQ = COPY_RESOURCE("TapQ", CImage);
	TapW = COPY_RESOURCE("TapW", CImage);
	TapR = COPY_RESOURCE("TapR", CImage);
	TapF = COPY_RESOURCE("TapF", CImage);*/
	notes[0] = COPY_RESOURCE("Note", CImage);
	criticalnotes[0] = COPY_RESOURCE("Note2", CImage);
	doublenotes[0] = COPY_RESOURCE("Note3", CImage);
	notes_long[0] = COPY_RESOURCE("Note4", CImage);
	slide[0] = COPY_RESOURCE("Note5", CImage);
	slide2[0] = COPY_RESOURCE("Note6", CImage);
	for (int i = 1; i < 5; i++) {
		notes[i] = COPY_RESOURCE("Note", CImage);
		criticalnotes[i] = COPY_RESOURCE("Note2", CImage);
		doublenotes[i] = COPY_RESOURCE("Note3", CImage);
		notes_long[i] = COPY_RESOURCE("Note4", CImage);
		slide[i] = COPY_RESOURCE("Note5", CImage);
		slide2[i] = COPY_RESOURCE("Note6", CImage);
	}
	//画像の切り取り
	notes[0].SetRect(23, 56, 438, 472);
	notes_long[0].SetRect(63, 32, 497, 520);
	doublenotes[0].SetRect(112, 17, 528, 433);
	/*CircleNotes[1].SetRect(23, 226, 438, 225);
	CircleNotes[2].SetRect(23, 226, 438, 225);
	CircleNotes[3].SetRect(23, 226, 438, 225);
	CircleNotes[4].SetRect(256, 256, 512, 512);*/
	criticalnotes[0].SetRect(10, 16, 428, 432);
	/*DarkCircleNotes[2].SetRect(263, 6, 505, 250);
	DarkCircleNotes[3].SetRect(28, 275, 228, 475);
	DarkCircleNotes[4].SetRect(256, 256, 512, 512);*/
	doublenotes[1].SetRect(159, 47, 528, 362);
	/*SquareNotes[2].SetRect(258, 2, 509, 255);
	SquareNotes[3].SetRect(21, 272, 235, 499);
	SquareNotes[4].SetRect(271, 272, 495, 496);*/
	notes_long[1].SetRect(22, 21, 592, 495);
	/*CircleNotesFrame[2].SetRect(270, 14, 499, 241);
	CircleNotesFrame[3].SetRect(10, 268, 241, 500);
	CircleNotesFrame[4].SetRect(266, 268, 501, 501);*/
	slide[0].SetRect(159,47,362,528);
	slide2[0].SetRect(22,21,594,496);
	//サイズの指定
	for (int i = 0; i < 5; i++) {
		doublenotes[i].SetSize(236, 118);
		notes[i].SetSize(120, 120);
		criticalnotes[i].SetSize(120, 120);
	}
}
void Notes::LSpeedSet() {
	//基準をspeed = 8とする
	if (m_speed < 8) {
		int temp = 780 / m_speed - 780 / 8;
		m_time -= temp;
	}
	else if (m_speed > 8) {
		int temp = 780 / 8 - 780 / m_speed;
		m_time += temp;
	}
}
void Notes::RSizeSet() {
	if (RNotesCount < 61) {
		RNotesCount++;
	}
	m_img.SetSize(120, 120);
	//Frame_img.SetSize(180 - RNotesCount, 180 - RNotesCount);
	m_img.SetPos(m_pos);
	//Frame_img.SetPos(m_pos.x - 30 + RNotesCount / 2, m_pos.y - 30 + RNotesCount / 2);
}
void Notes::RCheckHitNotes() {
	CVector2D mouse_pos = CInput::GetMousePoint();
	if (PUSH(CInput::eMouseL) && RNotesCount >= 45) {
		if (std::pow((mouse_pos.x - m_pos.x - 60), 2.0) + std::pow((mouse_pos.y - m_pos.y - 60), 2.0) <= 3600) {
			SOUND("Tap")->Play();
			m_kill = true;
			ShareNum::score += 350;
			if (RNotesCount == 60) {
				ShareNum::score += 650;
			}
		}
	}
	if (std::pow((mouse_pos.x - m_pos.x - 60), 2.0) + std::pow((mouse_pos.y - m_pos.y - 60), 2.0) <= 3600 && RNotesCount >= 45) {
		m_img = criticalnotes[ColorNum];
	}
	else {
		m_img = notes[ColorNum];
	}
}
void Notes::RArea(int x, int y) {
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