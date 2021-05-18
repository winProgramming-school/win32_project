#pragma once

class WGameFramework
{
public:
	WGameFramework();
	~WGameFramework();

	virtual void Reset();
	virtual void Clear();

	virtual void Create(HWND hWnd);
	virtual void OnDraw(HDC hdc);
	virtual void OnUpdate(const float frameTime = 0.17f);
	virtual void KeyBoard(UINT iMessage, WPARAM wParam, LPARAM lParam);

private:
	HWND	m_hWnd;
};