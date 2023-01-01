#include "Play.h"
#include "Notes.h"
#include "SoundBar.h"
#include "Score.h"
#include "FreeNotes.h"
#include "SelectScene/SelectScene.h" 
#include "ScoreScene.h"
#include <Gllibrary.h>
#include <iostream>
#include <fstream>
#include "../Base/Base.h"
Play::Play(int ChoiceSound) : Base(eType_Play),
score_text("C:\\Windows\\Fonts\\msgothic.ttc", 64) {
	std::cout << "ì«Ç›çûÇ›" << std::endl;
	glClearColor(0, 0, 0, 0);
	CountDownToStart = 190;
	CountUpToEnd = 0;
	SoundNum = ChoiceSound;
	std::cout << "Image" << std::endl;
	ImageSet();
	std::cout << "Imagefin" << std::endl;
	switch (ChoiceSound) {
	case eNum_Gothic:
		m_img = COPY_RESOURCE("gothic", CImage);
		break;
	case eNum_Bell:
		m_img = COPY_RESOURCE("Chic", CImage);
		break;
	case eNum_Tutorial:
		m_img = COPY_RESOURCE("tutorial", CImage);
		break;
	case eNum_Michikusa:
		m_img = COPY_RESOURCE("wahuu", CImage);
		break;
	}
	for (int i = 0; i < 8; i++) {
		PushKey[i] = false;
	}std::cout << "ÉRÉìÉgÉâÉNÉ^fin" << std::endl;
}
void Play::Draw() {
	std::cout << "Drawstart" << std::endl;
	m_img.Draw();
	gamen.Draw();
	TapA.Draw();
	TapS.Draw();
	TapD.Draw();
	TapE.Draw();
	TapQ.Draw();
	TapW.Draw();
	TapR.Draw();
	TapF.Draw();
	//NotesBar.Draw();
	//LeftClick.Draw();
	/*for (int i = 0; i < 8; i++) {
		if (PushKey[i] == true) {
			NotesBarBlue[i].Draw();
		}
	}*/
	std::cout << "Drawfin" << std::endl;
}
void Play::Update() {
	std::cout << "update" << std::endl;
	CountDownToStart--;
	CountUpToEnd++;
	//âπäyÇ™ó¨ÇÍÇÈéûä‘ÅiïbêîÅñÇUÇOÅj
	switch (ShareNum::GameNum) {
	case eNum_Gothic:
		if (CountDownToStart == 0) {
			Gothic();
		}
		if (CountUpToEnd >= 10500) {
			//10500
			m_kill = true;
		}
		break;
	case eNum_Bell:
		if (CountDownToStart == 0) {
			Bell();
		}
		if (CountUpToEnd >= 4200) {
			//4200
			m_kill = true;
		}
		break;
	case eNum_Tutorial:
		if (CountDownToStart == 0) {
			Tutorial();
		}
		if (CountUpToEnd >= 5700 ){
			//5700
			m_kill = true;
		}
		break;
	case eNum_Michikusa:
		if (CountDownToStart == 0) {
			Michikusa();
		}
		if (CountUpToEnd >= 7740) {
			//7740
			m_kill = true;
		}
		break;
	}
	//for (int i = 0; i < 8; i++) {
	//	if (PushKey[i] == true) {
	//		//m_NotesBar = NotesBarBlue;
	//		PushCount[i]++;
	//	}
	//	if (PushCount[i] >= 10) {
	//		PushKey[i] = false;
	//		//KeyNum = 4;
	//		//m_NotesBar = NotesBar;
	//	}
	//}/*
	/*if (HOLD(CInput::eButton1)) {
		PushKey[0] = true;
		PushCount[0] = 0;
	}
	if (HOLD(CInput::eButton2)) {
		PushKey[1] = true;
		PushCount[1] = 0;
	}
	if (HOLD(CInput::eButton3)) {
		PushKey[2] = true;
		PushCount[2] = 0;
	}
	if (HOLD(CInput::eButton4)) {
		PushKey[3] = true;
		PushCount[3] = 0;
	}
	if (HOLD(CInput::eButton5)) {
		PushKey[4] = true;
		PushCount[4] = 0;
	}
	if (HOLD(CInput::eButton6)) {
		PushKey[5] = true;
		PushCount[5] = 0;
	}
	if (HOLD(CInput::eButton7)) {
		PushKey[6] = true;
		PushCount[6] = 0;
	}
	if (HOLD(CInput::eButton8)) {
		PushKey[7] = true;
		PushCount[7] = 0;
	}*/
	//std::cout << ShareNum::HitCount << std::endl;
	std::cout << "UpdateFin" << std::endl;
}
Play::~Play() {
	std::ofstream Lfile("Score/LeanOn.txt", std::ios_base::app | std::ios_base::in);
	std::ofstream Bfile("Score/Tir.txt", std::ios_base::app | std::ios_base::in);
	std::ofstream Bofile("Score/Tutorial.txt", std::ios_base::app | std::ios_base::in);
	std::ofstream Boofile("Score/Michikusa.txt", std::ios_base::app | std::ios_base::in);
	switch (ShareNum::GameNum) {
	case eNum_Gothic:
		Lfile << ShareNum::score << std::endl;
		break;
	case eNum_Bell:
		Bfile << ShareNum::score << std::endl;
		break;
	case eNum_Tutorial:
		Bfile << ShareNum::score << std::endl;
		break;
	case eNum_Michikusa:
		Bofile << ShareNum::score << std::endl;
		break;
	}
	//video->Stop();
	Base::KillAll();
	Base::Add(new ScoreScene());
}
void Play::ImageSet() {
	gamen = COPY_RESOURCE("gamen", CImage);
	gamen.SetRect(489, 31, 1484, 1026);
	gamen.SetSize(1920*0.45,1080*0.8 );
	gamen.SetPos(528,90);
	
	//A
	TapA = COPY_RESOURCE("TapA", CImage);
	TapA.SetSize(361*0.2,363*0.2);
	TapA.SetPos(740,50);
	//S
	TapS = COPY_RESOURCE("TapS", CImage);
	TapS.SetSize(361 * 0.2, 363 * 0.2);
	TapS.SetPos(490, 300);
	//D
	TapD = COPY_RESOURCE("TapD", CImage);
	TapD.SetSize(361 * 0.2, 363 * 0.2);
	TapD.SetPos(490, 660);
	//E
	TapE = COPY_RESOURCE("TapE", CImage);
	TapE.SetSize(361 * 0.2, 363 * 0.2);
	TapE.SetPos(1370, 680);
	//Q
	TapQ = COPY_RESOURCE("TapQ", CImage);
	TapQ.SetSize(361 * 0.2, 363 * 0.2);
	TapQ.SetPos(1140, 45);
	//W
	TapW = COPY_RESOURCE("TapW", CImage);
	TapW.SetSize(361 * 0.23, 363 * 0.23);
	TapW.SetPos(1380, 300);
	//R
	TapR = COPY_RESOURCE("TapR", CImage);
	TapR.SetSize(361 * 0.2, 363 * 0.2);
	TapR.SetPos(1140, 920);
	//F
	TapF = COPY_RESOURCE("TapF", CImage);
	TapF.SetSize(361 * 0.2, 363 * 0.2);
	TapF.SetPos(740, 920);
	//NotesBar = COPY_RESOURCE("NotesBar", CImage);
	/*for (int i = 0; i < 4; i++) {
		NotesBarBlue[i] = COPY_RESOURCE("NotesBarBlue", CImage);
	}
	NotesBarBlue[0].SetRect(0, 0, 243, 1080);
	NotesBarBlue[1].SetRect(243, 0, 483, 1080);
	NotesBarBlue[2].SetRect(483, 0, 723, 1080);
	NotesBarBlue[3].SetRect(723, 0, 980, 1080);
	NotesBarBlue[0].SetPos(0, 0);
	NotesBarBlue[1].SetPos(243, 0);
	NotesBarBlue[2].SetPos(483, 0);
	NotesBarBlue[3].SetPos(723, 0);
	NotesBarBlue[0].SetSize(243, 1080);
	NotesBarBlue[1].SetSize(240, 1080);
	NotesBarBlue[2].SetSize(240, 1080);
	NotesBarBlue[3].SetSize(257, 1080);*/
	//LeftClick = COPY_RESOURCE("LeftClick", CImage);
	//m_NotesBar = NotesBar;
}
void Play::Gothic() {
	SOUND("Gothic")->Play();
	OneNotes = 19.75;
	//Base::Add(new SoundBar(3));
	Base::Add(new Score());
	NotesSet();
}
void Play::Bell() {
	SOUND("Bell")->Play();
	OneNotes = 15.5;
	//Base::Add(new SoundBar(1));
	Base::Add(new Score());
	NotesSet();
}
void Play::Tutorial(){
	SOUND("Tutorial")->Play();
	OneNotes = 20.725;
	//Base::Add(new SoundBar(0));
	Base::Add(new Score());
	NotesSet();

}
void Play::Michikusa() {
	SOUND("Michikusa")->Play();
	OneNotes = 15.725;
	//Base::Add(new SoundBar(2));
	Base::Add(new Score());
	NotesSet();
}
void Play::NotesPreSet(int SetNum) {
	switch (SetNum) {
	case 0: //ç≈å„ÇÃêîéöÇOÅ`2
		Base::Add(new Notes(0, OneNotes * 0 + NotesCount, 0));
		Base::Add(new Notes(1, OneNotes * 0 + NotesCount, 0));
		Base::Add(new Notes(2, OneNotes * 0 + NotesCount, 0));
		Base::Add(new Notes(3, OneNotes * 0 + NotesCount, 0));
		Base::Add(new Notes(4, OneNotes * 0 + NotesCount, 0));
		Base::Add(new Notes(5, OneNotes * 0 + NotesCount, 0));
		Base::Add(new Notes(6, OneNotes * 0 + NotesCount, 0));
		Base::Add(new Notes(7, OneNotes * 0 + NotesCount, 0));
		break;
	case 1:
		Base::Add(new Notes(0, OneNotes * 0.5 + NotesCount, 1));
		Base::Add(new Notes(1, OneNotes * 0.5 + NotesCount, 1));
		Base::Add(new Notes(2, OneNotes * 3 + NotesCount, 1));
		Base::Add(new Notes(3, OneNotes * 3 + NotesCount, 1));
		Base::Add(new Notes(4, OneNotes * 6.3 + NotesCount, 1));
		Base::Add(new Notes(5, OneNotes * 6.3+ NotesCount, 1));
		Base::Add(new Notes(6, OneNotes * 8.5 + NotesCount, 1));
		Base::Add(new Notes(7, OneNotes * 8.5 + NotesCount, 1));
		break;
	case 2:
		Base::Add(new Notes(1, OneNotes * 1.9 + NotesCount, 0));
		Base::Add(new Notes(3, OneNotes * 1.9 + NotesCount, 0));
		break;
	case 3:
		Base::Add(new Notes(0, OneNotes * 3.5 + NotesCount, 0));
		Base::Add(new Notes(3, OneNotes * 3.5 + NotesCount, 0));
		break;
	case 4:
		Base::Add(new Notes(1, OneNotes * 5 + NotesCount, 0));
		Base::Add(new Notes(2, OneNotes * 5 + NotesCount, 0));
		break;
	case 5:
		Base::Add(new Notes(0, OneNotes * 8.4 + NotesCount, 0));
		Base::Add(new Notes(1, OneNotes * 8.9 + NotesCount, 0));
		Base::Add(new Notes(2, OneNotes * 9.4 + NotesCount, 0));
		Base::Add(new Notes(3, OneNotes * 9.8 + NotesCount, 0));
		break;
	case 6:

		Base::Add(new Notes(0, OneNotes * 11 + NotesCount, 2));
		Base::Add(new Notes(2, OneNotes * 11.9 + NotesCount, 2));
		Base::Add(new Notes(6, OneNotes * 12.7 + NotesCount, 2));
		break;
	case 7:
		Base::Add(new Notes(3, OneNotes * 9.5 + NotesCount, 0));
		break;
	case 8:
		Base::Add(new Notes(0, OneNotes * 0 + NotesCount, 1));
		Base::Add(new Notes(1, OneNotes * 0 + NotesCount, 1));
		
		break;
	case 9:
		Base::Add(new Notes(2, OneNotes * 0 + NotesCount, 1));
		Base::Add(new Notes(3, OneNotes * 0 + NotesCount, 1));
		break;
	case 10:
		Base::Add(new Notes(0, OneNotes * 10 + NotesCount, 0));
		Base::Add(new Notes(1, OneNotes * 10.5 + NotesCount, 0));
		Base::Add(new Notes(2, OneNotes * 11 + NotesCount, 0));
		Base::Add(new Notes(3, OneNotes * 11.5 + NotesCount, 0));
		break;
	case 11:
		Base::Add(new Notes(6, OneNotes * 0 + NotesCount, 1));
		Base::Add(new Notes(7, OneNotes * 0 + NotesCount, 1));
		break;
	case 12:
		Base::Add(new Notes(4, OneNotes * 0 + NotesCount, 1));
		Base::Add(new Notes(5, OneNotes * 0 + NotesCount, 1));
		break;
	case 13:
		Base::Add(new Notes(1, OneNotes * 6 + NotesCount, 0));
		Base::Add(new Notes(0, OneNotes * 7 + NotesCount, 0));
		break;
	case 14:
		Base::Add(new Notes(3, OneNotes * 7 + NotesCount, 0));
		Base::Add(new Notes(1, OneNotes * 8 + NotesCount, 0));
		break;
	case 15:

		Base::Add(new Notes(1, OneNotes * 5.6 + NotesCount, 0));
		break;
	case 16:

		Base::Add(new Notes(2, OneNotes * 9.6 + NotesCount, 0));
		break;
	case 17:

		Base::Add(new Notes(3, OneNotes * 4.6 + NotesCount, 0));
		break;
	case 18:
		Base::Add(new Notes(3, OneNotes * 7 + NotesCount, 0));
		Base::Add(new Notes(2, OneNotes * 7.5 + NotesCount, 0));
		Base::Add(new Notes(1, OneNotes * 8 + NotesCount, 0));
		Base::Add(new Notes(0, OneNotes * 8.5 + NotesCount, 0));
		break;
	case 19:
		Base::Add(new Notes(1, OneNotes * 0 + NotesCount, 2));
		break;
	case 20:
		Base::Add(new Notes(2, OneNotes * 0 + NotesCount, 2));
		break;
	case 21:
		Base::Add(new Notes(3, OneNotes * 0 + NotesCount, 2));
		break;
	case 22:
		Base::Add(new Notes(1, OneNotes * 0 + NotesCount, 0));
		Base::Add(new Notes(1, OneNotes * 0.5 + NotesCount, 0));
		Base::Add(new Notes(2, OneNotes * 1 + NotesCount, 0));
		break;
	case 23:
		Base::Add(new Notes(2, OneNotes * 0 + NotesCount, 0));
		Base::Add(new Notes(3, OneNotes * 0.5 + NotesCount, 0));
		Base::Add(new Notes(2, OneNotes * 1 + NotesCount, 0));
		Base::Add(new Notes(3, OneNotes * 1.5 + NotesCount, 0));
		break;
	case 24:
		Base::Add(new Notes(4, OneNotes * 1.5 + NotesCount, 0));
		Base::Add(new Notes(5, OneNotes * 2 + NotesCount, 0));
		break;
	case 25:
		Base::Add(new Notes(0, OneNotes * 1.5 + NotesCount, 0));
		Base::Add(new Notes(1, OneNotes * 2 + NotesCount, 0));
		break;
	case 26:
		Base::Add(new Notes(6, OneNotes * 0 + NotesCount, 0));
		Base::Add(new Notes(7, OneNotes * 0 + NotesCount, 0));
		Base::Add(new Notes(3, OneNotes * 0 + NotesCount, 0));
		Base::Add(new Notes(2, OneNotes * 0 + NotesCount, 0));
		break;
	case 27:
		Base::Add(new Notes(4, OneNotes * 0 + NotesCount, 0));
		Base::Add(new Notes(5, OneNotes * 1.7 + NotesCount, 0));
		Base::Add(new Notes(6, OneNotes * 3.5 + NotesCount, 0));
		Base::Add(new Notes(7, OneNotes * 4.3 + NotesCount, 0));
		break;
	case 28:
		Base::Add(new Notes(0, OneNotes * 0 + NotesCount, 0));
		Base::Add(new Notes(1, OneNotes * 1.7 + NotesCount, 0));
		Base::Add(new Notes(2, OneNotes * 3.5 + NotesCount, 0));
		Base::Add(new Notes(3, OneNotes * 4.3+ NotesCount, 0));
		break;
	//case 29:
	//	Base::Add(new Notes(4, OneNotes * 0 + NotesCount, 3, 3));
	//	Base::Add(new Notes(4, OneNotes * 1 + NotesCount, 4, 2));
	//	Base::Add(new Notes(4, OneNotes * 2 + NotesCount, 5, 1));
	//	Base::Add(new Notes(4, OneNotes * 3 + NotesCount, 6, 0));
	//	Base::Add(new Notes(4, OneNotes * 4 + NotesCount, 7, 1));
	//	Base::Add(new Notes(4, OneNotes * 5 + NotesCount, 8, 2));
	//	break;
	//case 30:
	//	Base::Add(new Notes(0, OneNotes * 0 + NotesCount, 8));
	//	Base::Add(new Notes(1, OneNotes * 2 + NotesCount, 8));
	//	Base::Add(new Notes(2, OneNotes * 0 + NotesCount, 8));
	//	Base::Add(new Notes(3, OneNotes * 2 + NotesCount, 8));
	//	break;
	//case 31:
	//	Base::Add(new Notes(4, OneNotes * 1 + NotesCount, 1, 2));
	//	Base::Add(new Notes(4, OneNotes * 2.5 + NotesCount, 2, 1));
	//	Base::Add(new Notes(0, OneNotes * 3 + NotesCount, 8));
	//	Base::Add(new Notes(3, OneNotes * 4 + NotesCount, 8));
	//	break;
	//case 32:
	//	Base::Add(new Notes(1, OneNotes * 0 + NotesCount, 8));
	//	Base::Add(new Notes(2, OneNotes * 0.5 + NotesCount, 8));
	//	Base::Add(new Notes(1, OneNotes * 1 + NotesCount, 8));
	//	break;
	//case 33:
	//	Base::Add(new Notes(1, OneNotes * 0 + NotesCount, 8));
	//	Base::Add(new Notes(1, OneNotes * 1 + NotesCount, 8));
	//	Base::Add(new Notes(2, OneNotes * 2 + NotesCount, 8));
	//	Base::Add(new Notes(0, OneNotes * 3 + NotesCount, 8));
	//	break;
	//case 34:
	//	Base::Add(new Notes(4, OneNotes * 0 + NotesCount, 0, 4));
	//	Base::Add(new Notes(4, OneNotes * 1 + NotesCount, 3, 7));
	//	break;
	//case 35:
	//	Base::Add(new Notes(4, OneNotes * 1 + NotesCount, 2, 9));
	//	Base::Add(new Notes(4, OneNotes * 2 + NotesCount, 5, 1));
	//	break;
	//case 36:
	//	Base::Add(new Notes(4, OneNotes * 0 + NotesCount, 4, 3));
	//	Base::Add(new Notes(4, OneNotes * 2 + NotesCount, 4, 2));
	//	break;
	//case 37:
	//	Base::Add(new Notes(1, OneNotes * 4 + NotesCount, 8));
	//	Base::Add(new Notes(0, OneNotes * 3.5 + NotesCount, 8));
	//	break;
	//case 38:
	//	Base::Add(new Notes(4, OneNotes * 1 + NotesCount, 3, 3));
	//	Base::Add(new Notes(4, OneNotes * 2.5 + NotesCount, 2, 2));
	//	Base::Add(new Notes(0, OneNotes * 3 + NotesCount, 8));
	//	Base::Add(new Notes(3, OneNotes * 5 + NotesCount, 8));
	//	Base::Add(new Notes(4, OneNotes * 6 + NotesCount, 1, 1));
	//	Base::Add(new Notes(4, OneNotes * 7.5 + NotesCount, 2, 2));
	//	Base::Add(new Notes(2, OneNotes * 8 + NotesCount, 8));
	//	Base::Add(new Notes(0, OneNotes * 9 + NotesCount, 8));
	//	break;
	//case 39:
	//	Base::Add(new Notes(2, OneNotes * 1 + NotesCount, 8));
	//	Base::Add(new Notes(0, OneNotes * 3 + NotesCount, 8));
	//	break;
	//case 40:
	//	Base::Add(new Notes(0, OneNotes * 2 + NotesCount, 8));
	//	Base::Add(new Notes(3, OneNotes * 5 + NotesCount, 8));
	//	break;
	//case 41:
	//	Base::Add(new Notes(1, OneNotes * 0 + NotesCount, 8));
	//	Base::Add(new Notes(2, OneNotes * 3 + NotesCount, 8));
	//	break;
	//case 42:
	//	Base::Add(new Notes(3, OneNotes * 2 + NotesCount, 8));
	//	Base::Add(new Notes(3, OneNotes * 2 + NotesCount, 8));
	//	break;
	//case 43:
	//	Base::Add(new Notes(1, OneNotes * 0 + NotesCount, 8));
	//	Base::Add(new Notes(1, OneNotes * 4 + NotesCount, 8));
	//	break;
	//case 44:
	//	Base::Add(new Notes(4, OneNotes * 0 + NotesCount, 0, 1));
	//	Base::Add(new Notes(0, OneNotes * 2 + NotesCount, 8));
	//	Base::Add(new Notes(3, OneNotes * 4 + NotesCount, 8));
	//	Base::Add(new Notes(3, OneNotes * 7 + NotesCount, 8));
	//	break;
	//case 45:
	//	Base::Add(new Notes(0, OneNotes * 1 + NotesCount, 8));
	//	Base::Add(new Notes(0, OneNotes * 3 + NotesCount, 8));
	//	Base::Add(new Notes(3, OneNotes * 5 + NotesCount, 8));
	//	Base::Add(new Notes(3, OneNotes * 7 + NotesCount, 8));
	//	break;
	//case 46:
	//	Base::Add(new Notes(0, OneNotes * 1 + NotesCount, 8));
	//	Base::Add(new Notes(2, OneNotes * 1.3 + NotesCount, 8));
	//	Base::Add(new Notes(0, OneNotes * 2.5 + NotesCount, 8));
	//	Base::Add(new Notes(1, OneNotes * 4 + NotesCount, 8));
	//	Base::Add(new Notes(3, OneNotes * 4.3 + NotesCount, 8));
	//	break;
	//case 47:
	//	Base::Add(new Notes(2, OneNotes * 0 + NotesCount, 8));
	//	Base::Add(new Notes(1, OneNotes * 0.5 + NotesCount, 8));
	//	Base::Add(new Notes(3, OneNotes * 1 + NotesCount, 8));
	//	break;
	//case 48:
	//	Base::Add(new Notes(0, OneNotes * 3 + NotesCount, 8));
	//	Base::Add(new Notes(3, OneNotes * 3.5 + NotesCount, 8));
	//	Base::Add(new Notes(1, OneNotes * 4 + NotesCount, 8));
	//	break;
	case 49:
		Base::Add(new Notes(1, OneNotes * 7 + NotesCount, 8));
		Base::Add(new Notes(2, OneNotes * 0.5 + NotesCount, 8));
		Base::Add(new Notes(3, OneNotes * 1 + NotesCount, 8));
		Base::Add(new Notes(1, OneNotes * 2 + NotesCount, 8));
		Base::Add(new Notes(2, OneNotes * 2.5 + NotesCount, 8));
		Base::Add(new Notes(3, OneNotes * 3 + NotesCount, 8));
		Base::Add(new Notes(2, OneNotes * 3.5 + NotesCount, 8));
		break;
	case 50:
		Base::Add(new Notes(0, OneNotes * 0 + NotesCount, 8));
		Base::Add(new Notes(1, OneNotes * 1.5 + NotesCount, 8));
		Base::Add(new Notes(0, OneNotes * 2 + NotesCount, 8));
		Base::Add(new Notes(1, OneNotes * 2.5 + NotesCount, 8));
		break;
	/*
	case 51:
		Base::Add(new Notes(4, OneNotes * 0 + NotesCount, 4, 3));
		Base::Add(new Notes(4, OneNotes * 2.5 + NotesCount, 4, 2));
		break;
	case 52:
		Base::Add(new Notes(4, OneNotes * 1 + NotesCount, 3, 7));
		Base::Add(new Notes(4, OneNotes * 2.5 + NotesCount, 2, 8));
		break;
	case 53:
		Base::Add(new Notes(4, OneNotes * 3 + NotesCount, 0, 3));
		Base::Add(new Notes(4, OneNotes * 6 + NotesCount, 5, 4));
		break;
	case 54:
		Base::Add(new Notes(1, OneNotes * 0 + NotesCount, 8));
		Base::Add(new Notes(1, OneNotes * 0.5 + NotesCount, 8));
		break;
	case 55:
		Base::Add(new Notes(2, OneNotes * 0 + NotesCount, 8));
		Base::Add(new Notes(0, OneNotes * 2 + NotesCount, 8));
		break;
	case 56:
		Base::Add(new Notes(1, OneNotes * 1 + NotesCount, 8));
		Base::Add(new Notes(0, OneNotes * 2 + NotesCount, 8));
		Base::Add(new Notes(3, OneNotes * 2 + NotesCount, 8));
		Base::Add(new Notes(2, OneNotes * 3 + NotesCount, 8));
		break;
	case 57:
		Base::Add(new Notes(4, OneNotes * 0 + NotesCount, 9, 9));
		break;
		//3*/
	case 58:
		Base::Add(new Notes(0, OneNotes * 0 + NotesCount, 11));
		Base::Add(new Notes(2, OneNotes * 0 + NotesCount, 11));
		Base::Add(new Notes(1, OneNotes * 1 + NotesCount, 11));
		Base::Add(new Notes(2, OneNotes * 2 + NotesCount, 11));
		Base::Add(new Notes(1, OneNotes * 3 + NotesCount, 11));
		Base::Add(new Notes(3, OneNotes * 4 + NotesCount, 11));
		Base::Add(new Notes(2, OneNotes * 5 + NotesCount, 11));
		Base::Add(new Notes(0, OneNotes * 6 + NotesCount, 11));
		Base::Add(new Notes(1, OneNotes * 7 + NotesCount, 11));
		break;
	case 59:
		Base::Add(new Notes(0, OneNotes * 0 + NotesCount, 11));
		Base::Add(new Notes(3, OneNotes * 0 + NotesCount, 11));
		Base::Add(new Notes(2, OneNotes * 2 + NotesCount, 11));
		Base::Add(new Notes(1, OneNotes * 3 + NotesCount, 11));
		Base::Add(new Notes(3, OneNotes * 4 + NotesCount, 11));

		Base::Add(new Notes(0, OneNotes * 6 + NotesCount, 11));
		Base::Add(new Notes(1, OneNotes * 7 + NotesCount, 11));
		break;
	case 60:
		Base::Add(new Notes(0, OneNotes * 0 + NotesCount, 11));
		Base::Add(new Notes(2, OneNotes * 0 + NotesCount, 11));
		Base::Add(new Notes(3, OneNotes * 1 + NotesCount, 11));
		Base::Add(new Notes(2, OneNotes * 2 + NotesCount, 11));
		Base::Add(new Notes(3, OneNotes * 3 + NotesCount, 11));
		Base::Add(new Notes(1, OneNotes * 4 + NotesCount, 11));
		Base::Add(new Notes(0, OneNotes * 5 + NotesCount, 11));
		Base::Add(new Notes(0, OneNotes * 6 + NotesCount, 11));
		Base::Add(new Notes(2, OneNotes * 7 + NotesCount, 11));
		break;
	//case 61:
	//	Base::Add(new Notes(4, OneNotes * 3 + NotesCount, 0, 0));
	//	Base::Add(new Notes(4, OneNotes * 4 + NotesCount, 2, 3));
	//	Base::Add(new Notes(4, OneNotes * 6 + NotesCount, 1, 1));
	//	break;
	case 62:
		Base::Add(new Notes(1, OneNotes * 0 + NotesCount, 11));
		Base::Add(new Notes(3, OneNotes * 0 + NotesCount, 11));
		Base::Add(new Notes(2, OneNotes * 1 + NotesCount, 11));
		Base::Add(new Notes(2, OneNotes * 2 + NotesCount, 11));
		Base::Add(new Notes(0, OneNotes * 3 + NotesCount, 11));
		Base::Add(new Notes(3, OneNotes * 4 + NotesCount, 11));
		Base::Add(new Notes(1, OneNotes * 5 + NotesCount, 11));
		Base::Add(new Notes(0, OneNotes * 6 + NotesCount, 11));
		Base::Add(new Notes(1, OneNotes * 7 + NotesCount, 11));
		break;
	case 63:
		Base::Add(new Notes(0, OneNotes * 0 + NotesCount, 11));
		Base::Add(new Notes(1, OneNotes * 0 + NotesCount, 11));
		Base::Add(new Notes(3, OneNotes * 2 + NotesCount, 11));
		Base::Add(new Notes(3, OneNotes * 3 + NotesCount, 11));
		Base::Add(new Notes(2, OneNotes * 4 + NotesCount, 11));

		Base::Add(new Notes(1, OneNotes * 6 + NotesCount, 11));
		Base::Add(new Notes(2, OneNotes * 7 + NotesCount, 11));
		break;
	case 64:
		Base::Add(new Notes(3, OneNotes * 0 + NotesCount, 11));
		Base::Add(new Notes(2, OneNotes * 0 + NotesCount, 11));
		Base::Add(new Notes(1, OneNotes * 1 + NotesCount, 11));
		Base::Add(new Notes(1, OneNotes * 2 + NotesCount, 11));
		Base::Add(new Notes(2, OneNotes * 3 + NotesCount, 11));
		Base::Add(new Notes(2, OneNotes * 4 + NotesCount, 11));
		Base::Add(new Notes(3, OneNotes * 5 + NotesCount, 11));
		Base::Add(new Notes(2, OneNotes * 6 + NotesCount, 11));
		Base::Add(new Notes(0, OneNotes * 7 + NotesCount, 11));
		break;
	case 65:
		Base::Add(new Notes(0, OneNotes * 0 + NotesCount, 11));
		Base::Add(new Notes(2, OneNotes * 0 + NotesCount, 11));
		Base::Add(new Notes(1, OneNotes * 2 + NotesCount, 11));
		Base::Add(new Notes(0, OneNotes * 3 + NotesCount, 11));
		Base::Add(new Notes(3, OneNotes * 4 + NotesCount, 11));

		Base::Add(new Notes(0, OneNotes * 6 + NotesCount, 11));
		Base::Add(new Notes(1, OneNotes * 7 + NotesCount, 11));
		break;
	case 66:
		Base::Add(new Notes(2, OneNotes * 0 + NotesCount, 11));
		Base::Add(new Notes(0, OneNotes * 0 + NotesCount, 11));
		Base::Add(new Notes(2, OneNotes * 2 + NotesCount, 11));
		Base::Add(new Notes(3, OneNotes * 2 + NotesCount, 11));
		Base::Add(new Notes(1, OneNotes * 4 + NotesCount, 11));
		Base::Add(new Notes(0, OneNotes * 4 + NotesCount, 11));
		Base::Add(new Notes(3, OneNotes * 6 + NotesCount, 11));
		Base::Add(new Notes(2, OneNotes * 6 + NotesCount, 11));
		break;
	case 67:
		Base::Add(new Notes(2, OneNotes * 0 + NotesCount, 11));
		Base::Add(new Notes(3, OneNotes * 0 + NotesCount, 11));
		Base::Add(new Notes(0, OneNotes * 2 + NotesCount, 11));
		Base::Add(new Notes(1, OneNotes * 2 + NotesCount, 11));
		Base::Add(new Notes(3, OneNotes * 4 + NotesCount, 11));
		Base::Add(new Notes(0, OneNotes * 4 + NotesCount, 11));
		Base::Add(new Notes(3, OneNotes * 6 + NotesCount, 11));
		Base::Add(new Notes(2, OneNotes * 6 + NotesCount, 11));
		break;
	case 68:
		Base::Add(new Notes(2, OneNotes * 0 + NotesCount, 11));
		Base::Add(new Notes(3, OneNotes * 0 + NotesCount, 11));
		Base::Add(new Notes(0, OneNotes * 2 + NotesCount, 11));
		Base::Add(new Notes(1, OneNotes * 2 + NotesCount, 11));
		Base::Add(new Notes(3, OneNotes * 4 + NotesCount, 11));
		Base::Add(new Notes(0, OneNotes * 4 + NotesCount, 11));
		Base::Add(new Notes(3, OneNotes * 6 + NotesCount, 11));
		Base::Add(new Notes(2, OneNotes * 6 + NotesCount, 11));
		break;
	case 69:
		Base::Add(new Notes(0, OneNotes * 0 + NotesCount, 11));
		Base::Add(new Notes(0, OneNotes * 1.5 + NotesCount, 11));
		Base::Add(new Notes(1, OneNotes * 1.5 + NotesCount, 11));
		Base::Add(new Notes(0, OneNotes * 3 + NotesCount, 11));
		Base::Add(new Notes(1, OneNotes * 3 + NotesCount, 11));
		Base::Add(new Notes(2, OneNotes * 3 + NotesCount, 11));
		Base::Add(new Notes(3, OneNotes * 4.5 + NotesCount, 11));
		Base::Add(new Notes(3, OneNotes * 6 + NotesCount, 11));
		Base::Add(new Notes(2, OneNotes * 6 + NotesCount, 11));
		Base::Add(new Notes(3, OneNotes * 7 + NotesCount, 11));
		Base::Add(new Notes(2, OneNotes * 7 + NotesCount, 11));
		Base::Add(new Notes(1, OneNotes * 7 + NotesCount, 11));
		break;
	case 70:
		Base::Add(new Notes(3, OneNotes * 0 + NotesCount, 11));
		Base::Add(new Notes(1, OneNotes * 1 + NotesCount, 11));
		Base::Add(new Notes(2, OneNotes * 2 + NotesCount, 11));
		Base::Add(new Notes(0, OneNotes * 3 + NotesCount, 11));
		Base::Add(new Notes(2, OneNotes * 4 + NotesCount, 11));
		Base::Add(new Notes(3, OneNotes * 4 + NotesCount, 11));
		Base::Add(new Notes(0, OneNotes * 6 + NotesCount, 11));
		Base::Add(new Notes(1, OneNotes * 7 + NotesCount, 11));
		break;
	case 71:
		Base::Add(new Notes(3, OneNotes * 0 + NotesCount, 11));
		Base::Add(new Notes(1, OneNotes * 0 + NotesCount, 11));
		Base::Add(new Notes(1, OneNotes * 1 + NotesCount, 11));
		Base::Add(new Notes(2, OneNotes * 2 + NotesCount, 11));
		Base::Add(new Notes(0, OneNotes * 3 + NotesCount, 11));
		Base::Add(new Notes(2, OneNotes * 4 + NotesCount, 11));
		Base::Add(new Notes(3, OneNotes * 4 + NotesCount, 11));
		Base::Add(new Notes(0, OneNotes * 6 + NotesCount, 11));
		Base::Add(new Notes(1, OneNotes * 7 + NotesCount, 11));
		break;
	case 72:
		Base::Add(new Notes(1, OneNotes * 0 + NotesCount, 11));
		Base::Add(new Notes(1, OneNotes * 1 + NotesCount, 11));
		Base::Add(new Notes(2, OneNotes * 2 + NotesCount, 11));
		Base::Add(new Notes(0, OneNotes * 3 + NotesCount, 11));
		Base::Add(new Notes(3, OneNotes * 4 + NotesCount, 11));
		Base::Add(new Notes(2, OneNotes * 4 + NotesCount, 11));
		Base::Add(new Notes(3, OneNotes * 6 + NotesCount, 11));
		Base::Add(new Notes(1, OneNotes * 7 + NotesCount, 11));
		break;
	/*case 73:
		Base::Add(new Notes(3, OneNotes * 0 + NotesCount, 11));
		Base::Add(new Notes(1, OneNotes * 0 + NotesCount, 11));
		Base::Add(new Notes(1, OneNotes * 1 + NotesCount, 11));
		Base::Add(new Notes(2, OneNotes * 2 + NotesCount, 11));
		Base::Add(new Notes(0, OneNotes * 3 + NotesCount, 11));
		Base::Add(new Notes(2, OneNotes * 4 + NotesCount, 11));
		Base::Add(new Notes(3, OneNotes * 5.5 + NotesCount, 12));
		Base::Add(new Notes(3, OneNotes * 6 + NotesCount, 12));
		Base::Add(new Notes(2, OneNotes * 6.5 + NotesCount, 12));
		Base::Add(new Notes(1, OneNotes * 6.5 + NotesCount, 12));
		Base::Add(new Notes(4, OneNotes * 7 + NotesCount, 3, 2));
		break;
	*/ 
	case 74:
		Base::Add(new Notes(2, OneNotes * 0 + NotesCount, 11));
		Base::Add(new Notes(2, OneNotes * 1 + NotesCount, 11));
		Base::Add(new Notes(1, OneNotes * 2 + NotesCount, 11));
		Base::Add(new Notes(1, OneNotes * 3 + NotesCount, 11));
		Base::Add(new Notes(0, OneNotes * 4 + NotesCount, 11));
		Base::Add(new Notes(3, OneNotes * 4 + NotesCount, 11));
		Base::Add(new Notes(0, OneNotes * 6 + NotesCount, 11));
		Base::Add(new Notes(1, OneNotes * 7 + NotesCount, 11));
		break;
	case 75:
		Base::Add(new Notes(2, OneNotes * 0 + NotesCount, 11));
		Base::Add(new Notes(3, OneNotes * 0 + NotesCount, 11));
		Base::Add(new Notes(0, OneNotes * 1 + NotesCount, 11));
		Base::Add(new Notes(1, OneNotes * 2 + NotesCount, 11));
		Base::Add(new Notes(2, OneNotes * 3 + NotesCount, 11));
		Base::Add(new Notes(2, OneNotes * 4 + NotesCount, 11));
		Base::Add(new Notes(3, OneNotes * 4 + NotesCount, 11));
		Base::Add(new Notes(2, OneNotes * 6 + NotesCount, 11));
		Base::Add(new Notes(3, OneNotes * 7 + NotesCount, 11));
		break;
	case 76:
		Base::Add(new Notes(2, OneNotes * 0 + NotesCount, 11));
		Base::Add(new Notes(1, OneNotes * 0 + NotesCount, 11));
		Base::Add(new Notes(3, OneNotes * 1 + NotesCount, 11));
		Base::Add(new Notes(2, OneNotes * 2 + NotesCount, 11));
		Base::Add(new Notes(1, OneNotes * 3 + NotesCount, 11));
		Base::Add(new Notes(2, OneNotes * 4 + NotesCount, 11));
		Base::Add(new Notes(3, OneNotes * 4 + NotesCount, 11));
		Base::Add(new Notes(1, OneNotes * 6 + NotesCount, 11));
		Base::Add(new Notes(0, OneNotes * 7 + NotesCount, 11));
		break;
	/*case 77:
		Base::Add(new Notes(0, OneNotes * 0 + NotesCount, 11));
		Base::Add(new Notes(2, OneNotes * 0 + NotesCount, 11));
		Base::Add(new Notes(1, OneNotes * 1 + NotesCount, 11));
		Base::Add(new Notes(2, OneNotes * 2 + NotesCount, 11));
		Base::Add(new Notes(3, OneNotes * 3 + NotesCount, 11));
		Base::Add(new Notes(3, OneNotes * 4 + NotesCount, 11));
		Base::Add(new Notes(1, OneNotes * 5.5 + NotesCount, 12));
		Base::Add(new Notes(2, OneNotes * 6 + NotesCount, 12));
		Base::Add(new Notes(3, OneNotes * 6.5 + NotesCount, 12));
		Base::Add(new Notes(0, OneNotes * 6.5 + NotesCount, 12));
		Base::Add(new Notes(4, OneNotes * 7 + NotesCount, 9, 5));
		break;
	*/
	case 78:
		Base::Add(new Notes(0, OneNotes * 0 + NotesCount, 11));
		Base::Add(new Notes(1, OneNotes * 1 + NotesCount, 11));
		Base::Add(new Notes(0, OneNotes * 2 + NotesCount, 11));
		Base::Add(new Notes(1, OneNotes * 3 + NotesCount, 11));
		Base::Add(new Notes(2, OneNotes * 4 + NotesCount, 11));

		Base::Add(new Notes(2, OneNotes * 6 + NotesCount, 11));
		Base::Add(new Notes(3, OneNotes * 6.5 + NotesCount, 11));
		Base::Add(new Notes(1, OneNotes * 7 + NotesCount, 11));
		break;
	case 79:
		Base::Add(new Notes(0, OneNotes * 0 + NotesCount, 11));
		Base::Add(new Notes(0, OneNotes * 1 + NotesCount, 11));
		Base::Add(new Notes(0, OneNotes * 2 + NotesCount, 11));
		Base::Add(new Notes(0, OneNotes * 3 + NotesCount, 11));
		Base::Add(new Notes(0, OneNotes * 4 + NotesCount, 11));
		Base::Add(new Notes(1, OneNotes * 5 + NotesCount, 11));
		Base::Add(new Notes(2, OneNotes * 6 + NotesCount, 11));
		Base::Add(new Notes(3, OneNotes * 7 + NotesCount, 11));
		break;
	case 80:
		Base::Add(new Notes(2, OneNotes * 0 + NotesCount, 11));
		Base::Add(new Notes(2, OneNotes * 1 + NotesCount, 11));
		Base::Add(new Notes(3, OneNotes * 2 + NotesCount, 11));
		Base::Add(new Notes(3, OneNotes * 3 + NotesCount, 11));
		Base::Add(new Notes(1, OneNotes * 4 + NotesCount, 11));
		Base::Add(new Notes(1, OneNotes * 5 + NotesCount, 11));
		Base::Add(new Notes(0, OneNotes * 6 + NotesCount, 11));
		Base::Add(new Notes(0, OneNotes * 7 + NotesCount, 11));
		break;
	/*
	case 81:
		Base::Add(new Notes(0, OneNotes * 0 + NotesCount, 11));
		Base::Add(new Notes(1, OneNotes * 0.5 + NotesCount, 11));
		Base::Add(new Notes(2, OneNotes * 1 + NotesCount, 11));
		Base::Add(new Notes(3, OneNotes * 1.5 + NotesCount, 11));
		Base::Add(new Notes(2, OneNotes * 2 + NotesCount, 11));
		Base::Add(new Notes(1, OneNotes * 2.5 + NotesCount, 11));
		Base::Add(new Notes(0, OneNotes * 3 + NotesCount, 11));

		Base::Add(new Notes(4, OneNotes * 4.5 + NotesCount, 1, 1));

		Base::Add(new Notes(4, OneNotes * 6 + NotesCount, 5, 5));
		break;
	*/
	case 82:
		Base::Add(new Notes(3, OneNotes * 0 + NotesCount, 11));
		Base::Add(new Notes(3, OneNotes * 1 + NotesCount, 11));
		Base::Add(new Notes(3, OneNotes * 2 + NotesCount, 11));
		Base::Add(new Notes(3, OneNotes * 3 + NotesCount, 11));
		Base::Add(new Notes(3, OneNotes * 4 + NotesCount, 11));
		Base::Add(new Notes(2, OneNotes * 5 + NotesCount, 11));
		Base::Add(new Notes(1, OneNotes * 6 + NotesCount, 11));
		Base::Add(new Notes(0, OneNotes * 7 + NotesCount, 11));
		break;
	case 83:
		Base::Add(new Notes(0, OneNotes * 0 + NotesCount, 11));
		Base::Add(new Notes(0, OneNotes * 1 + NotesCount, 11));
		Base::Add(new Notes(2, OneNotes * 2 + NotesCount, 11));
		Base::Add(new Notes(2, OneNotes * 3 + NotesCount, 11));
		Base::Add(new Notes(3, OneNotes * 4 + NotesCount, 11));
		Base::Add(new Notes(3, OneNotes * 5 + NotesCount, 11));
		Base::Add(new Notes(1, OneNotes * 6 + NotesCount, 11));
		Base::Add(new Notes(1, OneNotes * 7 + NotesCount, 11));
		break;
	case 84:
		Base::Add(new Notes(0, OneNotes * 0 + NotesCount, 11));
		Base::Add(new Notes(1, OneNotes * 1 + NotesCount, 11));
		Base::Add(new Notes(1, OneNotes * 2 + NotesCount, 11));
		Base::Add(new Notes(2, OneNotes * 3 + NotesCount, 11));
		Base::Add(new Notes(2, OneNotes * 4 + NotesCount, 11));
		Base::Add(new Notes(3, OneNotes * 5 + NotesCount, 11));
		Base::Add(new Notes(3, OneNotes * 6 + NotesCount, 11));
		Base::Add(new Notes(0, OneNotes * 7 + NotesCount, 11));
		break;
	/*case 85:
		Base::Add(new Notes(3, OneNotes * 0 + NotesCount, 11));
		Base::Add(new Notes(2, OneNotes * 0.5 + NotesCount, 11));
		Base::Add(new Notes(1, OneNotes * 1 + NotesCount, 11));
		Base::Add(new Notes(0, OneNotes * 1.5 + NotesCount, 11));
		Base::Add(new Notes(1, OneNotes * 2 + NotesCount, 11));
		Base::Add(new Notes(2, OneNotes * 2.5 + NotesCount, 11));
		Base::Add(new Notes(3, OneNotes * 3 + NotesCount, 11));

		Base::Add(new Notes(4, OneNotes * 4.5 + NotesCount, 3, 3));

		Base::Add(new Notes(4, OneNotes * 6 + NotesCount, 3, 3));
		break;
	case 86:
		Base::Add(new Notes(0, OneNotes * 0 + NotesCount, 11));
		Base::Add(new Notes(1, OneNotes * 0 + NotesCount, 11));
		Base::Add(new Notes(0, OneNotes * 2 + NotesCount, 11));
		Base::Add(new Notes(1, OneNotes * 2 + NotesCount, 11));
		Base::Add(new Notes(2, OneNotes * 2 + NotesCount, 11));
		Base::Add(new Notes(0, OneNotes * 4 + NotesCount, 11));
		Base::Add(new Notes(1, OneNotes * 4 + NotesCount, 11));
		Base::Add(new Notes(2, OneNotes * 4 + NotesCount, 11));
		Base::Add(new Notes(3, OneNotes * 4 + NotesCount, 11));
		Base::Add(new Notes(4, OneNotes * 4.5 + NotesCount, 3, 3));
		break;
	*/
	case 87:
		Base::Add(new Notes(3, OneNotes * 0 + NotesCount, 11));
		Base::Add(new Notes(2, OneNotes * 0 + NotesCount, 11));
		Base::Add(new Notes(3, OneNotes * 2 + NotesCount, 11));
		Base::Add(new Notes(2, OneNotes * 2 + NotesCount, 11));
		Base::Add(new Notes(1, OneNotes * 2 + NotesCount, 11));
		Base::Add(new Notes(3, OneNotes * 4 + NotesCount, 11));
		Base::Add(new Notes(2, OneNotes * 4 + NotesCount, 11));
		Base::Add(new Notes(1, OneNotes * 4 + NotesCount, 11));
		Base::Add(new Notes(0, OneNotes * 4 + NotesCount, 11));
		Base::Add(new Notes(1, OneNotes * 6 + NotesCount, 11));
		Base::Add(new Notes(2, OneNotes * 6 + NotesCount, 11));
		break;
	case 88:
		Base::Add(new Notes(1, OneNotes * 0 + NotesCount, 11));
		Base::Add(new Notes(2, OneNotes * 1 + NotesCount, 11));
		Base::Add(new Notes(0, OneNotes * 1 + NotesCount, 11));
		Base::Add(new Notes(2, OneNotes * 2 + NotesCount, 11));
		Base::Add(new Notes(3, OneNotes * 3 + NotesCount, 11));
		Base::Add(new Notes(1, OneNotes * 3 + NotesCount, 11));
		Base::Add(new Notes(1, OneNotes * 4 + NotesCount, 11));
		Base::Add(new Notes(2, OneNotes * 5 + NotesCount, 11));
		Base::Add(new Notes(0, OneNotes * 5 + NotesCount, 11));
		Base::Add(new Notes(2, OneNotes * 6 + NotesCount, 11));
		Base::Add(new Notes(3, OneNotes * 7 + NotesCount, 11));
		Base::Add(new Notes(1, OneNotes * 7 + NotesCount, 11));
		break;
	case 89:
		Base::Add(new Notes(0, OneNotes * 0 + NotesCount, 13));
		Base::Add(new Notes(3, OneNotes * 0 + NotesCount, 13));
		Base::Add(new Notes(1, OneNotes * 1 + NotesCount, 13));
		Base::Add(new Notes(2, OneNotes * 1.5 + NotesCount, 13));
		Base::Add(new Notes(1, OneNotes * 2 + NotesCount, 13));
		Base::Add(new Notes(0, OneNotes * 3 + NotesCount, 13));
		Base::Add(new Notes(1, OneNotes * 4 + NotesCount, 13));
		Base::Add(new Notes(2, OneNotes * 6 + NotesCount, 13));
		break;
	case 90:
		Base::Add(new Notes(0, OneNotes * 0 + NotesCount, 13));
		Base::Add(new Notes(3, OneNotes * 0 + NotesCount, 13));
		Base::Add(new Notes(2, OneNotes * 1 + NotesCount, 13));
		Base::Add(new Notes(1, OneNotes * 1.5 + NotesCount, 13));
		Base::Add(new Notes(2, OneNotes * 2 + NotesCount, 13));
		Base::Add(new Notes(3, OneNotes * 3 + NotesCount, 13));
		Base::Add(new Notes(2, OneNotes * 4 + NotesCount, 13));
		Base::Add(new Notes(1, OneNotes * 6 + NotesCount, 13));
		break;
	case 91:
		Base::Add(new Notes(3, OneNotes * 0 + NotesCount, 11));
		Base::Add(new Notes(2, OneNotes * 0.5 + NotesCount, 11));
		Base::Add(new Notes(3, OneNotes * 1 + NotesCount, 11));
		Base::Add(new Notes(2, OneNotes * 2 + NotesCount, 11));
		Base::Add(new Notes(3, OneNotes * 2.5 + NotesCount, 11));
		Base::Add(new Notes(2, OneNotes * 3 + NotesCount, 11));
		Base::Add(new Notes(0, OneNotes * 4 + NotesCount, 11));
		Base::Add(new Notes(1, OneNotes * 5 + NotesCount, 11));
		Base::Add(new Notes(2, OneNotes * 6 + NotesCount, 11));
		break;
	case 92:
		Base::Add(new Notes(3, OneNotes * 0 + NotesCount, 11));
		Base::Add(new Notes(2, OneNotes * 0.5 + NotesCount, 11));
		Base::Add(new Notes(3, OneNotes * 1 + NotesCount, 11));
		Base::Add(new Notes(2, OneNotes * 1.5 + NotesCount, 11));
		Base::Add(new Notes(3, OneNotes * 2 + NotesCount, 11));
		Base::Add(new Notes(2, OneNotes * 2.5 + NotesCount, 11));
		Base::Add(new Notes(3, OneNotes * 3 + NotesCount, 11));
		Base::Add(new Notes(2, OneNotes * 3.5 + NotesCount, 11));
		Base::Add(new Notes(1, OneNotes * 6 + NotesCount, 11));
		break;
	case 93:
		Base::Add(new Notes(2, OneNotes * 0 + NotesCount, 11));
		Base::Add(new Notes(1, OneNotes * 0.5 + NotesCount, 11));
		Base::Add(new Notes(3, OneNotes * 1 + NotesCount, 11));
		Base::Add(new Notes(2, OneNotes * 2 + NotesCount, 11));
		Base::Add(new Notes(3, OneNotes * 2.5 + NotesCount, 11));
		Base::Add(new Notes(1, OneNotes * 3 + NotesCount, 11));

		Base::Add(new Notes(1, OneNotes * 5 + NotesCount, 11));
		Base::Add(new Notes(2, OneNotes * 5 + NotesCount, 11));
		break;
	/*case 94:
		Base::Add(new Notes(0, OneNotes * 0 + NotesCount, 11));
		Base::Add(new Notes(1, OneNotes * 0.5 + NotesCount, 11));
		Base::Add(new Notes(2, OneNotes * 1 + NotesCount, 11));
		Base::Add(new Notes(3, OneNotes * 2 + NotesCount, 11));
		Base::Add(new Notes(2, OneNotes * 2.5 + NotesCount, 11));
		Base::Add(new Notes(1, OneNotes * 3 + NotesCount, 11));
		Base::Add(new Notes(4, OneNotes * 5 + NotesCount, 3, 3));
		break;
	case 95:
		Base::Add(new Notes(2, OneNotes * 0 + NotesCount, 11));
		Base::Add(new Notes(2, OneNotes * 0.5 + NotesCount, 11));
		Base::Add(new Notes(2, OneNotes * 1 + NotesCount, 11));
		Base::Add(new Notes(3, OneNotes * 2 + NotesCount, 11));
		Base::Add(new Notes(3, OneNotes * 2.5 + NotesCount, 11));
		Base::Add(new Notes(3, OneNotes * 3 + NotesCount, 11));
		Base::Add(new Notes(4, OneNotes * 5 + NotesCount, 2, 3));
		break;
	case 96:
		Base::Add(new Notes(0, OneNotes * 0 + NotesCount, 11));
		Base::Add(new Notes(0, OneNotes * 0.5 + NotesCount, 11));
		Base::Add(new Notes(0, OneNotes * 1 + NotesCount, 11));
		Base::Add(new Notes(1, OneNotes * 2 + NotesCount, 11));
		Base::Add(new Notes(1, OneNotes * 2.5 + NotesCount, 11));
		Base::Add(new Notes(1, OneNotes * 3 + NotesCount, 11));
		Base::Add(new Notes(4, OneNotes * 5 + NotesCount, 6, 3));
		break;;
		*/
	case 97:
		Base::Add(new Notes(2, OneNotes * 0 + NotesCount, 11));
		Base::Add(new Notes(3, OneNotes * 1 + NotesCount, 11));
		Base::Add(new Notes(2, OneNotes * 2 + NotesCount, 11));
		Base::Add(new Notes(0, OneNotes * 3 + NotesCount, 11));
		Base::Add(new Notes(1, OneNotes * 4 + NotesCount, 11));
		Base::Add(new Notes(2, OneNotes * 5 + NotesCount, 11));
		Base::Add(new Notes(3, OneNotes * 6 + NotesCount, 11));
		Base::Add(new Notes(2, OneNotes * 7 + NotesCount, 11));
		break;
	case 98:
		Base::Add(new Notes(0, OneNotes * 0 + NotesCount, 11));
		Base::Add(new Notes(1, OneNotes * 1 + NotesCount, 11));
		Base::Add(new Notes(2, OneNotes * 2 + NotesCount, 11));
		Base::Add(new Notes(2, OneNotes * 3 + NotesCount, 11));
		Base::Add(new Notes(3, OneNotes * 4 + NotesCount, 11));
		Base::Add(new Notes(1, OneNotes * 5 + NotesCount, 11));
		Base::Add(new Notes(1, OneNotes * 6 + NotesCount, 11));
		Base::Add(new Notes(2, OneNotes * 7 + NotesCount, 11));
		break;
	case 99:
		Base::Add(new Notes(3, OneNotes * 0 + NotesCount, 11));
		Base::Add(new Notes(2, OneNotes * 1 + NotesCount, 11));
		Base::Add(new Notes(2, OneNotes * 2 + NotesCount, 11));
		Base::Add(new Notes(1, OneNotes * 3 + NotesCount, 11));
		Base::Add(new Notes(1, OneNotes * 4 + NotesCount, 11));
		Base::Add(new Notes(0, OneNotes * 5 + NotesCount, 11));
		Base::Add(new Notes(1, OneNotes * 6 + NotesCount, 11));
		Base::Add(new Notes(0, OneNotes * 7 + NotesCount, 11));
		break;
	case 103:
		Base::Add(new Notes(2, OneNotes * 0 + NotesCount, 11));
		Base::Add(new Notes(3, OneNotes * 1 + NotesCount, 11));
		Base::Add(new Notes(1, OneNotes * 2 + NotesCount, 11));
		Base::Add(new Notes(2, OneNotes * 3 + NotesCount, 11));
		Base::Add(new Notes(1, OneNotes * 4 + NotesCount, 11));
		Base::Add(new Notes(2, OneNotes * 5 + NotesCount, 11));
		Base::Add(new Notes(3, OneNotes * 6 + NotesCount, 11));
		Base::Add(new Notes(2, OneNotes * 7 + NotesCount, 11));
		break;
	case 104:
		Base::Add(new Notes(3, OneNotes * 0 + NotesCount, 11));
		Base::Add(new Notes(1, OneNotes * 1 + NotesCount, 11));
		Base::Add(new Notes(2, OneNotes * 2 + NotesCount, 11));
		Base::Add(new Notes(2, OneNotes * 3 + NotesCount, 11));
		Base::Add(new Notes(1, OneNotes * 4 + NotesCount, 11));
		Base::Add(new Notes(2, OneNotes * 5 + NotesCount, 11));
		Base::Add(new Notes(0, OneNotes * 6 + NotesCount, 11));
		Base::Add(new Notes(1, OneNotes * 7 + NotesCount, 11));
		break;
	case 105:
		Base::Add(new Notes(2, OneNotes * 0 + NotesCount, 11));
		Base::Add(new Notes(1, OneNotes * 1 + NotesCount, 11));
		Base::Add(new Notes(2, OneNotes * 2 + NotesCount, 11));
		Base::Add(new Notes(0, OneNotes * 3 + NotesCount, 11));
		Base::Add(new Notes(2, OneNotes * 4 + NotesCount, 11));
		Base::Add(new Notes(0, OneNotes * 5 + NotesCount, 11));
		Base::Add(new Notes(2, OneNotes * 6 + NotesCount, 11));
		Base::Add(new Notes(1, OneNotes * 7 + NotesCount, 11));
		break;
	case 106:
		Base::Add(new Notes(1, OneNotes * 0 + NotesCount, 11));
		Base::Add(new Notes(2, OneNotes * 1 + NotesCount, 11));
		Base::Add(new Notes(1, OneNotes * 2 + NotesCount, 11));
		Base::Add(new Notes(2, OneNotes * 3 + NotesCount, 11));
		Base::Add(new Notes(2, OneNotes * 4 + NotesCount, 11));
		Base::Add(new Notes(3, OneNotes * 5 + NotesCount, 11));
		Base::Add(new Notes(0, OneNotes * 6 + NotesCount, 11));
		Base::Add(new Notes(1, OneNotes * 7 + NotesCount, 11));
		break;
	case 107:
		Base::Add(new Notes(1, OneNotes * 0 + NotesCount, 11));
		Base::Add(new Notes(1, OneNotes * 1 + NotesCount, 11));
		Base::Add(new Notes(2, OneNotes * 2 + NotesCount, 11));
		Base::Add(new Notes(3, OneNotes * 3 + NotesCount, 11));
		Base::Add(new Notes(1, OneNotes * 4 + NotesCount, 11));
		Base::Add(new Notes(3, OneNotes * 4 + NotesCount, 11));
		Base::Add(new Notes(2, OneNotes * 5 + NotesCount, 11));
		Base::Add(new Notes(0, OneNotes * 6 + NotesCount, 11));
		Base::Add(new Notes(2, OneNotes * 7 + NotesCount, 11));
		break;
	case 108:
		Base::Add(new Notes(2, OneNotes * 0 + NotesCount, 11));
		Base::Add(new Notes(3, OneNotes * 1 + NotesCount, 11));
		Base::Add(new Notes(0, OneNotes * 1 + NotesCount, 11));
		Base::Add(new Notes(2, OneNotes * 2 + NotesCount, 11));
		Base::Add(new Notes(0, OneNotes * 3 + NotesCount, 11));
		Base::Add(new Notes(2, OneNotes * 3 + NotesCount, 11));
		Base::Add(new Notes(1, OneNotes * 4 + NotesCount, 11));
		Base::Add(new Notes(2, OneNotes * 5 + NotesCount, 11));
		Base::Add(new Notes(3, OneNotes * 6 + NotesCount, 11));
		Base::Add(new Notes(2, OneNotes * 7 + NotesCount, 11));
		break;
		//3

	case 100:
		Base::Add(new Notes(0, OneNotes * 0 + NotesCount, 8));
		break;
	case 101:
		Base::Add(new FreeNotes());
		break;


	case 110:
		Base::Add(new Notes(0, OneNotes * 0 + NotesCount, 0));
		break;
	case 111:
		Base::Add(new Notes(1, OneNotes * 0 + NotesCount, 0));
		break;
	case 112:
		Base::Add(new Notes(2, OneNotes * 0 + NotesCount, 0));
		break;
	case 113:
		Base::Add(new Notes(3, OneNotes * 0 + NotesCount, 0));
		break;
	case 114:
		Base::Add(new Notes(4, OneNotes * 0 + NotesCount, 0));
		break;
	case 115:
		Base::Add(new Notes(5, OneNotes * 0 + NotesCount, 0));
		break;
	case 116:
		Base::Add(new Notes(6, OneNotes * 0 + NotesCount, 0));
		break;
	case 117:
		Base::Add(new Notes(7, OneNotes * 0 + NotesCount, 0));
		break;
	case 118:
		Base::Add(new Notes(4, OneNotes * 0 + NotesCount, 1));
		Base::Add(new Notes(0, OneNotes * 0 + NotesCount, 1));
		break;
	
		
	}

	switch (SoundNum) {
	case eNum_Gothic:
		NotesCount += 56.8;//àÍè¨êﬂÇÃí∑Ç≥
		break;
	case eNum_Bell:
		NotesCount += 50.2;
		break;
	case eNum_Tutorial:
		NotesCount += 105.6;
		break;
	case eNum_Michikusa:
		NotesCount += 44.7;
		break;
	}
}
void Play::NotesSet() {
	switch (SoundNum) {
	case eNum_Gothic:
		NotesCount = -140.5;
		NotesPreSet(19);
		NotesPreSet(19);
		NotesPreSet(19);
		NotesPreSet(19);
		NotesPreSet(19);
		NotesPreSet(19);
		NotesPreSet(19);
		NotesPreSet(19);
		NotesPreSet(19);
		NotesPreSet(19);
		NotesPreSet(6);
		NotesPreSet(114);
		NotesPreSet(115);
		NotesPreSet(116);
		NotesPreSet(117);
		NotesPreSet(110);
		NotesPreSet(111);
		NotesPreSet(112);
		NotesPreSet(113);
		break;
	case eNum_Bell:
		NotesCount = -165.5;
		NotesPreSet(116);
		NotesPreSet(117);
		NotesPreSet(113);
		NotesPreSet(112);
		NotesPreSet(112);
		NotesPreSet(113);
		NotesPreSet(117);
		NotesPreSet(116);
		
		
		
		NotesPreSet(8);
		NotesPreSet(9);
		NotesPreSet(11);
		NotesPreSet(12);
		break;
	case eNum_Michikusa:
		NotesCount = -26.5;
		NotesPreSet(0);
		NotesPreSet(0);
		NotesPreSet(0);
		NotesPreSet(0);
		NotesPreSet(0);
		NotesPreSet(0);
		NotesPreSet(0);
		NotesPreSet(0);
		NotesPreSet(0);
		NotesPreSet(0);
		break;
	case eNum_Tutorial:
		NotesCount = -159.75;
		NotesPreSet(28);
		NotesPreSet(25);
		NotesPreSet(118);
		NotesPreSet(27);
		NotesPreSet(24);
		NotesPreSet(118);
		NotesPreSet(0);
		NotesPreSet(0);
		NotesPreSet(0);
		NotesPreSet(0);
		NotesPreSet(0);
		NotesPreSet(0);
		NotesPreSet(0);
		NotesPreSet(0);
		NotesPreSet(0);
		NotesPreSet(6);
		NotesPreSet(6);
		NotesPreSet(6);
		NotesPreSet(6);
		NotesPreSet(6);
		NotesPreSet(6);
		NotesPreSet(6);
		break;
	}
}