#include <stdlib.h>
#include <iostream>

#include "SDLWrappers/App.h"

using namespace jer;
using namespace std;

class TestRunnable: public Runnable
{
public:
	const SUCCESS run() override
	{
		cout<<"Running the Application"<<endl;
		return SUCCEEDED;
	}
};

int main(int argc, char **argv)
{
	TestRunnable myTest;
	App::GetApp().setApp(&myTest);
	return App::GetApp().run();
}