#include <bits/stdc++.h>
using namespace std ;
int main(int argc, char const *argv[])
{
    int a = 5, b = 3;
    //reference  https://stackoverflow.com/questions/24853/what-is-the-difference-between-i-and-i
    //case 1.
    printf("a++: %d, b++: %d\n",a++, b++); //post increment 5 3 (but the real value has been incresed to 6 4)
    printf("++a: %d, ++b: %d\n",++a ,++b); //pre increment directly output the pre increment vvalue, so 7, 5
    //case 2.
    a = 5, b = 3;
    a = a++ + ++a; //post increment first so a = 5(return the incremented value before being incremented) then add ++a directly pre increment, so finally a = 6 + 7 = 13
    b = b++;//same idea as above so a++ first , return the original value first and then incremented.
    printf("a: %d, b: %d\n",a , b); //

    b = 3;
    b++;
    printf("a: %d, b: %d\n",a , b); //

    ++b;
    printf("a: %d, b: %d\n",a , b); //

    b = 3;
    b = ++b;//pre increment, directly increment the value and return the incremented value.
    printf("a: %d, b: %d\n",a , b); //

    //case 3.
    a = 5, b = 3;
    a = a++ + ++a + a++;
    //evaluate the first a++ first , so return 5 and increment, then a is now6
    //then the last a++ so return 6 and increment, then a is now7
    //then finally the ++a increment first then return the incremented value, so a is now 8
    //the final value will be 5 + 6 + 8 = 19
    printf("a: %d\n",a );

    return 0;
}
