#include "CaBlockHeader.h"

#define	DoMiniTest

#ifdef DoMiniTest
using namespace MiniTest_NS;
#else
using namespace CABlock_NS;
#endif // DoMiniTest

int main()
{
#ifdef DoMiniTest
	Program* pr = new Program();
	pr->Run();
#else
	CABlock	ca;
	ca.Execute();
#endif // DoMiniTest
}
