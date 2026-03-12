#include "UI.h"
#include <iostream>

bool UI::Init()
{
	ImGuiIO& io = ImGui::GetIO();

	titleFont = io.Fonts->AddFontFromFileTTF(
		"resources/fonts/Roboto-Bold.ttf",
		35.0f
	);
	if (!titleFont)
	{
		std::cerr << "Failed to load file" << std::endl;
		return false;
	}
	return true;
}

void UI::Render()
{
	ImGui::Begin("Window Demo");

	ImGui::Text("Hello DearImGui");

	ImGui::End();
}
