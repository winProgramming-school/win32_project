#include "menuScene.h"
#include "stdafx.h"

WGameFramework framework;

menuScene::~menuScene()
{

}

void menuScene::init()
{
	//메뉴 화면에서 그릴 리소스 위치 초기화
	background.Load(TEXT("시작화면.png"));
}
void menuScene::processKey(UINT iMessage, WPARAM wParam, LPARAM lParam) 
{
	switch (iMessage)
	{
	case WM_KEYDOWN:
	{
		switch (wParam) {
		case VK_S:
			scene* scene = framework.curScene;	////현재 씬을 tmp에 넣고 지워줌
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
	//--- 메모리 DC에 배경 그리기
}
void menuScene::Update()
{
	//애니메이션 있으면 여기서 업데이트
}