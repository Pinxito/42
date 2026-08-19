#include "../includes/Animal.hpp"
#include "../includes/Cat.hpp"
#include "../includes/Dog.hpp"

static void separator(std::string const &title)
{
    std::cout << std::endl;
    std::cout << "========== " << title << " ==========" << std::endl;
}

int main(void)
{
    separator("POLYMORPHIC ARRAY");
    Animal *animals[10];

    for (int i = 0; i < 10; i++)
    {
        if (i < 5)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
        std::cout << animals[i]->getType() << ": ";
        animals[i]->makeSound();
    }

    separator("DEEP COPY - COPY CONSTRUCTOR");
    Dog originalDog;
    originalDog.getBrain()->setIdeas("Original dog idea", 0);
    Dog copiedDog(originalDog);
    copiedDog.getBrain()->setIdeas("Copied dog changed idea", 0);

    std::cout << "Original dog brain: "
              << originalDog.getBrain()->getIdeas(0) << std::endl;
    std::cout << "Copied dog brain:   "
              << copiedDog.getBrain()->getIdeas(0) << std::endl;
    std::cout << "Different Brain addresses: "
              << (originalDog.getBrain() != copiedDog.getBrain()) << std::endl;

    separator("DEEP COPY - COPY ASSIGNMENT");
    Cat originalCat;
    originalCat.getBrain()->setIdeas("Original cat idea", 0);
    Cat assignedCat;
    assignedCat = originalCat;
    assignedCat.getBrain()->setIdeas("Assigned cat changed idea", 0);

    std::cout << "Original cat brain: "
              << originalCat.getBrain()->getIdeas(0) << std::endl;
    std::cout << "Assigned cat brain: "
              << assignedCat.getBrain()->getIdeas(0) << std::endl;
    std::cout << "Different Brain addresses: "
              << (originalCat.getBrain() != assignedCat.getBrain()) << std::endl;

    separator("SUBJECT SCOPE TEST");
    Dog basic;
    basic.getBrain()->setIdeas("Basic survives", 1);
    {
        Dog tmp = basic;
        tmp.getBrain()->setIdeas("Temporary copy", 1);
        std::cout << "tmp:   " << tmp.getBrain()->getIdeas(1) << std::endl;
        std::cout << "basic: " << basic.getBrain()->getIdeas(1) << std::endl;
    }
    std::cout << "basic after tmp destruction: "
              << basic.getBrain()->getIdeas(1) << std::endl;

    separator("DELETE THROUGH ANIMAL POINTER");
    for (int i = 0; i < 10; i++)
        delete animals[i];

    return (0);
}
