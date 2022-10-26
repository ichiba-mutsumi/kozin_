#include "Score.h"
#include "ShareNum.h"
Score::Score() :Base(eType_Score) {
	score = ShareNum::score;
	ImageSet();
}
void Score::Draw() {
	int i = 0;
	Temp = score;

	while (i < 5) {
		int k;
		k = Temp % 10;
		Temp = Temp / 10;
		m_img[k].SetPos(1020 - i * 40, 40);
		m_img[k].Draw();
		i++;
	}
}
void Score::ImageSet() {
	/*for (int i = 0; i < 10; i++) {
		m_img[i] = COPY_RESOURCE("Number", CImage);
	}
	m_img[0].SetRect(0, 16, 13, 32);
	m_img[1].SetRect(18, 16, 30, 32);
	m_img[2].SetRect(34, 16, 46, 32);
	m_img[3].SetRect(50, 16, 63, 32);
	m_img[4].SetRect(65, 16, 78, 32);
	m_img[5].SetRect(81, 16, 93, 32);
	m_img[6].SetRect(97, 16, 110, 32);
	m_img[7].SetRect(114, 16, 126, 32);
	m_img[8].SetRect(129, 16, 142, 32);
	m_img[9].SetRect(145, 16, 158, 32);
	for (int i = 0; i < 10; i++) {
		m_img[i].SetSize(40, 40);
	}*/
	for (int i = 0; i < 10; i++) {
		m_img[i] = COPY_RESOURCE("BNumber", CImage);
		m_img[i].SetRect(i * 39, 0, (i + 1) * 39, 77);
		m_img[i].SetSize(40, 77);
	}
}
void Score::Update() {
	score = ShareNum::score;
}