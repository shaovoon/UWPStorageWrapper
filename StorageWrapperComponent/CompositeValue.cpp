#include "pch.h"
#include "CompositeValue.h"

namespace StorageWrapperComponent
{
	CompositeValue::CompositeValue() : m_Composite(ref new ApplicationDataCompositeValue())
	{
	}

	CompositeValue::CompositeValue(ApplicationDataCompositeValue^ composite_value) : m_Composite(composite_value)
	{
	}

	CompositeValue::~CompositeValue()
	{
	}

	ApplicationDataCompositeValue^ CompositeValue::GetRawCompositeValue()
	{
		return m_Composite;
	}

	bool CompositeValue::HasKey(String^ key)
	{
		return m_Composite->HasKey(key);
	}

	Platform::Object^ CompositeValue::GetValue(String^ key)
	{
		return m_Composite->Lookup(key);
	}

	void CompositeValue::Remove(String^ key)
	{
		m_Composite->Remove(key);
	}

	void CompositeValue::Clear()
	{
		m_Composite->Clear();
	}

	Platform::String^ CompositeValue::GetString(String^ key, bool* exists, Platform::String^ default_value)
	{
		*exists = HasKey(key);
		if (*exists == false)
			return default_value;

		return safe_cast<String^>(GetValue(key));
	}

	byte CompositeValue::GetUInt8(String^ key, bool* exists, byte default_value)
	{
		*exists = HasKey(key);
		if (*exists == false)
			return default_value;

		return safe_cast<IPropertyValue^>(GetValue(key))->GetUInt8(); // throws Platform::InvalidCastException
	}
	SHORT CompositeValue::GetInt16(String^ key, bool* exists, SHORT default_value)
	{
		*exists = HasKey(key);
		if (*exists == false)
			return default_value;

		return safe_cast<IPropertyValue^>(GetValue(key))->GetInt16(); // throws Platform::InvalidCastException
	}
	USHORT CompositeValue::GetUInt16(String^ key, bool* exists, USHORT default_value)
	{
		*exists = HasKey(key);
		if (*exists == false)
			return default_value;

		return safe_cast<IPropertyValue^>(GetValue(key))->GetUInt16(); // throws Platform::InvalidCastException
	}
	INT32 CompositeValue::GetInt32(String^ key, bool* exists, INT32 default_value)
	{
		*exists = HasKey(key);
		if (*exists == false)
			return default_value;

		return safe_cast<IPropertyValue^>(GetValue(key))->GetInt32(); // throws Platform::InvalidCastException
	}
	UINT32 CompositeValue::GetUInt32(String^ key, bool* exists, UINT32 default_value)
	{
		*exists = HasKey(key);
		if (*exists == false)
			return default_value;

		return safe_cast<IPropertyValue^>(GetValue(key))->GetUInt32(); // throws Platform::InvalidCastException
	}
	INT64 CompositeValue::GetInt64(String^ key, bool* exists, INT64 default_value)
	{
		*exists = HasKey(key);
		if (*exists == false)
			return default_value;

		return safe_cast<IPropertyValue^>(GetValue(key))->GetInt64(); // throws Platform::InvalidCastException
	}
	UINT64 CompositeValue::GetUInt64(String^ key, bool* exists, UINT64 default_value)
	{
		*exists = HasKey(key);
		if (*exists == false)
			return default_value;

		return safe_cast<IPropertyValue^>(GetValue(key))->GetUInt64(); // throws Platform::InvalidCastException
	}
	float CompositeValue::GetFloat(String^ key, bool* exists, float default_value)
	{
		*exists = HasKey(key);
		if (*exists == false)
			return default_value;

		return safe_cast<IPropertyValue^>(GetValue(key))->GetSingle(); // throws Platform::InvalidCastException
	}
	double CompositeValue::GetDouble(String^ key, bool* exists, double default_value)
	{
		*exists = HasKey(key);
		if (*exists == false)
			return default_value;

		return safe_cast<IPropertyValue^>(GetValue(key))->GetDouble(); // throws Platform::InvalidCastException
	}
	bool CompositeValue::GetBoolean(String^ key, bool* exists, bool default_value)
	{
		*exists = HasKey(key);
		if (*exists == false)
			return default_value;

		return safe_cast<IPropertyValue^>(GetValue(key))->GetBoolean(); // throws Platform::InvalidCastException
	}
	wchar_t CompositeValue::GetWChar(String^ key, bool* exists, wchar_t default_value)
	{
		*exists = HasKey(key);
		if (*exists == false)
			return default_value;

		return safe_cast<IPropertyValue^>(GetValue(key))->GetChar16(); // throws Platform::InvalidCastException
	}
	DateTime CompositeValue::GetDateTime(String^ key, bool* exists, DateTime default_value)
	{
		*exists = HasKey(key);
		if (*exists == false)
			return default_value;

		return safe_cast<IPropertyValue^>(GetValue(key))->GetDateTime(); // throws Platform::InvalidCastException
	}
	TimeSpan CompositeValue::GetTimeSpan(String^ key, bool* exists, TimeSpan default_value)
	{
		*exists = HasKey(key);
		if (*exists == false)
			return default_value;

		return safe_cast<IPropertyValue^>(GetValue(key))->GetTimeSpan(); // throws Platform::InvalidCastException
	}
	Guid CompositeValue::GetGuid(String^ key, bool* exists, Guid default_value)
	{
		*exists = HasKey(key);
		if (*exists == false)
			return default_value;

		return safe_cast<IPropertyValue^>(GetValue(key))->GetGuid(); // throws Platform::InvalidCastException
	}
	Point CompositeValue::GetPoint(String^ key, bool* exists, Point default_value)
	{
		*exists = HasKey(key);
		if (*exists == false)
			return default_value;

		return safe_cast<IPropertyValue^>(GetValue(key))->GetPoint(); // throws Platform::InvalidCastException
	}
	Size CompositeValue::GetSize(String^ key, bool* exists, Size default_value)
	{
		*exists = HasKey(key);
		if (*exists == false)
			return default_value;

		return safe_cast<IPropertyValue^>(GetValue(key))->GetSize(); // throws Platform::InvalidCastException
	}
	Rect CompositeValue::GetRect(String^ key, bool* exists, Rect default_value)
	{
		*exists = HasKey(key);
		if (*exists == false)
			return default_value;

		return safe_cast<IPropertyValue^>(GetValue(key))->GetRect(); // throws Platform::InvalidCastException
	}
	Array<Platform::String^>^ CompositeValue::GetStringArray(String^ key)
	{
		if (HasKey(key) == false)
			return nullptr;

		Array<Platform::String^>^ val = nullptr;
		safe_cast<IPropertyValue^>(GetValue(key))->GetStringArray(&val);
		return val;
	}

