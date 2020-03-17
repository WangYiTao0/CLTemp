#include "App.h"

void Main()
{
	App app;

	while (System::Update())
	{
		app.Update();
		app.Draw();
	}
}


