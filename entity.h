#pragma once
#include "component.h"

struct entity {
	int id = 0;
	
	int numOfComponents = 0;
	int componentsLength = 32;
	component* components[32] = {};

	int numOfChildEntities = 0;
	int childEntitiesLength = 32;
	entity* childEntities[32] = {};
};

void addComponent(entity* entity, component* component);