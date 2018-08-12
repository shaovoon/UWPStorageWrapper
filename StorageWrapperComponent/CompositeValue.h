#pragma once

using namespace Platform;
using namespace Windows::Storage;
using namespace Windows::Foundation;

namespace StorageWrapperComponent
{
	public ref class CompositeValue sealed
	{
	public:
		CompositeValue();
		CompositeValue(ApplicationDataCompositeValue^ composite_value);
		virtual ~CompositeValue();

		bool HasKey(String^ key);
		Platform::Object^ GetValue(String^ key);
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

		Array<Platform::String^>^ GetStringArray(String^ key);
		Array<byte>^ GetUInt8Array(String^ key);
		Array<SHORT>^ GetInt16Array(String^ key);
		Array<USHORT>^ GetUInt16Array(String^ key);
		Array<INT32>^ GetInt32Array(String^ key);
		Array<UINT32>^ GetUInt32Array(String^ key);
		Array<INT64>^ GetInt64Array(String^ key);
		Array<UINT64>^ GetUInt64Array(String^ key);
		Array<float>^ GetFloatArray(String^ key);
		Array<double>^ GetDoubleArray(String^ key);
		Array<bool>^ GetBooleanArray(String^ key);
		Array<wchar_t>^ GetWCharArray(String^ key);

		Array<DateTime>^ GetDateTimeArray(String^ key);
		Array<TimeSpan>^ GetTimeSpanArray(String^ key);
		Array<Guid>^ GetGuidArray(String^ key);
		Array<Point>^ GetPointArray(String^ key);
		Array<Size>^ GetSizeArray(String^ key);
		Array<Rect>^ GetRectArray(String^ key);

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

		void SetStringArray(String^ key, const Array<String^>^ val);
		void SetUInt8Array(String^ key, const Array<byte>^ val);
		void SetInt16Array(String^ key, const Array<SHORT>^ val);
		void SetUInt16Array(String^ key, const Array<USHORT>^ val);
		void SetInt32Array(String^ key, const Array<INT32>^ val);
		void SetUInt32Array(String^ key, const Array<UINT32>^ val);
		void SetInt64Array(String^ key, const Array<INT64>^ val);
		void SetUInt64Array(String^ key, const Array<UINT64>^ val);
		void SetFloatArray(String^ key, const Array<float>^ val);
		void SetDoubleArray(String^ key, const Array<double>^ val);
		void SetBooleanArray(String^ key, const Array<bool>^ val);
		void SetWCharArray(String^ key, const Array<wchar_t>^ val);

		void SetDateTimeArray(String^ key, const Array<DateTime>^ val);
		void SetTimeSpanArray(String^ key, const Array<TimeSpan>^ val);
		void SetGuidArray(String^ key, const Array<Guid>^ val);
		void SetPointArray(String^ key, const Array<Point>^ val);
		void SetSizeArray(String^ key, const Array<Size>^ val);
		void SetRectArray(String^ key, const Array<Rect>^ val);

		ApplicationDataCompositeValue^ GetRawCompositeValue();

	private:

		ApplicationDataCompositeValue^ m_Composite;
	};

}