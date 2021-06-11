#include "stdafx.h"
#include "GameFramework.h"


WGameFramework::WGameFramework()
{
	
}

WGameFramework::~WGameFramework()
{

}

void WGameFramework::Reset()
{

}

void WGameFramework::Clear()
{	
	//���α׷� ���� �� ���� ���� delete ���ֱ�

	scene* scene = curScene;
	delete scene;
}

void WGameFramework::Create(HWND hWnd)
{
	m_hWnd = hWnd;
	curScene = new menuScene;	//ó������ ���� ���� ȭ������
	nowscene = MENU;
	curScene->init();
}

void WGameFramework::OnDraw(HDC hdc)
{
	curScene->Render(hdc);
}

void WGameFramework::OnUpdate(const float frameTime)
{
	curScene->Update(frameTime);
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
	return (float)(curFrameTime - prevFrameTime) / 1000;
}