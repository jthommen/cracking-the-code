/*
###
Question 3.6: Animal Shelter
###

Description:
An animal shelter, which holds only dogs and cats, operates on a strict "first in, 
first out" basis. People must adopt either the "oldest" (based on arrival time) of
all animals at the shelter, or they can select whether they would prefer a dog or a cat
(and will receive the oldest animal of that type). They cannot select which specific
animal they would like. Create the data structures to maintain this system and 
implement operations such as enqueue, dequeueAny, dequeueDog, and dequeueCat.
You may use the built in LinkedList data structure.


*/
#include<cmath>
#include<iostream>
#include<list>
using namespace std;

class AnimalShelter
{
private:
    list<int> cats;
    list<int> dogs;
    int arrival;
public:
    AnimalShelter(): arrival{0} {};
    enum Animal {cat, dog};
    void enqueue(Animal);
    int dequeueAny();
    int dequeueCat();
    int dequeueDog();
};

void AnimalShelter::enqueue(Animal a)
{
    int t = ++arrival;
    if(a == cat) cats.push_front(t);
    if(a == dog) dogs.push_front(t);
}

int AnimalShelter::dequeueAny()
{
    
    int animal = min(cats.back(), dogs.back());
    cats.back() < dogs.back() ? cats.pop_back() : dogs.pop_back();
    return animal;
}

int AnimalShelter::dequeueCat()
{
    int cat = cats.back();
    cats.pop_back();
    return cat;
}

int AnimalShelter::dequeueDog()
{
    int dog = dogs.back();
    dogs.pop_back();
    return dog;
}



int main()
{
    AnimalShelter shelter;

    for(int i=0; i<15; i++)
        shelter.enqueue(static_cast<AnimalShelter::Animal>(rand()%2));

    cout << "Random: " << shelter.dequeueAny() << endl;
    cout << "Cat: " << shelter.dequeueCat() << endl;
    cout << "Dog: " << shelter.dequeueDog() << endl;
    
}
