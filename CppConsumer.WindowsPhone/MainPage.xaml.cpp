//
// MainPage.xaml.cpp
// Implementation of the MainPage class.
//

#include "pch.h"
#include "MainPage.xaml.h"
#include "../SharedObject/SharedObject.Shared/SharedObject.h"

using namespace CppConsumer_WindowsPhone;

using namespace Platform;
using namespace Windows::Foundation;
using namespace Windows::Foundation::Collections;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::UI::Xaml::Controls::Primitives;
using namespace Windows::UI::Xaml::Data;
using namespace Windows::UI::Xaml::Input;
using namespace Windows::UI::Xaml::Media;
using namespace Windows::UI::Xaml::Navigation;

// The Blank Page item template is documented at http://go.microsoft.com/fwlink/?LinkId=234238
typedef const char*(*GetStringFnType)();

MainPage::MainPage()
{
	auto mod = LoadPackagedLibrary(L"SharedObject.Windows.dll", 0);
	if (mod == nullptr)
	{
		auto err = GetLastError();
	}
	else
	{
		auto proc = (GetStringFnType)GetProcAddress(mod, "GetTemplateInfo2");
		if (proc != nullptr)
		{
			auto result = proc();
			printf(result);
		}

		FreeLibrary(mod);
	}

	//const char *str = GetTemplateInfo2();
	
	InitializeComponent();
}

/// <summary>
/// Invoked when this page is about to be displayed in a Frame.
/// </summary>
/// <param name="e">Event data that describes how this page was reached.  The Parameter
/// property is typically used to configure the page.</param>
void MainPage::OnNavigatedTo(NavigationEventArgs^ e)
{
	(void) e;	// Unused parameter


	// TODO: Prepare page for display here.

	// TODO: If your application contains multiple pages, ensure that you are
	// handling the hardware Back button by registering for the
	// Windows::Phone::UI::Input::HardwareButtons.BackPressed event.
	// If you are using the NavigationHelper provided by some templates,
	// this event is handled for you.
}

const char *GetText()
{
	auto mod = LoadPackagedLibrary(L"SharedObject.Windows.dll", 0);
	if (mod == nullptr)
	{
		auto err = GetLastError();
	}
	else
	{
		auto proc = (GetStringFnType) GetProcAddress(mod, "GetTemplateInfo2");
		if (proc != nullptr)
		{
			auto result = proc();
			return result;
		}

		FreeLibrary(mod);
	}
	return "";
}

void CppConsumer_WindowsPhone::MainPage::Button_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	// Convert to wide char string
	static wchar_t buffer[128];
	size_t converted;
	mbstowcs_s(&converted, buffer, GetText(), 128);
	bigButton->Content = ref new Platform::String(buffer);
}
