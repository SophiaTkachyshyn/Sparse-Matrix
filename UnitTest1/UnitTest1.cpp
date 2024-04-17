#include "pch.h"
#include "CppUnitTest.h"
#include "../Sparse Matrix/main.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
    TEST_CLASS(UnitTest)
    {
    public:

        TEST_METHOD(TestAddElementAndGetElement)
        {
            SparseMatrix matrix(3, 3);

            matrix.addElement(0, 1, 1);
            matrix.addElement(0, 2, 2);
            matrix.addElement(1, 1, 3);
            matrix.addElement(2, 0, 4);
            matrix.addElement(2, 2, 5);

            Assert::AreEqual(matrix.getElement(0, 1), 1);
            Assert::AreEqual(matrix.getElement(0, 2), 2);
            Assert::AreEqual(matrix.getElement(1, 1), 3);
            Assert::AreEqual(matrix.getElement(2, 0), 4);
            Assert::AreEqual(matrix.getElement(2, 2), 5);
        }

        TEST_METHOD(TestScalarMultiply)
        {
            SparseMatrix matrix(2, 2);
            matrix.addElement(0, 0, 1);
            matrix.addElement(0, 1, 2);
            matrix.addElement(1, 0, 3);
            matrix.addElement(1, 1, 4);

            matrix.scalarMultiply(2);

            Assert::AreEqual(matrix.getElement(0, 0), 2);
            Assert::AreEqual(matrix.getElement(0, 1), 4);
            Assert::AreEqual(matrix.getElement(1, 0), 6);
            Assert::AreEqual(matrix.getElement(1, 1), 8);
        }

        TEST_METHOD(TestScalarAdd)
        {
            SparseMatrix matrix(2, 2);
            matrix.addElement(0, 0, 1);
            matrix.addElement(0, 1, 2);
            matrix.addElement(1, 0, 3);
            matrix.addElement(1, 1, 4);

            matrix.scalarAdd(3);

            Assert::AreEqual(matrix.getElement(0, 0), 4);
            Assert::AreEqual(matrix.getElement(0, 1), 5);
            Assert::AreEqual(matrix.getElement(1, 0), 6);
            Assert::AreEqual(matrix.getElement(1, 1), 7);
        }
    };
}
