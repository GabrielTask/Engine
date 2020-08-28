#pragma once
#include "Base/Base.h"


extern Tigris::Application* CreateAppication();

int main(int argc, char** argv)
{
	Tigris::Application* app = CreateAppication();
	app->OnUpdate();
	delete app;

	return 0;
}