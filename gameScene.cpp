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
    random_device rd;
    uniform_int_distribution <int> dis(0, 49);

    int i = 0;
    if (fp == NULL)//열기 실패일 때
    {
        perror("fopen 실패");//에러 메시지 출력
        return;
    }

    while (!feof(fp)) {
        fscanf_s(fp, "%d %d %d", &cloud[i].cx, &cloud[i].cy, &cloud[i++].what);
        cloud[i].index = dis(rd);
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

    //0~4, 5~9, 10~14, 15~19, 20~24, 25~29, 30~34, 35~39, 40~44, 45~49 까지 같은 이미지라 보면 됨
    //20~24, 25~29, 30~34, 35~39 이때 비나 번개치는 애니메이션
    //업데이트 속도가 너무 빨라서 느리게 움직이게 하기 위함

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
    startX = 0, startY = MEM_HEIGHT - (FRAME_HEIGHT);

    player_image.Load(TEXT("image/꼬물이.png"));
    background.Load(TEXT("image/배경화면1.png"));
    normalCloud.Load(TEXT("image/일반구름.png"));
    rainCloud.Load(TEXT("image/비구름.png"));
    darkCloud.Load(TEXT("image/먹구름.png"));

    InitAnimation();
    InitCloud();
    ani_index = 0;      //충돌이면 20~27, 평상시면 0~19
    gravity = 1;

    fall = true;

    player = { MEM_WIDTH/2, PLAYER_FIRSTY, 1, 0 };      //플레이어 시작위치
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
            darkCloud.Draw(hdc, cloud[j].cx, cloud[j].cy, CLOUD_WIDTH, CLOUD_HEIGHT, cloud_ani[cloud[j].index].left, cloud_ani[cloud[j].index].top, CLOUD_IMAGE_SIZE, CLOUD_IMAGE_SIZE);
            break;
        case 2:
            rainCloud.Draw(hdc, cloud[j].cx, cloud[j].cy, CLOUD_WIDTH, CLOUD_HEIGHT, cloud_ani[cloud[j].index].left, cloud_ani[cloud[j].index].top, CLOUD_IMAGE_SIZE, CLOUD_IMAGE_SIZE);
            break;
        case 3:
            normalCloud.Draw(hdc, cloud[j].cx, cloud[j].cy, CLOUD_WIDTH, CLOUD_HEIGHT, cloud_ani[cloud[j].index].left, cloud_ani[cloud[j].index].top, CLOUD_IMAGE_SIZE, CLOUD_IMAGE_SIZE);
            break;
        }
    }
}

void gameScene::drawBox(HDC hdc) {
    Rectangle(hdc, pRECT.left, pRECT.top, pRECT.right, pRECT.bottom);
    for (int i = 0; i < cloud_index; ++i) {
        Rectangle(hdc, cloud[i].cx +30, cloud[i].cy+30, cloud[i].cx + CLOUD_COLLIDE_WIDTH, cloud[i].cy + CLOUD_COLLIDE_HEIGHT);
    }
    
}
void gameScene::processKey(UINT iMessage, WPARAM wParam, LPARAM lParam)
{
    switch (iMessage)
    {
    case WM_KEYDOWN:
    {
        //if ((GetAsyncKeyState(VK_LEFT) & 0x8000) && (GetAsyncKeyState(VK_UP) & 0x8000)) {
        //    fall = false;
        //    if (player.py <= PLAYERMOVE_START || player.py >= PLAYERMOVE_STOP) {
        //        player.py -= 7;
        //        player.px -= 7;
        //    }
        //    else {
        //        startY -= 7;
        //        player.py -= 7;
        //        player.px -= 7;
        //    }
        //    break;
        //}
        //if ((GetAsyncKeyState(VK_RIGHT) & 0x8000) && (GetAsyncKeyState(VK_UP) & 0x8000)) {
        //    fall = false;
        //    if (player.py <= PLAYERMOVE_START || player.py >= PLAYERMOVE_STOP) {
        //        player.py -= 7;
        //        player.px += 7;
        //    }
        //    else {
        //        startY -= 7;
        //        player.py -= 7;
        //        player.px += 7;
        //    }
        //    break;
        //}
        //if ((GetAsyncKeyState(VK_UP) & 0x8001)) {
        //    fall = false;
        //    if (player.py <= PLAYERMOVE_START || player.py >= PLAYERMOVE_STOP) {
        //        player.py -= 7;
        //    }
        //    else {
        //        startY -= 7;
        //        player.py -= 7;
        //    }
        //}
        //else if ((GetAsyncKeyState(VK_RIGHT) & 0x8000) || (GetAsyncKeyState(VK_RIGHT) & 0x8001))
        //    player.px += 5;
        //else if ((GetAsyncKeyState(VK_LEFT) & 0x8000) || (GetAsyncKeyState(VK_LEFT) & 0x8001))
        //    player.px -= 5;

    }
    break;
    case WM_KEYUP: 
    {
        if (wParam == VK_UP) {
            fall = true;
            gravity = 2;
        }
        else if (wParam == VK_RIGHT || wParam == VK_LEFT) {
            fall = true;
            gravity = 1;
        }
    }
    break;
    }
}

