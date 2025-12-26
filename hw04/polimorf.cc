#include <iostream>

class Animal {
public:
    virtual void speak() const{
        std::cout << "moo\n";
    };   
    virtual void action() const{

    }; 
    virtual ~Animal() = default;
};

class Dog : public Animal {
public:
    void speak() const  {
        std::cout << "Dog: woof\n";
    }

    void action() const override { 
        std::cout << "Dog: serves\n";
    }
};

class Cat : public Dog {  
public:
    void speak() const override {
        std::cout << "Cat: meow\n";
    }

    void action() const override {
        std::cout << "Cat: poops\n";
    }
};

int main() {
    Animal* a1 = new Dog();
    Animal* a2 = new Cat();

    a1->speak(); 
    a1->action();  

    a2->speak();   
    a2->action();  

    delete a1;
    delete a2;

    Dog dog;
    Cat cat;

    
    Animal& a3 = dog;
    Animal a4 = cat;

    a3.speak();   
    a3.action();   

    a4.speak();    
    a4.action(); 

    return 0;
}


// #include <iostream>

// class Character {
// public:
//     virtual void attack() const = 0;
//     virtual ~Character() = default;
// };

// class Warrior : public Character {
// public:
//     void attack() const override {
//         std::cout << "Warrior swings a sword!\n";
//     }
// };

// class Mage : public Character {
// public:
//     void attack() const override {
//         std::cout << "Mage casts a fireball!\n";
//     }
// };

// int main() {
//     Warrior w;
//     Mage m;
//     Character& c1 = w;
//     Character& c2 = m;

//     c1.attack();
//     c2.attack();

//     return 0;
// }
