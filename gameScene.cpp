#include "stdafx.h"
#include "gameScene.h"
//memdc�� �׷��ִ� ����, frame
extern WGameFramework framework;

gameScene::~gameScene()
{

}
void gameScene::InitCloud() {       //txt���Ͽ��� ���� ���� �޾ƿ��� �Լ�
    FILE* fp;
    fopen_s(&fp, "map1.txt", "r");

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

void gameScene::init()
{
    ani_index = 0;      //�浹�̸� 20~27, ���ø� 0~19
    startX = 0, startY = 0;
    int j = 0;

    for (int i = 0; i < 14; i++) {
        animation[j] = { i * PLAYER_IMAGE_SIZE, 0, (i + 1) * PLAYER_IMAGE_SIZE, PLAYER_IMAGE_SIZE };
        animation[j+1] = { i * PLAYER_IMAGE_SIZE, 0, (i + 1) * PLAYER_IMAGE_SIZE, PLAYER_IMAGE_SIZE };
        j += 2;
    }

    player_image.Load(TEXT("image/����.png"));
    background.Load(TEXT("image/���ȭ��1.png"));
    normalCloud.Load(TEXT("image/�Ϲݱ���.png"));
    rainCloud.Load(TEXT("image/�񱸸�.png"));
    darkCloud.Load(TEXT("image/�Ա���.png"));

    InitCloud();
    player = { 50, 50, 1 };
}

void gameScene::drawPlayer(HDC hdc) {
    //�÷��̾� �׸��� �Լ�(��� ������ ������ ����ؼ�..)
    player_image.Draw(hdc, player.px, player.py, CLOUD_WIDTH / 2, CLOUD_HEIGHT, animation[ani_index].left, animation[ani_index].top,
        PLAYER_IMAGE_SIZE, PLAYER_IMAGE_SIZE);
}

void gameScene::drawBackGround(HDC hdc) {
    //��� �׸��� �Լ�
    background.Draw(hdc, 0, 0, MEM_WIDTH, MEM_HEIGHT, 0, 0, background.GetWidth(), background.GetHeight());
}
void gameScene::drawCloud(HDC hdc) {
    //���� �׸��� �Լ�
    for (int j = 0; j < cloud_index; ++j) {
        switch (cloud[j].what) {
        case 1:
            darkCloud.Draw(hdc, cloud[j].cx, cloud[j].cy, CLOUD_WIDTH, CLOUD_HEIGHT, 0, 0, darkCloud.GetWidth(), darkCloud.GetHeight());
            break;
        case 2:
            rainCloud.Draw(hdc, cloud[j].cx, cloud[j].cy, CLOUD_WIDTH, CLOUD_HEIGHT, 0, 0, rainCloud.GetWidth(), rainCloud.GetHeight());
            break;
        case 3:
            normalCloud.Draw(hdc, cloud[j].cx, cloud[j].cy, CLOUD_WIDTH, CLOUD_HEIGHT, 0, 0, normalCloud.GetWidth(), normalCloud.GetHeight());
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

//�ִϸ��̼� ������ ���⼭ ������Ʈ
void gameScene::Update(const float frameTime)
{
    ani_index++;
    if (ani_index == 20)
        ani_index = 0;
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
