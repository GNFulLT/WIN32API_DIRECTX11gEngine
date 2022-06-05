#include "GraphicsRenderer.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

GraphicsRenderer::GraphicsRenderer(GraphicsCore* core) : _core(core)
{
	srand(time(0));
}


void GraphicsRenderer::Render()
{
	//Set New Target as the active object
	_core->_deviceContext->OMSetRenderTargets(1, &(_core->_renderTargetView), nullptr);
	
	CleanUpBg(0,0,0,1.0f);

	//Swap beetween back and front buffer
	_core->_swapChain->Present(1, 0);
}

void GraphicsRenderer::CleanUpBg(float r,float b,float g,float a)
{
	float color[4] = { r, g, b,a };

	_core->_deviceContext->ClearRenderTargetView((_core->_renderTargetView), color);
}