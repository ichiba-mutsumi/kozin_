#pragma once
#include "../Base/Base.h"
enum {
	eMode_Normal,
	eMode_Challenge,
};
class ShareNum {
public:
	static int GameNum;
	static int MaxGame;
	static int ModeNum;
	static int MaxMode;
	static int score;
	static int HitCount;
	static bool debug;
	static bool Hit;
	static void SetScore(int SelectGameNum);
	static void AddScore(int SelectGameNum);
	static void SubScore(int GameMode);
};