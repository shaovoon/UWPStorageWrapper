#include "pch.h"
#include "UWPStorage.h"

namespace StorageWrapperComponent
{

	UWPStorage::UWPStorage(StorageType storage_type) : m_StorageType(storage_type)
	{
		if (m_StorageType == StorageType::Local)
		{
			m_ApplicationDataContainer = GetLocalSettings();
			m_StorageFolder = GetLocalFolder();
		}
		else if (m_StorageType == StorageType::Roaming)
		{
			m_ApplicationDataContainer = GetRoamingSettings();
			m_StorageFolder = GetRoamingFolder();
		}
	}

	UWPStorage::~UWPStorage()
	{
	}

	Windows::Storage::ApplicationDataContainer^ UWPStorage::GetSettings()
	{
		return m_ApplicationDataContainer;
	}
	Windows::Storage::ApplicationDataContainer^ UWPStorage::GetLocalSettings()
	{
		return Windows::Storage::ApplicationData::Current->LocalSettings;
	}
	Windows::Storage::ApplicationDataContainer^ UWPStorage::GetRoamingSettings()
	{
		return Windows::Storage::ApplicationData::Current->RoamingSettings;
	}

	Windows::Storage::StorageFolder^ UWPStorage::GetFolder()
	{
		return m_StorageFolder;
	}
	Windows::Storage::StorageFolder^ UWPStorage::GetLocalFolder()
	{
		return Windows::Storage::ApplicationData::Current->LocalFolder;
	}
	Windows::Storage::StorageFolder^ UWPStorage::GetRoamingFolder()
	{
		return Windows::Storage::ApplicationData::Current->RoamingFolder;
	}

	bool UWPStorage::HasKey(String^ key)
	{
		return GetSettings()->Values->HasKey(key);
	}

	Platform::Object^ UWPStorage::GetValue(String^ key)
	{
		return GetSettings()->Values->Lookup(key);
	}

	void UWPStorage::Remove(String^ key)
	{
		GetSettings()->Values->Remove(key);
	}

	void UWPStorage::Clear()
	{
		GetSettings()->Values->Clear();
	}

	Platform::String^ UWPStorage::GetString(String^ key, bool* exists, Platform::String^ default_value)
	{
		*exists = HasKey(key);
		if (*exists == false)
			return default_value;

		Platform::Object^ obj = GetValue(key);
		return obj->ToString();
	}

	byte UWPStorage::GetUInt8(String^ key, bool* exists, byte default_value)
	{
		*exists = HasKey(key);
		if (*exists == false)
			return default_value;

		Platform::Object^ obj = GetValue(key);
		return safe_cast<byte>(obj); // throws Platform::InvalidCastException
	}
	SHORT UWPStorage::GetInt16(String^ key, bool* exists, SHORT default_value)
	{
		*exists = HasKey(key);
		if (*exists == false)
			return default_value;

		Platform::Object^ obj = GetValue(key);
		return safe_cast<SHORT>(obj); // throws Platform::InvalidCastException
	}
	USHORT UWPStorage::GetUInt16(String^ key, bool* exists, USHORT default_value)
	{
		*exists = HasKey(key);
		if (*exists == false)
			return default_value;

		Platform::Object^ obj = GetValue(key);
		return safe_cast<USHORT>(obj); // throws Platform::InvalidCastException
	}
	INT32 UWPStorage::GetInt32(String^ key, bool* exists, INT32 default_value)
	{
		*exists = HasKey(key);
		if (*exists == false)
			return default_value;

		Platform::Object^ obj = GetValue(key);
		return safe_cast<INT32>(obj); // throws Platform::InvalidCastException
	}
	UINT32 UWPStorage::GetUInt32(String^ key, bool* exists, UINT32 default_value)
	{
		*exists = HasKey(key);
		if (*exists == false)
			return default_value;

		Platform::Object^ obj = GetValue(key);
		return safe_cast<UINT32>(obj); // throws Platform::InvalidCastException
	}
	INT64 UWPStorage::GetInt64(String^ key, bool* exists, INT64 default_value)
	{
		*exists = HasKey(key);
		if (*exists == false)
			return default_value;

		Platform::Object^ obj = GetValue(key);
		return safe_cast<INT64>(obj); // throws Platform::InvalidCastException
	}
	UINT64 UWPStorage::GetUInt64(String^ key, bool* exists, UINT64 default_value)
	{
		*exists = HasKey(key);
		if (*exists == false)
			return default_value;

		Platform::Object^ obj = GetValue(key);
		return safe_cast<UINT64>(obj); // throws Platform::InvalidCastException
	}
	float UWPStorage::GetFloat(String^ key, bool* exists, float default_value)
	{
		*exists = HasKey(key);
		if (*exists == false)
			return default_value;

		Platform::Object^ obj = GetValue(key);
		return safe_cast<float>(obj); // throws Platform::InvalidCastException
	}
	double UWPStorage::GetDouble(String^ key, bool* exists, double default_value)
	{
		*exists = HasKey(key);
		if (*exists == false)
			return default_value;

		Platform::Object^ obj = GetValue(key);
		return safe_cast<double>(obj); // throws Platform::InvalidCastException
	}
	bool UWPStorage::GetBoolean(String^ key, bool* exists, bool default_value)
	{
		*exists = HasKey(key);
		if (*exists == false)
			return default_value;

		Platform::Object^ obj = GetValue(key);
		return safe_cast<bool>(obj); // throws Platform::InvalidCastException
	}
	wchar_t UWPStorage::GetWChar(String^ key, bool* exists, wchar_t default_value)
	{
		*exists = HasKey(key);
		if (*exists == false)
			return default_value;

		Platform::Object^ obj = GetValue(key);
		return safe_cast<wchar_t>(obj); // throws Platform::InvalidCastException
	}
	DateTime UWPStorage::GetDateTime(String^ key, bool* exists, DateTime default_value)
	{
		*exists = HasKey(key);
		if (*exists == false)
			return default_value;

		Platform::Object^ obj = GetValue(key);
		return safe_cast<DateTime>(obj); // throws Platform::InvalidCastException
	}
	TimeSpan UWPStorage::GetTimeSpan(String^ key, bool* exists, TimeSpan default_value)
	{
		*exists = HasKey(key);
		if (*exists == false)
			return default_value;

		Platform::Object^ obj = GetValue(key);
		return safe_cast<TimeSpan>(obj); // throws Platform::InvalidCastException
	}
	Guid UWPStorage::GetGuid(String^ key, bool* exists, Guid default_value)
	{
		*exists = HasKey(key);
		if (*exists == false)
			return default_value;

		Platform::Object^ obj = GetValue(key);
		return safe_cast<Guid>(obj); // throws Platform::InvalidCastException
	}
	Point UWPStorage::GetPoint(String^ key, bool* exists, Point default_value)
	{
		*exists = HasKey(key);
		if (*exists == false)
			return default_value;

		Platform::Object^ obj = GetValue(key);
		return safe_cast<Point>(obj); // throws Platform::InvalidCastException
	}
	Size UWPStorage::GetSize(String^ key, bool* exists, Size default_value)
	{
		*exists = HasKey(key);
		if (*exists == false)
			return default_value;

		Platform::Object^ obj = GetValue(key);
		return safe_cast<Size>(obj); // throws Platform::InvalidCastException
	}
	Rect UWPStorage::GetRect(String^ key, bool* exists, Rect default_value)
	{
		*exists = HasKey(key);
		if (*exists == false)
			return default_value;

		Platform::Object^ obj = GetValue(key);
		return safe_cast<Rect>(obj); // throws Platform::InvalidCastException
	}
	ApplicationDataCompositeValue^ UWPStorage::GetRawComposite(String^ key, bool* exists, ApplicationDataCompositeValue^ default_value)
	{
		*exists = HasKey(key);
		if (*exists == false)
			return default_value;

		Platform::Object^ obj = GetValue(key);
		return safe_cast<ApplicationDataCompositeValue^>(obj); // throws Platform::InvalidCastException
	}

