#pragma once


class TimeMgr
{
	SINGLE(TimeMgr);
private:
	LARGE_INTEGER m_IICurCount;
	LARGE_INTEGER m_IIFrequency;

	// FPS
	// 1�����Ӵ� �ð� (Delta Time)

public:
	void init();


};

