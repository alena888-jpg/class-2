#include <iostream>
using namespace std;
class Мужчина;
class Женщина;
class Выпускник;
class Работник;

class Человек {//привет
public:
    enum Sex
    {
        Male,
        Female,
    };
    Человек() {// Конструктор
        std::cout << this << "Привет Человек!\n";
    }
    Человек(const std::string& имя, int рост, int вес) 
        : 
        имя(имя), 
        рост(рост),     
        вес(вес)
    {}  

    int getHeight()
    {
        return рост;
    }
    void setВес(int value) {
        вес = value;
    }
    void printData()
    {
        std::cout << имя << " рост: " << рост << " , вес: " << вес << std::endl;
    }    
    bool operator==(const Человек& other) const
    {
        return false;
    }
protected:
    std::string имя;
    int рост;
    int вес;
    Sex sex;
    };
class Мужчина : public Человек {//Наследование класса мужчина от класса человека
    public:
    Мужчина() 
        : Человек("безымянный", 0, 0)
    {  
    }
    Мужчина(const std::string& имя, int рост, int вес)
    : Человек(имя, рост, вес)        
    {
        sex = Sex::Male;// Мужчина это человек мужского пола
    }
    void print() {
        std::cout << "Имя: " << Человек::имя << ", Рост: " << рост << " см, Вес: " << вес << " кг, пол: " <<  convertSex(sex) << std::endl;
    }
    private:
    std::string convertSex(Sex enumSex)
    {
        if (enumSex == Sex::Male) {
            return "мужской";
        }
        else if (enumSex == Sex::Female)
        {
            return "женский";
        }
    }
};
class Женщина : public Человек {
public:
    Женщина ()
        : Человек("безымянный", 0, 0)
    {
    }
    Женщина(const std::string& имя, int рост, int вес) 
        : Человек(имя, рост, вес) 
    {
        sex = Sex::Female;//Женщина это человек женского пола
    }
    void print() {
        std::cout << "Имя: " << Человек::имя << ", Рост: " << рост << " см, Вес: " << вес << " кг,  пол: " << convertSex(sex) << std::endl;
    }
private:

    std::string convertSex(Sex enumSex)
    {
        if (enumSex == Sex::Male) {
            return "мужской";
        }
        else if (enumSex == Sex::Female)
        {
            return "женский";
        }
    }
};
class Выпускник : public Человек {
    std::string университет;

public:
    Выпускник()
        : Человек("безымянный", 0, 0)
    {
    }
    Выпускник(const std::string& имя, int рост, int вес, const std::string& университет)
        : Человек(имя, рост, вес),
        университет(университет)
    {}
    void print() {
        std::cout << "Имя: " << имя << ", Рост: " << рост << " см, Вес: " << вес << " кг, Университет:" << университет << std::endl;
    }
};

class Работник : public Человек {
    std::string компания;

public:
    Работник()
        : Человек("безымянный", 0, 0)
    {
    }
    Работник(const std::string& имя, int рост, int вес, const std::string& компания)
        : Человек(имя, рост, вес) 
        ,компания(компания)
    
    {}
    void print() {
        std::cout << "Имя: " << имя << ", Рост: " << рост << " см, Вес: " << вес << " кг, Компания: " << компания << std::endl;
    }
};
int main() 
{
    setlocale(LC_ALL, "Russian");
    //SetConsoleOutputCP(866);
    Человек парень("Элвин", 160, 55);
    парень.getHeight();
    парень.setВес(65);
    парень.printData();
    Мужчина парень2("Мэт", 183, 79);
    парень2.getHeight();
    парень2.setВес(75);
    парень2.print();
    Человек соседка("Эльвира", 185, 75);
    соседка.printData();
    Женщина соседка2("Мила", 170, 79);
    соседка2.print();
    Выпускник выпускник1("Петр", 175, 70, "МГУ");
    выпускник1.print();
    Работник работник1("Анна", 168, 60, "Google");
    работник1.print();
    Мужчина* thatMan = new Мужчина();
    Женщина* thatWoman = new Женщина();
    Выпускник* thatHuman = new Выпускник();
    Работник* Person = new Работник();
    return 0;
}

