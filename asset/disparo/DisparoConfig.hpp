// import del asset con la config
#include "disparo.hpp" // Nave
using ContextoDisparo::Disparo;
using ContextoDisparo::getDisparo;
std::vector<Disparo *> ___render_list_disparo; // lista de render
void addEntity(Disparo *e)
{
    ___render_list_disparo.push_back(e);
};