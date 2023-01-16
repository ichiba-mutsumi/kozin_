#include "ShareNum.h"

int ShareNum::ModeNum = 0;
int ShareNum::MaxMode = 2;
int ShareNum::GameNum = 0;
int ShareNum::MaxGame = 4;
int ShareNum::score = 0;
int ShareNum::HitCount = 0;
bool ShareNum::debug = false;
bool ShareNum::Hit = false;
void ShareNum::AddScore(int SelectGameNum) {
	switch (SelectGameNum) {
	case eMode_Normal:
		score += 100;
		break;
	case eMode_Challenge:
		break;
	}
}
void ShareNum::SetScore(int SelectGameNum) {
	switch (SelectGameNum) {
	case eMode_Normal:
		score = 0;
		break;
	case eMode_Challenge:
		score = 8000;
		break;
	}
}
void ShareNum::SubScore(int GameMode) {
	switch (GameMode) {
	case eMode_Normal:
		break;
	case eMode_Challenge:
		score -= 100;
		if (score < 0) {
			score = 0;
		}
		break;
	}
	
}