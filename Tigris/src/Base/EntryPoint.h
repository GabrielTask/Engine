#pragma once
#include "Base/Base.h"


extern Tigris::Application* CreateApplication();

int main(int argc, char** argv)
{
	Tigris::Application* app = CreateApplication();
	app->OnUpdate();
	delete app;

	return 0;
}