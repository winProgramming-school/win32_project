#include "stdafx.h"
#include "gameScene.h"
//memdc에 그려주는 역할, frame
extern WGameFramework framework;

gameScene::~gameScene()
{

}

void gameScene::drawPlayer(HDC hdc) {
    //플레이어 그리는 함수(없어도 되지만 정리가 깔끔해서..)
    player_image.Draw(hdc, player.px, player.py, CLOUD_WIDTH / 2, CLOUD_HEIGHT, animation[ani_index].left, animation[ani_index].top,
        PLAYER_IMAGE_SIZE, PLAYER_IMAGE_SIZE);
}

void gameScene::drawBackGround(HDC hdc) {
    //배경 그리는 함수

}

void gameScene::init()
{
    ani_index = 0;      //충돌이면 10~13, 평상시면 0~9

    for (int i = 0; i < 14; ++i) {
        animation[i] = { i * PLAYER_IMAGE_SIZE, 0, (i + 1) * PLAYER_IMAGE_SIZE, PLAYER_IMAGE_SIZE };
    }

    player_image.Load(TEXT("image/벌.jpg"));
    background.Load(TEXT("image/배경화면1.png"));
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
void gameScene::Update(const float frameTime)
{
    ani_index++;
    if (ani_index == 10)
        ani_index = 0;
}

void gameScene::Render(HDC hdc)
{
    drawPlayer(hdc);
}


//void gameScene::Release() {
//
//
//}
