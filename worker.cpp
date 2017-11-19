//
// Created by wojtek on 10.11.17.
//

#include "worker.h"
using namespace std;

///-------Class Worker-------///

void worker::get_name_console() {
    cout<<"Name: "<<name<<endl;
}
void worker::get_salary_console() {
    cout<<"Salary: "<<salary<<" $"<<endl;
}
string worker::get_name_value() {
    return name;
}
int worker::get_salary_value() {
    return salary;
}
void worker::set_name_console() {
    cout<<"Enter Name: ";
    string x;
    getline(cin,x);
    name = x;
}
void worker::set_name_value(std::string tmp) {
    name = tmp;
}
void worker::set_salary_console() {
    cout<<"Enter Salary: ";
    int a;
    cin>>a;
    salary = a;
}
void worker::set_salary_value(int tmp) {
    salary = tmp;
}
worker::worker() {
    set_name_console();
    set_salary_console();
}
void worker::show() {
    get_name_console();
    get_salary_console();
}
worker::~worker() {}

///-------Class Leader-------///

void leader::set_office_nuber_console() {
    cout<<"Enter office number: ";
    int a;
    cin>>a;
    office_number = a;
}
void leader::show_office_number() {
    cout<<"Office number: "<<office_number<<endl;
}
void leader::show(){
    get_name_console();
    get_salary_console();
    show_office_number();
}

leader::leader(){
    set_office_nuber_console();
}
leader::~leader() {}

///-------Class Director-------///
void director::set_car_console() {
    cout<<"Enter car name: ";
    string a;
    cin>>a;
    car = a;
}
void director::show_car() {
    cout<<"Director's car is: "<<car<<endl;
}
void director::show() {
    get_name_console();
    get_salary_console();
    show_office_number();
    show_car();
}
director::director() {
    set_car_console();
}
director::~director() {
    cout<<"Deleted Director"<<endl;
}

///-------Class Manager-------///

void manager::set_team_id_console() {
    cout<<"Enter team ID: ";
    int a;
    cin>>a;
    team_id = a;
}
void manager::show_team_id() {
    cout<<"Team ID is: "<<team_id<<endl;
}
void manager::show(){
    get_name_console();
    get_salary_console();
    show_office_number();
    show_team_id();
}
manager::manager() {
    set_team_id_console();
}
manager::~manager() {
    cout<<"Deleted Manager"<<endl;
}

///-------Class Casual-------///

void casual::set_experiance_console() {
    cout<<"Enter experiance: ";
    int a;
    cin>>a;
    experiance = a;
}
void casual::show_experiance() {
    cout<<"Worker's experiance: "<<experiance<<" years"<<endl;
}
void casual::show() {
    get_name_console();
    get_salary_console();
    show_experiance();
}
casual::casual() {
    set_experiance_console();
}
casual::~casual() {}

///-------Salesman-------///

void salesman::set_region_id_console() {
    cout<<"Enter region ID: ";
    int a;
    cin>>a;
    region_id = a;
}
void salesman::show_region_id() {
    cout<<"Region ID: "<<region_id<<endl;
}
void salesman::show(){
    get_name_console();
    get_salary_console();
    show_experiance();
    show_region_id();
}
salesman::salesman() {
    set_region_id_console();
}
salesman::~salesman() {
    cout<<"Deleted Salesman"<<endl;
}

///-------Class Office Worker-------///

void office_worker::set_box_id_console() {
    cout<<"Enter workbox ID: ";
    int a;
    cin>>a;
    box_id = a;
}
void office_worker::show_box_id() {
    cout<<"Workbox ID is: "<<box_id<<endl;
}
void office_worker::show() {
    get_name_console();
    get_salary_console();
    show_experiance();
    show_box_id();
}
office_worker::office_worker() {
    set_box_id_console();
}
office_worker::~office_worker() {}

///-------Class Maintenance Worker-------///
void maintenance_worker::set_tool_console() {
    cout<<"Enter tool: ";
    string a;
    cin>>a;
    tool = a;
}
void maintenance_worker::show_tool() {
    cout<<"Tool is: "<<tool<<endl;
}
void maintenance_worker::show() {
    get_name_console();
    get_salary_console();
    show_experiance();
    show_tool();
}
maintenance_worker::maintenance_worker() {
    set_tool_console();
}
maintenance_worker::~maintenance_worker() {}

///-------Class Accountant-------///

void accountant::set_acces_level_console() {
    cout<<"Enter acces level: ";
    int a;
    cin>>a;
    acces_level = a;
}
void accountant::show_acces_level() {
    cout<<"Acces level is: "<<acces_level<<endl;
}
void accountant::show() {
    get_name_console();
    get_salary_console();
    show_experiance();
    show_box_id();
    show_acces_level();
}
accountant::accountant() {
    set_acces_level_console();
}
accountant::~accountant() {
    cout<<"Deleted Accountant"<<endl;
}

///-------IT GUY-------///

void IT_guy::set_computer_console() {
    cout<<"Enter computer: ";
    string a;
    cin>>a;
    computer = a;
}
void IT_guy::show_computer() {
    cout<<"IT Guy's PC is: "<<computer<<endl;
}
void IT_guy::show() {
    get_name_console();
    get_salary_console();
    show_experiance();
    show_box_id();
    show_tool();
    show_computer();
}
IT_guy::IT_guy() {
    set_computer_console();
}
IT_guy::~IT_guy() {
    cout<<"Deleted IT guy"<<endl;
}

///-------x-------///