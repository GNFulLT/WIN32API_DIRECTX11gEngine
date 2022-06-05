#include "GraphicsCore.h"
#include <wrl.h>

GraphicsCore::GraphicsCore(unsigned int width, unsigned int height, HWND hWnd)
{
	_graphCommon.reset(new GraphicsCommon(width, height, hWnd));
}


void GraphicsCore::Init()
{

	HRESULT result;

	unsigned int driver = 0;

	//Informations that is needed to create D3D11 Device are initializing
	_graphCommon->Init();

	//If informations didn't initialized correctly throw an error
	if (!_graphCommon->IsReady())
		throw std::exception("sa");


	//Creates device
	result = D3D11CreateDeviceAndSwapChain(_graphCommon->_adapter, _graphCommon->_driverType, _graphCommon->_module, _graphCommon->_creationFlags, &(_graphCommon->_featureLevel),
		1, _graphCommon->_sdkVersion, _graphCommon->_swapChainDesc, &(this->_swapChain), &(this->_device),NULL,&(this->_deviceContext));

	//Checks there is an error
	if (result == S_OK)
		_isLoaded = true;

	Microsoft::WRL::ComPtr<ID3D11Texture2D> backBuffer;
	result = _swapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), &backBuffer);

	if (result != S_OK)
		throw std::exception("cant get backbuffer");

	result = _device->CreateRenderTargetView(backBuffer.Get(), nullptr, &(this->_renderTargetView));

}

bool GraphicsCore::isReady()
{
	return _isLoaded;
}