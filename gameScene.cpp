#include "stdafx.h"
#include "gameScene.h"
//memdc�� �׷��ִ� ����, frame
extern WGameFramework framework;

gameScene::~gameScene()
{

}

void gameScene::init()
{

}
void gameScene::processKey(UINT iMessage, WPARAM wParam, LPARAM lParam)
{
    switch (iMessage)
    {
    case WM_KEYDOWN:
    {
        switch (wParam) {
        case VK_RETURN: 
            break;
        }
    }
    break;
    }
}

//�ִϸ��̼� ������ ���⼭ ������Ʈ
void gameScene::Update()
{
    
}
//�޴����� �׷��� ���ҽ��� �׸���
void gameScene::Render(HDC hdc)
{
    //PatBlt(hdc, 0, 0, FRAME_WIDTH, FRAME_HEIGHT, BLACKNESS);
}

//void menuScene::Release() {
//
//
//}
