#include "GraphicsCommon.h"


GraphicsCommon::GraphicsCommon(unsigned int width, unsigned int height, HWND hWnd) : _width(width),_height(height),_hWnd(hWnd)
{

}


void GraphicsCommon::Init()
{
	//Chain Descriptor

	DXGI_SWAP_CHAIN_DESC swapChainDesc;
	ZeroMemory(&swapChainDesc, sizeof(swapChainDesc));
	swapChainDesc.BufferCount = 1;
	swapChainDesc.BufferDesc.Width = _width;
	swapChainDesc.BufferDesc.Height = _height;
	swapChainDesc.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	swapChainDesc.BufferDesc.RefreshRate.Numerator = 60;
	swapChainDesc.BufferDesc.RefreshRate.Denominator = 1;
	swapChainDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
	swapChainDesc.OutputWindow = _hWnd;
	swapChainDesc.Windowed = true;
	swapChainDesc.SampleDesc.Count = 1;
	swapChainDesc.SampleDesc.Quality = 0;

	_swapChainDesc = new DXGI_SWAP_CHAIN_DESC(swapChainDesc);

	//GlAdapter
	_adapter = NULL;

	//Driver Type

	_driverType = D3D_DRIVER_TYPE_HARDWARE;

	//HModule

	if (_driverType != D3D_DRIVER_TYPE_SOFTWARE)
		_module = nullptr;

	


	 
	_creationFlags = 0;
#ifdef _DEBUG
	_creationFlags |= D3D11_CREATE_DEVICE_DEBUG;
#endif
	_featureLevel = D3D_FEATURE_LEVEL_11_0;

	_isLoaded = true;
}

bool GraphicsCommon::IsReady()
{
	return _isLoaded;
}