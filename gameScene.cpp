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

    int i = 0;
    if (fp == NULL)//���� ������ ��
    {
        perror("fopen ����");//���� �޽��� ���
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
}

void gameScene::init()
{
    startX = 0, startY = MEM_HEIGHT - (FRAME_HEIGHT);

    player_image.Load(TEXT("image/������.png"));
    background.Load(TEXT("image/���ȭ��1.png"));
    normalCloud.Load(TEXT("image/�Ϲݱ���.png"));
    rainCloud.Load(TEXT("image/�񱸸�.png"));
    darkCloud.Load(TEXT("image/�Ա���.png"));

    InitAnimation();
    InitCloud();
    ani_index = 0;      //�浹�̸� 20~27, ���ø� 0~19
    cloud_aniindex = 0;

    player = { MEM_WIDTH/2, PLAYER_FIRSTY, 1 };
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
        if ((GetAsyncKeyState(VK_UP) && 0x8000) || (GetAsyncKeyState(VK_UP) && 0x8001)) {
            if (player.py <= PLAYERMOVE_START || player.py >= PLAYERMOVE_STOP)
                player.py -= 5;
            else {
                startY -= 5;
                player.py -= 5;
            }
        }
        else if ((GetAsyncKeyState(VK_RIGHT) && 0x8000) || (GetAsyncKeyState(VK_RIGHT) && 0x8001))
            player.px += 5;
        else if ((GetAsyncKeyState(VK_LEFT) && 0x8000) || (GetAsyncKeyState(VK_LEFT) && 0x8001))
            player.px -= 5;
    }
    break;
    }
}

//�ִϸ��̼� ������ ���⼭ ������Ʈ
void gameScene::Update(const float frameTime)
{
    ani_index++;
    cloud_aniindex++;
    if (ani_index == 20)
        ani_index = 0;

    if (cloud_aniindex == 50)
        cloud_aniindex = 0;

    if (player.py <= PLAYER_FIRSTY && (player.py <= PLAYERMOVE_START || player.py >= PLAYERMOVE_STOP))
        player.py += 0.08 * frameTime;
    else if (player.py >= PLAYERMOVE_START && player.py <= PLAYERMOVE_STOP){
        startY += 0.08 * frameTime;
        player.py += 0.08 * frameTime;
    }
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
