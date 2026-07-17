#include "lklist.hpp"

int main(int argc, char** argv) {
    LkList *node = new LkList();
    node->append(67);
    node->append(69);
    node->append(89);
    node->append(419);
    node->append(823);
    node->insert(41, 0);
    node->pop(5);
    node->print_list();
}