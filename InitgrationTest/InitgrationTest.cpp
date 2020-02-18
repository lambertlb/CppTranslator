#include "TranslatedHeader.h"
#include <cstdlib>

//#define	DoMiniTest

#ifdef DoMiniTest
using namespace MiniTest_NS;
#else
using namespace CppTranslatorFeatureTest_NS;
#endif // DoMiniTest

int main()
{
#ifdef DoMiniTest
	Program* pr = new Program();
	pr->Run();
#else
	FeatureTest	featureTest;
	featureTest.Run();
#endif // DoMiniTest
}
