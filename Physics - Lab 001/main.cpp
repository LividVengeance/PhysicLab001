#include <iostream>

struct UserInputs
{
    float vectorOne[3];
    float vectorTwo[3];
    float vectorThree[3];
};

float DotProduct(float vec1[2], float vec2[2])
{
    // Gets the Dot Product of Two Vectors
    return(vec1[0] * vec2[0] + vec1[1] * vec2[1] + vec1[2] + vec2[2]);
}

float CrossProduct(float vec1[2], float vec2[2])
{
    // Gets the Cross Product of Two Vectors
    float returnVector[3];

    returnVector[0] = vec1[1] * vec2[2] - vec1[2] * vec2[1];
    returnVector[1] = vec1[2] * vec2[2] - vec1[2] * vec2[2];
    returnVector[2] = vec1[0] * vec2[2] - vec1[2] * vec2[0];

    return(returnVector[2]);
}

float ScalarMultiplication(float scalar, float vec1[2])
{
    // Multiplys a Vector by a Scalar 
    float vec2[3];

    for (int i = 0; i < 2; i++)
    {
        vec2[i] = vec1[i] * scalar;
    }
    return(vec2[2]);
}

float VectorSubtracion(float vec1[2], float vec2[2])
{
    // Subtracts a Vector by Another Vector
    float returnVector[3];

    for (int i = 0; i < 2; i++)
    {
        returnVector[i] = vec1[i] - vec2[i];
    }
    return(returnVector[2]);
}

int main()
{
    UserInputs instance;

    std::cout << "Input the X, Y, Z of first , hititng enter after each input" << std::endl;
    std::cin >> instance.vectorOne[0];
    std::cin >> instance.vectorOne[1];
    std::cin >> instance.vectorOne[2];

    std::cout << "Input the X, Y, Z of second , hititng enter after each input" << std::endl;
    std::cin >> instance.vectorTwo[0];
    std::cin >> instance.vectorTwo[1];
    std::cin >> instance.vectorTwo[2];

    std::cout << "Input the X, Y, Z of third , hititng enter after each input" << std::endl;
    std::cin >> instance.vectorThree[0];
    std::cin >> instance.vectorThree[1];
    std::cin >> instance.vectorThree[2];

    float ABDotProd = DotProduct(instance.vectorOne, instance.vectorTwo);
    float ACDotProd = DotProduct(instance.vectorOne, instance.vectorThree);

    float BCCrossProd[3];
    BCCrossProd[2] = CrossProduct(instance.vectorTwo, instance.vectorThree);
    float ABCCrossProd[3];
    ABCCrossProd[2] = CrossProduct(instance.vectorOne, BCCrossProd); // left Side of Formula

    float ACCrossProdScalar[3];
    ACCrossProdScalar[2] = ScalarMultiplication(ACDotProd, instance.vectorTwo);
    float ABCrossProdScalar[3];
    ABCrossProdScalar[2] = ScalarMultiplication(ABDotProd, instance.vectorThree);

    std::cout << ACCrossProdScalar[0] << ACCrossProdScalar[1] << ACCrossProdScalar[2] << std::endl;

    float BCSubtract[3];
    BCSubtract[2] = VectorSubtracion(ACCrossProdScalar, ABCrossProdScalar); // Right Side of Formula

    std::cout << ABCCrossProd[0] << ", " << ABCCrossProd[1] << ", " << ABCCrossProd[2] << " = "
        << BCSubtract[0] << ", " << BCSubtract[1] << ", " << BCSubtract[2] << std::endl;

    // Stops Program From Closing
    int temp;
    std::cin >> temp;

    return(0);
}