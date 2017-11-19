//
// Created by wojtek on 10.11.17.
//

#ifndef WORKERS_PROJECT_TERMINAL_H
#define WORKERS_PROJECT_TERMINAL_H

#include "worker.h"


struct item {
    item *next = nullptr;
    item *prev = nullptr;
    worker *p = nullptr;
};

class working_tree {
private:
    string name;
    item *p = nullptr;
    item *current_item = nullptr;
    working_tree *parent[2] = {nullptr};
    working_tree *q[3] = {nullptr};
protected:
    void set_name(string tmp);
public:
    void set_children(working_tree *p, working_tree *s, working_tree *r);
    void set_parent(working_tree *p,working_tree *q);

    bool is_leaf();
    void to_item(string name);

    void add_element(string param);
    void del_element(string param);
    void mod_element(string param);
    void show_element(string param);

    string get_name();
    working_tree *get_child(int i);
    working_tree *get_parent(int i);

    working_tree(string name);
    ~working_tree();
};

class terminal {
private:
    string names[13] = {"Worker", "Leader", "Casual", "Director", "Manager", "Salesman", "Office", "Maintenance", "Accountant", "ITguy"};
    //string command_list[9] = {"cd", "mo", "do", "mdo", "dir", "show", "save", "read", "tree"};
    working_tree *current;
    working_tree *tab[13];

protected:
    void joy_mark();
    void main_loop();
    void change_directory(string tmp);
public:
    terminal();
    ~terminal();

};


#endif //WORKERS_PROJECT_TERMINAL_H
