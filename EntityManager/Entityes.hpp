#pragma once
// inicio del import
#include "..\asset\box\BoxConfig.hpp"
#include "..\asset\misil\MisilConfig.hpp"
#include "..\asset\disparo\DisparoConfig.hpp"
#include "..\asset\nave\NaveConfig.hpp"
#include <windows.h>
template <typename Type>
void rmId(std::vector<Type> &listado, auto it, std::string tipo)
{
    if (it->classname == tipo)
    {
        int r = FindById(listado, it->id);
        if (r > -1)
        {
            listado.erase(listado.begin() + r);
            Console->warning("elemento descargado de la col" + std::to_string(it->id));
        }
    }
}
// render method by list
// metodo encargado de destruir las entidades
void remove()
{
    for (auto it = ___borrar.begin(); it != ___borrar.end(); ++it)
    {
        Console->gotoxy(5, 10);
        std::cout << "vaciando lista de items: " << ___borrar.size() << std::endl;
        // es necesario agregarlo a la lista de elementos de rm
        // listado de referencia, clase de comparacion, nombre de clase
        // todo es necesario agregarlos a la lista de destruccion
        rmId(___render_list_disparo, it, getNameClass(getDisparo(0.0f, 0.0f)));
        rmId(___render_list_box, it, getNameClass(getBox(0.0f, 0.0f)));
        rmId(___render_list_misil, it, getNameClass(getMisil(0.0f, 0.0f)));
        rmId(___render_list_nave, it, getNameClass(getNavePlayer(0.0f, 0.0f)));
    }
    ___borrar.clear();
}
template <typename Type>
void RenderViewsByListEntities(
    std::vector<Type *> listado,
    std::string action,
    unsigned char key = 0,
    int x = 0, int y = 0)
{
    remove();
    for (size_t i = 0; i < listado.size(); i++)
    {
        Type *e = listado[i];
        if (action == "draw")
        {
            DrawEntity(e);
        }
        else if (action == "update")
        {
            e->update();
        }
        else if (action == "key")
        {
            e->key(key, x, y);
        }
    }
    // Tareas.push_back(e);
}
// fin del import
void customkey(unsigned char key, int x, int y)
{
    RenderViewsByListEntities(___render_list_nave, "key", key, x, y); //<<- actualizar por cambio
}
void GestorBorrar(std::vector<EndEntity> list)
{
    for (int i = 0; i < list.size(); i++)
    {
        EndEntity e = list[i];
        int r = -1;
    }
}

// TODO en esta parte agreamos la las listas  a actualizar
void UpdatesEntities()
{

    // agregamos la lista de elementos a actualizar accion
    RenderViewsByListEntities(___render_list_nave, "update"); //<<- actualizar por cambio
    RenderViewsByListEntities(___render_list_box, "update");  //<<- actualizar por cambio

    // los disparos se dibujan de ultimo para detectar las coliciones
    RenderViewsByListEntities(___render_list_disparo, "update"); //<<- actualizar por cambio
    RenderViewsByListEntities(___render_list_misil, "update");   //<<- actualizar por cambio
}
void DrawEntities()
{
    // agregamos la lista de elementos a dibujar
    RenderViewsByListEntities(___render_list_nave, "draw");
    RenderViewsByListEntities(___render_list_box, "draw");
    // los disparos se dibujan de ultimo para detectar las coliciones
    RenderViewsByListEntities(___render_list_disparo, "draw");
    RenderViewsByListEntities(___render_list_misil, "draw"); //<<- actualizar por cambio
}
