#include "pch.h"

#include "World.h"

int main()
{
	shared_ptr<World> world = make_shared<World>();

	while (true)
	{
		world->Update();

		if (world->End())
			break;
	}

	return 0;
}