#pragma once
#include "stdafx.h"
#include "overScene.h"

extern WGameFramework framework;

overScene::~overScene()
{

}

void overScene::init()
{
    //메뉴 화면에서 그릴 리소스 위치 초기화
    background1.Load(TEXT("image/오버배경.png"));
    txt.Load(TEXT("image/gameover.png"));
    PlaySound(TEXT("sound/level1-step1.wav"), NULL, SND_ASYNC | SND_LOOP);
    ren1 = 0;
    y = 0;
}
void overScene::processKey(UINT iMessage, WPARAM wParam, LPARAM lParam)
{
    switch (iMessage)
    {
    case WM_KEYDOWN:
    {
        switch (wParam) {
        case VK_RETURN:
            PlaySound(NULL, NULL, NULL);
            scene* scene = framework.curScene;   ////현재 씬을 tmp에 넣고 지워줌
            framework.curScene = new gameScene;
            framework.curScene->init();
            framework.nowscene = GAME;
            delete scene;
            break;
        }
    }
    break;

    }
}

void overScene::Update(const float frameTime)
{
    ren1++;
    if (ren1 >= 10)
        ren1 = 0;

    if (y > -400)
        y -= 20;

    //애니메이션 있으면 여기서 업데이트
}

void overScene::Render(HDC hdc)
{
    background1.Draw(hdc, 0, 0, FRAME_WIDTH, FRAME_HEIGHT, 0, 0, background1.GetWidth(), background1.GetHeight());
    txt.Draw(hdc, 0, y, FRAME_WIDTH, FRAME_HEIGHT, 0, 0, txt.GetWidth(), txt.GetHeight());
   
    //--- 메모리 DC에 배경 그리기
}