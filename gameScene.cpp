#include "stdafx.h"
#include "gameScene.h"
//memdc에 그려주는 역할, frame
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

//애니메이션 있으면 여기서 업데이트
void gameScene::Update()
{
    
}
//메뉴에서 그려줄 리소스들 그리기
void gameScene::Render(HDC hdc)
{
    //PatBlt(hdc, 0, 0, FRAME_WIDTH, FRAME_HEIGHT, BLACKNESS);
}

//void menuScene::Release() {
//
//
//}
