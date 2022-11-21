#pragma once
#include <GL\freeglut.h>
#include <iostream>
#include <vector>
#include "includes\Console\Console.hpp"
#include <typeinfo>
#include <cxxabi.h>
#include "ulties\util.hpp"
#include <string.h>

void DrawEntities();
void UpdatesEntities();
void removeById(int);

#include "asset\PaletaColores.hpp"
#include "EntityManager\Entity.hpp"
#include "EntityManager\EntitiyManager.hpp"
#include "EntityManager\Entityes.hpp"


