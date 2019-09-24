//
//  main.cpp
//  goMockInterview
//
//  Created by Yuqi Cao on 9/23/19.
//  Copyright © 2019 GT. All rights reserved.
//

#include <iostream>

int findKth(int* a, int* b, int k, int sizeA, int sizeB);

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    //testcase1, expected 3
    int arrayA[] = {2, 3, 4, 5};
    int arrayB[] = {3, 4, 5, 6};
    int sizeA = sizeof(arrayA) / sizeof(arrayA[0]);
    int sizeB = sizeof(arrayB) / sizeof(arrayB[0]);
    std::cout << findKth(arrayA, arrayB, 3, sizeA, sizeB) << std::endl;
    //testcase2, expected 5
    int arrA[] = {2, 3};
    int arrB[] = {4, 5, 6};
    int tstsizeA = sizeof(arrA) / sizeof(arrA[0]);
    int tstsizeB = sizeof(arrB) / sizeof(arrB[0]);
    std::cout << findKth(arrA, arrB, 4, tstsizeA, tstsizeB) << std::endl;
    //testcase3, expected 6
    int aa[] = {5, 6, 7};
    int bb[] = {4};
    int tstsizeAA = sizeof(aa) / sizeof(aa[0]);
    int tstsizeBB = sizeof(bb) / sizeof(bb[0]);
    std::cout << findKth(aa, bb, 3, tstsizeAA, tstsizeBB) << std::endl;
    //testcase4
    int testA[] = {6};
    int testB[] = {5};
    std::cout << findKth(testA, testB, 1, 1, 1) << std::endl;
    return 0;
}

int findKth(int* a, int* b, int k, int lengthA, int lengthB) {
    if (k > lengthA + lengthB) {
        throw "invalid k";
    }
    if (k == lengthA + lengthB) {
        return *(a+ lengthA - 1) > *(b + lengthB - 1) ? *(a+ lengthA - 1) : *(b + lengthB - 1);
    }
    int countForTotal = 0;
    int result = 0;
    int countA = 0;
    int countB = 0;
    while (countForTotal < k && countA < lengthA && countB < lengthB) {
        int intA = *a;//2; 3; 4
        int intB = *b;//3
        if (intA <= intB) { //2 < 3; 3 <= 3; 4 > 3
            result = intA;
            a++; //1; 2
            countA++;
        } else {
            result = intB;
            b++; //0; 1
            countB++;
        }
        countForTotal++; //1; 2; 3
    }
    if (countForTotal == k) {
        return result;
    } else {
        //countForTotal < k, we’ve gone through a list already, we still need to increment
        if (countA < lengthA) {
            a += (k - 1 - countForTotal);//0+ (3-1) = 2
            return *a;//6
        } else {
            b += (k - 1 - countForTotal);//0 + (4 - 2) = 2
            return *b;
        }
    }
}
