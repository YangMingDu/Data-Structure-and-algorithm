#include <iostream>
#include <cassert>
#include "unionFindTestHelper.h"

using namespace ::std;



int main(){
    int n = 10000;
   /*  int n = 100000;*/
    unionFindTestHelper::testUF1(n);
    unionFindTestHelper::testUF2(n);

    return 0;
}