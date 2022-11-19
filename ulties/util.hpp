// funciones de utilidad multimple encontrar elementos y rediminencionar elementos
#pragma once
#include "../headers.hpp"
// generamos un linked para la interaccion
template <typename Type>
std::string getNameClass(Type *obj)
{
    int status;
    char *demangled = abi::__cxa_demangle(typeid(obj).name(), 0, 0, &status);
    return demangled;
}

template <typename Type>
int FindById(std::vector<Type *> lista, int id)
{
    for (int i = 0; i < lista.size(); i++)
    {
        Type *e = lista[i];
        if (id == e->getId())
        {
            Console->error(i);
            return i;
        }
    }
    return -1;
}
// metodo par encontrar la pocicion de un elemento
template <typename Type>
int Find(std::vector<Type *> lista, bool (*validador)(Type *))
{
    int tmp = 0;
    for (int i = 0; i < lista.size(); i++)
    {
        if (validador(lista[i]))
        {
            tmp = i;
        }
    }
    return tmp;
    // lista.erase(lista.begin() + index);
}
// TODO es necesario un cambio
struct EndEntity
{
    int id;
    std::string classname;
};

std::vector<EndEntity> ___borrar;

// agrega a la lista para los elementos a eliminar
template <typename Type>
void RemoveEntity(Type *e)
{
    EndEntity endT;
    endT.id = e->getId();
    endT.classname = getNameClass(e);
    ___borrar.push_back(endT);
}
