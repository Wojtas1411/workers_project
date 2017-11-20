#ifndef WORKERS_PROJECT_WORKER_H
#define WORKERS_PROJECT_WORKER_H
#include<iostream>
#include<fstream>
using namespace std;

//TODO not console constructors

class worker {
private:
    string name;
    int salary;
protected:
    void set_name_console();
    void set_name_value(std:: string tmp);
    void set_salary_console();
    void set_salary_value(int tmp);

public:
    virtual void get_name_console();
    string get_name_value();
    virtual void get_salary_console();
    int get_salary_value();
    worker();
    virtual void show();
    virtual void to_file(ofstream& save);
    virtual ~worker();
};

class leader: public worker {
private:
    int office_number;
protected:
    void set_office_nuber_console();
public:
    void show_office_number();
    int get_office_number_value();
    virtual void show();
    virtual void to_file(ofstream& save);
    leader();
    virtual ~leader();
};

class director: public leader {
private:
    string car;
protected:
    void set_car_console();
public:
    void show_car();
    string get_car_value();
    virtual void show();
    virtual void to_file(ofstream& save);
    director();
    virtual ~director();
};

class manager: public leader {
private:
    int team_id;
protected:
    void set_team_id_console();
public:
    void show_team_id();
    int get_team_id_value();
    virtual void show();
    virtual void to_file(ofstream& save);
    manager();
    virtual ~manager();
};

class casual: public worker {
private:
    int experiance;
protected:
    void set_experiance_console();
public:
    virtual void show_experiance();
    int get_experiance_value();
    virtual void show();
    virtual void to_file(ofstream& save);
    casual();
    virtual ~casual();
};

class salesman: public casual {
private:
    int region_id;
protected:
    void set_region_id_console();
public:
    void show_region_id();
    int get_region_id_value();
    virtual void show();
    virtual void to_file(ofstream& save);
    salesman();
    virtual ~salesman();
};

class office_worker: virtual public casual {
private:
    int box_id;
protected:
    void set_box_id_console();
public:
    void show_box_id();
    int get_box_id_value();
    virtual void show();
    virtual void to_file(ofstream& save);
    office_worker();
    virtual ~office_worker();
};

class maintenance_worker: virtual public casual {
private:
    string tool;
protected:
    void set_tool_console();
public:
    void show_tool();
    string get_tool_value();
    virtual void show();
    virtual void to_file(ofstream& save);
    maintenance_worker();
    virtual ~maintenance_worker();
};

class accountant: public office_worker {
private:
    int acces_level;
protected:
    void set_acces_level_console();
public:
    void show_acces_level();
    int get_acces_level_value();
    virtual void show();
    virtual void to_file(ofstream& save);
    accountant();
    virtual ~accountant();

};

class IT_guy: public office_worker, virtual public maintenance_worker {
private:
    string computer;
protected:
    void set_computer_console();
public:
    void show_computer();
    string get_computer_value();
    virtual void show();
    virtual void to_file(ofstream& save);
    IT_guy();
    virtual ~IT_guy();
};


#endif //WORKERS_PROJECT_WORKER_H
