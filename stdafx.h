#pragma once

// stdafx.h : ���� ��������� ���� ��������� �ʴ�
// ǥ�� �ý��� ���� ���� �Ǵ� ������Ʈ Ư�� ���� ������ ��� �ִ�
// ���� �����Դϴ�.
//


#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // ���� ������ �ʴ� ������ Windows ������� �����մϴ�.
// Windows ��� ����
#include <windows.h>
#include <atlimage.h>
#include <mmsystem.h>

// C ��Ÿ�� ��� �����Դϴ�.
#include <stdlib.h>
#include <time.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include <iostream>
#include <chrono>
#include <random>

using namespace std;
using namespace std::chrono;

#include "Define.h"

#include "scene.h"
#include "menuScene.h"
#include "gameScene.h"
#include "stage2Scene.h"
#include "overScene.h"
#include "clearScene.h"

#include "GameFramework.h"
// ���⼭ ���α׷��� �ʿ��� �߰� ����� �����մϴ�.