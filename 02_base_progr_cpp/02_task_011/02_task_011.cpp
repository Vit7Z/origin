#include <iostream>
#include <fstream>
#include <string>
#include <clocale>
#include <locale.h>
#include <windows.h>

void printArray(std::string* Arr, int z) {

    for (int i = 0; i < z; i++) {

        std::cout << Arr[i] << "\t";
    }
}

void moveArrayRight(std::string* Arr, int z) {   
    std::string tmp = Arr[z - 1];    
    for (int i = z - 1; i > 0; i--) {
			Arr[i] = Arr[i - 1];
    }   
    Arr[0] = tmp;
}

void moveArrayLeft(std::string* Arr, int z) {
    std::string tmp = Arr[0];
    for (int i = 0; i < z -1; i++) {
        Arr[i] = Arr[i + 1];
    }
    Arr[z - 1] = tmp;
}


int main(int argc, char** argv)
{
    setlocale(0, "Rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::string stringFromFile;

    int sizeOfArray_1 = 0;
    int sizeOfArray_2 = 0;

    std::ifstream readFromFile("in.txt");

    ///////-------opening the file-------///////

    if (!readFromFile.is_open())
    {
        std::cout << "Не получилось открыть файл!" << std::endl; 
    }
 
    readFromFile >> sizeOfArray_1;

    ///////-------allocation of memory for an array 1-------///////

    std::string* arrOfStr_1 = new std::string[sizeOfArray_1];

    ///////-------reading the array 1-------///////

    for (int counter = 0; counter < sizeOfArray_1; counter++) {

        readFromFile >> stringFromFile;

        arrOfStr_1[counter] = stringFromFile;
    }

    readFromFile >> sizeOfArray_2;

    ///////-------allocation of memory for an array 2-------///////

    std::string* arrOfStr_2 = new std::string[sizeOfArray_2];

    ///////-------reading the array 2-------///////

    for (int counter = 0; counter < sizeOfArray_2; counter++) {

        readFromFile >> stringFromFile;

        arrOfStr_2[counter] = stringFromFile;
    }

    readFromFile.close();

    moveArrayRight(arrOfStr_1, sizeOfArray_1);

    moveArrayLeft(arrOfStr_2, sizeOfArray_2);

    std::ofstream writeToFile("out.txt");

    ///////-------writing to a file the array 2-------///////

    writeToFile << sizeOfArray_2 << std::endl;

    for (int counter = 0; counter < sizeOfArray_2; counter++) {
        
        writeToFile << arrOfStr_2[counter] << "  ";
    }

    writeToFile << std::endl;

    ///////-------writing to a file the array 1-------///////

    writeToFile << sizeOfArray_1 << std::endl;;

    for (int counter = 0; counter < sizeOfArray_1; counter++) {

        writeToFile << arrOfStr_1[counter] << "  ";
    }

    writeToFile.close();

    delete[] arrOfStr_1;

    delete[] arrOfStr_2;

    return 0;
}
