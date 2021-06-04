#include "menuScene.h"
#include "stdafx.h"

WGameFramework framework;

menuScene::~menuScene()
{

}

void menuScene::init()
{
	//�޴� ȭ�鿡�� �׸� ���ҽ� ��ġ �ʱ�ȭ
	background.Load(TEXT("image/����ȭ��1.png"));
	nomalCloud.Load(TEXT("image/�Ϲݱ���.png"));
	rainCloud.Load(TEXT("image/�񱸸�.png"));
	darkCloud.Load(TEXT("image/�Ա���.png"));
	press.Load(TEXT("image/�����Ϸ��鴩������.png"));
	cloudSizeCount = 0;
	cloudSize = 300;
	rainCloudSize = 220;
	darkCloudSize = 250;
	pressText = 0;
	ren = 0;
}
void menuScene::processKey(UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	switch (iMessage)
	{
	case WM_KEYDOWN:
	{
		switch (wParam) {
		case VK_RETURN:
			scene* scene = framework.curScene;	////���� ���� tmp�� �ְ� ������
			framework.curScene = new gameScene;
			framework.curScene->init();
			delete scene;
			break;
		}
	}
	break;

	}
}

void menuScene::Update()
{
	ren++;
	if (ren >= 10)
		ren = 0;
	if (cloudSizeCount >= 10)
		cloudSizeCount = 0;
	if (cloudSizeCount % 2 == 0) {
		
		//cloudSize += 20;
		//rainCloudSize -= 10;
		//darkCloudSize += 40;
	}
	else {
		//cloudSize -= 20;
		//rainCloudSize += 10;
		//darkCloudSize -= 40;
	}
	//cloudSizeCount++;

	if(pressText %2 == 0)
		pressText = 0;
	else if(pressText %2 == 1)
		pressText = 1;
	pressText++;

	//�ִϸ��̼� ������ ���⼭ ������Ʈ
}

void menuScene::Render(HDC hdc)
{
	background.Draw(hdc, 0, 0, FRAME_WIDTH, FRAME_HEIGHT, 0, 0, background.GetWidth(), background.GetHeight());
	
	nomalCloud.Draw(hdc, 60, 400, cloudSize, cloudSize, 512 * ren, 0, nomalCloud.GetHeight(), nomalCloud.GetHeight());
	//press.Draw(hdc, 300, 200, 700, 70, 0, 0, press.GetHeight(), press.GetHeight());
	rainCloud.Draw(hdc, 900, 300, rainCloudSize, rainCloudSize, 512 * ren, 0, rainCloud.GetHeight(), rainCloud.GetHeight());
	darkCloud.Draw(hdc, 500, 0, darkCloudSize, darkCloudSize, 512 * ren, 0, darkCloud.GetHeight(), darkCloud.GetHeight());
	//--- �޸� DC�� ��� �׸���
}
