#include "Ranking.h"
#include "ShareNum.h"
#include <Gllibrary.h>
#include <iostream>
#include <fstream>

Ranking::Ranking(int state) :Base(eType_Ranking)
, Ranking_text("C:\\Windows\\Fonts\\msgothic.ttc", 50) {
	switch (state) {
	case eState_LeanOn:
		LeanOn();
		break;
	case eState_Baby:
		Baby();
		break;
	case eState_Bones:
		Bones();
		break;
	}
	ImageSet();
}
void Ranking::Draw() {
	//m_scoreを[0]から順番に10個出力
	for (int i = 0; i <= max && i < 10; i++) {
		int Temp = m_score[i];
		int m = 0;
		while (Temp >= 1) {
			int k = Temp % 10;
			Temp = Temp / 10;
			//printf("%d::k\n", k);
			m_img[k].SetPos(1500 - 40 * (m + 1), 240 + 70 * i);
			m_img[k].Draw();
			m++;
		}
	}
	Ranking_text.Draw(1310, 180, 1, 1, 1, "Ranking");
}
void Ranking::ImageSet() {
	for (int i = 0; i < 10; i++) {
		m_img[i] = COPY_RESOURCE("Number", CImage);
		m_img[i].SetRect(i * 39, 0, (i + 1) * 39, 77);
		m_img[i].SetSize(30, 50);
	}
}
void Ranking::LeanOn() {
	std::fstream file("Score/LeanOn.txt", std::ios::in);
	//データの読み取り
	int i = 0;
	for (i = 0; i < 10000; i++) {
		file >> data[i];
		m_score[i] = atoi(data[i].c_str());
		file.seekp(+2, std::ios::cur);
		if (file.eof()) {
			i--;
			break;
		}
	}
	max = i;
	//大きい順に並べ替え
	for (int k = max; k >= 1; k--) {
		for (int m = k - 1; m >= 0; m--) {
			if (m_score[k] > m_score[m]) {
				int w = m_score[k];
				m_score[k] = m_score[m];
				m_score[m] = w;
			}
		}
	}
}
void Ranking::Baby() {
	std::fstream file("Score/Baby.txt", std::ios::in);
	//データの読み取り
	int i = 0;
	for (i = 0; i < 10000; i++) {
		file >> data[i];
		m_score[i] = atoi(data[i].c_str());
		file.seekp(+2, std::ios::cur);
		if (file.eof()) {
			i--;
			break;
		}
	}
	max = i;
	//大きい順に並べ替え
	for (int k = max; k >= 1; k--) {
		for (int m = k - 1; m >= 0; m--) {
			if (m_score[k] > m_score[m]) {
				int w = m_score[k];
				m_score[k] = m_score[m];
				m_score[m] = w;
			}
		}
	}
}
void Ranking::Bones() {
	std::fstream file("Score/Bones.txt", std::ios::in);
	//データの読み取り
	int i = 0;
	for (i = 0; i < 10000; i++) {
		file >> data[i];
		m_score[i] = atoi(data[i].c_str());
		file.seekp(+2, std::ios::cur);
		if (file.eof()) {
			i--;
			break;
		}
	}
	max = i;
	//大きい順に並べ替え
	for (int k = max; k >= 1; k--) {
		for (int m = k - 1; m >= 0; m--) {
			if (m_score[k] > m_score[m]) {
				int w = m_score[k];
				m_score[k] = m_score[m];
				m_score[m] = w;
			}
		}
	}
}
void Ranking::Update() {
	switch (ShareNum::GameNum) {
	case eState_LeanOn:
		LeanOn();
		break;
	case eState_Baby:
		Baby();
		break;
	case eState_Bones:
		Bones();
		break;
	}
}