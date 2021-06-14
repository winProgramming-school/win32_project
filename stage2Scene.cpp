#include "stdafx.h"
#include "stage2Scene.h"
//memdc�� �׷��ִ� ����, frame
extern WGameFramework framework;

stage2Scene::~stage2Scene()
{

}
void stage2Scene::InitCloud() {       //txt���Ͽ��� ���� ���� �޾ƿ��� �Լ�
    FILE* fp;
    fopen_s(&fp, "image/map2.txt", "r");
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
void stage2Scene::InitHeart() {
    FILE* fp;
    fopen_s(&fp, "image/map2(heart).txt", "r");

    int i = 0;
    if (fp == NULL)
    {
        perror("fopen ����");
        return;
    }

    while (!feof(fp)) {
        fscanf_s(fp, "%d %d %d", &item[i].ix, &item[i].iy, &item[i].what);
        ++i;
    }

    item_index = i;
    fclose(fp);
}
void stage2Scene::InitAnimation() {
    int j = 0;
    //14��
    //1�ִϸ��̼� 4��
    //0 ~ 3, ... ~39
    for (int i = 0; i < 14; i++) {
        animation[j] = { i * PLAYER_IMAGE_SIZE, 0, (i + 1) * PLAYER_IMAGE_SIZE, PLAYER_IMAGE_SIZE };
        animation[j + 1] = { i * PLAYER_IMAGE_SIZE, 0, (i + 1) * PLAYER_IMAGE_SIZE, PLAYER_IMAGE_SIZE };
        animation[j + 2] = { i * PLAYER_IMAGE_SIZE, 0, (i + 1) * PLAYER_IMAGE_SIZE, PLAYER_IMAGE_SIZE };
        animation[j + 3] = { i * PLAYER_IMAGE_SIZE, 0, (i + 1) * PLAYER_IMAGE_SIZE, PLAYER_IMAGE_SIZE };
        j += 4;
    }

    j = 0;

    //0~4, 5~9, 10~14, 15~19, 20~24, |25~29, 30~34, 35~39, 40~44, 45~49,| 50 ~54, 55~59 ���� ���� �̹����� ���� ��
    //������Ʈ �ӵ��� �ʹ� ���� ������ �����̰� �ϱ� ����

    for (int i = 0; i < 15; i++) {
        if (i == 10 || i == 11) {
            cloud_ani[j] = { 9 * CLOUD_IMAGE_SIZE, 0, 10 * CLOUD_IMAGE_SIZE, CLOUD_IMAGE_SIZE };
            cloud_ani[j + 1] = { 9 * CLOUD_IMAGE_SIZE, 0, 10 * CLOUD_IMAGE_SIZE, CLOUD_IMAGE_SIZE };
            cloud_ani[j + 2] = { 9 * CLOUD_IMAGE_SIZE, 0, 10 * CLOUD_IMAGE_SIZE, CLOUD_IMAGE_SIZE };
            cloud_ani[j + 3] = { 9 * CLOUD_IMAGE_SIZE, 0, 10 * CLOUD_IMAGE_SIZE, CLOUD_IMAGE_SIZE };
            cloud_ani[j + 4] = { 9 * CLOUD_IMAGE_SIZE, 0, 10 * CLOUD_IMAGE_SIZE, CLOUD_IMAGE_SIZE };
        }
        else if (i == 12 || i == 13 || i == 14) {
            cloud_ani[j] = { 0 * CLOUD_IMAGE_SIZE, 0, 1 * CLOUD_IMAGE_SIZE, CLOUD_IMAGE_SIZE };
            cloud_ani[j + 1] = { 0 * CLOUD_IMAGE_SIZE, 0, 1 * CLOUD_IMAGE_SIZE, CLOUD_IMAGE_SIZE };
            cloud_ani[j + 2] = { 0 * CLOUD_IMAGE_SIZE, 0, 1 * CLOUD_IMAGE_SIZE, CLOUD_IMAGE_SIZE };
            cloud_ani[j + 3] = { 0 * CLOUD_IMAGE_SIZE, 0, 1 * CLOUD_IMAGE_SIZE, CLOUD_IMAGE_SIZE };
            cloud_ani[j + 4] = { 0 * CLOUD_IMAGE_SIZE, 0, 1 * CLOUD_IMAGE_SIZE, CLOUD_IMAGE_SIZE };
        }
        else {
            cloud_ani[j] = { i * CLOUD_IMAGE_SIZE, 0, (i + 1) * CLOUD_IMAGE_SIZE, CLOUD_IMAGE_SIZE };
            cloud_ani[j + 1] = { i * CLOUD_IMAGE_SIZE, 0, (i + 1) * CLOUD_IMAGE_SIZE, CLOUD_IMAGE_SIZE };
            cloud_ani[j + 2] = { i * CLOUD_IMAGE_SIZE, 0, (i + 1) * CLOUD_IMAGE_SIZE, CLOUD_IMAGE_SIZE };
            cloud_ani[j + 3] = { i * CLOUD_IMAGE_SIZE, 0, (i + 1) * CLOUD_IMAGE_SIZE, CLOUD_IMAGE_SIZE };
            cloud_ani[j + 4] = { i * CLOUD_IMAGE_SIZE, 0, (i + 1) * CLOUD_IMAGE_SIZE, CLOUD_IMAGE_SIZE };
        }
        j += 5;
    }
    j = 0;
    for (int i = 0; i < 7; i++) {
        if (i == 5 || i == 6) {
            rain_ani[j] = { 4 * CLOUD_IMAGE_SIZE, 0, 5 * CLOUD_IMAGE_SIZE, RAIN_IMAGE };
            rain_ani[j + 1] = { 4 * CLOUD_IMAGE_SIZE, 0, 5 * CLOUD_IMAGE_SIZE, RAIN_IMAGE };
            rain_ani[j + 2] = { 4 * CLOUD_IMAGE_SIZE, 0, 5 * CLOUD_IMAGE_SIZE, RAIN_IMAGE };
            rain_ani[j + 3] = { 4 * CLOUD_IMAGE_SIZE, 0, 5 * CLOUD_IMAGE_SIZE, RAIN_IMAGE };
            rain_ani[j + 4] = { 4 * CLOUD_IMAGE_SIZE, 0, 5 * CLOUD_IMAGE_SIZE, RAIN_IMAGE };
        }
        else {
            rain_ani[j] = { i * CLOUD_IMAGE_SIZE, 0, (i + 1) * CLOUD_IMAGE_SIZE, RAIN_IMAGE };
            rain_ani[j + 1] = { i * CLOUD_IMAGE_SIZE, 0, (i + 1) * CLOUD_IMAGE_SIZE, RAIN_IMAGE };
            rain_ani[j + 2] = { i * CLOUD_IMAGE_SIZE, 0, (i + 1) * CLOUD_IMAGE_SIZE, RAIN_IMAGE };
            rain_ani[j + 3] = { i * CLOUD_IMAGE_SIZE, 0, (i + 1) * CLOUD_IMAGE_SIZE, RAIN_IMAGE };
            rain_ani[j + 4] = { i * CLOUD_IMAGE_SIZE, 0, (i + 1) * CLOUD_IMAGE_SIZE, RAIN_IMAGE };
        }
        j += 5;
    }
}
void stage2Scene::init()
{
    startX = 0, startY = STAGE2_HEIGHT - (FRAME_HEIGHT);

    player_image.Load(TEXT("image/������.png"));
    background.Load(TEXT("image/���ȭ��1.png"));

    normalCloud.Load(TEXT("image/�Ϲݱ���.png"));
    rainCloud.Load(TEXT("image/�񱸸�.png"));
    rain.Load(TEXT("image/��.png"));
    darkCloud.Load(TEXT("image/�Ա���.png"));

    heart.Load(TEXT("image/heart.png"));
    stone.Load(TEXT("image/stone.png"));

    InitAnimation();
    InitCloud();
    InitHeart();
    ani_index = 0;      //�浹�̸� 20~27, ���ø� 0~19
    gravity = 1;
    bar_w = 498;
    bar_startY = (STAGE2_HEIGHT - (CLOUD_HEIGHT + 50)) + 100;
    fall = true;

    player = { MEM_WIDTH / 2, (STAGE2_HEIGHT - (CLOUD_HEIGHT + 50)), 1, 0 };      //�÷��̾� ������ġ
}

void stage2Scene::drawPlayer(HDC hdc) {
    //�÷��̾� �׸��� �Լ�
    player_image.Draw(hdc, player.px, player.py, PLAYER_WIDTH, PLAYER_HEIGHT, animation[ani_index].left, animation[ani_index].top,
        PLAYER_IMAGE_SIZE, PLAYER_IMAGE_SIZE);
}
void stage2Scene::drawBackGround(HDC hdc) {
    //��� �׸��� �Լ�
    background.BitBlt(hdc, 0, 0, SRCCOPY);
}
void stage2Scene::drawCloud(HDC hdc) {
    //���� �׸��� �Լ�
    for (int j = 0; j < cloud_index; ++j) {
        switch (cloud[j].what) {
        case 1:
            darkCloud.Draw(hdc, cloud[j].cx, cloud[j].cy, CLOUD_WIDTH, CLOUD_HEIGHT, cloud_ani[cloud[j].index].left, cloud_ani[cloud[j].index].top, CLOUD_IMAGE_SIZE, CLOUD_IMAGE_SIZE);
            break;
        case 2:
            if (cloud[j].index >= 25 && cloud[j].index <= 59) {
                rainCloud.Draw(hdc, cloud[j].cx, cloud[j].cy, CLOUD_WIDTH, CLOUD_HEIGHT - 30, cloud_ani[cloud[j].index].left, cloud_ani[cloud[j].index].top, CLOUD_IMAGE_SIZE, RAINCLOUD_IMAGE);
                rain.Draw(hdc, cloud[j].cx, cloud[j].cy + (CLOUD_HEIGHT - 30), CLOUD_WIDTH, CLOUD_HEIGHT, rain_ani[cloud[j].index - 25].left, rain_ani[cloud[j].index - 25].top, CLOUD_IMAGE_SIZE, RAIN_IMAGE);
            }
            else
                rainCloud.Draw(hdc, cloud[j].cx, cloud[j].cy, CLOUD_WIDTH, CLOUD_HEIGHT - 30, cloud_ani[cloud[j].index].left, cloud_ani[cloud[j].index].top, CLOUD_IMAGE_SIZE, RAINCLOUD_IMAGE);
            break;
        case 3:
            normalCloud.Draw(hdc, cloud[j].cx, cloud[j].cy, CLOUD_WIDTH, CLOUD_HEIGHT, cloud_ani[cloud[j].index].left, cloud_ani[cloud[j].index].top, CLOUD_IMAGE_SIZE, CLOUD_IMAGE_SIZE);
            break;
        }
    }
}
void stage2Scene::drawItems(HDC hdc) {
    for (int j = 0; j < item_index; ++j) {
        switch (item[j].what) {
        case 1:
            heart.Draw(hdc, item[j].ix, item[j].iy, ITEM_SIZE, ITEM_SIZE, 0, 0, heart.GetWidth(), heart.GetHeight());
            break;
        case 2:
            stone.Draw(hdc, item[j].ix, item[j].iy, ITEM_SIZE, ITEM_SIZE, 0, 0, stone.GetWidth(), stone.GetHeight());
            break;
        }
    }
}
void stage2Scene::drawHPBar(HDC hdc) {
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
void stage2Scene::drawBox(HDC hdc) {
    Rectangle(hdc, pRECT.left, pRECT.top, pRECT.right, pRECT.bottom);
    for (int i = 0; i < cloud_index; ++i) {
        Rectangle(hdc, cloud[i].cx + 30, cloud[i].cy + 30, cloud[i].cx + CLOUD_COLLIDE_WIDTH, cloud[i].cy + CLOUD_COLLIDE_HEIGHT);
    }

}

void stage2Scene::moveItem() {
    for (int i = 0; i < item_index; ++i) {
        if (item[i].get == 1) {
            item[i].iy = bar_startY;
        }
    }
}

void stage2Scene::processKey(UINT iMessage, WPARAM wParam, LPARAM lParam)
{
    switch (iMessage)
    {
    case WM_KEYDOWN:
    {

    }
    break;
    case WM_KEYUP:
    {
        if (wParam == VK_UP) {
            fall = true;
            gravity = 1.8;
        }
        else if (wParam == VK_RIGHT || wParam == VK_LEFT) {
            fall = true;
            gravity = 0.5;
        }
    }
    break;
    }
}

bool stage2Scene::getItemCheck() {
    for (int i = 0; i < item_index; ++i) {
        if (item[i].get == 0)
            return false;
    }
    return true;
}

//�ִϸ��̼� ������ ���⼭ ������Ʈ
void stage2Scene::Update(const float frameTime)
{

    if (player.status) {          //�浹�� �ƴ� ��
        ani_index++;
    }
    if (ani_index >= 39)
        ani_index = 0;

    pRECT = { player.px + 18,player.py + 10,player.px + 18 + PLAYER_COLLIDE_WIDTH ,player.py + PLAYER_HEIGHT };

    player.status = 1;

    for (int i = 0; i < cloud_index; ++i) {
        cloud[i].index++;
        if (cloud[i].index == 74)
            cloud[i].index = 0;
        cRECT = { cloud[i].cx + 30, cloud[i].cy + 30, cloud[i].cx + CLOUD_COLLIDE_WIDTH, cloud[i].cy + CLOUD_COLLIDE_HEIGHT };
        if (IntersectRect(&tmp, &cRECT, &pRECT) && i > 6) {                             //�浹 �˻�
            player.status = 0;
            ani_index = 50;
        }
        if (cloud[i].what != 3 && cloud[i].index >= 35 && cloud[i].index <= 59) {       //������ �� �浹 �˻�
            cRECT = { cloud[i].cx + 30, cloud[i].cy + (CLOUD_HEIGHT - 30),              //�� ����
                cloud[i].cx + CLOUD_COLLIDE_WIDTH, cloud[i].cy + (CLOUD_HEIGHT - 30) + CLOUD_HEIGHT };
            if (IntersectRect(&tmp, &cRECT, &pRECT)) {                             //�浹 �˻�
                player.status = 0;
                ani_index = 50;
            }
        }
    }

    if (!player.status) {           //�÷��̾ �浹�����̸� ü�� ����
        bar_w -= 40 * frameTime;
    }
    bar_w -= 0.5 * frameTime;       //�׻� ����

    if (bar_w <= 0) {
        scene* scene = framework.curScene;   ////���� ���� tmp�� �ְ� ������
        framework.curScene = new overScene;
        framework.curScene->init();
        framework.nowscene = MENU;
        delete scene;
        return;
    }

    for (int i = 0; i < item_index; ++i) {                                  //�÷��̾ ������ �Ծ����� �˻�
        cRECT = { item[i].ix, item[i].iy, item[i].ix + ITEM_SIZE, item[i].iy + ITEM_SIZE };
        if (IntersectRect(&tmp, &cRECT, &pRECT)) {
            item[i].ix = ITEM_START + i * 40;
            item[i].iy = bar_startY;
            item[i].get = 1;
        }
    }

    //if (!fall && player.py <= PLAYER_FIRSTY && (player.py <= PLAYERMOVE_START || player.py >= PLAYERMOVE_STOP))
    //    player.py += 10 * frameTime;
    //else if (!fall && player.py >= PLAYERMOVE_START && player.py <= PLAYERMOVE_STOP){
    //    startY += 10 * frameTime;
    //    bar_startY += 10 * frameTime;
    //    player.py += 10 * frameTime;
    //}

    if (fall && gravity >= -30)
        gravity -= frameTime * 12;

    if (fall && player.py <= (STAGE2_HEIGHT - (CLOUD_HEIGHT + 50))) {
        if (!player.status)
            player.py -= gravity / 3;
        else
            player.py -= gravity;
        if (startY <= STAGE2_HEIGHT - (FRAME_HEIGHT) && player.py >= PLAYERMOVE_START) {
            if (!player.status) {
                startY -= gravity / 3;
                bar_startY -= gravity / 3;
                moveItem();
            }
            else {
                startY -= gravity;
                bar_startY -= gravity;
                moveItem();
            }
        }
    }

    if ((GetAsyncKeyState(VK_LEFT) & 0x8000) && (GetAsyncKeyState(VK_UP) & 0x8001)) {
        fall = false;
        if (player.py <= PLAYERMOVE_START || player.py >= (STAGE2_HEIGHT - (FRAME_HEIGHT / 2))) {
            if (!player.status) {
                player.py -= 2;
                player.px -= 2;
            }
            else {
                player.py -= 7;
                player.px -= 7;
            }
            if (player.py <= 0 && getItemCheck()) {
                scene* scene = framework.curScene;   ////���� ���� tmp�� �ְ� ������
                framework.curScene = new clearScene;
                framework.curScene->init();
                framework.nowscene = MENU;
                delete scene;
            }
        }
        else {
            if (!player.status) {
                startY -= 2;
                bar_startY -= 2;
                moveItem();
                player.py -= 2;
                player.px -= 2;
            }
            else {
                startY -= 7;
                bar_startY -= 7;
                moveItem();
                player.py -= 7;
                player.px -= 7;
            }
        }
        return;
    }
    if ((GetAsyncKeyState(VK_RIGHT) & 0x8000) && (GetAsyncKeyState(VK_UP) & 0x8001)) {
        fall = false;
        if (player.py <= PLAYERMOVE_START || player.py >= (STAGE2_HEIGHT - (FRAME_HEIGHT / 2))) {
            if (!player.status) {
                player.py -= 2;
                player.px += 2;
            }
            else {
                player.py -= 7;
                player.px += 7;
            }
            if (player.py <= 0 && getItemCheck()) {
                scene* scene = framework.curScene;   ////���� ���� tmp�� �ְ� ������
                framework.curScene = new clearScene;
                framework.curScene->init();
                framework.nowscene = MENU;
                delete scene;
            }
        }
        else {
            if (!player.status) {
                startY -= 2;
                bar_startY -= 2;
                moveItem();
                player.py -= 2;
                player.px += 2;
            }
            else {
                startY -= 7;
                bar_startY -= 7;
                moveItem();
                player.py -= 7;
                player.px += 7;
            }
        }
        return;
    }
    if ((GetAsyncKeyState(VK_UP) & 0x8001)) {
        fall = false;
        if (player.py <= PLAYERMOVE_START || player.py >= (STAGE2_HEIGHT - (FRAME_HEIGHT / 2))) {
            if (!player.status)
                player.py -= 2;
            else
                player.py -= 7;

            if (player.py <= 0 && getItemCheck()) {
                scene* scene = framework.curScene;   ////���� ���� tmp�� �ְ� ������
                framework.curScene = new clearScene;
                framework.curScene->init();
                framework.nowscene = MENU;
                delete scene;
            }
        }
        else {
            if (!player.status) {
                startY -= 2;
                bar_startY -= 2;
                moveItem();
                player.py -= 2;
            }
            else {
                startY -= 7;
                bar_startY -= 7;
                moveItem();
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
void stage2Scene::Render(HDC hdc)
{
    drawBackGround(hdc);
    //drawBox(hdc);
    drawPlayer(hdc);
    drawCloud(hdc);
    drawItems(hdc);
    drawHPBar(hdc);
}



//void gameScene::Release() {
//
//
//}
