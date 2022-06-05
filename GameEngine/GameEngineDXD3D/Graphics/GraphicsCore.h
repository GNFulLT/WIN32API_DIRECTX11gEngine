#pragma once
#ifndef GRAPHICS_CORE_H
#define GRAPHICS_CORE_H

#include "GraphicsCommon.h";
#include <memory>

class GraphicsCore
{
	friend class GraphicsRenderer;

public:
	GraphicsCore(unsigned int width, unsigned int height, HWND hWnd);
	GraphicsCore(const GraphicsCore&) = delete;
	GraphicsCore& operator =(const GraphicsCore&) = delete;

	virtual ~GraphicsCore()
	{
		if (_device)
			_device->Release();
		if (_deviceContext)
			_deviceContext->Release();
		if (_swapChain)
			_swapChain->Release();
		if (_renderTargetView)
			_renderTargetView->Release();
	}
	void Init();
	bool isReady();
private:

	bool _isLoaded;

	std::unique_ptr<GraphicsCommon> _graphCommon;

	ID3D11Device* _device;
	ID3D11DeviceContext* _deviceContext;
	IDXGISwapChain* _swapChain;
	ID3D11RenderTargetView* _renderTargetView;
};


#endif