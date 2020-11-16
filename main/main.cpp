//3.	Интернет - соединение(Dial - Up, ADSL, 4G, выделенная линия).
//Функция вычисления времени передачи файла объемом N ГБ(скорости определить самостоятельно).
//Найти самое короткое время передачи файла.

#include <iostream>
using namespace std;

class Internet
{
private:
    int speed;
public:
    Internet() { this->speed = 1; }
    virtual double funk(int size) { return (double)size / this->speed; }
};

class Dual_Up :public Internet
{
private: int skorost;
public:
    Dual_Up() { this->skorost = 3; }
    double funk(int size) override { return (double)size / this->skorost; }
};

class ADSL :public Internet
{
private: int s;
public:
    ADSL() { this->s = 5; }
    double funk(int size) override { return (double)size / this->s; }
};

class G_4 :public Internet
{
private: int sa;
public:
    G_4() { this->sa = 10; }
    double funk(int size) override { return (double)size / this->sa; }
};

class DopLine :public Internet
{
private: int v;
public:
    DopLine() { this->v = 100; }
    double funk(int size) override { return (double)size / this->v; }
};

int main()
{
    Dual_Up q;
    ADSL w;
    G_4 e;
    DopLine r;

    Internet** alfa = new Internet*[4];
    alfa[0] = &q; 
    alfa[1] = &w;
    alfa[2] = &e;
    alfa[3] = &r;

    int a;
    double min = INT_MAX;
    cin >> a;

    for (int i = 0; i < 4; i++)
        if (alfa[i]->funk(a) < min) min = alfa[i]->funk(a);

    cout << "Min time is " << min << " minutes";

    delete[] alfa;

    return 0;
}