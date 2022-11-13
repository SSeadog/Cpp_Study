// StringCtrlSample.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "stdafx.h"
#include "CMyStringEx.h"

int main()
{
    CMyStringEx strTest;
    strTest.SetString("I am a boy.");
    cout << strTest << endl;

    int nIndex = strTest.Find("am");
    cout << "Index: " << nIndex << endl;

    return 0;
}