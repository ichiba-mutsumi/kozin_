#include <Gllibrary.h>
#include <iostream>
#include "../Base/Base.h"
#include "SoundBar.h"

SoundBar::SoundBar(int SoundNum) :Base(eType_Bar) {
	ImageSet();
	switch(SoundNum) {
	case LeanOn:
		SongLen = 7080;
		break;
	case Baby:
		SongLen = 9480;
		break;
	case Bones:
		SongLen = 6720;
		break;
	}
}
void SoundBar::Update() {
	SongCount++;
}
void SoundBar::ImageSet() {
	Bar = COPY_RESOURCE("SoundBar", CImage);
	BarFrame = COPY_RESOURCE("SoundBar", CImage);
	BarFrame.SetRect(0,0,1920,15);
	BarFrame.SetSize(1920, 15);
}
void SoundBar::Draw() {
	 int BarPos= 1918 * SongCount / SongLen;
	//std::cout << BarPos << std::endl;
	Bar.SetRect(1, 20, 1 + BarPos, 31);
	Bar.SetSize(BarPos, 11);
	Bar.SetPos(0, 21);
	BarFrame.SetPos(1, 20);
	BarFrame.Draw();
	Bar.Draw();
}