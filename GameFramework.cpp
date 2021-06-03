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
	curScene = new menuScene;	//ó������ ���� ���� ȭ������
	curScene->init();
}

void WGameFramework::OnDraw(HDC hdc)
{
	curScene->Render(hdc);
	//static int x = 10;
	//x++;
	//Rectangle(hdc, x + 10, 10, x + 100, 100);
}

void WGameFramework::OnUpdate(const float frameTime)
{
	//curScene->Update();
	//���⼭ ���� �� ������Ʈ
}

void WGameFramework::KeyBoard(UINT iMessage, WPARAM wParam, LPARAM lParam)
{

	switch (iMessage)
	{
	case WM_KEYDOWN:
	{
		if (wParam == VK_Q) {
			SendMessage(m_hWnd, WM_DESTROY, 0, 0);	//Q ������ ����
			return;
		}
	}
	}
	curScene->processKey(iMessage, wParam, lParam);	//���� ���� ���μ���Ű
}

float WGameFramework::GetTick()
{
	return duration_cast<milliseconds>(curFrameTime - prevFrameTime).count();
}