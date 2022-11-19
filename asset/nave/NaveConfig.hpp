// import del asset con la config
#include "nave.hpp" // Nave
using ContextoNave::getNavePlayer;
using ContextoNave::Nave;
std::vector<Nave *> ___render_list_nave; // lista de render
void addEntity(Nave *e)
{
    ___render_list_nave.push_back(e);
};
