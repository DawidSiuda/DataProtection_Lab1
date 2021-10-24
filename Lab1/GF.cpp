#include "GF.h"

#include <math.h>       /* pow */
#include<iomanip>

GF::GF(unsigned int p)
{
    vectorSize = p;

    twoDimensionalVectorAdding = createArrayAdding();
    twoDimensionalVectorMultiplication = createArrayMultiplication();
    inverseArray = createInverseArray();
}


TwoDimVector GF::createTwoDimensionalVector(unsigned int width, int defaultValue)
{
    return std::vector<std::vector<int>>(width, std::vector<int>(width, defaultValue));
}

void GF::printTwoDimensionalVectorAdding()
{
    cout << "Adding:" << endl;
    printTwoDimVector(twoDimensionalVectorAdding);
}

void GF::printTwoDimensionalVectorMultiplication()
{
    cout << "Multiplication:" << endl;
    printTwoDimVector(twoDimensionalVectorMultiplication);
}

void GF::printTwoDimVector(const TwoDimVector& twoDimVector)
{
    cout << "    ";
    for (int i = 0; i < twoDimVector.size(); i++)
        cout << std::setfill(' ') << std::setw(3) << i;
    std::cout << '\n';

    cout << "---";
    for (int i = 0; i < twoDimVector.size(); i++)
        cout << "---";
    std::cout << '\n';


    for (auto itX = twoDimVector.begin(); itX != twoDimVector.end(); ++itX)
    {
        cout << std::setfill(' ') << std::setw(3) << (itX - twoDimVector.begin()) << "|";
        for (auto itY = itX->begin(); itY != itX->end(); ++itY)
        {
            cout << std::setfill(' ') << std::setw(3) << *itY;
        }

        std::cout << '\n';
    }

    std::cout << '\n';
}

TwoDimVector GF::createArrayAdding()
{
    std::vector<std::vector<int>> twoDimVector(vectorSize, std::vector<int>(vectorSize, 0));

    unsigned int modulo = vectorSize;

    for (auto itX = twoDimVector.begin(); itX != twoDimVector.end(); ++itX)
    {
        for (auto itY = itX->begin(); itY != itX->end(); ++itY)
        {
            unsigned int indexX = itX - twoDimVector.begin();
            unsigned int indexY = itY - itX->begin();

            *itY = (indexX + indexY) % modulo;
        }
    }
    return twoDimVector;
}

TwoDimVector GF::createArrayMultiplication()
{
    std::vector<std::vector<int>> twoDimVector(vectorSize, std::vector<int>(vectorSize, 0));

    unsigned int modulo = vectorSize;

    for (auto itX = twoDimVector.begin(); itX != twoDimVector.end(); ++itX)
    {
        for (auto itY = itX->begin(); itY != itX->end(); ++itY)
        {
            unsigned int indexX = itX - twoDimVector.begin();
            unsigned int indexY = itY - itX->begin();

            *itY = (indexX * indexY) % modulo;
        }
    }
    return twoDimVector;
}

Vector GF::createInverseArray()
{
    unsigned int modulo = vectorSize;

    Vector reciprocalOfNumberVector(modulo, 0);

    for (auto x = 1; x != modulo; ++x)
    {
        for (auto y = 1; y != modulo; ++y)
        {
            int number = (x * y) % modulo;

            if (number == 1)
            {
                reciprocalOfNumberVector[x] = y;
            }
        }
    }

    return reciprocalOfNumberVector;
}

void GF::printInverseArray()
{
    cout << "Inverse:" << endl;
    for (int i = 0; i < inverseArray.size(); i++)
    {
        std::cout << i << " --> " << inverseArray[i] << endl;
    }

    std::cout << '\n';
}

void GF::printMultiplicativeGroup()
{
    for (int i = 1; i < vectorSize; i++)
    {
        for (int j = 1; j < vectorSize; j++)
        {
            auto powred = std::pow((double)i, (double)j);

           // cout <<  i << "^" << j << "= " << powred << " (mod " << vectorSize << ") = " << (int)powred % vectorSize  << "\n";
            if (((int)powred % vectorSize) == 1)
            {
                cout << "number " << i << " - has multiplicative order " << j << "\n";
                j = vectorSize;
            }
        }
    }
    cout << endl;
}

void GF::printPrimitiveElements()
{
    cout << "Primitive elements of " << vectorSize << ": ";
    
    for (int i = 1; i < vectorSize; i++)
    {

        for (int j = 1; j < vectorSize; j++)
        {
            auto powred = std::pow((double)i, (double)j);

            if (((int)powred % vectorSize) == 1)
            {
                if(j == (vectorSize-1))
                cout << i << ", ";
                j = vectorSize;
            }
        }
    }

    cout << endl;
}
