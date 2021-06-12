#include "clearScene.h"
#include "stdafx.h"

extern WGameFramework framework;

clearScene::~clearScene()
{

}

void clearScene::init()
{

}
void clearScene::processKey(UINT iMessage, WPARAM wParam, LPARAM lParam)
{
    switch (iMessage)
    {
    case WM_KEYDOWN:
    {
        switch (wParam) {

        }
    }
    break;

    }
}

void clearScene::Update(const float frameTime)
{

}

void clearScene::Render(HDC hdc)
{

}