#include <cmath>
#include <cstring>
#include <iostream>

using namespace std;

// class Table

class Table {
public:
    Table()
    {
        cout << "Table::Table()\n";

        m_size = new int;
        m_color = new char[10];
    }

    Table(int t_size, char* t_color)
    {
        cout << "Table::Table( int, char* )\n";

        if (t_size > 0) {
            m_size = new int;
            *m_size = t_size;
        }
        else {
            cout
                << "Размер стола должен быть больше нуля, введено: "
                << t_size
                << ". Выход."
                << endl;

            exit(1);
        }

        m_color = new char[10];
        strcpy(m_color, t_color);
    }

    Table(int t_size)
    {
        cout << "Table::Table( int )\n";

        if (t_size > 0) {
            m_size = new int;
            *m_size = t_size;
        }
        else {
            cout
                << "Размер стола должен быть больше нуля. Введено: " << t_size << ". \nВыход." << endl;

            exit(1);
        }

        m_color = new char[10];
    }

    virtual ~Table()
    {
        cout << "Table::~Table()\n";

        delete m_size;
        delete[] m_color;
    }

    virtual void show()
    {
        cout
            << "Обычный стол:"
            << "\n\tразмер: " << *m_size
            << "\n\tцвет: " << m_color
            << endl;
    }

    virtual int calc_volume()
    {
        return pow(*m_size, 3);
    }

private:
    int* m_size;
    char* m_color;
};

// class CompTable : public Table

class CompTable : public Table {
public:
    CompTable()
        : Table()
    {
        std::cout << "CompTable::CompTable()\n";

        m_h = new int;
        m_material = new char[20];
    }

    CompTable(int t_size, char* t_color, int t_h, char* t_material) : Table(t_size, t_color)
    {
        cout << "CompTable::CompTable( int, char*, int, char* )\n";

        if (t_h > 0) {
            m_h = new int;
            *m_h = t_h;
        }
        else {
            cout
                << "Высота комп.стола должна быть больше нуля. Введено: " << t_h << ". Выход." << endl;

            exit(1);
        }

        m_material = new char[20];
        strcpy(m_material, t_material);
    }

    ~CompTable()
    {
        cout << "CompTable::~CompTable()\n";

        delete m_h;
        delete[] m_material;
    }

    virtual int calc_volume() override
    {
        return Table::calc_volume() + pow(*m_h, 3);
    }

    int calc_volume_ct()
    {
        return Table::calc_volume() + pow(*m_h, 3);
    }

    virtual void show() override
    {
        cout
            << "Компьютерный стол:"
            << "\n\tвысота: " << *m_h
            << "\n\tматериал: " << m_material << endl;
    }

private:
    int* m_h;
    char* m_material;
}; 

// class RoundTable : public Table

class RoundTable : public Table {
public:
    RoundTable()
        : Table()
    {
        cout << "RoundTable::RoundTable()\n";
        m_radius = 1.0;
    }

    RoundTable(int t_size, char* t_color, double t_radius)
        : Table(t_size, t_color)
    {
        cout << "RoundTable::RoundTable( int, char*, double )\n";

        if (t_radius > 0.0) {
            m_radius = t_radius;
        }
        else {
            cout 
            << "Радиус круг.стола должен быть больше нуля. Введено: " 
            << t_radius << endl;

            exit(1);
        }
    }

    ~RoundTable()
    {
        cout << "RoundTable::~RoundTable()\n";
    }

    int calc_volume_rt()
    {
        return calc_volume() + 3.14 * pow(m_radius, 2);
    }

    virtual int calc_volume() override
    {
        return Table::calc_volume() + 3.14 * pow(m_radius, 2);
    }

    virtual void show() override
    {
        cout
            << "Круглый стол:"
            << "\n\tрадиус: " << m_radius
            << endl;
    }

private:
    double m_radius;
}; 

const double get_table_cost(Table* table)
{
    return table->calc_volume() * 12; // 12 - стоимость единицы объёма

}

int main()
{
    setlocale(LC_ALL,"RU");
    cout << "Часть 1 (Наследование)\n\n";

    Table* table = new Table(10, "коричневый");
    table->show();
    table->calc_volume();

    delete table;
    table = nullptr;

    cout << std::endl;

    CompTable* ctable = new CompTable(10, "белый", 2, "ДСП");
    ctable->show();
    ctable->calc_volume_ct();

    delete ctable;
    ctable = nullptr;

    cout << std::endl;

    RoundTable* rtable = new RoundTable(12, "чёрный", 10);
    rtable->show();
    rtable->calc_volume_rt();

    delete rtable;
    rtable = nullptr;

    cout << std::endl << " Часть 2 (Полиморфизм)"<<endl;;

    Table* random_table;

    cout
        << "Выберите стол:"
        << "\n1. Обычный стол"
        << "\n2. Компьютерный стол"
        << "\n3. Круглый стол"
        << "\nВыбор: ";

    int choice = 0;
    cin >> choice;

    if (choice == 1) {
        cout << '\n';
        random_table = new Table(25, "коричневый");
    }
    else if (choice == 2) {
        cout << '\n';
        random_table = new CompTable(25, "белый", 30, "дерево");
    }
    else if (choice == 3) {
        cout << '\n';
        random_table = new RoundTable(25, "черный", 32);
    }
    else {
        return 0;
    }

    random_table->show();

    cout << "\nИтоговая цена стола: " << get_table_cost(random_table) << endl;

    delete random_table;
    random_table = nullptr;

    return 0;
}
