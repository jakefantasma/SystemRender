// import del asset con la config
#include "box.hpp" // Nave
using ContextoBox::Box;
using ContextoBox::getBox;
std::vector<Box *> ___render_list_box; // lista de render
void addEntity(Box *e)
{
    ___render_list_box.push_back(e);
};
