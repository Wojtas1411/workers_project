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

void worker::set_salary_console() {
    cout<<"Enter Salary: ";
    int a;
    cin>>a;
    salary = a;
}

worker::worker() {
    set_name_console();
    set_salary_console();
}
void worker::show() {
    get_name_console();
    get_salary_console();
}
void worker::to_file(ofstream& save) {
    cout<<"Error"<<endl;
}
worker::worker(ifstream& read) {
    getline(read,name);
    read>>salary;
    string t;getline(read,t);
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
int leader::get_office_number_value() {
    return office_number;
}
void leader::show(){
    get_name_console();
    get_salary_console();
    show_office_number();
}
void leader::to_file(ofstream& save) {
    cout<<"Error"<<endl;
}

leader::leader(){
    set_office_nuber_console();
}
leader::leader(ifstream& read) : worker(read){
    read>>office_number;
    string t;getline(read,t);
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
string director::get_car_value() {
    return car;
}
void director::show() {
    get_name_console();
    get_salary_console();
    show_office_number();
    show_car();
}
void director::to_file(ofstream& save) {
    save<<get_name_value()<<endl;
    save<<get_salary_value()<<endl;
    save<<get_office_number_value()<<endl;
    save<<get_car_value()<<endl;
}
director::director() {
    set_car_console();
}
director::director(ifstream& read): leader(read) {
    getline(read,car);
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
int manager::get_team_id_value() {
    return team_id;
}
void manager::show(){
    get_name_console();
    get_salary_console();
    show_office_number();
    show_team_id();
}
void manager::to_file(ofstream& save) {
    save<<get_name_value()<<endl;
    save<<get_salary_value()<<endl;
    save<<get_office_number_value()<<endl;
    save<<get_team_id_value()<<endl;
}
manager::manager() {
    set_team_id_console();
}
manager::manager(ifstream& read):leader(read) {
    read>>team_id;
    string t;getline(read,t);
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
int casual::get_experiance_value() {
    return experiance;
}
void casual::show() {
    get_name_console();
    get_salary_console();
    show_experiance();
}
void casual::to_file(ofstream& save) {
    cout<<"Error"<<endl;
}
casual::casual() {
    set_experiance_console();
}
casual::casual(ifstream &read):worker(read) {
    read>>experiance;
    string t;getline(read,t);
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
int salesman::get_region_id_value() {
    return region_id;
}
void salesman::show(){
    get_name_console();
    get_salary_console();
    show_experiance();
    show_region_id();
}
void salesman::to_file(ofstream& save) {
    save<<get_name_value()<<endl;
    save<<get_salary_value()<<endl;
    save<<get_experiance_value()<<endl;
    save<<get_region_id_value()<<endl;
}
salesman::salesman() {
    set_region_id_console();
}
salesman::salesman(ifstream &read):casual(read) {
    read>>region_id;
    string t;getline(read,t);
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
int office_worker::get_box_id_value() {
    return box_id;
}
void office_worker::show() {
    get_name_console();
    get_salary_console();
    show_experiance();
    show_box_id();
}
void office_worker::to_file(ofstream& save) {
    cout<<"Error"<<endl;
}
office_worker::office_worker() {
    set_box_id_console();
}
office_worker::office_worker(ifstream &read) :casual(read){
    read>>box_id;
    string t;getline(read,t);
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
string maintenance_worker::get_tool_value() {
    return tool;
}
void maintenance_worker::show() {
    get_name_console();
    get_salary_console();
    show_experiance();
    show_tool();
}
void maintenance_worker::to_file(ofstream& save) {
    cout<<"Error"<<endl;
}
maintenance_worker::maintenance_worker() {
    set_tool_console();
}
maintenance_worker::maintenance_worker(ifstream &read):casual(read){
    getline(read,tool);
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
int accountant::get_acces_level_value() {
    return acces_level;
}
void accountant::show() {
    get_name_console();
    get_salary_console();
    show_experiance();
    show_box_id();
    show_acces_level();
}
void accountant::to_file(ofstream& save) {
    save<<get_name_value()<<endl;
    save<<get_salary_value()<<endl;
    save<<get_experiance_value()<<endl;
    save<<get_box_id_value()<<endl;
    save<<get_acces_level_value()<<endl;
}
accountant::accountant() {
    set_acces_level_console();
}
accountant::accountant(ifstream& read) : office_worker(read), casual(read){
    read>>acces_level;
    string t;getline(read,t);
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
string IT_guy::get_computer_value() {
    return computer;
}
void IT_guy::show() {
    get_name_console();
    get_salary_console();
    show_experiance();
    show_box_id();
    show_tool();
    show_computer();
}
void IT_guy::to_file(ofstream& save) {
    save<<get_name_value()<<endl;
    save<<get_salary_value()<<endl;
    save<<get_experiance_value()<<endl;
    save<<get_tool_value()<<endl;
    save<<get_box_id_value()<<endl;
    save<<get_computer_value()<<endl;
}
IT_guy::IT_guy() {
    set_computer_console();
}
IT_guy::IT_guy(ifstream &read) :maintenance_worker(read), office_worker(read), casual(read){
    getline(read,computer);
}
IT_guy::~IT_guy() {
    cout<<"Deleted IT guy"<<endl;
}

///-------x-------///