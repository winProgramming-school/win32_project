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
        case VK_RETURN: //enter Ű������ ���ӽ���
            scene* scene = framework.curScene;
            //framework.curScene = new gameScene;
            framework.curScene->init();
            delete scene;
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
    
}

//void menuScene::Release() {
//
//
//}