//애니메이션 있으면 여기서 업데이트
void gameScene::Update(const float frameTime)
{

    if (player.status) {          //충돌이 아닐 때
        ani_index++;
        if (ani_index == 20)
            ani_index = 0;
    }
    else
        ani_index = 20;

    pRECT = { player.px+18,player.py + 10,player.px+18 + PLAYER_COLLIDE_WIDTH ,player.py + PLAYER_HEIGHT};

    player.status = 1;
    ani_index = 0;

    for (int i = 0; i < cloud_index; ++i) {
        cloud[i].index++;
        if (cloud[i].index == 50)
            cloud[i].index = 0;
        cRECT = { cloud[i].cx+30, cloud[i].cy+30, cloud[i].cx + CLOUD_COLLIDE_WIDTH, cloud[i].cy + CLOUD_COLLIDE_HEIGHT };
        if (IntersectRect(&tmp, &cRECT, &pRECT) && i > 6) {          //충돌 검사
            player.status = 0;
            ani_index = 20;
            break;
        }
    }

    if (!fall && player.py <= PLAYER_FIRSTY && (player.py <= PLAYERMOVE_START || player.py >= PLAYERMOVE_STOP))
        player.py += 10 * frameTime;
    else if (!fall && player.py >= PLAYERMOVE_START && player.py <= PLAYERMOVE_STOP){
        startY += 10 * frameTime;
        player.py += 10 * frameTime;
    }

    if (fall && gravity >= -30)
        gravity -= frameTime * 10;

    if (fall && player.py <= PLAYER_FIRSTY) {
        player.py -= gravity;
        if(startY <= MEM_HEIGHT - (FRAME_HEIGHT))
            startY -= gravity;
    }

    if ((GetAsyncKeyState(VK_LEFT) & 0x8000) && (GetAsyncKeyState(VK_UP) & 0x8001)) {
        fall = false;
        if (player.py <= PLAYERMOVE_START || player.py >= PLAYERMOVE_STOP) {
            player.py -= 7;
            player.px -= 7;
        }
        else {
            startY -= 7;
            player.py -= 7;
            player.px -= 7;
        }
        return;
    }
    if ((GetAsyncKeyState(VK_RIGHT) & 0x8000) && (GetAsyncKeyState(VK_UP) & 0x8001)) {
        fall = false;
        if (player.py <= PLAYERMOVE_START || player.py >= PLAYERMOVE_STOP) {
            player.py -= 7;
            player.px += 7;
        }
        else {
            startY -= 7;
            player.py -= 7;
            player.px += 7;
        }
        return;
    }
    if ((GetAsyncKeyState(VK_UP) & 0x8001)) {
        fall = false;
        if (player.py <= PLAYERMOVE_START || player.py >= PLAYERMOVE_STOP) {
            player.py -= 7;
        }
        else {
            startY -= 7;
            player.py -= 7;
        }
    }
    else if ((GetAsyncKeyState(VK_RIGHT) & 0x8000) || (GetAsyncKeyState(VK_RIGHT) & 0x8001))
        player.px += 5;
    else if ((GetAsyncKeyState(VK_LEFT) & 0x8000) || (GetAsyncKeyState(VK_LEFT) & 0x8001))
        player.px -= 5;


}

void gameScene::Render(HDC hdc)
{
    drawBackGround(hdc);
    //drawBox(hdc);
    drawPlayer(hdc);
    drawCloud(hdc);
}


//void gameScene::Release() {
//
//
//}
