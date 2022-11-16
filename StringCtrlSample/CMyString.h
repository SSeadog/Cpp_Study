#pragma once
class CMyString
{
public:
	CMyString();
	explicit CMyString(const char* pszParam);
	CMyString(CMyString& rhs);
	CMyString(CMyString&& rhs);
	~CMyString();
	operator char*();
	operator char*() const;
private:
	// 문자열을 저장하기 위해 동적 할당한 메모리를 가리키는 포인터
	char* m_pszData;
	// 저장된 문자열의 길이
	int m_nLength;
public:
	int SetString(const char* pszParam);
	const char* GetString() const;
	int GetLength() const;
	int Append(const char* pszParam);
	void Release();
	CMyString& operator=(const CMyString& rhs);
	CMyString operator+(const CMyString& rhs);
	CMyString& operator+=(const CMyString& rhs);
	char& operator[](int nInt);
	char operator[](int nInt) const;
	int operator==(const CMyString& rhs);
	int operator!=(const CMyString& rhs);
	virtual void OnSetString(char* pszData, int nLength);
	friend CMyString operator+(const char* pszParam, const CMyString& strParam);
};

