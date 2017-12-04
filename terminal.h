//
// Created by wojtek on 10.11.17.
//

#ifndef WORKERS_PROJECT_TERMINAL_H
#define WORKERS_PROJECT_TERMINAL_H

#include <fstream>

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
    void set_name(string tmp); //standard setter for name
public:
    void set_children(working_tree *p, working_tree *s, working_tree *r); //setting children elements
    void set_parent(working_tree *p,working_tree *q); //setting parent elements

    bool is_leaf(); //checks if element has any children
    void to_item(string name); //moves pointer current to item which name is an argument

    void add_element(string param); //ads new object to the list of items in current element if it is a leaf
    void del_element(string param); //deletes object from items list
    void mod_element(string param); //modifies object in the list
    void show_element(string param); //shows objects properities
    void show_list(int depth); //shows lists of objects from current element

    int num_of_elements(); //returns number of items of list of objects in current element

    void add_element2(ifstream& read, string param); //adds elements form file
    void del_all_elements(); //deletes all items from the current element


    string get_name(); //standard getter
    working_tree *get_child(int i); //gets pointer to child
    working_tree *get_parent(int i); //gets pointer to parent
    item *get_p(); //gets pointer to beggining of the list

    working_tree(string name); //standard constructor
    ~working_tree(); //standard deconstructor
};

class terminal {
private:
    string names[10] = {"Worker", "Leader", "Casual", "Director", "Manager", "Salesman", "Office", "Maintenance", "Accountant", "ITguy"};
    bool seen[10] = {false};
    working_tree *current;
    working_tree *tab[10];

    void dir_rec(working_tree* tmp); //shows current directory items
    void tree_rec(working_tree* tmp, int depth); //shows tree of elements and items
    void seen_to_false(); //clears table of already dispalayed elements, used in dir function

protected:
    void joy_mark(); //shows "znak zachety"
    void main_loop(); //runs main loop - console
    void super_change_directory(string tmp); //changes pointer current for any alament in system
    void dir(); //executes function dir_rec for current element
    void tree(); //executes function tree_rec for with depth parameter set

    void save(string filename); //saves data to file
    void read(string filename); //reads data from file

public:
    terminal();
    ~terminal();

};


#endif //WORKERS_PROJECT_TERMINAL_H
