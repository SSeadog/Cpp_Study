#pragma once

class CUserData
{
	friend class CMyList;
	
public:
	CUserData();
	~CUserData();

	const char* GetName() const { return szName; }
	const char* GetPhone() const { return szPhone; }
	const CUserData* GetNext() const { return pNext; }

	static int GetUserDataCounter() { return nUserDataCounter; }

protected:
	char szName[32];
	char szPhone[32];

	CUserData* pNext;

	static int nUserDataCounter;
};