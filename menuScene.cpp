#include "menuScene.h"
#include "stdafx.h"

WGameFramework framework;

menuScene::~menuScene()
{
}

void menuScene::init()
{
	//�޴� ȭ�鿡�� �׸� ���ҽ� ��ġ �ʱ�ȭ
}
void menuScene::processKey(UINT iMessage, WPARAM wParam, LPARAM lParam) 
{
	switch (iMessage)
	{
	case WM_KEYDOWN:
	{
		switch (wParam) {
		case VK_S:
			//scene* scene = framework.curScene;	////���� ���� tmp�� �ְ� ������
			//S ������ start => ����ȭ������
			//framework.curScene = new gameScene;
			//framework.curScene->init();
			//delete scene;
			break;
		}
	}
	break;

	}
}

void menuScene::Render(HDC hdc) 
{
	//�޴����� �׷��� ���ҽ��� �׸���
}
void menuScene::Update()
{
	//�ִϸ��̼� ������ ���⼭ ������Ʈ
}