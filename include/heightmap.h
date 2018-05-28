#pragma once

#include <glm/glm.hpp>
#include <array>
#include <utility>

#include "concurrentqueue.h"

namespace vtk {

class World;

class HeightMap {
public:
	HeightMap(const glm::ivec2& pos, World& world);
	glm::ivec2 getPos();

	int getHeight(const glm::ivec2& pos);
	bool pushUpdate(const glm::ivec3& pos, const bool& destroyed);
	void flushUpdates(); // called from worker thread
protected:
	void setHeight(const::glm::ivec3& pos);
	
	World& mWorld;
	glm::ivec2 mPos;
	std::array<int, (16*16)> mHeights; //stores 16*16 heightmap
	moodycamel::ConcurrentQueue<std::pair<glm::ivec3, bool>> mUpdateQueue;
};

}
