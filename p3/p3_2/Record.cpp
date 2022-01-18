// The Record.cpp file that holds the methods of the Record.h class
// Created by Logan Brennaman on 10/18/21

#include <iostream>
#include "Record.h"

// Default constructor for the Record class
template<class T> Record<T>::Record()
{
    // This variable signifies that none of the important fields of a Record have been altered yet
    init = false;
}

// Second constructor: initializes the Record with a key
template<class T> Record<T>::Record(int key, T value)
{
    this->key = key;
    this->value = value;
    init = 1;
    gravestone = -1;
}

// Set methods
// setKey
template<class T> void Record<T>::setKey(int key)
{
    this->key = key;
}

// setValue
template<class T> void Record<T>::setValue(T value)
{
    this->value = value;
}

// setGrave
template<class T> void Record<T>::setGrave(int grave)
{
    gravestone = grave;
}

// setInit
template<class T> void Record<T>::setInit(bool init)
{
    this->init = init;
}

// Get methods
// getKey
template<class T> int Record<T>::getKey()
{
    return key;
}

// getValue
template<class T> T Record<T>::getValue()
{
    return value;
}

// getGrave
template<class T> int Record<T>::getGrave()
{
    return gravestone;
}

// initTrue
template<class T> bool Record<T>::initTrue()
{
    return init;
}

// Override the = operator
template<class T> Record<T>& Record<T>::operator=(const Record& other)
{
    this->key = other.key;
    this->value = other.value;
    this->gravestone = other.gravestone;
    this->init = other.init;
    return *this;
}