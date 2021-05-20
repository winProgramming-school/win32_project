#pragma once
#include <Windows.h>

enum GAME_STATUS{RUN, PAUSE, GAMEOVER};

class scene {
public:
	virtual ~scene();
	
	virtual void init() = 0;

	virtual void processKey(UINT iMessage, WPARAM wParam, LPARAM lParam) = 0;
	
	virtual void Update() = 0;

	virtual void Render(HDC hdc) = 0;
};