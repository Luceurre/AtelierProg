//
// Created by pglandon on 4/17/20.
//

#ifndef ATELIERPROG_SINGLETON_H
#define ATELIERPROG_SINGLETON_H


class Singleton {
public:
    static int a;
};

class Singleton2 {
public:
    static int b;
};

class A : public Singleton, public Singleton2 {

};

class B : public Singleton {

};


#endif //ATELIERPROG_SINGLETON_H
