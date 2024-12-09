/*
1. 	Дана последовательность натуральных чисел {aj}j=1...n (n<=10000). Если в последовательности есть хотя бы одно число, начинающееся цифрой 1, 
упорядочить последовательность по неубыванию.
 */

 /*
Дана последовательность натуральных чисел {Aj}j=1...n (n<=10000). Удалить из последовательности числа, содержащие цифру 7, но не содержащие цифру 6, 
а среди оставшихся продублировать простые числа.
*/


#include <iostream>
using namespace std;


void fillArray(int* array, int length)
{
    for (int i = 0; i < length; i++)
    {
        cout << "Enter a number: ";
        cin >> array[i];
    }
}


void printArray(int* array, int length)
{
    for (int i = 0; i < length; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}


int findFirstDigit(int number)
{
    int lastDigit = -1;

    while (number != 0)
    {
        lastDigit = number % 10;
        number /= 10;
    }

    return lastDigit;
}


bool isThereANumberThatStartsWithOne(int* array, int length)
{
    bool flag = false;
    
    for (int i = 0; i < length; i++)
    {
        if (findFirstDigit(array[i]) == 1)
        {
            flag = true;
            break;
        }
    }

    return flag;
}


void sortArray(int* array, int length)
{
    for (int i = 0; i < length; i++)
    {
        for (int j = i; j < length; j++)
        {
            if (array[i] > array[j])
            {
                swap(array[i], array[j]);
            }
        }
    }
}


void firstTask()
{
    cout <<"\t\t\t FIRST TASK " << endl;

    int arrayLength = 0;
    cout << "Enter an array length ";
    cin >> arrayLength;
    
    int* myArray = new int[arrayLength];
    cout << endl << "Enter array elements:" << endl;
    fillArray(myArray, arrayLength);

    if (isThereANumberThatStartsWithOne(myArray, arrayLength))
    {
        sortArray(myArray, arrayLength);
    }

    printArray(myArray, arrayLength);
    delete[] myArray;
}


/*
2. 	Ввести последовательность натуральных чисел {Aj}j=1...n (n<=1000). Упорядочить последовательность по неубыванию первой цифры числа, 
числа с одинаковыми первыми цифрами дополнительно упорядочить по неубыванию суммы цифр числа, числа с одинаковыми первыми цифрами и одинаковыми 
суммами цифр дополнительно упорядочить по неубыванию самого числа.
*/


int sumOfDigids(int x)
{
    x = abs(x);
    int sum = 0;

    while (x != 0)
    {
        sum += x % 10;
        x /= 10;
    }

    return sum;
}


void sortArrayByFirstDigit(int* array, int length)
{
    for (int i = 0; i < length; i++)
    {
        for (int j = i; j < length; j++)
        {
            if (findFirstDigit(array[i]) > findFirstDigit(array[j]))
            {
                swap(array[i], array[j]);
            }
            else if (findFirstDigit(array[i]) == findFirstDigit(array[j]))
            {
                if (sumOfDigids(array[i]) > sumOfDigids(array[j]))
                {
                    swap(array[i], array[j]);
                }
                else if (sumOfDigids(array[i]) == sumOfDigids(array[j]))
                {
                    swap(array[i], array[j]);
                }
            }  
        }
    }
}


void secondTask()
{
    cout <<"\t\t\t SECOND TASK " << endl;

    int arrayLength = 0;
    cout << "Enter an array length ";
    cin >> arrayLength;
    
    int* myArray = new int[arrayLength];
    cout << endl << "Enter array elements:" << endl;
    fillArray(myArray, arrayLength);

    sortArrayByFirstDigit(myArray, arrayLength);
    
    printArray(myArray, arrayLength);
    delete[] myArray;
}


/*
3. 	Дана целочисленная матрица {Aij}i=1..n,j=1..m (n,m<=100). Найти строку, сумма элементов которой наиболее близка к 0, и заменить все элементы этой строки числом 0.
*/


int** createMatrix(int strings, int columns)
{
    int** matrix = new int*[strings];

    for (int i = 0; i < strings; i++)
    {
        matrix[i] = new int[columns];
    }

    return matrix;
}


void fillMatrix(int** matrix, int strings, int columns)
{
    cout << endl << "Enter array elements:" << endl;

    for (int i = 0; i < strings; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            cout << "Enter a number: ";
            cin >> matrix[i][j];
        }
    }
}


void printMatrix(int** matrix, int strings, int columns)
{
    for (int i = 0; i < strings; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
}


void deleteMatrix(int** matrix, int strings, int columns)
{
    for (int i = 0; i < strings; i++)
    {
        delete[] matrix[i];
    }

    delete[] matrix;
}


int findSmallestString(int** matrix, int strings, int columns)
{
    int minSumOfString = 10*10, minStringNumber = 0;
    
    for (int i = 0; i < strings; i++)
    {
        int sumOfString = 0;

        for (int j = 0; j < columns; j++)
        {
            sumOfString += matrix[i][j];
        }
        
        if (sumOfString < minSumOfString)
        {
            minSumOfString = sumOfString;
            minStringNumber = i;
        }
    }

    return minStringNumber;
}


void multiplyAllElementsOfString(int** matrix, int columns, int stringNumber)
{
    for (int i = 0; i < columns; i++)
    {
        matrix[stringNumber][i] = 0;
    }
}


void thirdTask()
{
    cout <<"\t\t\t THIRD TASK " << endl;

    int matrixStrings = 0, matrixColumns = 0;
    cout << "Enter a number of matrix's strings ";
    cin >> matrixStrings;
    cout << "Enter a number of matrix's columns ";
    cin >> matrixColumns;
    
    int** myMatrix = createMatrix(matrixStrings, matrixColumns);
    fillMatrix(myMatrix, matrixStrings, matrixColumns);
    
    cout << endl;
    
    multiplyAllElementsOfString(myMatrix, matrixColumns, findSmallestString(myMatrix, matrixStrings, matrixColumns));
    printMatrix(myMatrix, matrixStrings, matrixColumns);
    
    deleteMatrix(myMatrix, matrixStrings, matrixColumns);
}


/*
4. Сначала введите последовательность. Затем удалите и продублируйте элементы. Затем выведите полученную последовательность (каждый элемент по одному разу). 
Используйте в программе только один массив.
*/


void moveElementsByOneFuther(int* array, int length, int firstIndex = 1)
{
    int tmp = array[firstIndex + 1];
    for (int i = firstIndex; i < length - 1; i++)
    {
        array[i + 1] = array[i];
        
    }
}


void fourthTask()
{
    cout <<"\t\t\t FOURTH TASK " << endl;

    int arrayLength = 0;
    cout << "Enter an array length ";
    cin >> arrayLength;
    arrayLength *= 2;
    
    int* myArray = new int[arrayLength];
    cout << endl << "Enter array elements:" << endl;
    fillArray(myArray, arrayLength);

    delete[] myArray;
}


int main()
{
    firstTask();
    //secondTask();
    //thirdTask();

    return 0;
}
