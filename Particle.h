#pragma once
#include "ofMain.h"

class Particle {
public:
	Particle();
	~Particle() {};

	void update();
	void draw();
	void addForce(ofVec3f _force);
	void attract(ofVec2f center, float _mass, float _min, float _max);
	void bounceOffWalls();
	void throughWalls();
	void setLocation(float x, float y, float z);
	void setGravity(float x, float y, float z);
	void setFriction(float x);
	void setRadius(float r);
private:
	float constrain(float d, float _min, float _max);
	ofVec3f location;
	ofVec3f velocity;
	ofVec3f acceleration;
	ofVec3f gravity;
	float mass = 1.0;
	float friction = 0.01;
	ofVec3f min;
	ofVec3f max;
	float radius = 4.0;
	float G = 2.0;
};