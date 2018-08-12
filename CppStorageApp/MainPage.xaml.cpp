//
// MainPage.xaml.cpp
// Implementation of the MainPage class.
//

#include "pch.h"
#include "MainPage.xaml.h"

using namespace CppStorageApp;

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
using namespace StorageWrapperComponent;
using namespace Windows::Storage;

// The Blank Page item template is documented at https://go.microsoft.com/fwlink/?LinkId=402352&clcid=0x409

MainPage::MainPage()
{
	InitializeComponent();
	//RawAPIexample();
	//WrapperAPIexample();
	RawCompositeExample();
	WrapperCompositeExample();
}

void MainPage::RawAPIexample()
{
	Windows::Storage::ApplicationDataContainer^ localSettings =
		Windows::Storage::ApplicationData::Current->LocalSettings;

	localSettings->Values->Insert("RawKey", 123);
	bool exists = localSettings->Values->HasKey("RawKey");
	if (exists)
	{
		Platform::Object^ obj = localSettings->Values->Lookup("RawKey");
		int result = safe_cast<int>(obj);
	}
	localSettings->Values->Clear();
}

void MainPage::WrapperAPIexample()
{
	UWPStorage^ storage = ref new UWPStorage(StorageType::Local);
	storage->SetInt32("WrapperKey", 456);
	bool exists = false;
	int result = storage->GetInt32("WrapperKey", &exists, 444);
	storage->Clear();
}

void MainPage::RawCompositeExample()
{
	Windows::Storage::ApplicationDataContainer^ localSettings =
		Windows::Storage::ApplicationData::Current->LocalSettings;

	// Create a composite setting
	ApplicationDataCompositeValue^ composite = ref new ApplicationDataCompositeValue();
	composite->Insert("intVal", dynamic_cast<PropertyValue^>(PropertyValue::CreateInt32(1212)));
	composite->Insert("strVal", dynamic_cast<PropertyValue^>(PropertyValue::CreateString("string")));

	auto values = localSettings->Values;
	values->Insert("RawCompositeSetting", composite);

	// Read data from a composite setting
	ApplicationDataCompositeValue^ composite2 = safe_cast<ApplicationDataCompositeValue^>(localSettings->Values->Lookup("RawCompositeSetting"));

	if (composite2)
	{
		// Access data in composite2["intVal"] and composite2["strVal"]
		int one = safe_cast<IPropertyValue^>(composite2->Lookup("intVal"))->GetInt32();
		String^ hello = safe_cast<String^>(composite2->Lookup("strVal"));
	}
	// Delete a composite setting
	values->Remove("RawCompositeSetting");
}

void MainPage::WrapperCompositeExample()
{
	UWPStorage^ storage = ref new UWPStorage(StorageType::Local);
	// Create a composite setting
	CompositeValue^ composite = ref new CompositeValue();
	composite->SetInt32("intVal", 3434);
	composite->SetString("strVal", "string");

	storage->SetComposite("WrapperCompositeSetting", composite);

	// Read data from a composite setting
	bool exists = false;
	CompositeValue^ composite2 = storage->GetComposite("WrapperCompositeSetting", &exists);
	if (exists)
	{
		// Access data in composite2["intVal"] and composite2["strVal"]
		int one = composite2->GetInt32("intVal", &exists, 4444);
		String^ hello = composite2->GetString("strVal", &exists, "error");
	}
	// Delete a composite setting
	storage->Remove("WrapperCompositeSetting");
}
