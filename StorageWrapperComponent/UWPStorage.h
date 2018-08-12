#pragma once

#include "CompositeValue.h"

using namespace Platform;
using namespace Windows::Storage;
using namespace Windows::Foundation;

namespace StorageWrapperComponent
{
	public enum class StorageType : int { Local, Roaming };

	public ref class UWPStorage sealed
	{
	public:
		UWPStorage(StorageType storage_type);
		virtual ~UWPStorage();

		static Windows::Storage::ApplicationDataContainer^ GetLocalSettings();
		static Windows::Storage::ApplicationDataContainer^ GetRoamingSettings();

		static Windows::Storage::StorageFolder^ GetLocalFolder();
		static Windows::Storage::StorageFolder^ GetRoamingFolder();

		StorageType GetStorageType() { return m_StorageType; }

		bool HasKey(String^ key);
		Platform::Object^ GetValue(String^ key);
		void SetValue(String^ key, Platform::Object^ obj);
		void Remove(String^ key);
		void Clear(); // RemoveAll

		Platform::String^ GetString(String^ key, bool* exists, Platform::String^ default_value);

		byte GetUInt8(String^ key, bool* exists, byte default_value);
		SHORT GetInt16(String^ key, bool* exists, SHORT default_value);
		USHORT GetUInt16(String^ key, bool* exists, USHORT default_value);
		INT32 GetInt32(String^ key, bool* exists, INT32 default_value);
		UINT32 GetUInt32(String^ key, bool* exists, UINT32 default_value);
		INT64 GetInt64(String^ key, bool* exists, INT64 default_value);
		UINT64 GetUInt64(String^ key, bool* exists, UINT64 default_value);
		float GetFloat(String^ key, bool* exists, float default_value);
		double GetDouble(String^ key, bool* exists, double default_value);
		bool GetBoolean(String^ key, bool* exists, bool default_value);
		wchar_t GetWChar(String^ key, bool* exists, wchar_t default_value);

		DateTime GetDateTime(String^ key, bool* exists, DateTime default_value);
		TimeSpan GetTimeSpan(String^ key, bool* exists, TimeSpan default_value);
		Guid GetGuid(String^ key, bool* exists, Guid default_value);
		Point GetPoint(String^ key, bool* exists, Point default_value);
		Size GetSize(String^ key, bool* exists, Size default_value);
		Rect GetRect(String^ key, bool* exists, Rect default_value);

		ApplicationDataCompositeValue^ GetRawComposite(String^ key, bool* exists, ApplicationDataCompositeValue^ default_value);
		CompositeValue^ GetComposite(String^ key, bool* exists);

		void SetString(String^ key, String^ val);
		void SetUInt8(String^ key, byte val);
		void SetInt16(String^ key, SHORT val);
		void SetUInt16(String^ key, USHORT val);
		void SetInt32(String^ key, INT32 val);
		void SetUInt32(String^ key, UINT32 val);
		void SetInt64(String^ key, INT64 val);
		void SetUInt64(String^ key, UINT64 val);
		void SetFloat(String^ key, float val);
		void SetDouble(String^ key, double val);
		void SetBoolean(String^ key, bool val);
		void SetWChar(String^ key, wchar_t val);

		void SetDateTime(String^ key, DateTime val);
		void SetTimeSpan(String^ key, TimeSpan val);
		void SetGuid(String^ key, Guid val);
		void SetPoint(String^ key, Point val);
		void SetSize(String^ key, Size val);
		void SetRect(String^ key, Rect val);
		void SetRawComposite(String^ key, ApplicationDataCompositeValue^ val);
		void SetComposite(String^ key, CompositeValue^ val);

	private:
		Windows::Storage::ApplicationDataContainer^ GetSettings();
		Windows::Storage::StorageFolder^ GetFolder();

		StorageType m_StorageType;
		Windows::Storage::ApplicationDataContainer^ m_ApplicationDataContainer;
		Windows::Storage::StorageFolder^ m_StorageFolder;
	};

}