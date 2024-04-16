// Pointeri.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

void foo(int a)
{
    std::cout << "Adresa var a in functia foo este: " << &a << std::endl;
    std::cout << "Val lui a este " << a << std::endl;
}


void foo_pointeri(int* a)
{
    std::cout << "Adresa var a in functia foo_pointeri este: " << a << std::endl;
    std::cout << "Val lui a in functia foo_pointeri este : " << *a << std::endl;
    *a = 99;
}


void bad_function(int* ptr)
{

    int temp;
    ptr = &temp;
}

void initUserApp(std::string* user_name)
{
    if (user_name == nullptr)
    {
        std::cout << "User alredy configured\n";
    }
    else 
    {
        
        std::cout << "Creating user name\n";
        *user_name = "Vociu";
    }
}


void reverseString(std::string& input)
{
    std::string res = "";
    for (int i = input.length()-1; i >= 0; i--)
    {
        res += input[i];
    }
    input = res;


}

int main()
{
    int test = 99;
    bad_function(&test);
    std::cout << "Val lui test este " << test << std::endl;
    std::string* my_user_ptr = nullptr; //merge intializati si cu NULL asta e mostenit din c sau chiar merge si cu 0
    std::string user;
    my_user_ptr = &user;
    initUserApp(my_user_ptr);
    const int* my_int = &test;
   // *my_int = 99; nu merge deoarece avem erroare

    int a = 5;
    my_int = &a;
    //std string este un fel de const char *
    int my_array[5] = { 1 , 2 ,3 ,4 ,5 };
    int* my_iterator = &my_array[0];
    for (int i = 0; i < 5; i++)
    {
        std::cout << *my_iterator << std::endl;
        std::cout << "adresa spre care pointuie my_iterator " << my_iterator << std::endl;
        my_iterator++;

    }


    //& --> operator addresOf -> ne returneaza adresa variabilei
    std::cout << "Adresa var a in main este: " << &a << std::endl;
    //val lui a din maine va fi copiata in a-ul din foo
    foo(a);
    foo_pointeri(&a);
    std::cout << "Val lui a dupa foo_pointeri este " << a << std::endl;







    std::string* food_ptr; // * inseamna pointer
    std::string mancare = "Pizza";
    food_ptr = &mancare; // am facut ca pointerul nostru sa arate catre adresa lui mancare

    std::cout << "Adresa lui mancare: " << &mancare << std::endl;
    std::cout << "Pointerul mancare: " << food_ptr << std::endl;

    // *food_ptr=este pointerul food_ptr dereferentiat 
    std::cout << "Valuarea adrasei la care pointuie food_ptr" << *food_ptr << std::endl;
    std::cout << "Val originala a lui mancare " << mancare << std::endl;
    *food_ptr = "Shaworma";
    std::cout << "Val lui mancare dupa modificare este " << mancare << std::endl;

    int* test_ptr;

    {
        int var_local = 5;
        // nu ii oke din punct de vedere logic
        //poate genera comportamente nedefinit
        //var_local este "distrusa" dupa ce se termina scope-ul
        // iar test_ptr ramane agatat de adresa respectiva
        test_ptr = &var_local;
    }//scope local
    //var_local nu mai exista deoarece este o variabila locala in scope-ul local ;
    std::cout << "Val lui test_ptr" << *test_ptr << std::endl;
    *test_ptr = 100;
    std::cout << "Val lui test_ptr" << *test_ptr << std::endl;




    std::string food = "Bergher";
    std::string& my_ref = food;
    std::cout << "My food is " << food << std::endl;
    my_ref = "Ciola";
    std::cout << "My food is " << food << std::endl;


    std::string next_food = my_ref; //next food este Ciola
    my_ref = "Bergher";
    std::cout << "My food is " << food << std::endl;
    std::cout << "My  nextfood is " << next_food << std::endl;
    my_ref = next_food;
    std::cout << "My  nextfood is " << my_ref << std::endl;
    std::cout << "My food is " << food << std::endl;
    reverseString(food);
    std::cout << "My food is " << food << std::endl;










}
