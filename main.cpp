#include <iostream>
#include "worker.h"
#include "terminal.h"
#include <cstring>
using namespace std;

int main() {

    /*worker *d = new director();

    d->show();

    delete d;*/

    /*worker *g = new IT_guy();

    g->show();

    delete g;*/

    terminal *d = new terminal();

    cout<<"ups"<<endl;

    delete d;

    cout<<"ups"<<endl;

    return 0;
}