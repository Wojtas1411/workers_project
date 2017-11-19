#ifndef WORKERS_PROJECT_WORKER_H
#define WORKERS_PROJECT_WORKER_H
#include<iostream>
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
    virtual ~worker();
};

class leader: public worker {
private:
    int office_number;
protected:
    void set_office_nuber_console();
public:
    void show_office_number();
    virtual void show();
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
    virtual void show();
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
    virtual void show();
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
    virtual void show();
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
    virtual void show();
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
    virtual void show();
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
    virtual void show();
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
    virtual void show();
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
    virtual void show();
    IT_guy();
    virtual ~IT_guy();
};


#endif //WORKERS_PROJECT_WORKER_H
