#include "Header.h"

int main() {
    std::ifstream file("text.txt");
    CheckIfstreamFile(file);
    std::ofstream outFile ("outText.txt");
    CheckIfstreamFile(outFile);
    int32_t arrSize = {};
    int32_t numOfVariant = {};
    int32_t outputNumOfVariant = {};

    ChooseHowFillArr(numOfVariant);
    outputNumOfVariant = numOfVariant;
    FindArrSize(file,arrSize,numOfVariant);

    double* nums = new double[arrSize];

    FillArr(file, nums, arrSize, numOfVariant);
    ChooseSort(numOfVariant);
    SortArr(nums, arrSize, numOfVariant);
    OutputArr(outputNumOfVariant,outFile, nums, arrSize);
    
   file.close();
   outFile.close();
   delete[] nums;

   std::cout << "Now create array of students\n";
   InputArrSizeFromConsole(arrSize);
   Student* students = new Student[arrSize];
   InputInfoAboutStudents(students, arrSize);
   QuickSort(students,0,arrSize - 1);
   ChooseTipeOfSort(numOfVariant);
   OutputStudent(students, arrSize);

   delete[] students;
    return 0;
}