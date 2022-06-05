#pragma once
#ifndef GNF_MAINWINDOW
#define GNF_MAINWINDOW

#include <Windows.h>
#include <memory>

class MainWindow
{
	friend class GameEngine;
private:
	static void CreateMainWindow(unsigned int width, unsigned int height, const wchar_t* windowName, const wchar_t* windowTitle) noexcept;
	static const MainWindow* const GetInstance() noexcept;
private:
	static LRESULT CALLBACK HandleMsgSetup(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
	static LRESULT CALLBACK HandleMsgReady(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) noexcept;
	LRESULT HandleMsg(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) noexcept;

private:
	explicit MainWindow(unsigned int width, unsigned int height, const wchar_t* windowClassName, const wchar_t* windowTitle);
	MainWindow(const MainWindow&) = delete;
	MainWindow& operator=(const MainWindow&) = delete;


private:
	class MainWindowClass
	{
	public:
		explicit MainWindowClass(const wchar_t* windowClassName, const wchar_t* windowTitle);
		MainWindowClass(const MainWindowClass&) = delete;
		virtual ~MainWindowClass();
		HINSTANCE GetInstance() const noexcept;
	public:
		const wchar_t* _windowClassName;
		const wchar_t* _windowTitle;
		HINSTANCE hInst;
	};
private:
	static std::unique_ptr<MainWindow> _window;
	std::unique_ptr<MainWindowClass> _windowClass;
	unsigned int _width;
	unsigned int _height;
	HWND hWnd;
};

#endif