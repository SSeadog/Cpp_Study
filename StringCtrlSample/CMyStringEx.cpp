#include "stdafx.h"
#include "CMyStringEx.h"

int CMyStringEx::Find(const char* pszParam)
{
	const char *findPtr = strstr(GetString(), pszParam);

	int index = findPtr - GetString();

	return index;
}

void CMyStringEx::OnSetString(char* pszData, int nLength)
{
	if (strcmp(pszData, "ธÛธÛภฬพฦต้") == 0)
		strcpy_s(pszData, sizeof(char) * (nLength + 1), "*ย๘วัพฦต้*");
}
