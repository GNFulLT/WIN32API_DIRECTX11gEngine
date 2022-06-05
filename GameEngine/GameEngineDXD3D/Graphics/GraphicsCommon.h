#pragma once
#ifndef GRAPHICS_COMMON_H
#define GRAPHICS_COMMON_H

#include <d3d11.h>
#pragma comment(lib,"d3d11.lib")



class GraphicsCommon
{

	friend class GraphicsCore;
public:
	GraphicsCommon(unsigned int width, unsigned int height,HWND hWnd);
	virtual ~GraphicsCommon()
	{
		delete _swapChainDesc;
	};
	void Init();
	bool IsReady();
private:
	bool _isLoaded;

	unsigned int _width;
	unsigned int _height;

	unsigned int _creationFlags;

	HWND _hWnd;

	HMODULE _module;

	const UINT _sdkVersion = D3D11_SDK_VERSION;

	D3D_DRIVER_TYPE _driverType;

private:

	IDXGIAdapter* _adapter;


	D3D_FEATURE_LEVEL _featureLevel;

	DXGI_SWAP_CHAIN_DESC* _swapChainDesc;
		
};

#endif