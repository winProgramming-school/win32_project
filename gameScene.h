#pragma once
#include "scene.h"

typedef struct Player {
	int px, py;
	int status = 1;		//상태 0: 충돌 1: 평상시
}Player;

class gameScene : public scene {
public:
	RECT animation[14];	//평상시 애니메이션(리소스 위치)
	int ani_index;
	CImage player_image, background;
	Player player;

public:
	virtual ~gameScene() override;

	virtual void init() override;

	virtual void processKey(UINT iMessage, WPARAM wParam, LPARAM lParam) override;

	virtual void Update(const float frameTime) override;

	virtual void Render(HDC hdc) override;

	void drawPlayer(HDC hdc);
	void drawBackGround(HDC hdc);
	
};