	Array<byte>^ CompositeValue::GetUInt8Array(String^ key)
	{
		if (HasKey(key) == false)
			return nullptr;

		Array<byte>^ val = nullptr;
		safe_cast<IPropertyValue^>(GetValue(key))->GetUInt8Array(&val); // throws Platform::InvalidCastException
		return val;
	}
	Array<SHORT>^ CompositeValue::GetInt16Array(String^ key)
	{
		if (HasKey(key) == false)
			return nullptr;

		Array<SHORT>^ val = nullptr;
		safe_cast<IPropertyValue^>(GetValue(key))->GetInt16Array(&val); // throws Platform::InvalidCastException
		return val;
	}
	Array<USHORT>^ CompositeValue::GetUInt16Array(String^ key)
	{
		if (HasKey(key) == false)
			return nullptr;

		Array<USHORT>^ val = nullptr;
		safe_cast<IPropertyValue^>(GetValue(key))->GetUInt16Array(&val); // throws Platform::InvalidCastException
		return val;
	}
	Array<INT32>^ CompositeValue::GetInt32Array(String^ key)
	{
		if (HasKey(key) == false)
			return nullptr;

		Array<INT32>^ val = nullptr;
		safe_cast<IPropertyValue^>(GetValue(key))->GetInt32Array(&val); // throws Platform::InvalidCastException
		return val;
	}
	Array<UINT32>^ CompositeValue::GetUInt32Array(String^ key)
	{
		if (HasKey(key) == false)
			return nullptr;

		Array<UINT32>^ val = nullptr;
		safe_cast<IPropertyValue^>(GetValue(key))->GetUInt32Array(&val); // throws Platform::InvalidCastException
		return val;
	}
	Array<INT64>^ CompositeValue::GetInt64Array(String^ key)
	{
		if (HasKey(key) == false)
			return nullptr;

		Array<INT64>^ val = nullptr;
		safe_cast<IPropertyValue^>(GetValue(key))->GetInt64Array(&val); // throws Platform::InvalidCastException
		return val;
	}
	Array<UINT64>^ CompositeValue::GetUInt64Array(String^ key)
	{
		if (HasKey(key) == false)
			return nullptr;

		Array<UINT64>^ val = nullptr;
		safe_cast<IPropertyValue^>(GetValue(key))->GetUInt64Array(&val); // throws Platform::InvalidCastException
		return val;
	}
	Array<float>^ CompositeValue::GetFloatArray(String^ key)
	{
		if (HasKey(key) == false)
			return nullptr;

		Array<float>^ val = nullptr;
		safe_cast<IPropertyValue^>(GetValue(key))->GetSingleArray(&val); // throws Platform::InvalidCastException
		return val;
	}
	Array<double>^ CompositeValue::GetDoubleArray(String^ key)
	{
		if (HasKey(key) == false)
			return nullptr;

		Array<double>^ val = nullptr;
		safe_cast<IPropertyValue^>(GetValue(key))->GetDoubleArray(&val); // throws Platform::InvalidCastException
		return val;
	}
	Array<bool>^ CompositeValue::GetBooleanArray(String^ key)
	{
		if (HasKey(key) == false)
			return nullptr;

		Array<bool>^ val = nullptr;
		safe_cast<IPropertyValue^>(GetValue(key))->GetBooleanArray(&val); // throws Platform::InvalidCastException
		return val;
	}
	Array<wchar_t>^ CompositeValue::GetWCharArray(String^ key)
	{
		if (HasKey(key) == false)
			return nullptr;

		Array<wchar_t>^ val = nullptr;
		safe_cast<IPropertyValue^>(GetValue(key))->GetChar16Array(&val); // throws Platform::InvalidCastException
		return val;
	}
	Array<DateTime>^ CompositeValue::GetDateTimeArray(String^ key)
	{
		if (HasKey(key) == false)
			return nullptr;

		Array<DateTime>^ val = nullptr;
		safe_cast<IPropertyValue^>(GetValue(key))->GetDateTimeArray(&val); // throws Platform::InvalidCastException
		return val;
	}
	Array<TimeSpan>^ CompositeValue::GetTimeSpanArray(String^ key)
	{
		if (HasKey(key) == false)
			return nullptr;

		Array<TimeSpan>^ val = nullptr;
		safe_cast<IPropertyValue^>(GetValue(key))->GetTimeSpanArray(&val); // throws Platform::InvalidCastException
		return val;
	}
	Array<Guid>^ CompositeValue::GetGuidArray(String^ key)
	{
		if (HasKey(key) == false)
			return nullptr;

		Array<Guid>^ val = nullptr;
		safe_cast<IPropertyValue^>(GetValue(key))->GetGuidArray(&val); // throws Platform::InvalidCastException
		return val;
	}
	Array<Point>^ CompositeValue::GetPointArray(String^ key)
	{
		if (HasKey(key) == false)
			return nullptr;

		Array<Point>^ val = nullptr;
		safe_cast<IPropertyValue^>(GetValue(key))->GetPointArray(&val); // throws Platform::InvalidCastException
		return val;
	}
	Array<Size>^ CompositeValue::GetSizeArray(String^ key)
	{
		if (HasKey(key) == false)
			return nullptr;

		Array<Size>^ val = nullptr;
		safe_cast<IPropertyValue^>(GetValue(key))->GetSizeArray(&val); // throws Platform::InvalidCastException
		return val;
	}
	Array<Rect>^ CompositeValue::GetRectArray(String^ key)
	{
		if (HasKey(key) == false)
			return nullptr;

		Array<Rect>^ val = nullptr;
		safe_cast<IPropertyValue^>(GetValue(key))->GetRectArray(&val); // throws Platform::InvalidCastException
		return val;
	}

