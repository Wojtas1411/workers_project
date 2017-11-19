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
    if(q[0] == NULL && q[1] == NULL && q[2] == NULL){
        return true;
    }
    else {
        return false;
    }
}
void working_tree::to_item(string name) {
    bool czy = false;
    item *s = p;
    current_item = NULL;
    if(s==NULL){
        current_item = NULL;
        cout<<"Object with this name doesn't exist"<<endl;
    }
    else if(s->next == NULL && s!=NULL && s->p->get_name_value()==name){
        current_item = s;
        czy = true;
        cout<<"one"<<endl;
        cout<<current_item->p->get_name_value()<<endl;
    }
    else{
        while(s->next!=NULL){
            //s=s->next;
            if(s->p->get_name_value() == name){
                current_item = s;
                czy = true;
                cout<<"two"<<endl;
                cout<<current_item->next->p->get_name_value()<<endl;
                break;
            }
            s=s->next;
            if(s->next==NULL){
                current_item = s;
                czy = true;
            }
        }
    }
    s = nullptr;
    delete s;
    if(czy == false){
        cout<<"Object with this name doesn't exist1"<<endl;
    }
}

void working_tree::set_children(working_tree *p, working_tree *s, working_tree *r) {
    if(p!=NULL)q[0] = p;
    if(s!=NULL)q[1] = s;
    if(r!=NULL)q[2] = r;
}
void working_tree::set_parent(working_tree *p, working_tree*q) {
    if(p!=NULL)parent[0] = p;
    if(q!=NULL)parent[1] = q;
}
working_tree *working_tree::get_child(int i) {
    return q[i];
}
working_tree *working_tree::get_parent(int i) {
    return parent[i];
}

void working_tree::add_element(string param) {
    if(p == NULL){
        p = new item;
        current_item = p;
        cout<<"one"<<endl;
    }
    else if(p!=NULL && p->next == NULL){
        p->next = new item;
        current_item = p->next;
        current_item->prev = p;
        cout<<"two"<<endl;
    }
    else{
        item *s = p;
        while(s->next != NULL){
            s = s->next;
        }
        s->next = new item;
        current_item = s->next;
        current_item->prev = s;
        s = NULL;
        delete s;
    }
    if(param == "Director"){
        current_item->p = new director();
    }
    else if(param == "Manager"){
        current_item->p = new manager();
    }
    else if(param == "Salesman"){
        current_item->p = new salesman();
    }
    else if(param == "Accountant"){
        current_item->p = new accountant();
    }
    else if(param == "ITguy"){
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
    s = NULL;
    delete s;
    cout<<"xd"<<endl;
}
void working_tree::mod_element(string param) {
    //TODO
}
void working_tree::show_element(string param) {
    to_item(param);
    if(current_item!=NULL)current_item->p->show();
    else{
        cout<<"show fatal error"<<endl;
    }
}


working_tree::working_tree(string name) {
    set_name(name);
}

working_tree::~working_tree() {
    if(p== nullptr)current_item = nullptr;
    cout<<"step1"<<endl;
    for(int i=0;i<2;i++){
        parent[i]=NULL;
        delete parent[i];
    }
    cout<<"sted2"<<endl;
    for(int i=0;i<3;i++){
        q[i] = NULL;
        delete q[i];
    }
    cout<<"step3"<<endl;
    item *s = p;
    p = nullptr;
    while (s!=NULL && s->next!=NULL){
        s = s->next;
        cout<<"Deleting "<<s->prev->p->get_name_value()<<endl;
        delete s->prev->p;
        delete s->prev->prev;
        current_item = NULL;
    }
    if(s!=NULL){
        delete s->p;
        delete s->prev;
        s=NULL;
    }
    delete s;
    cout<<"step4"<<endl;
    //p =NULL;
    if(p!=NULL){
        cout<<"xd"<<endl;
        delete p->p;
        if(p->next!=NULL)delete p->next;
        if(p->prev!=NULL)delete p->prev;
        delete p;
    }
    cout<<"step5"<<endl;
    if(current_item!=NULL){
        cout<<"xd"<<endl;
        delete current_item->p;
        delete current_item;
    }
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
        if(current->get_parent(i) != NULL && current->get_parent(i)->get_name() == tmp){
            current = current->get_parent(i);
            tester = true;
        }
    }

    if(tester == false){
        for(int i=0;i<3;i++){
            if(current->get_child(i) != NULL && current->get_child(i)->get_name() == tmp){
                current = current->get_child(i);
                tester = true;
                break;
            }
        }
    }

    if(tester == false){
        cout<<"Directory is not accesible"<<endl;
    }
}

void terminal::main_loop() {
    while(1){
        joy_mark();
        string x; getline(cin,x);
        //cout<<x<<endl;
        string command = x.substr(0,x.find(" "));
        //cout<<command<<endl;
        string parameter = x.substr(x.find(" ")+1,x.length());
        //cout<<parameter<<endl;
        if(command == "exit"){
            break;
        }
        else if(command == "cd"){
            change_directory(parameter);
        }
        else if(command == "mo"){
            current->add_element(parameter);
        }
        else if(command == "do"){
            current->del_element(parameter);
        }
        else if(command == "mdo"){
            current->mod_element(parameter);
        }
        else if(command == "dir"){
            //TODO
        }
        else if(command == "show"){
            current->show_element(parameter);
        }
        else if(command == "save"){
            //TODO
        }
        else if(command == "read"){
            //TODO
        }
        else if(command == "tree"){
            //TODO
        }
        else{
            cout<<"Invalid command"<<endl;
        }
    }


}

terminal::terminal() {
    for(int i=0;i<13;i++){
        //cout<<names[i]<<endl;
        tab[i] = new working_tree(names[i]);
    }
    current = tab[3];
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
    for(int i=0;i<13;i++){
        cout<<"Deleting "<<tab[i]->get_name()<<endl;
        delete tab[i];
    }
    delete current;
}