#pragma once
#include "stdafx.h"
#include "overScene.h"

extern WGameFramework framework;

overScene::~overScene()
{

}

void overScene::init()
{
    //�޴� ȭ�鿡�� �׸� ���ҽ� ��ġ �ʱ�ȭ
    background1.Load(TEXT("image/�������.png"));
    txt.Load(TEXT("image/gameover.png"));
    PlaySound(TEXT("sound/over.wav"), NULL, SND_ASYNC);
    ren1 = 30;
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
            scene* scene = framework.curScene;   //���� ���� tmp�� �ְ� ������
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

    if (y < 250)
        y += 15;

    //�ִϸ��̼� ������ ���⼭ ������Ʈ
}

void overScene::Render(HDC hdc)
{
    background1.Draw(hdc, 0, 0, FRAME_WIDTH, FRAME_HEIGHT, 0, 0, background1.GetWidth(), background1.GetHeight());
    txt.Draw(hdc, ren1, ren1+y, FRAME_WIDTH-2*ren1, FRAME_HEIGHT-2*ren1, 0, 0, txt.GetWidth(), txt.GetHeight());
   
    //--- �޸� DC�� ��� �׸���
}