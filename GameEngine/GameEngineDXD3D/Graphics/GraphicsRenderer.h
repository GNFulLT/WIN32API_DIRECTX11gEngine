#pragma once
#ifndef GRAPHICS_RENDERER_H
#define GRAPHICS_RENDERER_H

#include "GraphicsCore.h"

class GraphicsRenderer
{
public:
	GraphicsRenderer(GraphicsCore* core);
	GraphicsRenderer(const GraphicsRenderer&) = delete;
	GraphicsRenderer& operator = (const GraphicsRenderer&) = delete;

	void Render();
	void CleanUpBg(float r, float g,float b,float a);

private:
	GraphicsCore* _core;

};

#endif