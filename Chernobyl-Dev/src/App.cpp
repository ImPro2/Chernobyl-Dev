#include "CoreEngine.h"

int main()
{
	CH::Application* app = new CH::Application();

	while (app->GetRunState())
	{
		app->OnUpdate();
	}

	return 0;
}