//#1
#include<stdio.h>

struct StructureExample {
    int intvalue;
    float floatvalue;
};

union unionExample {
    int intvalue;
    float floatvalue;
};

int main(){
    struct StructureExample structInstance;
    structInstance.intvalue = 42;
    structInstance.floatvalue = 3.14;
    printf("\nStructure Example: %d   %f",structInstance.intvalue, structInstance.floatvalue);

    union unionExample unionInstance;
    unionInstance.intvalue = 42;
    unionInstance.floatvalue = 3.14;
    printf("\nUnion Example: %d   %f",unionInstance.intvalue, unionInstance.floatvalue);

    return 0;
}

