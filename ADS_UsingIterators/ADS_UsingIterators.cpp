// ADS_UsingIterators.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <list>
using namespace std;

/// @brief Prints a list of integers
/// @param list 
void print(std::list<int> list) {
    for (int x : list)
        cout << x << endl;
}

/// @brief Prints a list of elements
/// @tparam E Element of a list
/// @param list 
template <typename E>
void print(std::list<E> list) {
    for (E ele : list)
        cout << ele << endl;
}


template <typename Iter>
void print(Iter iter, Iter end) {
    while (iter != end){
        cout << *iter << endl;
        iter++;
    }
}

/// @brief Demos how to use list iterators and related methods (
void demoUsingListIterators();
/// @brief Demos how we can write a highly generic print function using iterators
void demoGenericPrint();

int main()
{
    cout << endl << "demoUsingListIterators..." << endl;
    demoUsingListIterators();

    cout << endl << "demoGenericPrint..." << endl;
    demoGenericPrint();
}

/// @brief Demos use of iterator related methods for the list
void demoUsingListIterators(){
    std::list<int> agesList = { 1, 2, 3, 4, 5, 6 };
    //agesList.push_back(25); //remember we can use push_front, push_back to add values also

    //printing without using an iterator
    for (int x : agesList)
        cout << x << endl;

    cout << endl;
    //demo iterating through a list of ints using iterator
    std::list<int>::iterator it1 = agesList.begin();
    cout << *it1 << endl; //1
    it1++;
    cout << *it1 << endl; //2

    cout << endl;
    //iterating through a list using begin and end
    for (std::list<int>::iterator it = agesList.begin();
                                    it != agesList.end(); it++) {
        cout << *it << endl; //2
    }

    cout << endl;
    //reverse iterating through a list using begin and end
    std::list<int> yearList = { 2019, 2012, 1999, 1978, 1999 };
    auto it = yearList.end();
    while (it != yearList.begin()) {
        it--;
        cout << *it << endl;
    }

    cout << endl;
    //demo iterating through a list of ints using const_iterator
    for (std::list<int>::const_iterator cIt = yearList.cbegin(); cIt != yearList.cend(); cIt++) {
        cout << *cIt << endl; //2
    }
  
    cout << endl;
     //demo iterating through a list of ints using reverse_iterator
    std::list<int>::reverse_iterator rIt = yearList.rend(); //rend() returns the same iterator position as begin()
    --rIt;
    cout << *rIt << endl;
     --rIt;
    cout << *rIt << endl;

    //demo iterating through a list of ints using const_reverse_iterator
    std::list<int>::const_reverse_iterator crIt = yearList.rend();
    --crIt;
    cout << *crIt << endl;
    --crIt;
    cout << *crIt << endl;

    //to do...size, clear, emplace, remove_if, sort, merge, reverse, splice
}

/// @brief Demos use of print methods that using generics and iterators
void demoGenericPrint() {

    //print that takes elements E
    std::list<int> agesList = { 1, 2, 3, 4, 5, 6 };
    print(agesList);

    //print using iterators 
    cout << endl;
    cout << "Use print() to print using the iterators..." << endl;
    print(agesList.begin(), agesList.end());

    //print in REVERSE using iterators 
    cout << endl;
    cout << "Use print() to print in reverse by just changing the iterators..." << endl;
    print(agesList.rbegin(), agesList.rend());
}
