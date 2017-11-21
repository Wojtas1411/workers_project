//
// Created by wojtek on 10.11.17.
//

#include "terminal.h"

///--------Working Tree--------///
void working_tree::set_name(string tmp) {
    name = tmp;
}
string working_tree::get_name() {
    return name;
}

bool working_tree::is_leaf() {
    if(q[0] == nullptr && q[1] == nullptr && q[2] == nullptr){
        return true;
    }
    else {
        return false;
    }

}
void working_tree::to_item(string name) {
    bool czy = false;
    item *s = p;
    current_item = nullptr;
    if(s== nullptr){
        current_item = nullptr;
        cout<<"Object with this name doesn't exist"<<endl;
        czy = true;
    }
    else if(s->next == nullptr && s!= nullptr && s->p->get_name_value()==name){
        current_item = s;
        czy = true;
        //cout<<"one"<<endl;
        //cout<<current_item->p->get_name_value()<<endl;
    }
    else{
        while(s->next!= nullptr){
            //s=s->next;
            if(s->p->get_name_value() == name){
                current_item = s;
                czy = true;
                //cout<<"two"<<endl;
                //cout<<current_item->next->p->get_name_value()<<endl;
                break;
            }
            s=s->next;
            if(s->next== nullptr && s->p->get_name_value() == name){
                current_item = s;
                czy = true;
            }
        }
    }
    s = nullptr;
    delete s;
    if(!czy){
        cout<<"Object with this name doesn't exist"<<endl;
    }
}

void working_tree::set_children(working_tree *p, working_tree *s, working_tree *r) {
    if(p!= nullptr)q[0] = p;
    if(s!= nullptr)q[1] = s;
    if(r!= nullptr)q[2] = r;
}
void working_tree::set_parent(working_tree *p, working_tree*q) {
    if(p!= nullptr)parent[0] = p;
    if(q!= nullptr)parent[1] = q;
}
working_tree *working_tree::get_child(int i) {
    return q[i];
}
working_tree *working_tree::get_parent(int i) {
    return parent[i];
}

void working_tree::add_element(string param) {
    if(p == nullptr){
        p = new item;
        current_item = p;
        //cout<<"one"<<endl;
    }
    else if(p!= nullptr && p->next == nullptr){
        p->next = new item;
        current_item = p->next;
        current_item->prev = p;
        //cout<<"two"<<endl;
    }
    else{
        item *s = p;
        while(s->next != nullptr){
            s = s->next;
        }
        s->next = new item;
        current_item = s->next;
        current_item->prev = s;
        s = nullptr;
        delete s;
    }
    if(param == "Director" || (param.empty() && name == "Director")){
        current_item->p = new director();
    }
    else if(param == "Manager" || (param.empty() && name == "Manager")){
        current_item->p = new manager();
    }
    else if(param == "Salesman" || (param.empty() && name == "Salesman")){
        current_item->p = new salesman();
    }
    else if(param == "Accountant" || (param.empty() && name == "Accountant")){
        current_item->p = new accountant();
    }
    else if(param == "ITguy" || (param.empty() && name == "ITguy")){
        current_item->p = new IT_guy();
    }
    else{
        cout<<"Invalid parameter";
    }
    cout<<"Making finished"<<endl;
}
void working_tree::del_element(string param) {
    to_item(param);
    if(current_item== nullptr)cout<<"fatal error"<<endl;
    cout<<"xd"<<endl;
    delete current_item->p;
    cout<<"xd"<<endl;
    item *s= nullptr;
    if(current_item->next != nullptr){
        s = current_item->next;
        s->prev = current_item->prev;
    }
    if(current_item->prev != nullptr){
        s = current_item->prev;
        s->next = current_item->next;
    }
    if(current_item->prev == nullptr){
        p = current_item->next;
    }
    cout<<"xd"<<endl;
    current_item->next = nullptr;
    current_item->prev = nullptr;
    delete current_item;
    cout<<"xd"<<endl;
    s = nullptr;
    delete s;
    cout<<"xd"<<endl;
}
void working_tree::mod_element(string param) {
    to_item(param);
    if(current_item != nullptr){
        delete current_item->p;
        if(name == "Director"){
            current_item->p = new director();
        }
        else if(name == "Manager"){
            current_item->p = new manager();
        }
        else if(name == "Salesman"){
            current_item->p = new salesman();
        }
        else if(name == "Accountant"){
            current_item->p = new accountant();
        }
        else if(name == "ITguy"){
            current_item->p = new IT_guy();
        }
        else{
            cout<<"Invalid parameter";
        }
        current_item = nullptr;

    }
    else{
        cout<<"mdo fatal error"<<endl;
    }
}
void working_tree::show_element(string param) {
    to_item(param);
    if(current_item!= nullptr)current_item->p->show();
    else{
        cout<<"show fatal error"<<endl;
    }
}
void working_tree::show_list(int depth) {
    if(is_leaf() && p!= nullptr){
        item *s = p;
        while(s!= nullptr){
            for(int i=0;i<depth;i++)cout<<"  ";
            cout<<s->p->get_name_value()<<endl;
            s = s->next;
        }
        s = nullptr;
        delete s;

    }
    else{
        for(int i=0;i<depth;i++)cout<<"  ";
        cout<<"Is not a leaf or empty"<<endl;
    }
}

