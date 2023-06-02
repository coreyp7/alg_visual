#include "Dot.h"

int Dot::ID_COUNTER = 0;

Dot::Dot(float x, float y, float w, float h) {
	rect = new SDL_FRect{ x, y, w, h };
  id = ID_COUNTER;
  ID_COUNTER++;

	// Set random velocity for square to move at.
	xVel = (float)(rand()) / (float)(rand());
	yVel = (float)(rand()) / (float)(rand());
	xVel *= 10;
	yVel *= 10;

}

Dot::~Dot() {
	delete rect;
}

void Dot::simulate(float dt) {
	float oldX = rect->x;
	float oldY = rect->y;

	rect->x += xVel * dt;
	rect->y += yVel * dt;

	if (rect->x < 0 || rect->x + rect->w > X_MAX) {
		xVel = -xVel;
		rect->x = oldX + (xVel * dt);
	}

	if (rect->y < 0 || rect->y + rect->h > Y_MAX) {
		yVel = -yVel;
		rect->y = oldY + (yVel * dt);
	}
}
