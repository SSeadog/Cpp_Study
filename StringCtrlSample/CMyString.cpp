#include "stdafx.h"
#include "CMyString.h"
#define _CRT_SECURE_NO_WARNINGS

CMyString::CMyString() : m_pszData(NULL), m_nLength(0)
{

}

CMyString::CMyString(const char* pszParam) : m_pszData(NULL), m_nLength(0)
{
	this->SetString(pszParam);
}

CMyString::CMyString(CMyString& rhs) : m_pszData(NULL), m_nLength(0)
{
	SetString(rhs.GetString());

	// 아래처럼 했을 때 char* = char*은 왜 문자열 복사가 제대로 이뤄지지 않는지?
	/*m_nLength = rhs.m_nLength;

	m_pszData = new char[m_nLength + 1];
	*m_pszData = *rhs.m_pszData;*/
}

CMyString::CMyString(CMyString&& rhs)
	: m_pszData(NULL)
	, m_nLength(0)
{
	cout << "CMyString 이동 생성자 호출" << endl;

	m_pszData = rhs.m_pszData;
	m_nLength = rhs.m_nLength;

	rhs.m_pszData = NULL;
	rhs.m_nLength = 0;
}

CMyString::~CMyString()
{
	Release();
}

CMyString& CMyString::operator=(const CMyString& rhs)
{
	if (this != &rhs)
		this->SetString(rhs.GetString());

	return *this;
}

CMyString CMyString::operator+(const CMyString& rhs)
{
	CMyString temp(GetString());
	temp.Append(rhs.GetString());

	return temp;
}

CMyString& CMyString::operator+=(const CMyString& rhs)
{
	Append(rhs.GetString());

	return *this;
}

char& CMyString::operator[](int nInt)
{
	return m_pszData[nInt];
}

char CMyString::operator[](int nInt) const
{
	return m_pszData[nInt];
}

int CMyString::operator==(const CMyString& rhs)
{
	if (m_pszData != NULL && rhs.m_pszData != NULL)
		if (strcmp(m_pszData, rhs.m_pszData) == 0)
			return 1;

	return 0;
}

int CMyString::operator!=(const CMyString& rhs)
{
	if (m_pszData != NULL && rhs.m_pszData != NULL)
		if (strcmp(m_pszData, rhs.m_pszData) == 0)
			return 0;

	return 1;
}

void CMyString::OnSetString(char* pszData, int nLength)
{
}

CMyString::operator char* ()
{
	return m_pszData;
}

CMyString::operator char*() const
{
	return m_pszData;
}

int CMyString::SetString(const char* pszParam)
{
	// TODO: 여기에 구현 코드 추가.
	Release();

	if (pszParam == NULL)
		return 0;

	int nLength = strlen(pszParam);

	if (nLength == 0)
		return 0;

	m_pszData = new char[nLength + 1];
	strcpy_s(m_pszData, sizeof(char) * (nLength + 1), pszParam);
	m_nLength = nLength;

	OnSetString(m_pszData, m_nLength);

	return nLength;
}


const char* CMyString::GetString() const
{
	// TODO: 여기에 구현 코드 추가.
	return m_pszData;
}

int CMyString::GetLength() const
{
	return m_nLength;
}

int CMyString::Append(const char* pszParam)
{
	if (pszParam == NULL)
		return 0;

	int nLenParam = strlen(pszParam);

	if (nLenParam == 0)
		return 0;

	if (m_pszData == NULL)
	{
		SetString(pszParam);

		return m_nLength;
	}

	int nLenCur = m_nLength;

	char* pszResult = new char[nLenCur * nLenParam + 1];

	strcpy_s(pszResult, sizeof(char) * (nLenCur + 1), m_pszData);
	strcpy_s(pszResult + (sizeof(char) * nLenCur), sizeof(char) * (nLenParam + 1), pszParam);

	Release();
	m_pszData = pszResult;
	m_nLength = nLenCur + nLenParam;

	return m_nLength;
}

void CMyString::Release()
{
	// TODO: 여기에 구현 코드 추가.
	if (m_pszData != NULL)
	{
		delete[] m_pszData;
	}

	m_pszData = NULL;
	m_nLength = 0;
}


CMyString operator+(const char* pszParam, const CMyString& strParam)
{
	CMyString strResult(pszParam);
	strResult.Append(strParam.m_pszData);

	return strResult;
}