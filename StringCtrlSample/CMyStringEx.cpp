#include "stdafx.h"
#include "CMyStringEx.h"

int CMyStringEx::Find(const char* pszParam)
{
	const char *findPtr = strstr(GetString(), pszParam);

	int index = findPtr - GetString();

	return index;
}