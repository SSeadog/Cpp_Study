#include <iostream>
#include "UserInterface.h"
#include "MyList.h"

int main()
{
    CMyList DB;
    CUserInterface UI(DB);
    UI.Run();

    return 0;
}
