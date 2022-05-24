#include "WindowsMessageMap.h"

#include <windowsx.h>
#include <sstream>
#include <iomanip>

#define WM_UAHDESTROYWINDOW 0x0090
#define WM_UAHDRAWMENU 0x0091
#define WM_UAHDRAWMENUITEM 0x0092
#define WM_UAHINITMENU 0x0093
#define WM_UAHMEASUREMENUITEM 0x0094
#define WM_UAHNCPAINTMENUPOPUP 0x0095
#define WM_COPYGLOBALDATA 0x0049
#define EM_SETFONT 0x00C3
#define EM_SETWORDBREAK 0x00CA
#define WM_CONVERTREQUEST 0x010A
#define WM_CONVERTRESULT 0x010B
#define WM_INTERIM 0x010C
#define WM_SYSTIMER 0X0118
#define WM_LBTRACKPOINT 0x0131
#define CB_MULTIPLEADDSTRING 0x0163
#define WM_IME_REPORT 0x0280
#define REGISTER_MESSAGE(msg){msg,#msg}
WindowsMessageMap::WindowsMessageMap() :
	map({
	
	REGISTER_MESSAGE(WM_CREATE),
	REGISTER_MESSAGE(WM_DESTROY),
	REGISTER_MESSAGE(WM_MOVE),
	REGISTER_MESSAGE(WM_SIZE),
	REGISTER_MESSAGE(WM_ACTIVATE),
	REGISTER_MESSAGE(WM_SETFOCUS),
	REGISTER_MESSAGE(WM_KILLFOCUS),
	REGISTER_MESSAGE(WM_ENABLE),
	REGISTER_MESSAGE(WM_SETREDRAW),
	REGISTER_MESSAGE(WM_SETTEXT),
	REGISTER_MESSAGE(WM_GETTEXT),
	REGISTER_MESSAGE(WM_GETTEXTLENGTH),
	REGISTER_MESSAGE(WM_PAINT),
	REGISTER_MESSAGE(WM_CLOSE),
	REGISTER_MESSAGE(WM_QUERYENDSESSION),
	REGISTER_MESSAGE(WM_QUIT),
	REGISTER_MESSAGE(WM_QUERYOPEN),
	REGISTER_MESSAGE(WM_ERASEBKGND),
	REGISTER_MESSAGE(WM_SYSCOLORCHANGE),
	REGISTER_MESSAGE(WM_ENDSESSION),
	REGISTER_MESSAGE(WM_SHOWWINDOW),
	REGISTER_MESSAGE(WM_CTLCOLOR),
	REGISTER_MESSAGE(WM_WININICHANGE),
	REGISTER_MESSAGE(WM_DEVMODECHANGE),
	REGISTER_MESSAGE(WM_ACTIVATEAPP),
	REGISTER_MESSAGE(WM_FONTCHANGE),
	REGISTER_MESSAGE(WM_TIMECHANGE),
	REGISTER_MESSAGE(WM_CANCELMODE),
	REGISTER_MESSAGE(WM_SETCURSOR),
	REGISTER_MESSAGE(WM_MOUSEACTIVATE),
	REGISTER_MESSAGE(WM_CHILDACTIVATE),
	REGISTER_MESSAGE(WM_QUEUESYNC),
	REGISTER_MESSAGE(WM_GETMINMAXINFO),
	REGISTER_MESSAGE(WM_PAINTICON),
	REGISTER_MESSAGE(WM_ICONERASEBKGND),
	REGISTER_MESSAGE(WM_NEXTDLGCTL),
	REGISTER_MESSAGE(WM_SPOOLERSTATUS),
	REGISTER_MESSAGE(WM_DRAWITEM),
	REGISTER_MESSAGE(WM_MEASUREITEM),
	REGISTER_MESSAGE(WM_DELETEITEM),
	REGISTER_MESSAGE(WM_VKEYTOITEM),
	REGISTER_MESSAGE(WM_CHARTOITEM),
	REGISTER_MESSAGE(WM_SETFONT),
	REGISTER_MESSAGE(WM_GETFONT),
	REGISTER_MESSAGE(WM_SETHOTKEY),
	REGISTER_MESSAGE(WM_GETHOTKEY),
	REGISTER_MESSAGE(WM_QUERYDRAGICON),
	REGISTER_MESSAGE(WM_COMPAREITEM),
	REGISTER_MESSAGE(WM_GETOBJECT),
	REGISTER_MESSAGE(WM_COMPACTING),
	REGISTER_MESSAGE(WM_COMMNOTIFY),
	REGISTER_MESSAGE(WM_WINDOWPOSCHANGING),
	REGISTER_MESSAGE(WM_WINDOWPOSCHANGED),
	REGISTER_MESSAGE(WM_POWER),
	REGISTER_MESSAGE(WM_COPYGLOBALDATA),
	REGISTER_MESSAGE(WM_COPYDATA),
	REGISTER_MESSAGE(WM_CANCELJOURNAL),
	REGISTER_MESSAGE(WM_NOTIFY),
	REGISTER_MESSAGE(WM_INPUTLANGCHANGEREQUEST),
	REGISTER_MESSAGE(WM_INPUTLANGCHANGE),
	REGISTER_MESSAGE(WM_TCARD),
	REGISTER_MESSAGE(WM_HELP),
	REGISTER_MESSAGE(WM_USERCHANGED),
	REGISTER_MESSAGE(WM_NOTIFYFORMAT),
	REGISTER_MESSAGE(WM_CONTEXTMENU),
	REGISTER_MESSAGE(WM_STYLECHANGING),
	REGISTER_MESSAGE(WM_STYLECHANGED),
	REGISTER_MESSAGE(WM_DISPLAYCHANGE),
	REGISTER_MESSAGE(WM_GETICON),
	REGISTER_MESSAGE(WM_SETICON),
	REGISTER_MESSAGE(WM_NCCREATE),
	REGISTER_MESSAGE(WM_NCDESTROY),
	REGISTER_MESSAGE(WM_NCCALCSIZE),
	REGISTER_MESSAGE(WM_NCHITTEST),
	REGISTER_MESSAGE(WM_NCPAINT),
	REGISTER_MESSAGE(WM_NCACTIVATE),
	REGISTER_MESSAGE(WM_GETDLGCODE),
	REGISTER_MESSAGE(WM_SYNCPAINT),
	REGISTER_MESSAGE(WM_NCMOUSEMOVE),
	REGISTER_MESSAGE(WM_NCLBUTTONDOWN),
	REGISTER_MESSAGE(WM_NCLBUTTONUP),
	REGISTER_MESSAGE(WM_NCLBUTTONDBLCLK),
	REGISTER_MESSAGE(WM_NCRBUTTONDOWN),
	REGISTER_MESSAGE(WM_NCRBUTTONUP),
	REGISTER_MESSAGE(WM_NCRBUTTONDBLCLK),
	REGISTER_MESSAGE(WM_NCMBUTTONDOWN),
	REGISTER_MESSAGE(WM_NCMBUTTONUP),
	REGISTER_MESSAGE(WM_NCMBUTTONDBLCLK),
	REGISTER_MESSAGE(WM_NCXBUTTONDOWN),
	REGISTER_MESSAGE(WM_NCXBUTTONUP),
	REGISTER_MESSAGE(WM_NCXBUTTONDBLCLK),
	REGISTER_MESSAGE(EM_GETSEL),
	REGISTER_MESSAGE(EM_SETSEL),
	REGISTER_MESSAGE(EM_GETRECT),
	REGISTER_MESSAGE(EM_SETRECT),
	REGISTER_MESSAGE(EM_SETRECTNP),
	REGISTER_MESSAGE(EM_SCROLL),
	REGISTER_MESSAGE(EM_LINESCROLL),
	REGISTER_MESSAGE(EM_SCROLLCARET),
	REGISTER_MESSAGE(EM_GETMODIFY),
	REGISTER_MESSAGE(EM_SETMODIFY),
	REGISTER_MESSAGE(EM_GETLINECOUNT),
	REGISTER_MESSAGE(EM_LINEINDEX),
	REGISTER_MESSAGE(EM_SETHANDLE),
	REGISTER_MESSAGE(EM_GETHANDLE),
	REGISTER_MESSAGE(EM_GETTHUMB),
	REGISTER_MESSAGE(EM_LINELENGTH),
	REGISTER_MESSAGE(EM_REPLACESEL),
	REGISTER_MESSAGE(EM_SETFONT),
	REGISTER_MESSAGE(EM_GETLINE),
	REGISTER_MESSAGE(EM_LIMITTEXT),
	REGISTER_MESSAGE(EM_SETLIMITTEXT),
	REGISTER_MESSAGE(EM_CANUNDO),
	REGISTER_MESSAGE(EM_UNDO),
	REGISTER_MESSAGE(EM_FMTLINES),
	REGISTER_MESSAGE(EM_LINEFROMCHAR),
	REGISTER_MESSAGE(EM_SETWORDBREAK),
	REGISTER_MESSAGE(EM_SETTABSTOPS),
	REGISTER_MESSAGE(EM_SETPASSWORDCHAR),
	REGISTER_MESSAGE(EM_EMPTYUNDOBUFFER),
	REGISTER_MESSAGE(EM_GETFIRSTVISIBLELINE),
	REGISTER_MESSAGE(EM_SETREADONLY),
	REGISTER_MESSAGE(EM_SETWORDBREAKPROC),
		REGISTER_MESSAGE(EM_GETWORDBREAKPROC),
		REGISTER_MESSAGE(EM_GETPASSWORDCHAR),
		REGISTER_MESSAGE(EM_SETMARGINS),
		REGISTER_MESSAGE(EM_GETMARGINS),
		REGISTER_MESSAGE(EM_GETLIMITTEXT),
		REGISTER_MESSAGE(EM_POSFROMCHAR),
		REGISTER_MESSAGE(EM_CHARFROMPOS),
		REGISTER_MESSAGE(EM_SETIMESTATUS),
		REGISTER_MESSAGE(EM_GETIMESTATUS),
		REGISTER_MESSAGE(SBM_SETPOS),
		REGISTER_MESSAGE(SBM_GETPOS),
		REGISTER_MESSAGE(SBM_SETRANGE),
		REGISTER_MESSAGE(SBM_GETRANGE),
		REGISTER_MESSAGE(SBM_ENABLE_ARROWS),
		REGISTER_MESSAGE(SBM_SETRANGEREDRAW),
		REGISTER_MESSAGE(SBM_SETSCROLLINFO),
		REGISTER_MESSAGE(SBM_GETSCROLLINFO),
		REGISTER_MESSAGE(SBM_GETSCROLLBARINFO),
		REGISTER_MESSAGE(BM_GETCHECK),
		REGISTER_MESSAGE(BM_SETCHECK),
		REGISTER_MESSAGE(BM_GETSTATE),
		REGISTER_MESSAGE(BM_SETSTATE),
		REGISTER_MESSAGE(BM_SETSTYLE),
		REGISTER_MESSAGE(BM_CLICK),
		REGISTER_MESSAGE(BM_GETIMAGE),
		REGISTER_MESSAGE(BM_SETIMAGE),
		REGISTER_MESSAGE(BM_SETDONTCLICK),
		REGISTER_MESSAGE(WM_INPUT),
		REGISTER_MESSAGE(WM_KEYDOWN),
		REGISTER_MESSAGE(WM_KEYFIRST),
		REGISTER_MESSAGE(WM_KEYUP),
		REGISTER_MESSAGE(WM_CHAR),
		REGISTER_MESSAGE(WM_DEADCHAR),
		REGISTER_MESSAGE(WM_SYSKEYDOWN),
		REGISTER_MESSAGE(WM_SYSKEYUP),
		REGISTER_MESSAGE(WM_SYSCHAR),
		REGISTER_MESSAGE(WM_SYSDEADCHAR),
		REGISTER_MESSAGE(WM_UNICHAR),
		REGISTER_MESSAGE(WM_CONVERTREQUEST),
		REGISTER_MESSAGE(WM_CONVERTRESULT),
		REGISTER_MESSAGE(WM_INTERIM),
		REGISTER_MESSAGE(WM_IME_STARTCOMPOSITION),
		REGISTER_MESSAGE(WM_IME_ENDCOMPOSITION),
		REGISTER_MESSAGE(WM_IME_COMPOSITION),
		REGISTER_MESSAGE(WM_IME_KEYLAST),
		REGISTER_MESSAGE(WM_INITDIALOG),
		REGISTER_MESSAGE(WM_COMMAND),
		REGISTER_MESSAGE(WM_SYSCOMMAND),
		REGISTER_MESSAGE(WM_TIMER),
		REGISTER_MESSAGE(WM_HSCROLL),
		REGISTER_MESSAGE(WM_VSCROLL),
		REGISTER_MESSAGE(WM_INITMENU),
		REGISTER_MESSAGE(WM_INITMENUPOPUP),
		REGISTER_MESSAGE(WM_SYSTIMER),
		REGISTER_MESSAGE(WM_MENUSELECT),
		REGISTER_MESSAGE(WM_MENUCHAR),
		REGISTER_MESSAGE(WM_ENTERIDLE),
		REGISTER_MESSAGE(WM_MENURBUTTONUP),
		REGISTER_MESSAGE(WM_MENUDRAG),
		REGISTER_MESSAGE(WM_MENUGETOBJECT),
		REGISTER_MESSAGE(WM_UNINITMENUPOPUP),
		REGISTER_MESSAGE(WM_MENUCOMMAND),
		REGISTER_MESSAGE(WM_CHANGEUISTATE),
		REGISTER_MESSAGE(WM_UPDATEUISTATE),
		REGISTER_MESSAGE(WM_QUERYUISTATE),
		REGISTER_MESSAGE(WM_LBTRACKPOINT),
		REGISTER_MESSAGE(WM_CTLCOLORMSGBOX),
		REGISTER_MESSAGE(WM_CTLCOLOREDIT),
		REGISTER_MESSAGE(WM_CTLCOLORLISTBOX),
		REGISTER_MESSAGE(WM_CTLCOLORBTN),
		REGISTER_MESSAGE(WM_CTLCOLORDLG),
		REGISTER_MESSAGE(WM_CTLCOLORSCROLLBAR),
		REGISTER_MESSAGE(WM_CTLCOLORSTATIC),
		REGISTER_MESSAGE(CB_GETEDITSEL),
		REGISTER_MESSAGE(CB_LIMITTEXT),
		REGISTER_MESSAGE(CB_SETEDITSEL),
		REGISTER_MESSAGE(CB_ADDSTRING),
		REGISTER_MESSAGE(CB_DELETESTRING),
		REGISTER_MESSAGE(CB_DIR),
		REGISTER_MESSAGE(CB_GETCOUNT),
		REGISTER_MESSAGE(CB_GETCURSEL),
		REGISTER_MESSAGE(CB_GETLBTEXT),
		REGISTER_MESSAGE(CB_GETLBTEXTLEN),
		REGISTER_MESSAGE(CB_INSERTSTRING),
		REGISTER_MESSAGE(CB_RESETCONTENT),
		REGISTER_MESSAGE(CB_FINDSTRING),
		REGISTER_MESSAGE(CB_SELECTSTRING),
		REGISTER_MESSAGE(CB_SETCURSEL),
		REGISTER_MESSAGE(CB_SHOWDROPDOWN),
		REGISTER_MESSAGE(CB_GETITEMDATA),
		REGISTER_MESSAGE(CB_SETITEMDATA),
		REGISTER_MESSAGE(CB_GETDROPPEDCONTROLRECT),
		REGISTER_MESSAGE(CB_SETITEMHEIGHT),
		REGISTER_MESSAGE(CB_GETITEMHEIGHT),
		REGISTER_MESSAGE(CB_SETEXTENDEDUI),
		REGISTER_MESSAGE(CB_GETEXTENDEDUI),
		REGISTER_MESSAGE(CB_GETDROPPEDSTATE),
		REGISTER_MESSAGE(CB_FINDSTRINGEXACT),
		REGISTER_MESSAGE(CB_SETLOCALE),
		REGISTER_MESSAGE(CB_GETLOCALE),
		REGISTER_MESSAGE(CB_GETTOPINDEX),
		REGISTER_MESSAGE(CB_SETTOPINDEX),
		REGISTER_MESSAGE(CB_GETHORIZONTALEXTENT),
		REGISTER_MESSAGE(CB_SETHORIZONTALEXTENT),
		REGISTER_MESSAGE(CB_GETDROPPEDWIDTH),
		REGISTER_MESSAGE(CB_SETDROPPEDWIDTH),
		REGISTER_MESSAGE(CB_INITSTORAGE),
		REGISTER_MESSAGE(CB_MULTIPLEADDSTRING),
		REGISTER_MESSAGE(CB_GETCOMBOBOXINFO),
		REGISTER_MESSAGE(CB_MSGMAX),
		REGISTER_MESSAGE(WM_MOUSEFIRST),
		REGISTER_MESSAGE(WM_MOUSEMOVE),
		REGISTER_MESSAGE(WM_LBUTTONDOWN),
		REGISTER_MESSAGE(WM_LBUTTONUP),
		REGISTER_MESSAGE(WM_LBUTTONDBLCLK),
		REGISTER_MESSAGE(WM_RBUTTONDOWN),
		REGISTER_MESSAGE(WM_RBUTTONUP),
		REGISTER_MESSAGE(WM_RBUTTONDBLCLK),
		REGISTER_MESSAGE(WM_MBUTTONDOWN),
		REGISTER_MESSAGE(WM_MBUTTONUP),
		REGISTER_MESSAGE(WM_MBUTTONDBLCLK),
		REGISTER_MESSAGE(WM_MOUSELAST),
		REGISTER_MESSAGE(WM_MOUSEWHEEL),
		REGISTER_MESSAGE(WM_XBUTTONDOWN),
		REGISTER_MESSAGE(WM_XBUTTONUP),
		REGISTER_MESSAGE(WM_XBUTTONDBLCLK),
		REGISTER_MESSAGE(WM_MOUSEHWHEEL),
		REGISTER_MESSAGE(WM_PARENTNOTIFY),
		REGISTER_MESSAGE(WM_ENTERMENULOOP),
		REGISTER_MESSAGE(WM_EXITMENULOOP),
		REGISTER_MESSAGE(WM_NEXTMENU),
		REGISTER_MESSAGE(WM_SIZING),
		REGISTER_MESSAGE(WM_CAPTURECHANGED),
		REGISTER_MESSAGE(WM_MOVING),
		REGISTER_MESSAGE(WM_POWERBROADCAST),
		REGISTER_MESSAGE(WM_DEVICECHANGE),
		REGISTER_MESSAGE(WM_MDICREATE),
		REGISTER_MESSAGE(WM_MDIDESTROY),
		REGISTER_MESSAGE(WM_MDIACTIVATE),
		REGISTER_MESSAGE(WM_MDIRESTORE),
		REGISTER_MESSAGE(WM_MDINEXT),
		REGISTER_MESSAGE(WM_MDIMAXIMIZE),
		REGISTER_MESSAGE(WM_MDITILE),
		REGISTER_MESSAGE(WM_MDICASCADE),
		REGISTER_MESSAGE(WM_MDIICONARRANGE),
		REGISTER_MESSAGE(WM_MDIGETACTIVE),
		REGISTER_MESSAGE(WM_MDISETMENU),
		REGISTER_MESSAGE(WM_ENTERSIZEMOVE),
		REGISTER_MESSAGE(WM_EXITSIZEMOVE),
		REGISTER_MESSAGE(WM_DROPFILES),
		REGISTER_MESSAGE(WM_MDIREFRESHMENU),
		REGISTER_MESSAGE(WM_IME_REPORT),
		REGISTER_MESSAGE(WM_IME_SETCONTEXT),
		}
	
		)
{}


		std::string WindowsMessageMap::operator() (DWORD msg, LPARAM lp, WPARAM wp) const {
			constexpr int firstColWidth = 25;
			const auto i = map.find(msg);

			std::ostringstream oss;

			if (i != map.end())
			{
				oss << std::left << std::setw(firstColWidth) << i->second << std::right;
			}
			else 
			{
				std::ostringstream padss;
				padss << "Unknown message: 0x" << std::hex << msg;
			}

			oss << "		LP:  0x" << std::hex << std::setfill('0') << std::setw(8) << lp;
			oss << "		WP:  0x" << std::hex << std::setfill('0') << std::setw(8) << wp << std::endl;
			return oss.str();
		}