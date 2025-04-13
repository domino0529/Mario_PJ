#pragma once


class TimeMgr
{
	SINGLE(TimeMgr);
private:
	LARGE_INTEGER m_IICurCount;
	LARGE_INTEGER m_IIFrequency;

	// FPS
	// 1프레임당 시간 (Delta Time)

public:
	void init();


};

