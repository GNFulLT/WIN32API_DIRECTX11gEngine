#include "MainWindow.h"
#include <exception>
#include "../WindowsMessageMap.h"


std::unique_ptr<MainWindow> MainWindow::_window;


void MainWindow::CreateMainWindow(unsigned int width, unsigned int height, const wchar_t* windowName, const wchar_t* windowTitle) noexcept
{
	_window.reset(new MainWindow(width, height, windowName, windowTitle));
}

const MainWindow* const MainWindow::GetInstance() noexcept
{
	return _window.get();
}

MainWindow::MainWindowClass::~MainWindowClass()
{
	UnregisterClass(_windowClassName, GetInstance());

}

HINSTANCE MainWindow::MainWindowClass::GetInstance() const noexcept
{
	return hInst;
}
MainWindow::MainWindowClass::MainWindowClass(const wchar_t* windowClassName, const wchar_t* windowTitle) : _windowClassName(windowClassName),_windowTitle(windowTitle)
{
	WNDCLASSEX wc = { 0 };
	wc.cbSize = sizeof(wc);
	wc.style = CS_OWNDC;
	wc.lpfnWndProc = HandleMsgSetup;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = GetInstance();
	wc.hIcon = nullptr;
	wc.hCursor = nullptr;
	wc.hIconSm = nullptr;
	wc.hbrBackground = nullptr;
	wc.lpszClassName = _windowClassName;
	wc.lpszMenuName = nullptr;
	RegisterClassEx(&wc);

	
}

MainWindow::MainWindow(unsigned int width, unsigned int height, const wchar_t* windowClassName, const wchar_t* windowTitle) : 
_height(height),
_width(width)
{
	RECT wr;
	wr.left = 0;
	wr.top = 0;
	wr.right = width + wr.left;
	wr.bottom = height + wr.top;

	if (FAILED(AdjustWindowRect(&wr, WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU, FALSE)))
	{
		throw std::exception("Can't create window rect");
	}

	_windowClass.reset(new MainWindow::MainWindowClass(windowClassName, windowTitle));

	hWnd = CreateWindowEx(NULL, windowClassName, windowTitle, WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU, CW_USEDEFAULT, CW_USEDEFAULT, 
		wr.right - wr.left, wr.bottom - wr.top, nullptr, nullptr,_windowClass->GetInstance(), this);
	if (hWnd == nullptr)
	{
		throw std::exception("Can't create window rect");
	}

	ShowWindow(hWnd, 10);

}

LRESULT MainWindow::HandleMsgSetup(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	if (msg == WM_NCCREATE)
	{
		const CREATESTRUCTW* const pcreate = reinterpret_cast<CREATESTRUCTW*>(lParam);

		MainWindow* const pWnd = static_cast<MainWindow*>(pcreate->lpCreateParams);

		SetWindowLongPtr(hWnd, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(pWnd));

		SetWindowLongPtr(hWnd, GWLP_WNDPROC, reinterpret_cast<LONG_PTR>(&MainWindow::HandleMsgReady));

		return pWnd->HandleMsg(hWnd, msg, wParam, lParam);
	}
	return DefWindowProc(hWnd, msg, wParam, lParam);
}

LRESULT MainWindow::HandleMsgReady(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) noexcept
{
	MainWindow* const pWnd = reinterpret_cast<MainWindow*>(GetWindowLongPtr(hWnd, GWLP_USERDATA));

	return pWnd->HandleMsg(hWnd, msg, wParam, lParam);
}

LRESULT MainWindow::HandleMsg(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) noexcept
{
#if defined _DEBUG
	static WindowsMessageMap mm;
	std::string str = mm(msg, lParam, wParam);
	OutputDebugString(std::wstring(str.begin(),str.end()).c_str());
#endif
	switch (msg) 
	{
	case WM_CLOSE:
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hWnd, msg, wParam, lParam);

}
