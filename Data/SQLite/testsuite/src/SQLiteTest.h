//
// SQLiteTest.h
//
// $Id: //poco/Main/Data/SQLite/testsuite/src/SQLiteTest.h#4 $
//
// Definition of the SQLiteTest class.
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


#ifndef SQLiteTest_INCLUDED
#define SQLiteTest_INCLUDED


#include "Poco/Data/SQLite/SQLite.h"
#include "CppUnit/TestCase.h"


class SQLiteTest: public CppUnit::TestCase
{
public:
	SQLiteTest(const std::string& name);
	~SQLiteTest();

	void testSimpleAccess();
	void testInsertCharPointer();
	void testInsertCharPointer2();
	void testComplexType();
	void testSimpleAccessVector();
	void testComplexTypeVector();
	void testInsertVector();
	void testInsertEmptyVector();

	void testInsertSingleBulk();
	void testInsertSingleBulkVec();

	void testLimit();
	void testLimitOnce();
	void testLimitPrepare();
	void testLimitZero();
	void testPrepare();

	void testSetSimple();
	void testSetComplex();
	void testSetComplexUnique();
	void testMultiSetSimple();
	void testMultiSetComplex();
	void testMapComplex();
	void testMapComplexUnique();
	void testMultiMapComplex();
	void testSelectIntoSingle();
	void testSelectIntoSingleStep();
	void testSelectIntoSingleFail();
	void testLowerLimitOk();
	void testLowerLimitFail();
	void testCombinedLimits();
	void testCombinedIllegalLimits();
	void testRange();
	void testIllegalRange();
	void testSingleSelect();
	void testEmptyDB();

	void testBLOB();

	void testTuple1();
	void testTupleVector1();
	void testTuple2();
	void testTupleVector2();
	void testTuple3();
	void testTupleVector3();
	void testTuple4();
	void testTupleVector4();
	void testTuple5();
	void testTupleVector5();
	void testTuple6();
	void testTupleVector6();
	void testTuple7();
	void testTupleVector7();
	void testTuple8();
	void testTupleVector8();
	void testTuple9();
	void testTupleVector9();
	void testTuple10();
	void testTupleVector10();

	void testInternalExtraction();
	void testPrimaryKeyConstraint();
	void testNull();
	void testRowIterator();
	void testAsync();

	void testAny();
	void testDynamicAny();

	void setUp();
	void tearDown();

	static CppUnit::Test* suite();

private:
};


#endif // SQLiteTest_INCLUDED
