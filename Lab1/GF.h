#pragma once

#include<iostream>
#include<vector>


using TwoDimVector = std::vector<std::vector<int>>;
using Vector = std::vector<int>;

using namespace std;

class GF
{
public:
	GF(unsigned int p);
	
	void printTwoDimensionalVectorAdding();
	void printTwoDimensionalVectorMultiplication();
	void printInverseArray();
	void printMultiplicativeGroup();
	void printPrimitiveElements();


private:
	TwoDimVector createTwoDimensionalVector(unsigned int width, int defaultValue = 0);
	TwoDimVector createArrayAdding();
	TwoDimVector createArrayMultiplication();
	Vector createInverseArray();
	
	void printTwoDimVector(const TwoDimVector& twoDimVector);

	unsigned int vectorSize;
	TwoDimVector twoDimensionalVectorAdding;
	TwoDimVector twoDimensionalVectorMultiplication;
	Vector inverseArray;
};

