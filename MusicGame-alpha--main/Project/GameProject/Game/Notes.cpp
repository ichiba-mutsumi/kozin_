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
Notes::Notes(int area, int time, int type) :Base(eType_Notes) {
	ImageSet();
	m_time = time + 180;
	Notestype = type;
	NotesArea = area;
	VecSet();
	if (m_time <= 0) {
		state = true;
	}
	switch (area) {
	case eState_Q:
		m_vec = Q_vec;
		break;
	case eState_W:
		m_vec = W_vec;
		break;
	case eState_E:
		m_vec = E_vec;
		break;
	case eState_R:
		m_vec = R_vec;
		break;
	case eState_A:
		m_vec = A_vec;
		break;
	case eState_S:
		m_vec = S_vec;
		break;
	case eState_D:
		m_vec = D_vec;
		break;
	case eState_F:
		m_vec = F_vec;
		break;

		/*case eState_RightSide:
			RNotesCount = 0;
			RArea(0, 0);
			m_img = CircleNotes;*/

	}
	switch (type) {
	case etype_normal:
		m_img = notes;
		break;
	case etype_double:
		m_img = doublenotes;
		break;
	case etype_kira:
		m_img = criticalnotes;
		break;
	case etype_long:
		m_img = notes_long;
		break;
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
	case eState_Q:
		if (state == true) {
			m_img.SetPos(m_pos);
			m_img.Draw();
			/*TapA.SetPos(m_pos);
			TapA.Draw();*/
		}
		break;
	case eState_W:
		if (state == true) {
			m_img.SetPos(m_pos);
			m_img.Draw();
			/*TapS.SetPos(m_pos);
			TapS.Draw();*/
		}
		break;
	case eState_E:
		if (state == true) {
			m_img.SetPos(m_pos);
			m_img.Draw();
			/*TapD.SetPos(m_pos);
			TapD.Draw();*/
		}
		break;
	case eState_R:
		if (state == true) {
			m_img.SetPos(m_pos);
			m_img.Draw();
			/*TapE.SetPos(m_pos);
			TapE.Draw();*/
		}
		break;
	case  eState_A:
		if (state == true) {
			//RSizeSet();
			m_img.SetPos(m_pos);
			m_img.Draw();
		}
		break;
	case  eState_S:
		if (state == true) {
			//RSizeSet();
			m_img.SetPos(m_pos);
			m_img.Draw();
		}
		break;
	case  eState_D:
		if (state == true) {
			//RSizeSet();
			m_img.SetPos(m_pos);
			m_img.Draw();
		}
		break;
	case  eState_F:
		if (state == true) {
			//RSizeSet();
			m_img.SetPos(m_pos);
			m_img.Draw();
		}
		break;

	};
}
void Notes::Update() {
	if (m_time == 0) {
		HitCountDown = 60;
	}
	if (state == true) {
		HitCountDown--;
		LCheckHitNotes();
		m_pos += m_vec;
	}
	LNotesDelete();
	Timer();
}
void Notes::LCheckHitNotes() {
	//オートモード
	/*if (HitCountDown == 0) {
		SOUND("Tap")->Play();
		ShareNum::AddScore(ShareNum::ModeNum);
		m_kill = true;
	}*/
	if (PUSH(CInput::eButton1)) {
		if (-9 <= HitCountDown && HitCountDown <= 9 && NotesArea == eState_Q) {
			//Base::Add(new Hit(m_pos));
			SOUND("Tap")->Play();
			m_kill = true;
			ShareNum::AddScore(ShareNum::ModeNum);
			/*if (HitCountDown == 0) {
				ShareNum::score += 100;
			}*/
		}
	}
	if (PUSH(CInput::eButton2)) {
		if (-9 <= HitCountDown && HitCountDown <= 9 && NotesArea == eState_W) {
			//Base::Add(new Hit(m_pos));
			SOUND("Tap")->Play();
			m_kill = true;
			ShareNum::AddScore(ShareNum::ModeNum);
			/*if (HitCountDown == 0) {
				ShareNum::score += 100;
			}*/
		}
	}
	if (PUSH(CInput::eButton3)) {
		if (-9 <= HitCountDown && HitCountDown <= 9 && NotesArea == eState_E) {
			//Base::Add(new Hit(m_pos));
			SOUND("Tap")->Play();
			m_kill = true;
			ShareNum::AddScore(ShareNum::ModeNum);
			/*if (HitCountDown == 0) {
				ShareNum::score += 100;
			}*/
		}
	}
	if (PUSH(CInput::eButton4)) {
		if (-9 <= HitCountDown && HitCountDown <= 9 && NotesArea == eState_R) {
			//Base::Add(new Hit(m_pos));
			SOUND("Tap")->Play();
			m_kill = true;
			ShareNum::AddScore(ShareNum::ModeNum);
			/*if (HitCountDown == 0) {
				ShareNum::score += 100;
			}*/
		}
	}
	if (PUSH(CInput::eButton5)) {
		if (-9 <= HitCountDown && HitCountDown <= 9 && NotesArea == eState_A) {
			//Base::Add(new Hit(m_pos));
			SOUND("Tap")->Play();
			m_kill = true;
			ShareNum::AddScore(ShareNum::ModeNum);
			/*if (HitCountDown == 0) {
				ShareNum::score += 100;
			}*/
		}
	}
	if (PUSH(CInput::eButton6)) {
		if (-9 <= HitCountDown && HitCountDown <= 9 && NotesArea == eState_S) {
			//Base::Add(new Hit(m_pos));
			SOUND("Tap")->Play();
			m_kill = true;
			ShareNum::AddScore(ShareNum::ModeNum);
			/*if (HitCountDown == 0) {
				ShareNum::score += 100;
			}*/
		}
	}
	if (PUSH(CInput::eButton7)) {
		if (-9 <= HitCountDown && HitCountDown <= 9 && NotesArea == eState_D) {
			//Base::Add(new Hit(m_pos));
			SOUND("Tap")->Play();
			m_kill = true;
			ShareNum::AddScore(ShareNum::ModeNum);
			/*if (HitCountDown == 0) {
				ShareNum::score += 100;
			}*/
		}
	}
	if (PUSH(CInput::eButton8)) {
		if (-9 <= HitCountDown && HitCountDown <= 9 && NotesArea == eState_F) {
			//Base::Add(new Hit(m_pos));
			SOUND("Tap")->Play();
			m_kill = true;
			ShareNum::AddScore(ShareNum::ModeNum);
			/*if (HitCountDown == 0) {
				ShareNum::score += 100;
			}*/
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
	notes = COPY_RESOURCE("Note", CImage);
	criticalnotes = COPY_RESOURCE("Note2", CImage);
	doublenotes = COPY_RESOURCE("Note3", CImage);
	notes_long = COPY_RESOURCE("Note4", CImage);
	slide = COPY_RESOURCE("Note5", CImage);
	slide2 = COPY_RESOURCE("Note6", CImage);
	/*for (int i = 1; i < 5; i++) {
		notes[i] = COPY_RESOURCE("Note", CImage);
		criticalnotes[i] = COPY_RESOURCE("Note2", CImage);
		doublenotes[i] = COPY_RESOURCE("Note3", CImage);
		notes_long[i] = COPY_RESOURCE("Note4", CImage);
		slide[i] = COPY_RESOURCE("Note5", CImage);
		slide2[i] = COPY_RESOURCE("Note6", CImage);
	}*/

	//画像の切り取り
	notes.SetRect(23, 56, 438, 472);
	notes_long.SetRect(63, 32, 497, 520);
	doublenotes.SetRect(112, 17, 528, 433);
	criticalnotes.SetRect(10, 16, 428, 432);
	slide.SetRect(159, 49, 530, 362);
	slide2.SetRect(115, 30, 536, 430);
	/*CircleNotes[1].SetRect(23, 226, 438, 225);
	CircleNotes[2].SetRect(23, 226, 438, 225);
	CircleNotes[3].SetRect(23, 226, 438, 225);
	CircleNotes[4].SetRect(256, 256, 512, 512);
	DarkCircleNotes[2].SetRect(263, 6, 505, 250);
	DarkCircleNotes[3].SetRect(28, 275, 228, 475);
	DarkCircleNotes[4].SetRect(256, 256, 512, 512);
	doublenotes[1].SetRect(159, 47, 528, 362);
	SquareNotes[2].SetRect(258, 2, 509, 255);
	SquareNotes[3].SetRect(21, 272, 235, 499);
	SquareNotes[4].SetRect(271, 272, 495, 496);
	notes_long[1].SetRect(22, 21, 592, 495);
	CircleNotesFrame[2].SetRect(270, 14, 499, 241);
	CircleNotesFrame[3].SetRect(10, 268, 241, 500);
	CircleNotesFrame[4].SetRect(266, 268, 501, 501);*/
	//中心位置の設定
	notes.SetCenter(70, 65);
	doublenotes.SetCenter(70, 65);
	criticalnotes.SetCenter(70, 65);
	notes_long.SetCenter(70, 65);
	slide.SetCenter(70, 65);
	slide2.SetCenter(70, 65);
	//サイズの指定
	notes.SetSize(140, 130);
	doublenotes.SetSize(140, 130);
	criticalnotes.SetSize(140, 130);
	notes_long.SetSize(140, 130);
	slide.SetSize(140, 130);
	slide2.SetSize(140, 130);

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
void Notes::LNotesDelete() {
	if (HitCountDown == -20) {
		ShareNum::SubScore(ShareNum::ModeNum);
		m_kill = true;
	}
}
void Notes::VecSet()
{
	//終わりの座標設定
	Qend = CVector2D(1140, 145);
	Wend = CVector2D(1340, 395);
	Eend = CVector2D(1380, 708);
	Rend = CVector2D(1152, 923);
	Aend = CVector2D(791, 147);
	Send = CVector2D(580, 389);;
	Dend = CVector2D(545, 707);
	Fend = CVector2D(775, 923);
	//画面の中央の座標
	Center = CVector2D(1920 / 2, 1080 / 2);
	Q_vec = (Qend - Center) / 60;
	W_vec = (Wend - Center) / 60;
	E_vec = (Eend - Center) / 60;
	R_vec = (Rend - Center) / 60;
	A_vec = (Aend - Center) / 60;
	S_vec = (Send - Center) / 60;
	D_vec = (Dend - Center) / 60;
	F_vec = (Fend - Center) / 60;
}
