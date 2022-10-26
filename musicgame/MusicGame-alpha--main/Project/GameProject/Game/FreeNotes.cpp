#include "FreeNotes.h"
#include "../Base/Base.h"
#include "ShareNum.h"
#include <iostream>
#include <random>
#define PI 3.14159265359
FreeNotes::FreeNotes(/*int time*/):Base(eType_FreeNotes) {
	ImageSet();
	//m_time = time + 216;
	//if (m_time <= 0) {
	//	state = true;
	//}
	//NotesCount = 0;
	//NotesCountToDelete = 20;
	m_pos=CVector2D(1000, 500);
	RandomArea();
	TimeLimit = 0;
}
void FreeNotes::ImageSet() {
	CircleNotes = COPY_RESOURCE("Notes", CImage);
	CircleNotesFrame = COPY_RESOURCE("Notes", CImage);
	CircleNotes.SetRect(263, 157, 596, 493);
	CircleNotesFrame.SetRect(1595, 0, 1920, 325);
	CircleNotes.SetSize(120, 120);
}
void FreeNotes::Draw() {
	/*if (state == true) {
		SizeSet();
		CircleNotesFrame.Draw();
		CircleNotes.Draw();
	}*/
	CircleNotes.SetPos(m_pos.x - 60, m_pos.y - 60);
	CircleNotes.Draw();
}
void FreeNotes::SizeSet() {
	if (NotesCount < 120) {
		NotesCount++;
	}
	CircleNotes.SetSize(120, 120);
	CircleNotesFrame.SetSize(180 - NotesCount/2, 180 - NotesCount/2);
	CircleNotes.SetPos(m_pos);
	CircleNotesFrame.SetPos(m_pos.x - 30 + NotesCount / 4, m_pos.y - 30 + NotesCount / 4);
}
void FreeNotes::RandomArea() {
	std::random_device rnd;
	std::default_random_engine eng(rnd());
	std::uniform_int_distribution<int> distrX(1, 19);
	std::uniform_int_distribution<int> distrY(1, 9);
	m_pos.x = 140 + distrX(eng) * 1460 / 19;
	m_pos.y = 140 + distrY(eng) * 640 / 9;
	//std::cout << distrX(eng) << distrY(eng)<< "; ";
}
void FreeNotes::CheckHitNotes() {
	CVector2D mouse_pos = CInput::GetMousePoint();
	if (PUSH(CInput::eMouseL) && NotesCount >= 55) {
		if (std::pow((mouse_pos.x - m_pos.x - 60), 2.0) + std::pow((mouse_pos.y - m_pos.y - 60), 2.0) <= 3600) {
			SOUND("Tap")->Play();
			m_kill = true;
			ShareNum::score += 500;
		}
	}
}
void FreeNotes::Update() {
	/*if (state == true) {
		CheckHitNotes();
		CountDownToDelete();
		NotesMove();
	}*/
	//Timer();
	NotesMove();
}
void FreeNotes::Timer() {
	m_time--;
	if (m_time <= 0) {
		state = true;
	}
}
void FreeNotes::CountDownToDelete() {
	if (NotesCount >= 120) {
		NotesCountToDelete--;
		if (NotesCountToDelete <= 0) {
			m_kill = true;
		}
	}
}
void FreeNotes::NotesMove() {
	std::random_device rnd;
	std::default_random_engine eng(rnd());
	std::uniform_int_distribution<int> Angle(0, 360);
	std::uniform_int_distribution<int> MakeRadius(150, 800);
	std::uniform_int_distribution<int> WhichRotate(0, 1);
	std::uniform_int_distribution<int> TimeRand(60, 180);
	Base* AnotherNotes = Base::FindObject(eType_FreeNotes);
	CVector2D Anpos = (AnotherNotes->m_pos);
	if (TimeLimit <= 0) {
		//0~360で乱数生成
		NotesAngle = DtoR(Angle(eng));
		//半径を乱数生成
		radius = MakeRadius(eng);
		//中心点を割り出し
		center = m_pos - CVector2D(cosf(NotesAngle), sinf(NotesAngle)) * radius;
		//時計回りか反時計回りで乱数生成
		rotate = WhichRotate(eng);
		//その方向に移動する時間を乱数生成
		TimeLimit = TimeRand(eng);
	}
	TimeLimit--;
	if (160 >= m_pos.x + 60 || m_pos.x + 60 >= 1760 ||
		260 >= m_pos.y + 60 || m_pos.y + 60 >= 900 /*||
		std::pow((Anpos.x + 60) - (m_pos.x + 60), 2.0) + std::pow((Anpos.y + 60) - (m_pos.y + 60), 2.0) <= 14400*/) {
		if (rotate == 0) {
			rotate = 1;
		}
		else {
			rotate = 0;
		}
	}
	//std::cout << std::pow((Anpos.x + 60) - (m_pos.x + 60), 2.0) + std::pow((Anpos.y + 60) - (m_pos.y + 60), 2.0) <<std::endl;
	//移動する場所の角度
	if (rotate == 0) {
		NextAngle = NotesAngle + DtoR(360 / ((radius * 2 * PI) / 8));
	}
	else {
		NextAngle = NotesAngle - DtoR(360 / ((radius * 2 * PI) / 8));
	}
	//移動先の座標を割り出す
	m_pos = CVector2D(cosf(NextAngle), sinf(NextAngle)) * radius + center;
	//現在の角度を次の角度に変更
	NotesAngle = NextAngle;
}