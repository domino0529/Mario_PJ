#pragma once


// 싱글톤 패턴
// 객체의 생성을 1개로 제한
// 어디서든 쉽게 접근 가능
#include "define.h"

class Core
{
public:
	SINGLE(Core);

private:
	HWND	m_hwnd;			// 메인 윈도우 핸들
	POINT	m_ptResolution;	// 메인 윈도우 해상도
	HDC		m_hDC;

public:
	int Init(HWND _hwnd, POINT _ptResolution);
	void progress();

private:
	void update();
	void render();



};