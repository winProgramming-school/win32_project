#pragma once
#include "scene.h"

class gameScene : public scene {
public:
	RECT animation[10];
public:
	virtual ~gameScene() override;

	virtual void init() override;

	virtual void processKey(UINT iMessage, WPARAM wParam, LPARAM lParam) override;

	virtual void Update() override;

	virtual void Render(HDC hdc) override;

};