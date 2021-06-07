#include "stdafx.h"
#include "gameScene.h"
//memdc에 그려주는 역할, frame
extern WGameFramework framework;

gameScene::~gameScene()
{

}
void gameScene::InitCloud() {       //txt파일에서 구름 정보 받아오는 함수
    FILE* fp;
    fopen_s(&fp, "image/map1.txt", "r");

    int i = 0;
    if (fp == NULL)//열기 실패일 때
    {
        perror("fopen 실패");//에러 메시지 출력
        return;
    }

    while (!feof(fp)) {
        fscanf_s(fp, "%d %d %d", &cloud[i].cx, &cloud[i].cy, &cloud[i++].what);
    }

    cloud_index = i;
    fclose(fp);
}
void gameScene::InitAnimation() {
    int j = 0;
    for (int i = 0; i < 14; i++) {
        animation[j] = { i * PLAYER_IMAGE_SIZE, 0, (i + 1) * PLAYER_IMAGE_SIZE, PLAYER_IMAGE_SIZE };
        animation[j + 1] = { i * PLAYER_IMAGE_SIZE, 0, (i + 1) * PLAYER_IMAGE_SIZE, PLAYER_IMAGE_SIZE };
        j += 2;
    }
    j = 0;
    for (int i = 0; i < 10; i++) {
        cloud_ani[j] = { i * CLOUD_IMAGE_SIZE, 0, (i + 1) * CLOUD_IMAGE_SIZE, CLOUD_IMAGE_SIZE };
        cloud_ani[j + 1] = { i * CLOUD_IMAGE_SIZE, 0, (i + 1) * CLOUD_IMAGE_SIZE, CLOUD_IMAGE_SIZE };
        cloud_ani[j + 2] = { i * CLOUD_IMAGE_SIZE, 0, (i + 1) * CLOUD_IMAGE_SIZE, CLOUD_IMAGE_SIZE };
        cloud_ani[j + 3] = { i * CLOUD_IMAGE_SIZE, 0, (i + 1) * CLOUD_IMAGE_SIZE, CLOUD_IMAGE_SIZE };
        cloud_ani[j + 4] = { i * CLOUD_IMAGE_SIZE, 0, (i + 1) * CLOUD_IMAGE_SIZE, CLOUD_IMAGE_SIZE };
        j += 5;
    }

}
void gameScene::init()
{
    startX = 0, startY = MEM_HEIGHT - FRAME_HEIGHT;

    player_image.Load(TEXT("image/꼬물이.png"));
    background.Load(TEXT("image/배경화면1.png"));
    normalCloud.Load(TEXT("image/일반구름.png"));
    rainCloud.Load(TEXT("image/비구름.png"));
    darkCloud.Load(TEXT("image/먹구름.png"));

    InitAnimation();
    InitCloud();
    ani_index = 0;      //충돌이면 20~27, 평상시면 0~19
    cloud_aniindex = 0;

    player = { MEM_WIDTH/2, MEM_HEIGHT- CLOUD_HEIGHT-50, 1 };
}

void gameScene::drawPlayer(HDC hdc) {
    //플레이어 그리는 함수
    player_image.Draw(hdc, player.px, player.py, PLAYER_WIDTH, PLAYER_HEIGHT, animation[ani_index].left, animation[ani_index].top,
        PLAYER_IMAGE_SIZE, PLAYER_IMAGE_SIZE);
}

void gameScene::drawBackGround(HDC hdc) {
    //배경 그리는 함수
    background.BitBlt(hdc, 0, 0, SRCCOPY);
}

void gameScene::drawCloud(HDC hdc) {
    //구름 그리는 함수
    for (int j = 0; j < cloud_index; ++j) {
        switch (cloud[j].what) {
        case 1:
            darkCloud.Draw(hdc, cloud[j].cx, cloud[j].cy, CLOUD_WIDTH, CLOUD_HEIGHT, cloud_ani[cloud_aniindex].left, cloud_ani[cloud_aniindex].top, CLOUD_IMAGE_SIZE, CLOUD_IMAGE_SIZE);
            break;
        case 2:
            rainCloud.Draw(hdc, cloud[j].cx, cloud[j].cy, CLOUD_WIDTH, CLOUD_HEIGHT, cloud_ani[cloud_aniindex].left, cloud_ani[cloud_aniindex].top, CLOUD_IMAGE_SIZE, CLOUD_IMAGE_SIZE);
            break;
        case 3:
            normalCloud.Draw(hdc, cloud[j].cx, cloud[j].cy, CLOUD_WIDTH, CLOUD_HEIGHT, cloud_ani[cloud_aniindex].left, cloud_ani[cloud_aniindex].top, CLOUD_IMAGE_SIZE, CLOUD_IMAGE_SIZE);
            break;
        }
    }
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
    cloud_aniindex++;
    if (ani_index == 20)
        ani_index = 0;

    if (cloud_aniindex == 50)
        cloud_aniindex = 0;
}

void gameScene::Render(HDC hdc)
{
    drawBackGround(hdc);
    drawPlayer(hdc);
    drawCloud(hdc);
}


//void gameScene::Release() {
//
//
//}
