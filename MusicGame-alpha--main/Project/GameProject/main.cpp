#include <GLLibrary.h>
#include "Base/Base.h"
#include "Game/Play.h"
#include "Game/Ranking.h"
#include "Game/ScoreScene.h"
#include "Game/SelectScene/SelectScene.h"
#include"Title/Title.h"
#define SCREEN_WIDTH 1579
#define SCREEN_HEIGHT 1118



//--------------------------------------------
//�O���[�o���ϐ��̈�
//-------------------------------------------



void MainLoop(void) {
	Base::CheckKillAll();
	Base::UpdateAll();
	Base::DrawAll();
}

void Init(void)
{
	glClearColor(1.0, 1.0, 1.0, 1.0);

	glEnable(GL_DEPTH_TEST);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_BLEND);//�u�����h�̗L����
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);

	//�Œ�V�F�[�_�[�p
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	glEnable(GL_ALPHA_TEST);

	CFPS::SetFPS(60);
	//�t���[�����䏉����
	CFPS::Init();
	//�{�^���̐ݒ�
	CInput::Init();
	CInput::SetButton(0, CInput::eButton1, 'Q');
	CInput::SetButton(0, CInput::eButton2, 'W');
	CInput::SetButton(0, CInput::eButton3, 'E');
	CInput::SetButton(0, CInput::eButton4, 'A');
	CInput::SetButton(0, CInput::eButton5, 'S');
	CInput::SetButton(0, CInput::eButton6, 'D');
	CInput::SetButton(0, CInput::eButton7, 'Z');
	CInput::SetButton(0, CInput::eButton8, 'X');
	CInput::SetButton(0, CInput::eButton9, VK_SPACE);
	CInput::SetButton(0, CInput::eButton10, VK_RETURN);
	CInput::SetButton(0, CInput::eUp, VK_UP);
	CInput::SetButton(0, CInput::eDown, VK_DOWN);
	CInput::SetButton(0, CInput::eLeft, VK_LEFT);
	CInput::SetButton(0, CInput::eRight, VK_RIGHT);
	CInput::SetButton(0, CInput::eMouseL, VK_LBUTTON);
	CInput::SetButton(0, CInput::eMouseR, VK_RBUTTON);
	CInput::SetButton(0, CInput::eMouseC, VK_MBUTTON);

	//�}�E�X��\��
	//CInput::ShowCursor(false);
	//CInput::SetMouseInside(true);
	CInput::Update();
	CInput::Update();


	//���C�g�ݒ�
	CLight::SetType(0, CLight::eLight_Direction);
	CLight::SetPos(0, CVector3D(0, 200, 200));
	CLight::SetDir(0, CVector3D(-1, -2, 1).GetNormalize());
	CLight::SetColor(0, CVector3D(0.2f, 0.2f, 0.2f), CVector3D(0.8f, 0.8f, 0.8f));


	CLight::SetFogParam(CVector4D(1, 1, 1, 1), 1200, 1400);

	//�J����������
	CCamera::GetCamera()->LookAt(CVector3D(5, 5, 5),
		CVector3D(0, 0, 0),
		CVector3D(0.0, 1.0, 0.0));

	SetCurrentDirectory("data");


	CShader::GetInstance("StaticMesh");
	CShader::GetInstance("SkinMesh");
	CSound::GetInstance();

	//-----------------------------------------------------
	//�������̖��߂�����
	//�Q�[���N�����Ɉ�x�����Ă΂��
	//-----------------------------------------------------

	//Base::Add(new Title());
	/*
	ADD_RESOURCE("Lane", CImage::CreateImage("Image/Lane.png"));
	ADD_RESOURCE("Notes",CImage::CreateImage("Image/Notes.png"));
	ADD_RESOURCE("NotesBar", CImage::CreateImage("Image/NotesBar.png"));

	SOUND("LeanOn")->Load("Sound/LeanOn.wav");
	SOUND("Baby")->Load("Sound/Baby.wav");
	*/
	SOUND("Bones")->Load("Sound/Bones.wav");


	ADD_RESOURCE("Note", CImage::CreateImage("Image/note.png"));
	ADD_RESOURCE("Note2", CImage::CreateImage("Image/criticalnote.png"));
	ADD_RESOURCE("Note3", CImage::CreateImage("Image/doublenote.png"));
	ADD_RESOURCE("Note4", CImage::CreateImage("Image/note_long.png"));
	ADD_RESOURCE("Note5", CImage::CreateImage("Image/slide.png"));
	ADD_RESOURCE("Note6", CImage::CreateImage("Image/slide2.png"));
	ADD_RESOURCE("Number", CImage::CreateImage("Image/Number.png"));
	ADD_RESOURCE("number", CImage::CreateImage("Image/scorenumber.png"));
	ADD_RESOURCE("SoundBar", CImage::CreateImage("Image/SoundBar.png"));
	ADD_RESOURCE("Title", CImage::CreateImage("Image/tile.png"));
	ADD_RESOURCE("gothic", CImage::CreateImage("Image/gothic.png"));
	ADD_RESOURCE("Fantastical", CImage::CreateImage("Image/fantastical.png"));
	ADD_RESOURCE("fullcombo", CImage::CreateImage("Image/FULLCOMBO.png"));
	ADD_RESOURCE("gamen", CImage::CreateImage("Image/gamen.png"));
	ADD_RESOURCE("TapA", CImage::CreateImage("Image/A.png"));
	ADD_RESOURCE("TapQ", CImage::CreateImage("Image/Q.png"));
	ADD_RESOURCE("TapW", CImage::CreateImage("Image/W.png"));
	ADD_RESOURCE("TapE", CImage::CreateImage("Image/E.png"));
	ADD_RESOURCE("TapS", CImage::CreateImage("Image/S.png"));
	ADD_RESOURCE("TapD", CImage::CreateImage("Image/D.png"));
	ADD_RESOURCE("TapZ", CImage::CreateImage("Image/Z.png"));
	ADD_RESOURCE("TapX", CImage::CreateImage("Image/X.png"));
	ADD_RESOURCE("select", CImage::CreateImage("Image/select.png"));
	SOUND("Gothic")->Load("Sound/PerituneMaterial_Gothic_Cute (online-audio-converter.com).wav");
	SOUND("Tir")->Load("Sound/PerituneMaterial_Tir_sonas (online-audio-converter.com).wav");
	SOUND("Tap")->Load("Sound/TapSound.wav", 10);
	Base::Add(new Title());

}
void Release()
{
	CLoadThread::ClearInstance();
	CSound::ClearInstance();
	CResourceManager::ClearInstance();
}

