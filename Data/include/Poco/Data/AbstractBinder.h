//
// AbstractBinder.h
//
// $Id: //poco/Main/Data/include/Poco/Data/AbstractBinder.h#12 $
//
// Library: Data
// Package: DataCore
// Module:  AbstractBinder
//
// Definition of the AbstractBinder class.
//
// Copyright (c) 2006, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// Permission is hereby granted, free of charge, to any person or organization
// obtaining a copy of the software and accompanying documentation covered by
// this license (the "Software") to use, reproduce, display, distribute,
// execute, and transmit the Software, and to prepare derivative works of the
// Software, and to permit third-parties to whom the Software is furnished to
// do so, all subject to the following:
// 
// The copyright notices in the Software and this entire statement, including
// the above license grant, this restriction and the following disclaimer,
// must be included in all copies of the Software, in whole or in part, and
// all derivative works of the Software, unless such copies or derivative
// works are solely in the form of machine-executable object code generated by
// a source language processor.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
// SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
// FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
// ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
// DEALINGS IN THE SOFTWARE.
//


#ifndef Data_AbstractBinder_INCLUDED
#define Data_AbstractBinder_INCLUDED


#include "Poco/Data/Data.h"
#include <cstddef>


namespace Poco {

class DateTime;
class Any;
class DynamicAny;

namespace Data {

class BLOB;

enum NullData
{
	NULL_GENERIC = 0,
	NULL_INT8,
	NULL_UINT8,
	NULL_INT16,
	NULL_UINT16,
	NULL_INT32,
	NULL_UINT32,
	NULL_INT64,
	NULL_UINT64,
	NULL_BOOL,
	NULL_FLOAT,
	NULL_DOUBLE,
	NULL_STRING,
	NULL_BLOB,
	NULL_TIMESTAMP
};


static const NullData null = NULL_GENERIC;


class Data_API AbstractBinder
	/// Interface for Binding data types to placeholders. The default placeholder format 
	/// in the SQL query is ":name".
{
public:
	enum Direction
		/// Binding direction for a parameter.
	{
		PD_IN,
		PD_OUT,
		PD_IN_OUT
	};

	AbstractBinder();
		/// Creates the AbstractBinder.

	virtual ~AbstractBinder();
		/// Destroys the AbstractBinder.

	virtual void bind(std::size_t pos, const Poco::Int8& val, Direction dir) = 0;
		/// Binds an Int8.

	virtual void bind(std::size_t pos, const Poco::UInt8& val, Direction dir) = 0;
		/// Binds an UInt8.

	virtual void bind(std::size_t pos, const Poco::Int16& val, Direction dir) = 0;
		/// Binds an Int16.

	virtual void bind(std::size_t pos, const Poco::UInt16& val, Direction dir) = 0;
		/// Binds an UInt16.

	virtual void bind(std::size_t pos, const Poco::Int32& val, Direction dir) = 0;
		/// Binds an Int32.

	virtual void bind(std::size_t pos, const Poco::UInt32& val, Direction dir) = 0;
		/// Binds an UInt32.
		
	virtual void bind(std::size_t pos, const Poco::Int64& val, Direction dir) = 0;
		/// Binds an Int64.

	virtual void bind(std::size_t pos, const Poco::UInt64& val, Direction dir) = 0;
		/// Binds an UInt64.

#ifndef POCO_LONG_IS_64_BIT
	virtual void bind(std::size_t pos, const long& val, Direction dir) = 0;
		/// Binds a long.
#endif

	virtual void bind(std::size_t pos, const bool& val, Direction dir) = 0;
		/// Binds a boolean.

	virtual void bind(std::size_t pos, const float& val, Direction dir) = 0;
		/// Binds a float.

	virtual void bind(std::size_t pos, const double& val, Direction dir) = 0;
		/// Binds a double.

	virtual void bind(std::size_t pos, const char& val, Direction dir) = 0;
		/// Binds a single character.

	virtual void bind(std::size_t pos, const char* const &pVal, Direction dir) = 0;
		/// Binds a const char ptr.

	virtual void bind(std::size_t pos, const std::string& val, Direction dir) = 0;
		/// Binds a string.

	virtual void bind(std::size_t pos, const BLOB& val, Direction dir) = 0;
		/// Binds a BLOB.

	virtual void bind(std::size_t pos, const DateTime& val, Direction dir) = 0;
		/// Binds a DateTime.

	virtual void bind(std::size_t pos, const NullData& val, Direction dir) = 0;
		/// Binds a null.

	void bind(std::size_t pos, const Any& val, Direction dir = PD_IN);
		/// Binds an Any.
	
	void bind(std::size_t pos, const DynamicAny& val, Direction dir = PD_IN);
		/// Binds a DynamicAny.

	static bool isOutBound(Direction dir);
		/// Returns true if direction is out bound;

	static bool isInBound(Direction dir);
		/// Returns true if direction is in bound;
};


//
// inlines
//
inline bool AbstractBinder::isOutBound(Direction dir)
{
	return PD_OUT == dir || PD_IN_OUT == dir;
}


inline bool AbstractBinder::isInBound(Direction dir)
{
	return PD_IN == dir || PD_IN_OUT == dir;
}


} } // namespace Poco::Data


#endif // Data_AbstractBinder_INCLUDED
