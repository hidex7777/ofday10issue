#include "Particle.h"

Particle::Particle() {
	this->min = ofVec3f(0, 0, -ofGetHeight() / 2);
	this->max = ofVec3f(ofGetWidth(), ofGetHeight(), ofGetHeight() / 2);
}
void Particle::update() {
	this->acceleration += this->gravity;
	this->velocity += this->acceleration;
	this->velocity *= (1.0 - this->friction);
	this->location += this->velocity;
	this->acceleration.set(0, 0, 0);
}
void Particle::draw() {
	ofDrawEllipse(this->location, this->mass * this->radius * 2, this->mass * this->radius * 2);
}
void Particle::addForce(ofVec3f _force) {
	_force /= this->mass;
	this->acceleration += _force;
}
void Particle::attract(ofVec2f center, float _mass, float _min, float _max) {
	float distance = center.distance(this->location);
	distance = this->constrain(distance, _min, _max);
	float strength = this->G * (this->mass * _mass) / (distance * distance);
	ofVec3f force = center - this->location;
	force.normalize();
	force *= strength;
	this->addForce(force);
}
float Particle::constrain(float d, float _min, float _max) {
	if (d < _min) {
		d = _min;
	}
	else if (d > _max) {
		d = _max;
	}
	return d;
}
void Particle::bounceOffWalls() {
	if (this->location.x > this->max.x) {
		this->location.x = this->max.x;
		this->velocity.x *= -1;
	}
	if (this->location.x < this->min.x) {
		this->location.x = this->min.x;
		this->velocity.x *= -1;
	}
	if (this->location.y > this->max.y) {
		this->location.y = this->max.y;
		this->velocity.y *= -1;
	}
	if (this->location.y < this->min.y) {
		this->location.y = this->min.y;
		this->velocity.y *= -1;
	}
	if (this->location.z > this->max.z) {
		this->location.z = this->max.z;
		this->velocity.z *= -1;
	}
	if (this->location.z < this->min.z) {
		this->location.z = this->min.z;
		this->velocity.z *= -1;
	}
}
void Particle::throughWalls() {
	if (this->location.x < this->min.x) {
		this->location.x = this->max.x;
	}
	if (this->location.y < this->min.y) {
		this->location.y = this->max.y;
	}
	if (this->location.z < this->min.z) {
		this->location.z = this->max.z;
	}
	if (this->location.x > this->max.x) {
		this->location.x = this->min.x;
	}
	if (this->location.y > this->max.y) {
		this->location.y = this->min.y;
	}
	if (this->location.z > this->max.z) {
		this->location.z = this->min.z;
	}
}
void Particle::setLocation(float x, float y, float z) {
	this->location.set(x, y, z);
}
void Particle::setGravity(float x, float y, float z) {
	this->gravity.set(x, y, z);
}
void Particle::setFriction(float x) {
	this->friction = x;
}
void Particle::setRadius(float r) {
	this->radius = r;
}