#include "menuScene.h"
#include "stdafx.h"

WGameFramework framework;

menuScene::~menuScene()
{

}

void menuScene::init()
{
	//�޴� ȭ�鿡�� �׸� ���ҽ� ��ġ �ʱ�ȭ
	background.Load(TEXT("����ȭ��.png"));
}
void menuScene::processKey(UINT iMessage, WPARAM wParam, LPARAM lParam) 
{
	switch (iMessage)
	{
	case WM_KEYDOWN:
	{
		switch (wParam) {
		case VK_S:
			scene* scene = framework.curScene;	////���� ���� tmp�� �ְ� ������
			framework.curScene = new gameScene;
			framework.curScene->init();
			delete scene;
			break;
		}
	}
	break;

	}
}

void menuScene::Render(HDC hdc) 
{
	background.Draw(hdc, 0, 0, FRAME_WIDTH, FRAME_HEIGHT, 0, 0, background.GetWidth(), background.GetHeight());
	//--- �޸� DC�� ��� �׸���
}
void menuScene::Update()
{
	//�ִϸ��̼� ������ ���⼭ ������Ʈ
}