static void ResizeCallback(GLFWwindow* window, int w, int h)
{
	glViewport(0, 0, w, h);

	//��ʉ𑜓x�ϓ�
	CCamera::GetCamera()->SetSize((float)w, (float)h);
	//��ʉ𑜓x�Œ�
	//CCamera::GetCamera()->SetSize(SCREEN_WIDTH, SCREEN_HEIGHT);

	CCamera::GetCamera()->Viewport(0, 0, w, h);
	CCamera::GetCurrent()->Perspective(DtoR(60.0), (float)w / (float)h, 1.0, 10000.0);

	glfwGetWindowPos(window, &GL::window_x, &GL::window_y);
	GL::UpdateWindowRect(GL::window_x, GL::window_y, w, h);
	CInput::UpdateClipCursor(true);

}
static void WheelCallback(GLFWwindow* _window, double _offsetx, double _offsety) {
	CInput::AddMouseWheel((int)_offsety);

}
static void PosCallback(GLFWwindow* _window, int x, int y) {
	GL::window_x = x;
	GL::window_y = y;
	GL::UpdateWindosRect(x, y, GL::window_width, GL::window_height);
	CInput::UpdateClipCursor(true);

}
static void FocusCallback(GLFWwindow* _window, int f) {
	CInput::UpdateClipCursor(f);
	GL::focus = f;
}

static void error_callback(int error, const char* description)
{
	printf("Error: %s\n", description);
}

//�t���X�N���[��?�E�C���h�E���[�h�̐؂�ւ�
//Alt+Enter�Ő؂�ւ���
void CheckFullScreen() {
	static int key_enter = 0;
	int key_enter_buf = key_enter;
	if (key_enter_buf ^ (key_enter = glfwGetKey(GL::window, GLFW_KEY_ENTER)) && key_enter && (glfwGetKey(GL::window, GLFW_KEY_LEFT_ALT) || glfwGetKey(GL::window, GLFW_KEY_RIGHT_ALT))) {
		GL::ChangeFullScreen(!GL::full_screen);
	}
}

int __main(int* argcp, char** argv) {
	// ���������[�N���o
	//	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF | _CRTDBG_CHECK_ALWAYS_DF);
	//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);


	//OpenGL4.3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);


	glfwSetErrorCallback(error_callback);
	if (!glfwInit()) return -1;
	//	glutInit(argcp, argv);

	GL::window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Simple", nullptr, nullptr);
	glfwGetWindowSize(GL::window, &GL::window_width, &GL::window_height);
	glfwGetWindowPos(GL::window, &GL::window_x, &GL::window_y);

	glfwSetFramebufferSizeCallback(GL::window, ResizeCallback);
	glfwSetScrollCallback(GL::window, WheelCallback);
	glfwSetWindowFocusCallback(GL::window, FocusCallback);
	glfwSetWindowPosCallback(GL::window, PosCallback);
	if (!GL::window) {
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(GL::window);
	glfwSwapInterval(1);
	ResizeCallback(GL::window, SCREEN_WIDTH, SCREEN_HEIGHT);

	GLenum err = glewInit();
	if (err == GLEW_OK) {
		printf("%s\n", glewGetString(GLEW_VERSION));
	}
	else {
		printf("%s\n", glewGetErrorString(err));
		getchar();
		return -1;
	}
	HDC glDc = wglGetCurrentDC();
	GL::hWnd = WindowFromDC(glDc);

	Init();

	while (!glfwWindowShouldClose(GL::window)) {
		CheckFullScreen();


		CInput::Update();
		//�e�o�b�t�@�[���N���A
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		MainLoop();


		glfwSwapBuffers(GL::window);

		CFPS::Wait();

		char title[32];
		sprintf_s(title, "math fps:%d dt:%.3f", CFPS::GetFPS(), CFPS::GetDeltaTime());
		glfwSetWindowTitle(GL::window, title);

		glfwPollEvents();
		if (glfwGetKey(GL::window, GLFW_KEY_ESCAPE)) {
			glfwSetWindowShouldClose(GL::window, GL_TRUE);
		}

	}

	glfwTerminate();

	Release();
	return 0;
}

INT WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR argv, INT argc)
{
	return __main(&__argc, __argv);
}

int main(int argc, char** argv)
{
	return __main(&argc, argv);
}
