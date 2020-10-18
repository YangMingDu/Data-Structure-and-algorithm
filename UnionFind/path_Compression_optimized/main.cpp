#include <iostream>
#include <cassert>
#include "unionFindTestHelper.h"

using namespace ::std;



int main(){
    int n = 1000000;
   /*  int n = 100000;*/

    unionFindTestHelper::testUF6(n);
    unionFindTestHelper::testUF5(n);

    return 0;
}