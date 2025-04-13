#include"pch.h"
#include "Core.h"

#include"TimeMgr.h"
#include"KeyMgr.h"

#include"CObject.h"



CObject g_obj;

Core::Core()
			: m_hwnd(0)
			, m_ptResolution{}
			, m_hDC(0)
{
}

Core::~Core()
{
	ReleaseDC(m_hwnd, m_hDC);
}

int Core::Init(HWND _hwnd, POINT _ptResolution)
{
	m_hwnd = _hwnd;
	m_ptResolution = _ptResolution;

	// 해상도에 맞게 윈도우 크기 조정
	RECT rt = {0, 0, m_ptResolution.x, m_ptResolution.y};
	AdjustWindowRect(&rt, WS_OVERLAPPEDWINDOW, true);
	SetWindowPos(m_hwnd, nullptr, 100, 100, rt.right - rt.left, rt.bottom- rt.top, 0);


	m_hDC = GetDC(m_hwnd);

	//Manager 초기화
	TimeMgr::GetInst()->init();
	KeyMgr::GetInst()->init();


	g_obj.SetPos(Vec2((float)(m_ptResolution.x / 2), (float)(m_ptResolution.y / 2)));
	g_obj.SetScale(Vec2 (100, 100));


	return S_OK;
}

void Core::progress()
{
	static int callcount = 0;
	++callcount;

	static int iPrevCount = GetTickCount();
	
	int iCurCount = GetTickCount();
	if (iCurCount - iPrevCount > 1000)
	{
		iPrevCount = iCurCount;
		callcount = 0;
	}

	update();

	render();
}

void Core::update()
{
	Vec2 vPos = g_obj.GetPos();

	if (GetAsyncKeyState(VK_LEFT) & 0x8000)
	{
		vPos.x -= 0.01f;
	}

	if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
	{
		vPos.x += 0.01f;
	}
	
	g_obj.SetPos(vPos);
}

void Core::render()
{
	// 그리기
	Vec2 vPos = g_obj.GetPos();
	Vec2 vScale = g_obj.GetScale();

	Rectangle(m_hDC,  int(vPos.x - vScale.x / 2.f)
					, int(vPos.y - vScale.y / 2.f)
					, int(vPos.x + vScale.x / 2.f)
					, int(vPos.y + vScale.y / 2.f));
}
