#pragma once

#define MAIN_TIMER			1	

#define MAIN_TIEMR_FRAME	60 // 60FPS

#define MAIN_TIEMR_FRAME	17 // 60FPS


#define FRAME_WIDTH			1200
#define FRAME_HEIGHT		720
#define MEM_WIDTH			1200
#define MEM_HEIGHT			1550

#define PLAYER_IMAGE_SIZE	512
#define CLOUD_IMAGE_SIZE	512

#define CLOUD_WIDTH			172
#define CLOUD_HEIGHT		130

#define PLAYER_WIDTH		CLOUD_WIDTH / 2
#define PLAYER_HEIGHT		CLOUD_HEIGHT - 50

#define PLAYERMOVE_STOP		MEM_HEIGHT - (FRAME_HEIGHT/2)		//ó�� ������ �� �÷��̾ ȭ���� ���� �� �̻� �ö󰡸� ȭ�� ������
#define PLAYERMOVE_START	FRAME_HEIGHT/2						//���߿� Ŭ���� ������ ������ �������� ���� ȭ�� ���߰� �÷��̾ ������
#define PLAYER_FIRSTY		MEM_HEIGHT- (CLOUD_HEIGHT + 50)		//�÷��̾� ó�� ���� y����

// KeyBoard
enum VK_KEY
{
	VK_0 = 48,
	VK_1 = 49,
	VK_2,
	VK_3,
	VK_4,
	VK_5,
	VK_6,
	VK_7,
	VK_8,
	VK_9,
	VK_A = 0x41,
	VK_B,
	VK_C,
	VK_D,
	VK_E,
	VK_F,
	VK_G,
	VK_H,
	VK_I,
	VK_J,
	VK_K,
	VK_L,
	VK_M,
	VK_N,
	VK_O,
	VK_P,
	VK_Q,
	VK_R,
	VK_S,
	VK_T,
	VK_U,
	VK_V,
	VK_W,
	VK_X,
	VK_Y,
	VK_Z
};
// KeyBoard
