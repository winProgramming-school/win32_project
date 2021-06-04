#include "stdafx.h"
#include "gameScene.h"
//memdc�� �׷��ִ� ����, frame
extern WGameFramework framework;

gameScene::~gameScene()
{

}

void gameScene::drawPlayer(HDC hdc) {
    //�÷��̾� �׸��� �Լ�(��� ������ ������ ����ؼ�..)
    player_image.Draw(hdc, player.px, player.py, CLOUD_WIDTH / 2, CLOUD_HEIGHT, animation[ani_index].left, animation[ani_index].top,
        PLAYER_IMAGE_SIZE, PLAYER_IMAGE_SIZE);
}

void gameScene::drawBackGround(HDC hdc) {
    //��� �׸��� �Լ�

}

void gameScene::init()
{
    ani_index = 0;      //�浹�̸� 10~13, ���ø� 0~9

    for (int i = 0; i < 14; ++i) {
        animation[i] = { i * PLAYER_IMAGE_SIZE, 0, (i + 1) * PLAYER_IMAGE_SIZE, PLAYER_IMAGE_SIZE };
    }

    player_image.Load(TEXT("image/��.jpg"));
    background.Load(TEXT("image/���ȭ��1.png"));
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
