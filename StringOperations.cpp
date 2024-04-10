// StringOperations.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int stringLength(char str[])
{
    int length = 0;
    for (int i = 0; str[i] != '\0'; i++)
        length++;

    return length;
}

void toUpperCaseStr(char str[])
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] >= 97 && str[i] <= 122)
            str[i] = str[i] - 32;
    }
}

void toLowerCaseStr(char str[])
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] >= 65 && str[i] <= 90)
            str[i] = str[i] + 32;
    }
}

void title(char str[])
{
    if (str[0] >= 97 && str[0] <= 122)
        str[0] = str[0] - 32;
}

bool isStringValid(char str[])
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (!(str[i] >= 97 && str[i] <= 122)
            && !(str[i] >= 65 && str[i] <= 90)
            && !(str[i] >= 48 && str[i] <= 57))
            return false;
    }

    return true;
}

void reverseString(char str[])
{
    int i = 0, j = 0;
    for (j = 0; str[j] != '\0'; j++)
    {
        //dummy loop
    }

    j--;
    while (i < j)
    {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        
        i++;
        j--;
    }
}

//isAnagram - done using Hash table
bool isAnagram(char str1[], char str2[])
{
    int str1length = 0, str2length = 0;
    int i = 0, j = 0;
    int H[25] = { 0 };

    for (i = 0; str1[i] != '\0'; i++)
        str1length++;
    
    for (j = 0; str2[j] != '\0'; j++)
        str2length++;

    if (str1length != str2length)
        return false;

    
    for (i = 0; str1[i] != '\0'; i++)
        H[str1[i] - 97]++;

    for (j = 0; str2[j] != '\0'; j++)
    {
        H[str1[j] - 97]--;
        if (H[str1[j] - 97] < 0)
        {
            return false;
        }
    }

    return true;

}
//using bitwise operations
void findDuplicatesInString(char str[])
{
    int i = 0;
    long x = 0, h = 0;
    while (str[i] != '\0')
    {
        x = 1;
        x = x << (str[i] - 97);

        if ((x & h) > 0)
            std::cout << "Duplicate letter " << str[i] << std::endl;
        else
            h = x | h;

        i++;
    }

    return;
}

void getVowelAndConsonantCount(char str[], int &nVowels, int &nConsonants)
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (!(str[i] >= 97 && str[i] <= 122) && !(str[i] >= 65 && str[i] <= 90))
            continue;

        if (str[i] == 'a' || str[i] == 'A' || str[i] == 'e' || str[i] == 'E'
            || str[i] == 'i' || str[i] == 'I' || str[i] == 'o' || str[i] == 'O'
            || str[i] == 'u' || str[i] == 'U')
            nVowels++;
        else
            nConsonants++;
    }

    return;
}

//given string ABC -- generate all possible permutations 
//1. ABC, ACB, BAC, BCA, CAB, CBA
//Built using Backtracking and Recursion
void stringPermutation(char s[], int k)
{
    static int indexFlags[256] = {0};
    static char result[256] = { '\0' };

    if (s[k] == '\0')
    {
        result[k] = '\0';
        std::cout << result << "\n";
    }
    else
    {
        for (int i = 0; s[i] != '\0'; i++)
        {
            if (indexFlags[i] != 0)
                continue;

            indexFlags[i] = 1;
            result[k] = s[i];

            stringPermutation(s, k + 1);
            indexFlags[i] = 0;
        }
    }
}

void stringPermutationBySwapping(char s[], int l, int h)
{
    if (l == h)
    {
        std::cout << s << "\n";
    }
    else
    {
        for (int i = l; i <= h; i++)
        {
            {
                char temp = s[i];
                s[i] = s[l];
                s[l] = temp;
            }

            stringPermutationBySwapping(s, l + 1, h);

            {
                char temp = s[i];
                s[i] = s[l];
                s[l] = temp;
            }
        }
    }
}

int main()
{
    char str[] = "finding", strPermutation[] = "ABC";

    findDuplicatesInString(str);

    char s1[] = "decimal", s2[] = "medical", svalidateStr[] = "AliNadim12";
    if (isAnagram(s1, s2))
        std::cout << "The strings are anagram" << std::endl;
    else
        std::cout << "The strings are not an anagram" << std::endl;

    reverseString(s1);
    std::cout << "The reversed string is " << s1 <<std::endl;


    if (isStringValid(svalidateStr))
        std::cout << "The string is valid" << std::endl;
    else
        std::cout << "The string is not valid" << std::endl;

    std::cout << "String permutation by backtracking and recursion" << std::endl;
    stringPermutation(strPermutation, 0);

    std::cout << "String permutation by swapping and recursion" << std::endl;
    stringPermutationBySwapping(strPermutation, 0, strlen(strPermutation) - 1);
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
