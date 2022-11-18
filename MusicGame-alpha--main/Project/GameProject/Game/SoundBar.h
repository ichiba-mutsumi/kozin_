#pragma once
#include <Gllibrary.h>
#include "../Base/Base.h"
class SoundBar :public Base {
public:
	enum {
		Gothic,
		Tir,
		Bones,
	};
	int SongCount;
	int SongLen;
	CImage BarFrame;
	CImage Bar;
public:
	SoundBar(int SoundNum);
	void Update();
	void ImageSet();
	void Draw();
};