	CompositeValue^ UWPStorage::GetComposite(String^ key, bool* exists)
	{
		ApplicationDataCompositeValue^ raw_composite = GetRawComposite(key, exists, nullptr);

		if(*exists)
			return ref new CompositeValue(raw_composite);

		return nullptr;
	}

	void UWPStorage::SetValue(String^ key, Platform::Object^ obj)
	{
		GetSettings()->Values->Insert(key, obj);
	}

	void UWPStorage::SetString(String^ key, String^ val)
	{
		SetValue(key, val);
	}

	void UWPStorage::SetUInt8(String^ key, byte val)
	{
		SetValue(key, val);
	}
	void UWPStorage::SetInt16(String^ key, SHORT val)
	{
		SetValue(key, val);
	}
	void UWPStorage::SetUInt16(String^ key, USHORT val)
	{
		SetValue(key, val);
	}
	void UWPStorage::SetInt32(String^ key, INT32 val)
	{
		SetValue(key, val);
	}
	void UWPStorage::SetUInt32(String^ key, UINT32 val)
	{
		SetValue(key, val);
	}
	void UWPStorage::SetInt64(String^ key, INT64 val)
	{
		SetValue(key, val);
	}
	void UWPStorage::SetUInt64(String^ key, UINT64 val)
	{
		SetValue(key, val);
	}
	void UWPStorage::SetFloat(String^ key, float val)
	{
		SetValue(key, val);
	}
	void UWPStorage::SetDouble(String^ key, double val)
	{
		SetValue(key, val);
	}
	void UWPStorage::SetBoolean(String^ key, bool val)
	{
		SetValue(key, val);
	}
	void UWPStorage::SetWChar(String^ key, wchar_t val)
	{
		SetValue(key, val);
	}
	void UWPStorage::SetDateTime(String^ key, DateTime val)
	{
		SetValue(key, val);
	}
	void UWPStorage::SetTimeSpan(String^ key, TimeSpan val)
	{
		SetValue(key, val);
	}
	void UWPStorage::SetGuid(String^ key, Guid val)
	{
		SetValue(key, val);
	}
	void UWPStorage::SetPoint(String^ key, Point val)
	{
		SetValue(key, val);
	}
	void UWPStorage::SetSize(String^ key, Size val)
	{
		SetValue(key, val);
	}
	void UWPStorage::SetRect(String^ key, Rect val)
	{
		SetValue(key, val);
	}
	void UWPStorage::SetRawComposite(String^ key, ApplicationDataCompositeValue^ val)
	{
		SetValue(key, val);
	}
	void UWPStorage::SetComposite(String^ key, CompositeValue^ val)
	{
		SetRawComposite(key, val->GetRawCompositeValue());
	}


}