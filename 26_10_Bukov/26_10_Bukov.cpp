#include <iostream>
#include <string>

class Animal 
{
public:
    Animal(const std::string& name, const std::string& type)
        : name(name), type(type) {}

    virtual void printInfo() const = 0;

protected:
    std::string name;
    std::string type;
};

class Dog : public Animal 
{
public:
    Dog(const std::string& name, int age, const std::string& color)
        : Animal(name, "Собака"), age(age), color(color) {}

    void printInfo() const override 
    {
        std::cout << type << " по имени " << name << " возраст: " << age << " лет, окрас: " << color << std::endl;
    }

private:
    int age;
    std::string color;
};

class Cat : public Animal 
{
public:
    Cat(const std::string& name, bool tail, const std::string& eyeColor)
        : Animal(name, "Кошка"), tail(tail), eyeColor(eyeColor) {}

    void printInfo() const override 
    {
        std::cout << type << " по имени " << name << " " << (tail ? "имеет хвост" : "без хвоста") << ", цвет глаз: " << eyeColor << std::endl;
    }

private:
    bool tail;
    std::string eyeColor;
};

class Parrot : public Animal 
{
public:
    Parrot(const std::string& name, const std::string& species, bool canSpeak)
        : Animal(name, "Попугай"), species(species), canSpeak(canSpeak) {}

    void printInfo() const override 
    {
        std::cout << type << " по имени " << name << " вида " << species << " " << (canSpeak ? "умеет говорить" : "не умеет говорить") << std::endl;
    }

private:
    std::string species;
    bool canSpeak;
};

int main() {
    setlocale(LC_ALL, "rus");
    Dog dog("Рекс", 5, "коричневый");
    Cat cat("Барсик", true, "зеленый");
    Parrot parrot("Кеша", "Ара", true);

    dog.printInfo();
    cat.printInfo();
    parrot.printInfo();

    return 0;
}
