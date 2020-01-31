#pragma once
#ifdef WIN32
#pragma warning( disable : 4244 )
#pragma warning( disable : 4018 )
#pragma warning( disable : 4102 )
#pragma warning( disable : 4101 )
#pragma warning( disable : 26812 )
#pragma warning( disable : 26495 )
#ifdef	DOTNETLIBRARYSUPPORT_EXPORTS
#define	SUPPORTDLL_EXPORT	__declspec( dllexport )
#else
#define	SUPPORTDLL_EXPORT	__declspec( dllimport )
#endif
#else
#define	SUPPORTDLL_EXPORT	
#endif
#include <DotnetTypes.h>
using namespace DotnetLibrary;

namespace DotnetLibrarySupport
{
	class SUPPORTDLL_EXPORT TranslatorSupport
	{
	public:
		TranslatorSupport() {};
		void	Send(String* message);
		virtual void	RunCode() {

		}
		void	Run();
	private:
	};

	class SUPPORTDLL_EXPORT DataAccess : public TranslatorSupport {
	public:
		DataAccess() {};

	};
}