int working_tree::num_of_elements() {
    if(p == nullptr)return 0;
    else{
        item *s = p;
        int count = 0;
        while(s != nullptr){
            count++;
            s=s->next;
        }
        s = nullptr;
        delete s;
        return count;
    }
}

void working_tree::add_element2(ifstream &read, string param) {
    if(p == nullptr){
        p = new item;
        current_item = p;
        //cout<<"one"<<endl;
    }
    else if(p!= nullptr && p->next == nullptr){
        p->next = new item;
        current_item = p->next;
        current_item->prev = p;
        //cout<<"two"<<endl;
    }
    else{
        item *s = p;
        while(s->next != nullptr){
            s = s->next;
        }
        s->next = new item;
        current_item = s->next;
        current_item->prev = s;
        s = nullptr;
        delete s;
    }
    if(param == "Director" || (param.empty() && name == "Director")){
        current_item->p = new director(read);
    }
    else if(param == "Manager" || (param.empty() && name == "Manager")){
        current_item->p = new manager(read);
    }
    else if(param == "Salesman" || (param.empty() && name == "Salesman")){
        current_item->p = new salesman(read);
    }
    else if(param == "Accountant" || (param.empty() && name == "Accountant")){
        current_item->p = new accountant(read);
    }
    else if(param == "ITguy" || (param.empty() && name == "ITguy")){
        current_item->p = new IT_guy(read);
    }
    else{
        cout<<"Invalid parameter";
    }
    //cout<<"Making finished"<<endl;
}
void working_tree::del_all_elements() {
    item *s = p;
    while(s != nullptr){
        delete s->p;
        s->prev = nullptr;
        s = s->next;
        if(s != nullptr)delete s->prev;
    }
    s = nullptr;
    delete s;
    p = nullptr;
    //if(p != nullptr)cout<<"Something went terribly wrong here!"<<endl;
}

item *working_tree::get_p() {
    return p;
}

working_tree::working_tree(string name) {
    set_name(name);
}

working_tree::~working_tree() {
    current_item = nullptr;
    cout<<"step1"<<endl;
    for(int i=0;i<2;i++){
        parent[i]= nullptr;
        delete parent[i];
    }
    cout<<"sted2"<<endl;
    for(int i=0;i<3;i++){
        q[i] = nullptr;
        delete q[i];
    }
    cout<<"step3"<<endl;
    item *s = p;
    p = nullptr;
    while (s!= nullptr && s->next!= nullptr){
        s = s->next;
        //cout<<"Deleting "<<s->prev->p->get_name_value()<<endl;
        delete s->prev->p;
        delete s->prev->prev;
        current_item = nullptr;
    }
    if(s!= nullptr){
        delete s->p;
        delete s->prev;
        s= nullptr;
    }
    delete s;
    cout<<"step4"<<endl;
    if(p!= nullptr){
        delete p->p;
        if(p->next!= nullptr)delete p->next;
        if(p->prev!= nullptr)delete p->prev;
        delete p;
    }
    cout<<"step5"<<endl;
    /*if(current_item!= nullptr){
        delete current_item->p;
        delete current_item;
    }*/
    delete current_item;
    delete p;
    cout<<"done"<<endl;
}

///--------Terminal--------///

void terminal::joy_mark() {
    cout<<">> "<<current->get_name()<<" :";
}
void terminal::change_directory(string tmp) {
    bool tester = false;

    for(int i=0;i<2;i++){
        if(current->get_parent(i) != nullptr && current->get_parent(i)->get_name() == tmp){
            current = current->get_parent(i);
            tester = true;
        }
    }

    if(!tester){
        for(int i=0;i<3;i++){
            if(current->get_child(i) != nullptr && current->get_child(i)->get_name() == tmp){
                current = current->get_child(i);
                tester = true;
                break;
            }
        }
    }

    if(!tester){
        cout<<"Directory is not accesible"<<endl;
    }
}

void terminal::super_change_directory(string tmp) {
    bool tester = false;
    for(int i=0;i<10;i++){
        if(tab[i]->get_name()==tmp){
            current = tab[i];
            tester = true;
            break;
        }
    }
    if(!tester){
        cout<<"Directory is not accesible"<<endl;
    }
}


