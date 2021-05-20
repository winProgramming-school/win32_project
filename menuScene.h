#pragma once
#include "scene.h"

class menuScene : public scene {

public:
	virtual ~menuScene() override;

	virtual void init() override;

	virtual void processKey(UINT iMessage, WPARAM wParam, LPARAM lParam) override;

	virtual void Update() override;

	virtual void Render(HDC hdc) override;
};