	void CompositeValue::SetString(String^ key, String^ val)
	{
		m_Composite->Insert(key, dynamic_cast<PropertyValue^>(PropertyValue::CreateString(val)));
	}
	void CompositeValue::SetUInt8(String^ key, byte val)
	{
		m_Composite->Insert(key, dynamic_cast<PropertyValue^>(PropertyValue::CreateUInt8(val)));
	}
	void CompositeValue::SetInt16(String^ key, SHORT val)
	{
		m_Composite->Insert(key, dynamic_cast<PropertyValue^>(PropertyValue::CreateInt16(val)));
	}
	void CompositeValue::SetUInt16(String^ key, USHORT val)
	{
		m_Composite->Insert(key, dynamic_cast<PropertyValue^>(PropertyValue::CreateUInt16(val)));
	}
	void CompositeValue::SetInt32(String^ key, INT32 val)
	{
		m_Composite->Insert(key, dynamic_cast<PropertyValue^>(PropertyValue::CreateInt32(val)));
	}
	void CompositeValue::SetUInt32(String^ key, UINT32 val)
	{
		m_Composite->Insert(key, dynamic_cast<PropertyValue^>(PropertyValue::CreateUInt32(val)));
	}
	void CompositeValue::SetInt64(String^ key, INT64 val)
	{
		m_Composite->Insert(key, dynamic_cast<PropertyValue^>(PropertyValue::CreateInt64(val)));
	}
	void CompositeValue::SetUInt64(String^ key, UINT64 val)
	{
		m_Composite->Insert(key, dynamic_cast<PropertyValue^>(PropertyValue::CreateUInt64(val)));
	}
	void CompositeValue::SetFloat(String^ key, float val)
	{
		m_Composite->Insert(key, dynamic_cast<PropertyValue^>(PropertyValue::CreateSingle(val)));
	}
	void CompositeValue::SetDouble(String^ key, double val)
	{
		m_Composite->Insert(key, dynamic_cast<PropertyValue^>(PropertyValue::CreateDouble(val)));
	}
	void CompositeValue::SetBoolean(String^ key, bool val)
	{
		m_Composite->Insert(key, dynamic_cast<PropertyValue^>(PropertyValue::CreateBoolean(val)));
	}
	void CompositeValue::SetWChar(String^ key, wchar_t val)
	{
		m_Composite->Insert(key, dynamic_cast<PropertyValue^>(PropertyValue::CreateChar16(val)));
	}
	void CompositeValue::SetDateTime(String^ key, DateTime val)
	{
		m_Composite->Insert(key, dynamic_cast<PropertyValue^>(PropertyValue::CreateDateTime(val)));
	}
	void CompositeValue::SetTimeSpan(String^ key, TimeSpan val)
	{
		m_Composite->Insert(key, dynamic_cast<PropertyValue^>(PropertyValue::CreateTimeSpan(val)));
	}
	void CompositeValue::SetGuid(String^ key, Guid val)
	{
		m_Composite->Insert(key, dynamic_cast<PropertyValue^>(PropertyValue::CreateGuid(val)));
	}
	void CompositeValue::SetPoint(String^ key, Point val)
	{
		m_Composite->Insert(key, dynamic_cast<PropertyValue^>(PropertyValue::CreatePoint(val)));
	}
	void CompositeValue::SetSize(String^ key, Size val)
	{
		m_Composite->Insert(key, dynamic_cast<PropertyValue^>(PropertyValue::CreateSize(val)));
	}
	void CompositeValue::SetRect(String^ key, Rect val)
	{
		m_Composite->Insert(key, dynamic_cast<PropertyValue^>(PropertyValue::CreateRect(val)));
	}
	void CompositeValue::SetStringArray(String^ key, const Array<String^>^ val)
	{
		m_Composite->Insert(key, dynamic_cast<PropertyValue^>(PropertyValue::CreateStringArray(val)));
	}
	void CompositeValue::SetUInt8Array(String^ key, const Array<byte>^ val)
	{
		m_Composite->Insert(key, dynamic_cast<PropertyValue^>(PropertyValue::CreateUInt8Array(val)));
	}
	void CompositeValue::SetInt16Array(String^ key, const Array<SHORT>^ val)
	{
		m_Composite->Insert(key, dynamic_cast<PropertyValue^>(PropertyValue::CreateInt16Array(val)));
	}
	void CompositeValue::SetUInt16Array(String^ key, const Array<USHORT>^ val)
	{
		m_Composite->Insert(key, dynamic_cast<PropertyValue^>(PropertyValue::CreateUInt16Array(val)));
	}
	void CompositeValue::SetInt32Array(String^ key, const Array<INT32>^ val)
	{
		m_Composite->Insert(key, dynamic_cast<PropertyValue^>(PropertyValue::CreateInt32Array(val)));
	}
	void CompositeValue::SetUInt32Array(String^ key, const Array<UINT32>^ val)
	{
		m_Composite->Insert(key, dynamic_cast<PropertyValue^>(PropertyValue::CreateUInt32Array(val)));
	}
	void CompositeValue::SetInt64Array(String^ key, const Array<INT64>^ val)
	{
		m_Composite->Insert(key, dynamic_cast<PropertyValue^>(PropertyValue::CreateInt64Array(val)));
	}
	void CompositeValue::SetUInt64Array(String^ key, const Array<UINT64>^ val)
	{
		m_Composite->Insert(key, dynamic_cast<PropertyValue^>(PropertyValue::CreateUInt64Array(val)));
	}
	void CompositeValue::SetFloatArray(String^ key, const Array<float>^ val)
	{
		m_Composite->Insert(key, dynamic_cast<PropertyValue^>(PropertyValue::CreateSingleArray(val)));
	}
	void CompositeValue::SetDoubleArray(String^ key, const Array<double>^ val)
	{
		m_Composite->Insert(key, dynamic_cast<PropertyValue^>(PropertyValue::CreateDoubleArray(val)));
	}
	void CompositeValue::SetBooleanArray(String^ key, const Array<bool>^ val)
	{
		m_Composite->Insert(key, dynamic_cast<PropertyValue^>(PropertyValue::CreateBooleanArray(val)));
	}
	void CompositeValue::SetWCharArray(String^ key, const Array<wchar_t>^ val)
	{
		m_Composite->Insert(key, dynamic_cast<PropertyValue^>(PropertyValue::CreateChar16Array(val)));
	}
	void CompositeValue::SetDateTimeArray(String^ key, const Array<DateTime>^ val)
	{
		m_Composite->Insert(key, dynamic_cast<PropertyValue^>(PropertyValue::CreateDateTimeArray(val)));
	}
	void CompositeValue::SetTimeSpanArray(String^ key, const Array<TimeSpan>^ val)
	{
		m_Composite->Insert(key, dynamic_cast<PropertyValue^>(PropertyValue::CreateTimeSpanArray(val)));
	}
	void CompositeValue::SetGuidArray(String^ key, const Array<Guid>^ val)
	{
		m_Composite->Insert(key, dynamic_cast<PropertyValue^>(PropertyValue::CreateGuidArray(val)));
	}
	void CompositeValue::SetPointArray(String^ key, const Array<Point>^ val)
	{
		m_Composite->Insert(key, dynamic_cast<PropertyValue^>(PropertyValue::CreatePointArray(val)));
	}
	void CompositeValue::SetSizeArray(String^ key, const Array<Size>^ val)
	{
		m_Composite->Insert(key, dynamic_cast<PropertyValue^>(PropertyValue::CreateSizeArray(val)));
	}
	void CompositeValue::SetRectArray(String^ key, const Array<Rect>^ val)
	{
		m_Composite->Insert(key, dynamic_cast<PropertyValue^>(PropertyValue::CreateRectArray(val)));
	}

}