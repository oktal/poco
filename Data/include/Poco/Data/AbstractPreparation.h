//
// AbstractPreparation.h
//
// $Id: //poco/Main/Data/include/Poco/Data/AbstractPreparation.h#5 $
//
// Library: Data
// Package: DataCore
// Module:  AbstractPreparation
//
// Definition of the AbstractPreparation class.
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


#ifndef Data_AbstractPreparation_INCLUDED
#define Data_AbstractPreparation_INCLUDED


#include "Poco/Data/Data.h"
#include "Poco/RefCountedObject.h"
#include <cstddef>


namespace Poco {


class DateTime;
class Any;
class DynamicAny;


namespace Data {


class BLOB;


class Data_API AbstractPreparation: public Poco::RefCountedObject
	/// Interface used for database preparation where we first have to register all data types (and memory output locations)
	/// before extracting data, i.e. extract works as two-pase extract: first we call prepare once, then extract n-times.
	/// Only some database connectors will need to implement this interface.
	/// Note that the values in the interface serve only the purpose of type distinction.
{
public:
	AbstractPreparation();
		/// Creates the AbstractPreparation.

	virtual ~AbstractPreparation();
		/// Destroys the AbstractPreparation.

	virtual void prepare(std::size_t pos, Poco::Int8) = 0;
		/// Prepares an Int8.

	virtual void prepare(std::size_t pos, Poco::UInt8) = 0;
		/// Prepares an UInt8.

	virtual void prepare(std::size_t pos, Poco::Int16) = 0;
		/// Prepares an Int16.

	virtual void prepare(std::size_t pos, Poco::UInt16) = 0;
		/// Prepares an UInt16.

	virtual void prepare(std::size_t pos, Poco::Int32) = 0;
		/// Prepares an Int32.

	virtual void prepare(std::size_t pos, Poco::UInt32) = 0;
		/// Prepares an UInt32.

	virtual void prepare(std::size_t pos, Poco::Int64) = 0;
		/// Prepares an Int64.

	virtual void prepare(std::size_t pos, Poco::UInt64) = 0;
		/// Prepares an UInt64.

#ifndef POCO_LONG_IS_64_BIT
	virtual void prepare(std::size_t pos, long) = 0;
		/// Prepares a long.
#endif

	virtual void prepare(std::size_t pos, bool) = 0;
		/// Prepares a boolean.

	virtual void prepare(std::size_t pos, float) = 0;
		/// Prepares a float.

	virtual void prepare(std::size_t pos, double) = 0;
		/// Prepares a double.

	virtual void prepare(std::size_t pos, char) = 0;
		/// Prepares a single character.

	virtual void prepare(std::size_t pos, const std::string& ) = 0;
		/// Prepares a string.

	virtual void prepare(std::size_t pos, const BLOB&) = 0;
		/// Prepares a BLOB.

	virtual void prepare(std::size_t pos, const DateTime&) = 0;
		/// Prepares a DateTime.

	virtual void prepare(std::size_t pos, const Any&) = 0;
		/// Prepares an Any.

	virtual void prepare(std::size_t pos, const DynamicAny&) = 0;
		/// Prepares a DynamicAny.
};


} } // namespace Poco::Data


#endif // Data_AbstractPreparation_INCLUDED