void terminal::seen_to_false() {
    for(int i=0;i<10;i++){
        seen[i]=false;
    }
}
void terminal::dir_rec(working_tree *tmp) {
    if(tmp->is_leaf()){
        for(int i=0;i<10;i++){
            if(tmp->get_name()==names[i] && !seen[i]){
                seen[i]=true;
                cout<<tmp->get_name()<<" :"<<endl;
                tmp->show_list(0);
                break;
            }
        }

    }
    else{
        for(int i=0;i<3;i++){
            if(tmp->get_child(i) != nullptr){
                dir_rec(tmp->get_child(i));
            }
        }
    }
    tmp = nullptr;
    delete tmp;
}
void terminal::dir() {
    if(current->is_leaf()){
        cout<<current->get_name()<<" :"<<endl;
        current->show_list(1);
    }
    else{
        for(int i=0;i<3;i++){
            if(current->get_child(i) != nullptr){
                dir_rec(current->get_child(i));
            }
        }
    }
    seen_to_false();
}
void terminal::tree_rec(working_tree *tmp, int depth) {
    for(int i=0;i<depth;i++){
        cout<<"  ";
    }
    cout<<tmp->get_name()<<endl;
    if(!tmp->is_leaf()){
        depth++;
        for(int i=0;i<3;i++){
            if(tmp->get_child(i) != nullptr){
                tree_rec(tmp->get_child(i),depth);
            }
        }
    }
    else{
        tmp->show_list(depth + 1);
    }
}
void terminal::tree() {
    tree_rec(tab[0],0);
}

void terminal::save(string filename) {
    if(filename.empty()){
        filename = "default_save.txt";
    }
    if(filename.find(".txt") == -1){
        filename+=".txt";
    }
    ofstream save;
    save.open(filename.c_str());
    for(int i=0;i<10;i++){
        if(tab[i]->is_leaf()){
            save<<tab[i]->get_name()<<" "<<tab[i]->num_of_elements()<<endl;
            if(tab[i]->get_p() != nullptr){
                item *s = tab[i]->get_p();
                while(s!= nullptr){
                    s->p->to_file(save);
                    s=s->next;
                }
            }
        }
    }
    save.close();
}

void terminal::read(string filename) {
    if(filename.empty()){
        filename = "default_save.txt";
    }
    if(filename.find(".txt") == -1){
        filename+=".txt";
    }
    ifstream read;
    read.open(filename.c_str());
    if(!read){
        cout<<"Wrong filename"<<endl;
        read.close();
        read.clear(read.rdstate()&~ios::failbit);
    }
    else{
        string tmp;
        int a;
        string buff;
        while(!read.eof()){
            read>>tmp;
            read>>a;
            getline(read,buff);
            cout<<tmp<<" "<<a<<endl;
            cout<<buff<<endl;

            for(int i=0;i<10;i++){
                if(tab[i]->get_name()==tmp){
                    if(tab[i]->get_p() != nullptr){
                        //cout<<"p is not empty"<<endl;
                        tab[i]->del_all_elements();
                    }
                    for(int j=0;j<a;j++){
                        tab[i]->add_element2(read,tmp);
                    }
                    tab[i]->show_list(0);
                    break;
                }
            }
            if(tmp == "ITguy")break;
        }
    }
}

void terminal::main_loop() {
    while(true){
        joy_mark();
        string x; getline(cin,x);
        string command = x.substr(0,x.find(' '));
        string parameter = x.substr(x.find(' ')+1,x.length());
        if(command == parameter)parameter = "";

        if(command == "exit"){
            break;
        }
        else if(command == "cd"){
            change_directory(parameter);
        }
        else if(command == "xd"){
            super_change_directory(parameter);
        }
        else if(command == "mo"){
            current->add_element(parameter);
            string t; getline(cin,t);//czyszczenie bufora
        }
        else if(command == "do"){
            current->del_element(parameter);
        }
        else if(command == "mdo"){
            current->mod_element(parameter);
        }
        else if(command == "dir"){
            dir();
        }
        else if(command == "show"){
            current->show_element(parameter);
        }
        else if(command == "save"){
            save(parameter);
        }
        else if(command == "read"){
            read(parameter);
        }
        else if(command == "tree"){
            tree();
        }
        else if(command == "showL"){
            current->show_list(0);
        }
        else{
            cout<<"Invalid command"<<endl;
        }
    }


}

terminal::terminal() {
    for(int i=0;i<10;i++){
        tab[i] = new working_tree(names[i]);
    }
    current = tab[0];
    tab[0]->set_children(tab[1],tab[2], nullptr);
    tab[1]->set_parent(tab[0], nullptr);
    tab[1]->set_children(tab[3], tab[4], nullptr);
    tab[3]->set_parent(tab[1], nullptr);
    tab[4]->set_parent(tab[1], nullptr);
    tab[2]->set_parent(tab[0], nullptr);
    tab[2]->set_children(tab[5], tab[6], tab[7]);
    tab[5]->set_parent(tab[2], nullptr);
    tab[6]->set_parent(tab[2], nullptr);
    tab[7]->set_parent(tab[2], nullptr);
    tab[6]->set_children(tab[8], tab[9], nullptr);
    tab[7]->set_children(tab[9], nullptr, nullptr);
    tab[8]->set_parent(tab[6], nullptr);
    tab[9]->set_parent(tab[6],tab[7]);


    main_loop();

}
terminal::~terminal() {
    for(int i=0;i<10;i++){
        cout<<"Deleting "<<tab[i]->get_name()<<endl;
        delete tab[i];
    }
    current = NULL;
    delete current;
}