#include "GameEngine.h"

#include <d3d11.h>

std::unique_ptr<GameEngine> GameEngine::_gameEngine;

GameEngine::GameEngine(unsigned int width, unsigned int height, const wchar_t* windowClassName,const wchar_t* windowTitle) noexcept : m_isReady(true),
m_isStarted(true)
{
	MainWindow::CreateMainWindow(width, height, windowClassName, windowTitle);
	this->m_window = MainWindow::GetInstance()->hWnd;

	unsigned int creationFlags = 0;

#ifdef _DEBUG
	creationFlags |= D3D11_CREATE_DEVICE_DEBUG;
#endif
}

GameEngine* const GameEngine::GetInstance() noexcept
{
	return _gameEngine.get();
}

void GameEngine::StartEngine(unsigned int width, unsigned int height, const wchar_t* windowClassName,const wchar_t* windowTitle)
{
	if (_gameEngine)
		if (_gameEngine->m_isStarted)
			return;

	_gameEngine.reset(new GameEngine(width,height,windowClassName,windowTitle));
	
	_gameEngine->_graphCore.reset(new GraphicsCore(width, height, _gameEngine->m_window));

	_gameEngine->_graphCore->Init();

	_gameEngine->_graphRender.reset(new GraphicsRenderer(_gameEngine->_graphCore.get()));
	
}

bool GameEngine::IsReady()
{
	return m_isReady;
}

int GameEngine::Run()
{
	while (true)
	{
		if (auto code = ProcessWindowMessage())
		{
			return *code;
		}
	
	}
}

std::optional<int> GameEngine::ProcessWindowMessage()
{
	MSG msg;

	while (PeekMessage(&msg, 0, 0, 0, PM_REMOVE))
	{
		if (msg.message == WM_QUIT)
			return msg.message;

		TranslateMessage(&msg);
		DispatchMessage(&msg);

	}
	_graphRender->Render();
	
	return {};
}