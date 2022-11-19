// import del asset con la config
#include "misil.hpp" // Nave
using ContextoMisil::getMisil;
using ContextoMisil::Misil;
std::vector<Misil *> ___render_list_misil; // lista de render
void addEntity(Misil *e)
{
    ___render_list_misil.push_back(e);
};