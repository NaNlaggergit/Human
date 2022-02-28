
#include <iostream>
#include <string>
#include <locale>
#include <cstdlib>
#include <time.h>
#include <vector>
#include <math.h>
using namespace std;
class Walk {                     
public:
    int speed;
    Walk() {
        speed = rand() % 5 + 1;
    }
    int getSpeed(){
        return speed;
    }
};
class GCS : public Walk{
public:
    double longtitude;
    double latitude;
    vector<double> miliage;
    double path;
    GCS(double longt, double latit) : Walk() {
        if (longt >= 0 && longt <= 180) longtitude = longt;
        else {
            cout << "ОШИБКА: Неверно задана долгота" << endl;
            longtitude = -1;
        }
        if (latit >= 0 && latit <= 90) latitude = latit;
        else {
            cout << "ОШИБКА: Неверно задана широта" << endl;
            latitude = -1;
        }
    }

    void setGcs(double longt, double latit) {
        longtitude = longt;
        latitude = latit;
    }
    void randWalk(){
        int flag = 0;
        flag = rand() % 2;
        double lon1 = longtitude;//начальная долгота
        double lat1 = latitude;//широта
        if(flag==0){
            longtitude = longtitude + ((rand()%1000000000)/static_cast<double>(2000000000));
            latitude = latitude + ((rand() % 1000000000) / static_cast<double>(2000000000));
        }
        if(flag==1)
        {
            longtitude = longtitude - ((rand() % 1000000000) / static_cast<double>(2000000000));
            latitude = latitude - ((rand() % 1000000000) / static_cast<double>(2000000000));
        }
        walk_mileage(lon1, lat1);
    }
    void walk_mileage(double lon1, double lat1){
        path += 111.2 * sqrt((abs(lon1 - longtitude)) * (abs(lon1 - longtitude)) + (abs(lat1 - latitude)) * cos(3.14 * lon1 / 180) * (abs(lat1 - latitude)) * cos(3.14 * lon1 / 180));
        miliage.push_back(path);
    }
    void getPath(){
        cout << "Км пройдено: ";
        cout<<path<<endl;
    }
    double getLongtitude() {
        return longtitude;
    }

    double getLatitude() {
        return latitude;
    }

    void getGcs() {
        cout << "\nДолгота: " << getLongtitude() << endl;
        cout << "Широта: " << getLatitude() << endl;
    }
};
class Human : public GCS {
private:
    string firstname;
    string secondname;
    string middlename;
    double height;
    int speed;
    double weight;
public:
    Human(string fn, string sn, string mn, double w, double h, double longt, double latit) : GCS(longt, latit) {
        firstname = fn;
        secondname = sn;
        middlename = mn;
        weight = w;
        height = h;
        speed = getSpeed();
    }

    void setFirstname(string fn) {
        firstname = fn;
    }
    string getFirstname() {
        return firstname;
    }

    void setSecondname(string sn) {
        secondname = sn;
    }
    string getSecondname() {
        return secondname;
    }

    void setMiddlename(string mn) {
        middlename = mn;
    }
    string getMiddlename() {
        return middlename;
    }
    void getName() {
        cout << "ФИО: " << getSecondname();
        cout << " " << getFirstname();
        cout << " " << getMiddlename();
    }
    void set_name(string fn, string sn, string mn) {
        firstname = fn;
        secondname = sn;
        middlename = mn;
    }

    void setHeight(double h) {
        height = h;
    }
    double getHeight() {
        return height;
    }

    double getWeight() {
        return weight;
    }

    void getParameters() {
        cout << "\nВес: " << getWeight() << endl;
        cout << "Рост: " << getHeight() << endl;
    }
    void setParameters(double w, double h) {
        weight = w;
        height = h;
    }
};

int main()
{
    srand(time(NULL));//для рандомазера чисел
    setlocale(LC_ALL, "RUS");
    double w, h;
    Human* human_1 = new Human("Кирилл", "Ляшенко", "Евгеньевич", 79, 186, 55, 82.9);
    for (int i = 0; i < 1000; i++) {
        human_1->randWalk();
    }
    human_1->getName();
    human_1->getParameters();
    human_1->getGcs();
    human_1->getPath();
    cout << endl;
}
