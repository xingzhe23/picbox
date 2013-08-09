#include "WinUtil.h"
#include "stables.h"

void WinUtil::addWindowStyle( UINT32 windowId, UINT32 addStyle )
{
    LONG style = ::GetWindowLong((HWND)windowId, GWL_STYLE);
    style |= addStyle;
    ::SetWindowLong((HWND)windowId, GWL_STYLE, style);
}