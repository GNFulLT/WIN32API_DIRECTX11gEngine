#pragma once
#ifndef GAME_ENGINE_H
#define GAME_ENGINE_H

#include "../MainWindow/MainWindow.h"
#include <optional>
#include "../Graphics/GraphicsCore.h";
#include "../Graphics/GraphicsRenderer.h"
class GameEngine 
{
public:
	static void StartEngine(unsigned int width, unsigned int height, const wchar_t* windowClassName, const wchar_t* windowTitle);
	static GameEngine* const GetInstance() noexcept;
public:
	bool IsReady();
	int Run();
private:
	GameEngine(unsigned int width, unsigned int height, const wchar_t* windowClassName, const wchar_t* windowTitle) noexcept;
	GameEngine(const GameEngine&) = delete;
	GameEngine& operator =(const GameEngine&) = delete;
    std::optional<int> ProcessWindowMessage();

private:
	static std::unique_ptr<GameEngine> _gameEngine;
	std::unique_ptr<GraphicsCore> _graphCore;
	std::unique_ptr<GraphicsRenderer> _graphRender;

private:
	bool m_isStarted;
	HWND m_window;
	bool m_isReady;


};

#endif