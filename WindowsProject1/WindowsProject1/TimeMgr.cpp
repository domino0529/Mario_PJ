#include "pch.h"
#include "TimeMgr.h"

TimeMgr::TimeMgr()
	: m_IICurCount{}
	, m_IIFrequency{}
{

}

TimeMgr::~TimeMgr()
{

}

void TimeMgr::init()
{
	QueryPerformanceCounter(&m_IICurCount);
	QueryPerformanceFrequency(&m_IIFrequency);
}
