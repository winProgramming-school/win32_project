#pragma once
#include "scene.h"

typedef struct Player {
	int px, py;
	int status = 1;		//���� 0: �浹 1: ����
	int jump;
}Player;
typedef struct Cloud {
	int cx, cy;
	int what;			//1: �Ա��� 2: �񱸸� 3: �Ϲݱ���
	int index;
}Cloud;

class gameScene : public scene {
public:
	RECT animation[28];	//���� �ִϸ��̼�(���ҽ� ��ġ)
	RECT cloud_ani[50];

	int ani_index;		//�ִϸ��̼� index(�÷��̾�)
	int cloud_index;	//���� ����

	float gravity;
	bool fall;			//�������� ����
	RECT cRECT;			//���� �簢��
	RECT pRECT;			//�÷��̾� �簢��
	RECT tmp;			//�浹 �˻��� �簢��

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