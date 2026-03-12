#pragma once

#include <imgui.h>

class UI
{
public:
	bool Init();

	void Render();

private:
	ImFont* titleFont = nullptr;
};