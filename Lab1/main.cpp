#pragma once

#include"GF.h"

using namespace std;

int main()
{
	cout << "==================================== \n";
	cout << "== p = 7 \n";
	cout << "==================================== \n\n";
	GF gf7(7);
	gf7.printTwoDimensionalVectorAdding();
	gf7.printTwoDimensionalVectorMultiplication();
	gf7.printInverseArray();
	gf7.printMultiplicativeGroup();
	gf7.printPrimitiveElements();
	cout << endl;


	cout << "==================================== \n";
	cout << "== p = 13 \n";
	cout << "==================================== \n\n";
	GF gf13(13);
	gf13.printTwoDimensionalVectorAdding();
	gf13.printTwoDimensionalVectorMultiplication();
	gf13.printInverseArray();
	gf13.printMultiplicativeGroup();
	gf13.printPrimitiveElements();
	cout << endl;


	cout << "==================================== \n";
	cout << "== p = 17 \n";
	cout << "==================================== \n\n";
	GF gf17(17);
	gf17.printTwoDimensionalVectorAdding();
	gf17.printTwoDimensionalVectorMultiplication();
	gf17.printInverseArray();
	gf17.printMultiplicativeGroup();
	gf17.printPrimitiveElements();
	cout << endl;
}
//
//#include<iostream>
//#include<vector>
//#include <iomanip>
//
//using namespace std;
//
//using TwoDimVector = std::vector<std::vector<int>>;
//using Vector = std::vector<int>;
//
//void printTwoDimVector(const TwoDimVector& twoDimVector);
//TwoDimVector createTwoDimensionalVector(unsigned int width, int defaultValue = 0);
//int fillArrayAdding(TwoDimVector& twoDimVector);
//int fillArrayMultiplication(TwoDimVector& twoDimVector);
//Vector createInverseArray(unsigned int modulo);
//
//const unsigned int vectorSize{ 7 };
//
//int main()
//{
//    auto twoDimensionalVector = createTwoDimensionalVector(vectorSize);
//
//    cout << "Empty array.\n";
//    printTwoDimVector(twoDimensionalVector);
//
//    fillArrayAdding(twoDimensionalVector);
//
//    cout << "\nArray (adding).\n";
//    printTwoDimVector(twoDimensionalVector);
//
//    fillArrayMultiplication(twoDimensionalVector);
//
//    cout << "\nArray (multiplication).\n";
//    printTwoDimVector(twoDimensionalVector);
//
//    createInverseArray(vectorSize);
//
//	return 0;
//}
//
//TwoDimVector createTwoDimensionalVector(unsigned int width, int defaultValue)
//{
//    return std::vector<std::vector<int>>(width, std::vector<int>(width, defaultValue));
//}
//
//void printTwoDimVector(const TwoDimVector& twoDimVector)
//{
//    cout << "    ";
//    for (int i = 0; i < twoDimVector.size(); i++)
//        cout << std::setfill(' ') << std::setw(3) << i;
//    std::cout << '\n';
//
//    cout << "---";
//    for (int i = 0; i < twoDimVector.size(); i++)
//        cout << "---";
//    std::cout << '\n';
//
//
//    for (auto itX = twoDimVector.begin(); itX != twoDimVector.end(); ++itX)
//    {
//        cout << std::setfill(' ') << std::setw(3) << (itX - twoDimVector.begin()) << "|";
//        for (auto itY = itX->begin(); itY != itX->end(); ++itY)
//        {
//            cout << std::setfill(' ') << std::setw(3) << *itY;
//        }
//        
//        std::cout << '\n';
//    }
//}
//
//int fillArrayAdding(TwoDimVector& twoDimVector)
//{
//    unsigned int modulo = twoDimVector.size();
//
//    for (auto itX = twoDimVector.begin(); itX != twoDimVector.end(); ++itX)
//    {
//        for (auto itY = itX->begin(); itY != itX->end(); ++itY)
//        {
//            unsigned int indexX = itX - twoDimVector.begin();
//            unsigned int indexY = itY - itX->begin();
//
//            *itY = (indexX + indexY) % modulo;
//        }
//    }
//    return 0;
//}
//
//int fillArrayMultiplication(TwoDimVector& twoDimVector)
//{
//    unsigned int modulo = twoDimVector.size();
//
//    for (auto itX = twoDimVector.begin(); itX != twoDimVector.end(); ++itX)
//    {
//        for (auto itY = itX->begin(); itY != itX->end(); ++itY)
//        {
//            unsigned int indexX = itX - twoDimVector.begin();
//            unsigned int indexY = itY - itX->begin();
//
//            *itY = (indexX * indexY) % modulo;
//        }
//    }
//    return 0;
//}
//
//Vector createInverseArray(unsigned int modulo)
//{
//    Vector reciprocalOfNumberVector( modulo, 0 );
//
//    for (auto x = 1; x != modulo; ++x)
//    {
//        for (auto y = 1; y != modulo; ++y)
//        {
//            int number = (x * y) % modulo;
//
//            if (number == 1)
//            {
//                reciprocalOfNumberVector[x] = y;
//                std::cout << x << " --> " << y << endl;
//            }
//
//        }
//    }
//    return reciprocalOfNumberVector;
//}