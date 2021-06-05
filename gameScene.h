#pragma once
#include "scene.h"

typedef struct Player {
	int px, py;
	int status = 1;		//상태 0: 충돌 1: 평상시
}Player;
typedef struct Cloud {
	int cx, cy;
	int what;			//1: 먹구름 2: 비구름 3: 일반구름
}Cloud;

class gameScene : public scene {
public:
	RECT animation[28];	//평상시 애니메이션(리소스 위치)
	RECT cloud_ani[50];

	int ani_index;		//애니메이션 index(플레이어)
	int cloud_aniindex;	//애니메이션 index(구름)
	int cloud_index;	//구름 개수

	CImage player_image, background;
	CImage normalCloud, rainCloud, darkCloud;

	Player player;
	Cloud cloud[200];

public:
	virtual ~gameScene() override;

	virtual void init() override;

	virtual void processKey(UINT iMessage, WPARAM wParam, LPARAM lParam) override;

	virtual void Update(const float frameTime) override;

	virtual void Render(HDC hdc) override;

	void drawPlayer(HDC hdc);
	void drawBackGround(HDC hdc);
	void drawCloud(HDC hdc);

	void InitCloud();
	void InitAnimation();
};