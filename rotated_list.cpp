// Copyright (c) 2021 Caylee Annett All rights reserved
//
// Created by Caylee Annett
// Created on June 2021
// This program rotates the values in an array

#include <iostream>
#include <array>

template<size_t N>
std::string RotateList(std::array<std::string, N> arrayOfValues,
                       int rotations) {
    // This function rotates the array

    std::string arrayAsString;
    std::array<std::string, 10> rotatedArray;

    for (int counter = 0; counter < rotatedArray.size() - rotations;
        counter++) {
        rotatedArray[counter] = arrayOfValues[counter + rotations];
    }
    for (int counter = 0; counter < rotations; counter++) {
        rotatedArray[rotatedArray.size() + counter - rotations]
            = arrayOfValues[counter];
    }
    arrayAsString = rotatedArray[0];
    for (int counter = 1; counter < rotatedArray.size(); counter++) {
        arrayAsString = arrayAsString + ", " + rotatedArray[counter];
    }

    return arrayAsString;
}

main() {
    // This function gets the array values
    std::array<std::string, 10> inputArray;
    std::string valueInput;
    std::string rotationNumberString;
    int rotationNumberInteger;
    std::string newArray;
    std::string inputArrayString;

    // Input & Process
    std::cout << "This program rotates the values in an array that holds "
        "10 values." << std::endl;
    std::cout << "" << std::endl;
    std::cout << "Enter one array value at a time." << std::endl;
    for (int counter = 0; counter < inputArray.size(); counter++) {
        std::cout << "Enter a list values: ";
        std::cin >> valueInput;
        inputArray[counter] = valueInput;
    }
    std::cout << "Enter the number of positions that you want "
                 "the list rotated: ";
    std::cin >> rotationNumberString;
    while (true) {
        try {
            rotationNumberInteger = std::stoi(rotationNumberString);

            if (rotationNumberInteger >= 0) {
                break;
            } else {
                std::cout << "Must be a positive integer. Enter the number of "
                             "positions that you want the list rotated: ";
            std::cin >> rotationNumberString;
            }
        } catch (std::invalid_argument) {
            std::cout << rotationNumberString << " is not a valid input. "
                                                 "Enter the number of "
                                                 "positions that you want "
                                                 "the list rotated: ";
            std::cin >> rotationNumberString;
        }
    }

    // Call functions
    newArray = RotateList(inputArray, rotationNumberInteger);

    // Output
    std::cout << "" << std::endl;
    std::cout << "The array [";
    inputArrayString = inputArray[0];
    for (int counter = 1; counter < inputArray.size(); counter++) {
        inputArrayString = inputArrayString + ", " + inputArray[counter];
    }
    std::cout << inputArrayString << "] rotated " << rotationNumberInteger
        << " places is: [" << newArray;
    std::cout << "]" << std::endl;
    std::cout << "" << std::endl;
    std::cout << "Done." << std::endl;
}
