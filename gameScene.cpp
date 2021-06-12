#include "stdafx.h"
#include "gameScene.h"
//memdc�� �׷��ִ� ����, frame
extern WGameFramework framework;

gameScene::~gameScene()
{

}
void gameScene::InitCloud() {       //txt���Ͽ��� ���� ���� �޾ƿ��� �Լ�
    FILE* fp;
    fopen_s(&fp, "image/map1.txt", "r");
    random_device rd;
    uniform_int_distribution <int> dis(0, 49);

    int i = 0;
    if (fp == NULL)//���� ������ ��
    {
        perror("fopen ����");//���� �޽��� ���
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

    //0~4, 5~9, 10~14, 15~19, 20~24, 25~29, 30~34, 35~39, 40~44, 45~49 ���� ���� �̹����� ���� ��
    //20~24, 25~29, 30~34, 35~39 �̶� �� ����ġ�� �ִϸ��̼�
    //������Ʈ �ӵ��� �ʹ� ���� ������ �����̰� �ϱ� ����

    for (int i = 0; i < 10; i++) {
        cloud_ani[j] = { i * CLOUD_IMAGE_SIZE, 0, (i + 1) * CLOUD_IMAGE_SIZE, CLOUD_IMAGE_SIZE };
        cloud_ani[j + 1] = { i * CLOUD_IMAGE_SIZE, 0, (i + 1) * CLOUD_IMAGE_SIZE, CLOUD_IMAGE_SIZE };
        cloud_ani[j + 2] = { i * CLOUD_IMAGE_SIZE, 0, (i + 1) * CLOUD_IMAGE_SIZE, CLOUD_IMAGE_SIZE };
        cloud_ani[j + 3] = { i * CLOUD_IMAGE_SIZE, 0, (i + 1) * CLOUD_IMAGE_SIZE, CLOUD_IMAGE_SIZE };
        cloud_ani[j + 4] = { i * CLOUD_IMAGE_SIZE, 0, (i + 1) * CLOUD_IMAGE_SIZE, CLOUD_IMAGE_SIZE };
        j += 5;
    }
    j = 0;
    for (int i = 0; i < 10; i++) {
        raincloud_ani[j] = { i * CLOUD_IMAGE_SIZE, 0, (i + 1) * CLOUD_IMAGE_SIZE, RAINCLOUD_IMAGE };
        raincloud_ani[j + 1] = { i * CLOUD_IMAGE_SIZE, 0, (i + 1) * CLOUD_IMAGE_SIZE, RAINCLOUD_IMAGE };
        raincloud_ani[j + 2] = { i * CLOUD_IMAGE_SIZE, 0, (i + 1) * CLOUD_IMAGE_SIZE, RAINCLOUD_IMAGE };
        raincloud_ani[j + 3] = { i * CLOUD_IMAGE_SIZE, 0, (i + 1) * CLOUD_IMAGE_SIZE, RAINCLOUD_IMAGE };
        raincloud_ani[j + 4] = { i * CLOUD_IMAGE_SIZE, 0, (i + 1) * CLOUD_IMAGE_SIZE, RAINCLOUD_IMAGE };
        j += 5;
    }
}

void gameScene::init()
{
    startX = 0, startY = MEM_HEIGHT - (FRAME_HEIGHT);

    player_image.Load(TEXT("image/������.png"));
    background.Load(TEXT("image/���ȭ��1.png"));
    normalCloud.Load(TEXT("image/�Ϲݱ���.png"));
    rainCloud.Load(TEXT("image/�񱸸�.png"));
    darkCloud.Load(TEXT("image/�Ա���.png"));

    heart.Load(TEXT("image/heart.png"));
    stone.Load(TEXT("image/stone.png"));

    InitAnimation();
    InitCloud();
    ani_index = 0;      //�浹�̸� 20~27, ���ø� 0~19
    gravity = 1;
    bar_w = 498;
    bar_startY = PLAYER_FIRSTY + 100;
    fall = true;

    player = { MEM_WIDTH/2, PLAYER_FIRSTY, 1, 0 };      //�÷��̾� ������ġ
}

void gameScene::drawPlayer(HDC hdc) {
    //�÷��̾� �׸��� �Լ�
    player_image.Draw(hdc, player.px, player.py, PLAYER_WIDTH, PLAYER_HEIGHT, animation[ani_index].left, animation[ani_index].top,
        PLAYER_IMAGE_SIZE, PLAYER_IMAGE_SIZE);
}

void gameScene::drawBackGround(HDC hdc) {
    //��� �׸��� �Լ�
    background.BitBlt(hdc, 0, 0, SRCCOPY);
}

void gameScene::drawCloud(HDC hdc) {
    //���� �׸��� �Լ�
    for (int j = 0; j < cloud_index; ++j) {
        switch (cloud[j].what) {
        case 1:
            darkCloud.Draw(hdc, cloud[j].cx, cloud[j].cy, CLOUD_WIDTH, CLOUD_HEIGHT, cloud_ani[cloud[j].index].left, cloud_ani[cloud[j].index].top, CLOUD_IMAGE_SIZE, CLOUD_IMAGE_SIZE);
            break;
        case 2:
            rainCloud.Draw(hdc, cloud[j].cx, cloud[j].cy, CLOUD_WIDTH, CLOUD_HEIGHT, raincloud_ani[cloud[j].index].left, raincloud_ani[cloud[j].index].top, CLOUD_IMAGE_SIZE, RAINCLOUD_IMAGE);
            break;
        case 3:
            normalCloud.Draw(hdc, cloud[j].cx, cloud[j].cy, CLOUD_WIDTH, CLOUD_HEIGHT, cloud_ani[cloud[j].index].left, cloud_ani[cloud[j].index].top, CLOUD_IMAGE_SIZE, CLOUD_IMAGE_SIZE);
            break;
        }
    }
}

void gameScene::drawHPBar(HDC hdc) {
    HBRUSH myBrush = (HBRUSH)CreateSolidBrush(RGB(150, 50, 0));
    HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, myBrush);
    Rectangle(hdc, 50, bar_startY + 1, bar_w + 50, bar_startY + 29);
    SelectObject(hdc, oldBrush);
    DeleteObject(myBrush);

    myBrush = (HBRUSH)GetStockObject(NULL_BRUSH);
    oldBrush = (HBRUSH)SelectObject(hdc, myBrush);
    HPEN hPen = CreatePen(PS_DOT, 2, RGB(0, 0, 0));
    HPEN oldPen = (HPEN)SelectObject(hdc, hPen); 
    Rectangle(hdc, 50, bar_startY, HPBAR_WIDTH + 50, bar_startY + 30);
    SelectObject(hdc, oldBrush);
    DeleteObject(myBrush);
    SelectObject(hdc, oldPen);
    DeleteObject(hPen);
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

//�ִϸ��̼� ������ ���⼭ ������Ʈ
void gameScene::Update(const float frameTime)
{

    if (player.status) {          //�浹�� �ƴ� ��
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
        if (IntersectRect(&tmp, &cRECT, &pRECT) && i > 6) {          //�浹 �˻�
            player.status = 0;
            ani_index = 20;
            break;
        }
    }
    if (!player.status) {           //�÷��̾ �浹�����̸� ü�� ����
        bar_w -= 20 * frameTime;
    }

    //if (!fall && player.py <= PLAYER_FIRSTY && (player.py <= PLAYERMOVE_START || player.py >= PLAYERMOVE_STOP))
    //    player.py += 10 * frameTime;
    //else if (!fall && player.py >= PLAYERMOVE_START && player.py <= PLAYERMOVE_STOP){
    //    startY += 10 * frameTime;
    //    bar_startY += 10 * frameTime;
    //    player.py += 10 * frameTime;
    //}

    if (fall && gravity >= -30)
        gravity -= frameTime * 10;

    if (fall && player.py <= PLAYER_FIRSTY) {
        if(!player.status)
            player.py -= gravity/3;
        else
            player.py -= gravity;
        if (startY <= MEM_HEIGHT - (FRAME_HEIGHT) && player.py >= PLAYERMOVE_START) {
            if (!player.status) {
                startY -= gravity/3;
                bar_startY -= gravity/3;
            }
            else {
                startY -= gravity;
                bar_startY -= gravity;
            }
        }
    }

    if ((GetAsyncKeyState(VK_LEFT) & 0x8000) && (GetAsyncKeyState(VK_UP) & 0x8001)) {
        fall = false;
        if (player.py <= PLAYERMOVE_START || player.py >= PLAYERMOVE_STOP) {
            if (!player.status) {
                player.py -= 2;
                player.px -= 2;
            }
            else {
                player.py -= 7;
                player.px -= 7;
            }
        }
        else {
            if (!player.status) {
                startY -= 2;
                bar_startY -= 2;
                player.py -= 2;
                player.px -= 2;
            }
            else {
                startY -= 7;
                bar_startY -= 7;
                player.py -= 7;
                player.px -= 7;
            }
        }
        return;
    }
    if ((GetAsyncKeyState(VK_RIGHT) & 0x8000) && (GetAsyncKeyState(VK_UP) & 0x8001)) {
        fall = false;
        if (player.py <= PLAYERMOVE_START || player.py >= PLAYERMOVE_STOP) {
            if (!player.status) {
                player.py -= 2;
                player.px += 2;
            }
            else {
                player.py -= 7;
                player.px += 7;
            }
        }
        else {
            if (!player.status) {
                startY -= 2;
                bar_startY -= 2;
                player.py -= 2;
                player.px += 2;
            }
            else {
                startY -= 7;
                bar_startY -= 7;
                player.py -= 7;
                player.px += 7;
            }
        }
        return;
    }
    if ((GetAsyncKeyState(VK_UP) & 0x8001)) {
        fall = false;
        if (player.py <= PLAYERMOVE_START || player.py >= PLAYERMOVE_STOP) {
            if(!player.status)
                player.py -= 2;
            else
                player.py -= 7;
        }
        else {
            if (!player.status) {
                startY -= 2;
                bar_startY -= 2;
                player.py -= 2;
            }
            else {
                startY -= 7;
                bar_startY -= 7;
                player.py -= 7;
            }
        }
    }
    else if ((GetAsyncKeyState(VK_RIGHT) & 0x8000) || (GetAsyncKeyState(VK_RIGHT) & 0x8001)) {
        if (!player.status)
            player.px += 2;
        else
            player.px += 5;
    }

    else if ((GetAsyncKeyState(VK_LEFT) & 0x8000) || (GetAsyncKeyState(VK_LEFT) & 0x8001)) {
        if (!player.status)
            player.px -= 2;
        else
            player.px -= 5;
    }



}

void gameScene::Render(HDC hdc)
{
    drawBackGround(hdc);
    //drawBox(hdc);
    drawPlayer(hdc);
    drawCloud(hdc);
    drawHPBar(hdc);
}


//void gameScene::Release() {
//
//
//}
