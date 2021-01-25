#include "CoreEngine.h"

int main()
{
	CH::Application::OnCreate();

	while (CH::Application::GetRunState())
	{
		CH::Application::OnUpdate();
	}

	CH::Application::OnDestroy();
	return 0;
}