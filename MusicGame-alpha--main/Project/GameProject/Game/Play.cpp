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
score_text("C:\\Windows\\Fonts\\msgothic.ttc", 64){
	glClearColor(0, 0, 0, 0);
	CountDownToStart = 190;
	CountUpToEnd = 0;
	SoundNum = ChoiceSound;
	ImageSet();
	switch (ChoiceSound) {
	case eNum_LeanOn:
		video = new CVideo("Movie/LeanOn.mp4");
		break;
	case eNum_Baby:
		video = new CVideo("Movie/Baby.mp4");
		break;
	case eNum_Bones:
		video = new CVideo("Movie/Bones.mp4");
		break;
	}
	for (int i = 0; i < 4; i++) {
		PushKey[i] = false;
	}
}
void Play::Draw() {
	if (CountDownToStart <= 0) {
		video->Draw();
	}
	Lane.Draw();
	NotesBar.Draw();
	LeftClick.Draw();
	for (int i = 0; i < 4; i++) {
		if (PushKey[i] == true) {
			NotesBarBlue[i].Draw();
		}
	}
}
void Play::Update() {
	CountDownToStart--;
	CountUpToEnd++;
	switch (ShareNum::GameNum) {
	case eNum_LeanOn:
		if (CountDownToStart == 0) {
			LeanOn();
		}
		if (CountUpToEnd >= 7080) {
			m_kill = true;
		}
		break;
	case eNum_Baby:
		if (CountDownToStart == 0) {
			Baby();
		}
		if (CountUpToEnd >= 9480) {
			m_kill = true;
		}
		break;
	case eNum_Bones:
		if (CountDownToStart == 0) {
			Bones();
		}
		if (CountUpToEnd >= 6720) {
			m_kill = true;
		}
		break;
	}
	for (int i = 0; i < 4; i++) {
		if (PushKey[i] == true) {
			//m_NotesBar = NotesBarBlue;
			PushCount[i]++;
		}
		if (PushCount[i] >= 10) {
			PushKey[i] = false;
			//KeyNum = 4;
			//m_NotesBar = NotesBar;
		}
	}
	if (HOLD(CInput::eButton1)) {
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
	//std::cout << ShareNum::HitCount << std::endl;
}	
Play::~Play() {
	std::ofstream Lfile("Score/LeanOn.txt", std::ios_base::app | std::ios_base::in);
	std::ofstream Bfile("Score/Baby.txt", std::ios_base::app | std::ios_base::in);
	std::ofstream Bofile("Score/Baby.txt", std::ios_base::app | std::ios_base::in);
	switch (ShareNum::GameNum) {
	case eNum_LeanOn:
		Lfile << ShareNum::score << std::endl;
		break;
	case eNum_Baby:
		Bfile << ShareNum::score << std::endl;
		break;
	case eNum_Bones:
		Bofile << ShareNum::score << std::endl;
		break;
	}
	video->Stop();
	Base::KillAll();
	Base::Add(new ScoreScene());
}
void Play::ImageSet() {
	Lane = COPY_RESOURCE("Lane", CImage);
	NotesBar = COPY_RESOURCE("NotesBar", CImage);
	for (int i = 0; i < 4; i++) {
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
	NotesBarBlue[3].SetSize(257, 1080);
	LeftClick= COPY_RESOURCE("LeftClick", CImage);
	//m_NotesBar = NotesBar;
}
void Play::Baby() {
	video->Play();
	OneNotes = 13.6;
	Base::Add(new SoundBar(1));
	Base::Add(new Score());
	NotesSet();
}
void Play::LeanOn() {
	video->Play();
	OneNotes = 18.125;
	Base::Add(new SoundBar(0));
	Base::Add(new Score());
	NotesSet();
}
void Play::Bones() {
	video->Play();
	OneNotes = 15.725;
	Base::Add(new SoundBar(2));
	Base::Add(new Score());
	NotesSet();
}
void Play::NotesPreSet(int SetNum) {
	switch (SetNum) {
	case 0:
		Base::Add(new Notes(4, OneNotes * 0 + NotesCount,2,6));
		Base::Add(new Notes(4, OneNotes * 4 + NotesCount, 0, 7));
		Base::Add(new Notes(4, OneNotes * 15 + NotesCount, 6, 0));
		Base::Add(new Notes(4, OneNotes * 23 + NotesCount, 1, 3));
		Base::Add(new Notes(4, OneNotes * 34 + NotesCount, 0, 1));
		Base::Add(new Notes(4, OneNotes * 47 + NotesCount, 0, 6));
		Base::Add(new Notes(4, OneNotes * 59 + NotesCount, 5, 5));
		Base::Add(new Notes(4, OneNotes * 78 + NotesCount, 4, 9));
		Base::Add(new Notes(4, OneNotes * 86 + NotesCount, 7, 2));
		Base::Add(new Notes(4, OneNotes * 104 + NotesCount, 6, 6));
		Base::Add(new Notes(4, OneNotes * 112 + NotesCount, 4, 1));
		Base::Add(new Notes(4, OneNotes * 123 + NotesCount, 9, 4));
		Base::Add(new Notes(4, OneNotes * 137 + NotesCount, 2, 1));
		Base::Add(new Notes(4, OneNotes * 144 + NotesCount, 3, 6));
		Base::Add(new Notes(4, OneNotes * 170 + NotesCount, 8, 7));
		Base::Add(new Notes(4, OneNotes * 188 + NotesCount, 4, 2));
		Base::Add(new Notes(4, OneNotes * 199 + NotesCount, 2, 6));
		Base::Add(new Notes(4, OneNotes * 210 + NotesCount, 0, 7));

		Base::Add(new Notes(4, OneNotes * 270 + NotesCount, 0, 0));
		Base::Add(new Notes(4, OneNotes * 275 + NotesCount, 1, 0));
		Base::Add(new Notes(4, OneNotes * 280 + NotesCount, 2, 0));
		Base::Add(new Notes(4, OneNotes * 285 + NotesCount, 3, 0));
		Base::Add(new Notes(4, OneNotes * 290 + NotesCount, 4, 0));
		Base::Add(new Notes(4, OneNotes * 295 + NotesCount, 5, 0));

		Base::Add(new Notes(4, OneNotes * 310 + NotesCount, 2, 2));
		Base::Add(new Notes(4, OneNotes * 330 + NotesCount, 4, 8));
		Base::Add(new Notes(4, OneNotes * 345 + NotesCount, 3, 5));
		Base::Add(new Notes(4, OneNotes * 354 + NotesCount, 9, 0));
		Base::Add(new Notes(4, OneNotes * 367 + NotesCount, 0, 6));
		Base::Add(new Notes(4, OneNotes * 371 + NotesCount, 1, 6));
		Base::Add(new Notes(4, OneNotes * 389 + NotesCount, 4, 8));
		Base::Add(new Notes(4, OneNotes * 427 + NotesCount, 5, 0));
		//Base::Add(new Notes(1, OneNotes * 2 + NotesCount, 8));
		//Base::Add(new Notes(2, OneNotes * 4 + NotesCount, 20));
		break;
	case 1:
		Base::Add(new Notes(0, OneNotes * 0 + NotesCount, 8));
		Base::Add(new Notes(2, OneNotes * 0 + NotesCount, 8));
		break;
	case 2:
		Base::Add(new Notes(1, OneNotes * 1.9+ NotesCount, 8));
		Base::Add(new Notes(3, OneNotes * 1.9 + NotesCount, 8));
		break;
	case 3:
		Base::Add(new Notes(0, OneNotes * 3.5 + NotesCount, 8));
		Base::Add(new Notes(3, OneNotes * 3.5+ NotesCount, 8));
		break;
	case 4:
		Base::Add(new Notes(1, OneNotes * 5 + NotesCount, 8));
		Base::Add(new Notes(2, OneNotes * 5 + NotesCount, 8));
		break;
	case 5:
		Base::Add(new Notes(0, OneNotes * 7.3 + NotesCount, 8));
		Base::Add(new Notes(1, OneNotes * 7.3 + NotesCount, 8));
		break;
	case 6:
		
		Base::Add(new Notes(0, OneNotes * 8.2 + NotesCount, 8));
		break;
	case 7:
		Base::Add(new Notes(3, OneNotes * 9.5 + NotesCount, 3));
		break;
	case 8:
		Base::Add(new Notes(0, OneNotes * 2 + NotesCount, 8));
		Base::Add(new Notes(2, OneNotes * 3 + NotesCount, 8));
		break;
	case 9:
		Base::Add(new Notes(0, OneNotes * 2 + NotesCount, 8));
		Base::Add(new Notes(2, OneNotes * 3 + NotesCount, 8));
		break;
	case 10:
		Base::Add(new Notes(0, OneNotes * 10 + NotesCount, 8));
		Base::Add(new Notes(1, OneNotes * 10.5 + NotesCount, 8));
		Base::Add(new Notes(2, OneNotes * 11 + NotesCount, 8));
		Base::Add(new Notes(3, OneNotes * 11.5 + NotesCount, 8));
		break;
	case 11:
		Base::Add(new Notes(3, OneNotes * 5 + NotesCount, 8));
		Base::Add(new Notes(2, OneNotes * 6 + NotesCount, 8));
		break;
	case 12:
		Base::Add(new Notes(3, OneNotes * 9 + NotesCount, 8));
		Base::Add(new Notes(0, OneNotes * 10 + NotesCount, 8));
		break;
	case 13:
		Base::Add(new Notes(1, OneNotes * 6 + NotesCount, 8));
		Base::Add(new Notes(0, OneNotes * 7 + NotesCount, 8));
		break;
	case 14:
		Base::Add(new Notes(3, OneNotes * 7 + NotesCount, 8));
		Base::Add(new Notes(1, OneNotes * 8 + NotesCount, 8));
		break;
	case 15:
		
		Base::Add(new Notes(1, OneNotes * 5.6 + NotesCount, 8));
		break;
	case 16:
		
		Base::Add(new Notes(2, OneNotes * 9.6 + NotesCount, 9));
		break;
	case 17:
		
		Base::Add(new Notes(3, OneNotes * 4.6 + NotesCount, 9));
		break;
	case 18:
		Base::Add(new Notes(3, OneNotes * 7 + NotesCount, 8));
		Base::Add(new Notes(2, OneNotes * 7.5 + NotesCount, 8));
		Base::Add(new Notes(1, OneNotes * 8 + NotesCount, 8));
		Base::Add(new Notes(0, OneNotes * 8.5 + NotesCount, 8));
		break;
	case 19:
		Base::Add(new Notes(1, OneNotes * 0 + NotesCount, 8));
		break;
	case 20:
		Base::Add(new Notes(2, OneNotes * 0 + NotesCount, 8));
		break;
	case 21:
		Base::Add(new Notes(3, OneNotes * 0 + NotesCount, 8));
		break;
	case 22:
		Base::Add(new Notes(1, OneNotes * 0 + NotesCount, 8));
		Base::Add(new Notes(1, OneNotes * 0.5 + NotesCount, 8));
		Base::Add(new Notes(2, OneNotes * 1 + NotesCount, 8));
		break;
	case 23:
		Base::Add(new Notes(2, OneNotes * 0 + NotesCount, 8));
		Base::Add(new Notes(3, OneNotes * 0.5 + NotesCount, 8));
		Base::Add(new Notes(2, OneNotes * 1 + NotesCount, 8));
		Base::Add(new Notes(3, OneNotes * 1.5 + NotesCount, 8));
		break;
	case 24:
		Base::Add(new Notes(1, OneNotes * 0 + NotesCount, 8));
		Base::Add(new Notes(3, OneNotes * 0 + NotesCount, 8));
		Base::Add(new Notes(0, OneNotes * 1 + NotesCount, 8));
		Base::Add(new Notes(1, OneNotes * 2 + NotesCount, 8));
		break;
	case 25:
		Base::Add(new Notes(2, OneNotes * 1 + NotesCount, 6));
		Base::Add(new Notes(3, OneNotes * 1.3 + NotesCount, 8));
		Base::Add(new Notes(1, OneNotes * 1.6 + NotesCount, 9));
		break;
	case 26:
		Base::Add(new Notes(1, OneNotes * 0 + NotesCount, 8));
		
		Base::Add(new Notes(2, OneNotes * 2 + NotesCount, 8));
		
		Base::Add(new Notes(1, OneNotes * 4 + NotesCount, 8));
		
		Base::Add(new Notes(3, OneNotes * 6 + NotesCount, 8));
		break;
	case 27:
		Base::Add(new Notes(1, OneNotes * 0 + NotesCount, 8));
		Base::Add(new Notes(2, OneNotes * 1 + NotesCount, 8));
		Base::Add(new Notes(1, OneNotes * 2.5 + NotesCount, 8));
		Base::Add(new Notes(2, OneNotes * 3 + NotesCount, 8));
		Base::Add(new Notes(3, OneNotes * 3.5 + NotesCount, 8));
		break;
	case 28:
		Base::Add(new Notes(0, OneNotes * 1.5 + NotesCount, 8));
		Base::Add(new Notes(1, OneNotes * 2 + NotesCount, 8));
		Base::Add(new Notes(2, OneNotes * 3.5 + NotesCount, 8));
		break;
	case 29:
		Base::Add(new Notes(4, OneNotes * 0 + NotesCount, 3, 3));
		Base::Add(new Notes(4, OneNotes * 1 + NotesCount, 4, 2));
		Base::Add(new Notes(4, OneNotes * 2 + NotesCount, 5, 1));
		Base::Add(new Notes(4, OneNotes * 3 + NotesCount, 6, 0));
		Base::Add(new Notes(4, OneNotes * 4 + NotesCount, 7, 1));
		Base::Add(new Notes(4, OneNotes * 5 + NotesCount, 8, 2));
		break;
	case 30:
		Base::Add(new Notes(0, OneNotes * 0 + NotesCount, 8));
		Base::Add(new Notes(1, OneNotes * 2 + NotesCount, 8));
		Base::Add(new Notes(2, OneNotes * 0 + NotesCount, 8));
		Base::Add(new Notes(3, OneNotes * 2 + NotesCount, 8));
		break;
	case 31:
		Base::Add(new Notes(4, OneNotes * 1 + NotesCount, 1, 2));
		Base::Add(new Notes(4, OneNotes * 2.5 + NotesCount, 2, 1));
		Base::Add(new Notes(0, OneNotes * 3 + NotesCount, 8));
		Base::Add(new Notes(3, OneNotes * 4 + NotesCount, 8));
		break;
	case 32:
		Base::Add(new Notes(1, OneNotes * 0 + NotesCount, 8));
		Base::Add(new Notes(2, OneNotes * 0.5 + NotesCount, 8));
		Base::Add(new Notes(1, OneNotes * 1 + NotesCount, 8));
		break;
	case 33:
		Base::Add(new Notes(1, OneNotes * 0 + NotesCount, 8));
		Base::Add(new Notes(1, OneNotes * 1 + NotesCount, 8));
		Base::Add(new Notes(2, OneNotes * 2 + NotesCount, 8));
		Base::Add(new Notes(0, OneNotes * 3 + NotesCount, 8));
		break;
	case 34:
		Base::Add(new Notes(4, OneNotes * 0 + NotesCount, 0, 4));
		Base::Add(new Notes(4, OneNotes * 1 + NotesCount, 3, 7));
		break;
	case 35:
		Base::Add(new Notes(4, OneNotes * 1 + NotesCount, 2, 9));
		Base::Add(new Notes(4, OneNotes * 2 + NotesCount, 5, 1));
		break;
	case 36:
		Base::Add(new Notes(4, OneNotes * 0 + NotesCount, 4, 3));
		Base::Add(new Notes(4, OneNotes * 2 + NotesCount, 4, 2));
		break;
	case 37:
		Base::Add(new Notes(1, OneNotes * 4 + NotesCount, 8));
		Base::Add(new Notes(0, OneNotes * 3.5 + NotesCount, 8));
		break;
	case 38:
		Base::Add(new Notes(4, OneNotes * 1 + NotesCount, 3, 3));
		Base::Add(new Notes(4, OneNotes * 2.5 + NotesCount, 2, 2));
		Base::Add(new Notes(0, OneNotes * 3 + NotesCount, 8));
		Base::Add(new Notes(3, OneNotes * 5 + NotesCount, 8));
		Base::Add(new Notes(4, OneNotes * 6 + NotesCount, 1, 1));
		Base::Add(new Notes(4, OneNotes * 7.5 + NotesCount, 2, 2));
		Base::Add(new Notes(2, OneNotes * 8 + NotesCount, 8));
		Base::Add(new Notes(0, OneNotes * 9 + NotesCount, 8));
		break;
	case 39:
		Base::Add(new Notes(2, OneNotes * 1 + NotesCount, 8));
		Base::Add(new Notes(0, OneNotes * 3 + NotesCount, 8));
		break;
	case 40:
		Base::Add(new Notes(0, OneNotes * 2 + NotesCount, 8));
		Base::Add(new Notes(3, OneNotes * 5 + NotesCount, 8));
		break;
	case 41:
		Base::Add(new Notes(1, OneNotes * 0 + NotesCount,8));
		Base::Add(new Notes(2, OneNotes * 3 + NotesCount, 8));
		break;
	case 42:
		Base::Add(new Notes(3, OneNotes * 2 + NotesCount, 8));
		Base::Add(new Notes(3, OneNotes * 2 + NotesCount, 8));
		break;
	case 43:
		Base::Add(new Notes(1, OneNotes * 0 + NotesCount, 8));
		Base::Add(new Notes(1, OneNotes * 4 + NotesCount, 8));
		break;
	case 44:
		Base::Add(new Notes(4, OneNotes * 0 + NotesCount, 0, 1));
		Base::Add(new Notes(0, OneNotes * 2 + NotesCount, 8));
		Base::Add(new Notes(3, OneNotes * 4 + NotesCount, 8));
		Base::Add(new Notes(3, OneNotes * 7 + NotesCount, 8));
		break;
	case 45:
		Base::Add(new Notes(0, OneNotes * 1 + NotesCount, 8));
		Base::Add(new Notes(0, OneNotes * 3 + NotesCount, 8));
		Base::Add(new Notes(3, OneNotes * 5 + NotesCount, 8));
		Base::Add(new Notes(3, OneNotes * 7 + NotesCount, 8));
		break;
	case 46:
		Base::Add(new Notes(0, OneNotes * 1 + NotesCount, 8));
		Base::Add(new Notes(2, OneNotes * 1.3 + NotesCount, 8));
		Base::Add(new Notes(0, OneNotes * 2.5 + NotesCount, 8));
		Base::Add(new Notes(1, OneNotes * 4 + NotesCount, 8));
		Base::Add(new Notes(3, OneNotes * 4.3 + NotesCount, 8));
		break;
	case 47:
		Base::Add(new Notes(2, OneNotes * 0 + NotesCount, 8));
		Base::Add(new Notes(1, OneNotes * 0.5 + NotesCount, 8));
		Base::Add(new Notes(3, OneNotes * 1 + NotesCount, 8));
		break;
	case 48:
		Base::Add(new Notes(0, OneNotes * 3 + NotesCount, 8));
		Base::Add(new Notes(3, OneNotes * 3.5 + NotesCount, 8));
		Base::Add(new Notes(1, OneNotes * 4 + NotesCount, 8));
		break;
	case 49:
		Base::Add(new Notes(1, OneNotes * 0 + NotesCount, 8));
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
		//3
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
	case 61:
		Base::Add(new Notes(4, OneNotes * 3 + NotesCount, 0, 0));
		Base::Add(new Notes(4, OneNotes * 4 + NotesCount, 2, 3));
		Base::Add(new Notes(4, OneNotes * 6 + NotesCount, 1, 1));
		break;
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
	case 73:
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
	case 77:
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
	case 85:
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
		Base::Add(new Notes(3, OneNotes * 3+ NotesCount, 11));
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
	case 94:
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
	}
	
	switch (SoundNum) {
	case eNum_LeanOn:
		NotesCount += 145.1;
		break;
	case eNum_Baby:
		NotesCount += 108.8;
		break;
	case eNum_Bones:
		NotesCount += 125.8;
		break;
	}
}
void Play::NotesSet() {
	switch (SoundNum) {
	case eNum_LeanOn:
		NotesCount = -117.75; 
		/*Base::Add(new FreeNotes());
		Base::Add(new FreeNotes());
		Base::Add(new FreeNotes());
		Base::Add(new FreeNotes());*/
		//‚±‚±‚Ü‚Åtest
		NotesPreSet(0);
		NotesPreSet(1);
		NotesPreSet(2);
		NotesPreSet(3);
		NotesPreSet(4);
		NotesPreSet(15);
		NotesPreSet(5);
		NotesPreSet(6);
		NotesPreSet(17);
		NotesPreSet(7);
		NotesPreSet(8);
		NotesPreSet(16);
		NotesPreSet(2);
		NotesPreSet(1);
		NotesPreSet(17);
		NotesPreSet(6);
		NotesPreSet(12);
		NotesPreSet(7);
		NotesPreSet(3);
		NotesPreSet(15);
		NotesPreSet(4);
		NotesPreSet(11);
		NotesPreSet(8);
		NotesPreSet(5);
		NotesPreSet(11);
		NotesPreSet(3);
		NotesPreSet(12);
		NotesPreSet(10);
		NotesPreSet(13);
		NotesPreSet(4);
		NotesPreSet(14);
		NotesPreSet(7);
		NotesPreSet(15);
		NotesPreSet(18);
		NotesPreSet(9);
		NotesPreSet(13);
		NotesPreSet(16);
		NotesPreSet(15);
		NotesPreSet(17);
		NotesPreSet(12);
		NotesPreSet(11);
		NotesPreSet(14);
		NotesPreSet(13);
		NotesPreSet(15);
		NotesPreSet(12);
		NotesPreSet(4);
		NotesPreSet(5);
		NotesPreSet(0);
		NotesPreSet(0);
		NotesPreSet(0);
		break;
	case eNum_Baby:
		NotesCount = -54.4;
		NotesPreSet(30);
		NotesPreSet(7);
		NotesPreSet(10);
		NotesPreSet(14);
		NotesPreSet(14);
		NotesPreSet(200);
		NotesPreSet(200);
		NotesPreSet(100);
		NotesPreSet(100);
		NotesPreSet(19);
		NotesPreSet(19);
		NotesPreSet(21);
		NotesPreSet(21);
		NotesPreSet(20);
		NotesPreSet(20);
		NotesPreSet(100);
		NotesPreSet(28);
		NotesPreSet(100);
		NotesPreSet(23);
		NotesPreSet(100);
		NotesPreSet(25);
		NotesPreSet(100);
		NotesPreSet(24);
		NotesPreSet(27);
		NotesPreSet(26);
		NotesPreSet(28);
		NotesPreSet(29);
		NotesPreSet(20);
		NotesPreSet(31);
		NotesPreSet(34);
		NotesPreSet(41);
		NotesPreSet(42);
		NotesPreSet(24);
		NotesPreSet(43);
		NotesPreSet(23);
		NotesPreSet(20);
		NotesPreSet(42);
		NotesPreSet(35);
		NotesPreSet(41);
		NotesPreSet(29);
		NotesPreSet(4);
		NotesPreSet(20);
		NotesPreSet(36);
		NotesPreSet(43);
		NotesPreSet(37);
		NotesPreSet(38);
		NotesPreSet(100);
		NotesPreSet(40);
		NotesPreSet(48);
		NotesPreSet(52);
		NotesPreSet(39);
		NotesPreSet(44);
		NotesPreSet(45);
		NotesPreSet(42);
		NotesPreSet(51);
		NotesPreSet(46);
		NotesPreSet(48);
		NotesPreSet(47);
		NotesPreSet(49);
		NotesPreSet(50);
		NotesPreSet(53);
		NotesPreSet(42);
		NotesPreSet(33);
		NotesPreSet(41);
		NotesPreSet(27);
		NotesPreSet(16);
		NotesPreSet(51);
		NotesPreSet(19);
		NotesPreSet(37);
		NotesPreSet(46);
		NotesPreSet(47);
		NotesPreSet(40);
		NotesPreSet(42);
		NotesPreSet(35);
		NotesPreSet(54);
		NotesPreSet(44);
		NotesPreSet(55);
		NotesPreSet(8);
		NotesPreSet(57);
		NotesPreSet(200);
		NotesPreSet(200);
		NotesPreSet(200);
		NotesPreSet(200);
		NotesPreSet(200);
		NotesPreSet(200);
		NotesPreSet(200);
		NotesPreSet(200);
		NotesPreSet(200);
		NotesPreSet(200);
		NotesPreSet(200);
		NotesPreSet(200);
		NotesPreSet(200);
		NotesPreSet(200);
		NotesPreSet(200);
		NotesPreSet(200);
		NotesPreSet(200);
		break;
	case eNum_Bones:
		NotesCount = -15;
		NotesPreSet(200);
		NotesPreSet(58);
		NotesPreSet(59);
		NotesPreSet(60);
		NotesPreSet(61);
		NotesPreSet(62);
		NotesPreSet(63);
		NotesPreSet(64);
		NotesPreSet(65);
		NotesPreSet(66);
		NotesPreSet(67);
		NotesPreSet(68);
		NotesPreSet(69);
		NotesPreSet(70);
		NotesPreSet(71);
		NotesPreSet(72);
		NotesPreSet(73); 
		NotesPreSet(74);
		NotesPreSet(75);
		NotesPreSet(76);
		NotesPreSet(77);
		NotesPreSet(78);
		NotesPreSet(79);
		NotesPreSet(80);
		NotesPreSet(81);
		NotesPreSet(82);
		NotesPreSet(83);
		NotesPreSet(84);
		NotesPreSet(85);
		NotesPreSet(86);
		NotesPreSet(86);
		NotesPreSet(87);
		NotesPreSet(88);
		NotesPreSet(89);
		NotesPreSet(90);
		NotesPreSet(91);
		NotesPreSet(92);
		NotesPreSet(93);
		NotesPreSet(94);
		NotesPreSet(95);
		NotesPreSet(96);
		NotesPreSet(97);
		NotesPreSet(98);
		NotesPreSet(99);
		NotesPreSet(103);
		NotesPreSet(104);
		NotesPreSet(105);
		NotesPreSet(106);
		NotesPreSet(107);
		NotesPreSet(200);
		NotesPreSet(200);
		NotesPreSet(200);
		NotesPreSet(200);
		NotesPreSet(200);
		NotesPreSet(200);
		NotesPreSet(100);
		NotesPreSet(100);
		NotesPreSet(100);
		NotesPreSet(100);
		NotesPreSet(100);
		NotesPreSet(100);
		NotesPreSet(100);
		NotesPreSet(100);
		NotesPreSet(100);
		NotesPreSet(100);
		NotesPreSet(100);
		NotesPreSet(100);
		NotesPreSet(100);
		NotesPreSet(100);
		NotesPreSet(100);
		NotesPreSet(100);
		NotesPreSet(100);
		NotesPreSet(100);
		NotesPreSet(100);
		NotesPreSet(100);
		NotesPreSet(100);
		NotesPreSet(100);
		NotesPreSet(100);
		NotesPreSet(100);
		NotesPreSet(100);
		NotesPreSet(100);
		NotesPreSet(100);
		NotesPreSet(100);
		NotesPreSet(100);
		NotesPreSet(100);
		NotesPreSet(100);
		NotesPreSet(100);
		NotesPreSet(100);
		NotesPreSet(100);
		NotesPreSet(100);
		NotesPreSet(100);
		NotesPreSet(100);
		NotesPreSet(100);
		NotesPreSet(100);
		NotesPreSet(100);
		NotesPreSet(100);
		NotesPreSet(100);
		NotesPreSet(100);
		NotesPreSet(100);
		NotesPreSet(100);
		NotesPreSet(100);
		NotesPreSet(100);
		NotesPreSet(100);
		NotesPreSet(100);
		NotesPreSet(100);
		NotesPreSet(100);
		NotesPreSet(100);
		NotesPreSet(100);
		NotesPreSet(100);
		NotesPreSet(100);
		NotesPreSet(100);
		NotesPreSet(100);
		NotesPreSet(100);
		break;
	}
}