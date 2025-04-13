#pragma once


// �̱��� ����
// ��ü�� ������ 1���� ����
// ��𼭵� ���� ���� ����
#include "define.h"

class Core
{
public:
	SINGLE(Core);

private:
	HWND	m_hwnd;			// ���� ������ �ڵ�
	POINT	m_ptResolution;	// ���� ������ �ػ�
	HDC		m_hDC;

public:
	int Init(HWND _hwnd, POINT _ptResolution);
	void progress();

private:
	void update();
	void render();



};