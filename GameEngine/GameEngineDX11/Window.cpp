#include "Window.h"
#include "WindowsMessageMap.h"
Window::WindowClass Window::WindowClass::wndClass;

Window::WindowClass::WindowClass() noexcept : hInst(GetModuleHandle(nullptr))
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
	wc.lpszClassName = GetName();
	wc.lpszMenuName = nullptr;
	RegisterClassEx(&wc);
}

Window::WindowClass::~WindowClass() {
	UnregisterClass(wndClassName, GetInstance());
}
const char* Window::WindowClass::GetName() noexcept {
	return wndClassName;
}
HINSTANCE Window::WindowClass::GetInstance() noexcept {
	return wndClass.hInst;
}
Window::Window(int width,int height,const char* name) noexcept {

	RECT wr;
	wr.left = 100;
	wr.top = 100;
	wr.right = width + wr.left;
	wr.bottom = height + wr.top;
	AdjustWindowRect(&wr, WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU, FALSE);

	hWnd = CreateWindow(WindowClass::GetName(), name, WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU, CW_USEDEFAULT, CW_USEDEFAULT, wr.right - wr.left, wr.bottom - wr.top,
		nullptr, nullptr, WindowClass::GetInstance(), this);
	
	ShowWindow(hWnd, SW_SHOWDEFAULT);

	this->height = height;
	this->width = width;
}

Window::~Window() {
	DestroyWindow(hWnd);
}

LRESULT WINAPI Window::HandleMsgSetup(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) noexcept
{
	if (msg == WM_NCCREATE) 
	{
		const CREATESTRUCTW* const pcreate = reinterpret_cast<CREATESTRUCTW*>(lParam);

		Window* const pWnd = static_cast<Window*>(pcreate->lpCreateParams);

		SetWindowLongPtr(hWnd, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(pWnd));

		SetWindowLongPtr(hWnd, GWLP_WNDPROC, reinterpret_cast<LONG_PTR>(&Window::HandleMsgThunk));

		return pWnd->HandleMsg(hWnd, msg, wParam, lParam);
	}
	return DefWindowProc(hWnd, msg, wParam, lParam);
}

LRESULT WINAPI Window::HandleMsgThunk(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) noexcept 
{
	Window* const pWnd = reinterpret_cast<Window*>(GetWindowLongPtr(hWnd,GWLP_USERDATA));

	return pWnd->HandleMsg(hWnd, msg, wParam, lParam);
}
LRESULT Window::HandleMsg(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) noexcept
{
#if defined _DEBUG
	static WindowsMessageMap mm;
	OutputDebugString(mm(msg, lParam, wParam).c_str());
#endif
	switch (msg) {
	case WM_CLOSE:
		PostQuitMessage(0);
		return 0;
	case WM_CHAR:
		static std::string title;
		char sendedChar = (char)wParam;
		if (sendedChar == VK_BACK) {
			title.pop_back();
		}
		else {
			title.push_back(sendedChar);
		}
		SetWindowText(hWnd, title.c_str());
		break;

	}
	return DefWindowProc(hWnd, msg, wParam, lParam);
}
