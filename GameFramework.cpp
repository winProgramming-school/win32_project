
#include "stdafx.h"
#include "GameFramework.h"


WGameFramework::WGameFramework()
{
	Clear();
}

WGameFramework::~WGameFramework()
{
}

void WGameFramework::Reset()
{

}

void WGameFramework::Clear()
{

}

void WGameFramework::Create(HWND hWnd)
{
	m_hWnd = hWnd;
	curScene = new menuScene;	//처음에는 게임 시작 화면으로
}

void WGameFramework::OnDraw(HDC hdc)
{
	static int x = 10;
	x++;
	Rectangle(hdc, x + 10, 10, x + 100, 100);
	//여기서 현재 씬 그려주기
	//curScene->Render(hdc);
}

void WGameFramework::OnUpdate(const float frameTime)
{
	//curScene->Update();
	//여기서 현재 씬 업데이트
}

void WGameFramework::KeyBoard(UINT iMessage, WPARAM wParam, LPARAM lParam)
{

	switch (iMessage)
	{
	case WM_KEYDOWN:
	{
		if (wParam == VK_Q) {
			SendMessage(m_hWnd, WM_DESTROY, 0, 0);	//Q 누르면 종료
			return;
		}
	}
	}
	curScene->processKey(iMessage, wParam, lParam);	//현재 씬의 프로세스키
}