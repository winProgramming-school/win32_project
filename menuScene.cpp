#include "menuScene.h"
#include "stdafx.h"

WGameFramework framework;

menuScene::~menuScene()
{
}

void menuScene::init()
{
	//메뉴 화면에서 그릴 리소스 위치 초기화
}
void menuScene::processKey(UINT iMessage, WPARAM wParam, LPARAM lParam) 
{
	switch (iMessage)
	{
	case WM_KEYDOWN:
	{
		switch (wParam) {
		case VK_S:
			//scene* scene = framework.curScene;	////현재 씬을 tmp에 넣고 지워줌
			//S 누르면 start => 게임화면으로
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
	//메뉴에서 그려줄 리소스들 그리기
}
void menuScene::Update()
{
	//애니메이션 있으면 여기서 업데이트
}