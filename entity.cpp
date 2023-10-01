#pragma once
#include <iostream>
#include <string>

#include "entity.h"

void addComponent(entity* entity, component* component) {
	if ((entity->componentsLength - 1) >= entity->numOfComponents) {
		std::cout << "Error: Adding component to full components buffer" << std::endl;
	}
	else {
		entity->numOfComponents++;
		entity->components[entity->numOfComponents] = component;
	}
}