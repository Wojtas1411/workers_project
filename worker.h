#ifndef WORKERS_PROJECT_WORKER_H
#define WORKERS_PROJECT_WORKER_H
#include<iostream>
#include<fstream>
using namespace std;

class worker {
private:
    string name;
    int salary;
protected:
    int A;
    void set_name_console();//standard setters
    void set_name(string tmp);
    void set_salary_console();
    void set_salary(int x);
    void set_A_console();

public:
    void show_A();
    int get_A();
    virtual void get_name_console(); //standard getter to console
    string get_name_value(); //returns name value
    virtual void get_salary_console();
    int get_salary_value();
    worker(); //standard console constructor
    worker(ifstream& read); //file constructor
    virtual void show(); //shows all class variables
    virtual void to_file(ofstream& save); //saves to file all class variables
    virtual ~worker();
    virtual void modify();
};

class leader: public worker {
private:
    int office_number;
protected:
    int B;
    void set_office_nuber_console();
    void set_office_number(int x);
    void set_B_console();

public:
    void show_B();
    int get_B();
    void show_office_number();
    int get_office_number_value();
    virtual void show();
    virtual void to_file(ofstream& save);
    leader();
    leader(ifstream& read);
    virtual ~leader();
    virtual void modify();
};

class director: public leader {
private:
    string car;
protected:
    int D;
    void set_car_console();
    void set_D_console();
public:
    void show_D();
    int get_D();
    void show_car();
    string get_car_value();
    virtual void show();
    virtual void to_file(ofstream& save);
    director();
    director(ifstream& read);
    virtual ~director();
    virtual void modify();
};

class manager: public leader {
private:
    int team_id;
protected:
    int E;
    void set_team_id_console();
    void set_E_console();
public:
    void show_E();
    int get_E();
    void show_team_id();
    int get_team_id_value();
    virtual void show();
    virtual void to_file(ofstream& save);
    manager();
    manager(ifstream& read);
    virtual ~manager();
    virtual void modify();
};

class casual: public worker {
private:
    int experiance;
protected:
    int C;
    void set_experiance_console();
    void set_C_console();
    void set_experiance(int x);
public:
    void show_C();
    int get_C();
    virtual void show_experiance();
    int get_experiance_value();
    virtual void show();
    virtual void to_file(ofstream& save);
    casual();
    casual(ifstream& read);
    virtual ~casual();
    virtual void modify();
};

class salesman: public casual {
private:
    int region_id;
protected:
    int F;
    void set_region_id_console();
    void set_F_console();
public:
    void show_F();
    int get_F();
    void show_region_id();
    int get_region_id_value();
    virtual void show();
    virtual void to_file(ofstream& save);
    salesman();
    salesman(ifstream& read);
    virtual ~salesman();
    virtual void modify();
};

class office_worker: virtual public casual {
private:
    int box_id;
protected:
    int G;
    void set_box_id_console();
    void set_G_console();
    void set_box_id(int x);
public:
    void show_G();
    int get_G();
    void show_box_id();
    int get_box_id_value();
    virtual void show();
    virtual void to_file(ofstream& save);
    office_worker();
    office_worker(ifstream& read);
    virtual ~office_worker();
    virtual void modify();
};

class maintenance_worker: virtual public casual {
private:
    string tool;
protected:
    int H;
    void set_tool_console();
    void set_H_console();
    void set_tool(string tmp);
public:
    void show_H();
    int get_H();
    void show_tool();
    string get_tool_value();
    virtual void show();
    virtual void to_file(ofstream& save);
    maintenance_worker();
    maintenance_worker(ifstream& read);
    virtual ~maintenance_worker();
    virtual void modify();
};

class accountant: virtual public office_worker {
private:
    int acces_level;
protected:
    int I;
    void set_I_console();
    void set_acces_level_console();
public:
    void show_I();
    int get_I();
    void show_acces_level();
    int get_acces_level_value();
    virtual void show();
    virtual void to_file(ofstream& save);
    accountant();
    accountant(ifstream& read);
    virtual ~accountant();
    virtual void modify();

};

class IT_guy: public office_worker, virtual public maintenance_worker {
private:
    string computer;
protected:
    int J;
    void set_computer_console();
    void set_J_console();
public:
    void show_computer();
    string get_computer_value();
    void show_J();
    int get_J();
    virtual void show();
    virtual void to_file(ofstream& save);
    IT_guy();
    IT_guy(ifstream& read);
    virtual ~IT_guy();
    virtual void modify();
};


#endif //WORKERS_PROJECT_WORKER_H
