#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	ofSetFrameRate(60);
	ofEnableAlphaBlending();
	ofSetCircleResolution(64);
	NUM = 2000;
	//ofEnableDepthTest();
	for (int i = 0; i < NUM; i++) {
		this->particles.push_back(shared_ptr<Particle>(new Particle()));
		this->particles[i]->setLocation(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()), ofRandom(-ofGetHeight() / 2, ofGetHeight() / 2));
		this->particles[i]->setGravity(0.0, 0.0, 0.0);
		this->particles[i]->setFriction(0.01);
		this->particles[i]->setRadius(3.0);
	}
	ofBackground(0);

	this->fbo.allocate(ofGetWidth(), ofGetHeight());
}

//--------------------------------------------------------------
void ofApp::update(){
	this->fbo.begin();
	ofSetBackgroundAuto(false);
	ofClear(0);
	ofSetColor(0, 0, 0, 60);
	ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
	
	ofSetColor(255);
	for (int i = 0; i < NUM; i++) {
		this->particles[i]->update();
		this->particles[i]->draw();
		this->particles[i]->bounceOffWalls();
	}
	this->fbo.end();
}
//--------------------------------------------------------------
void ofApp::draw(){
	ofSetBackgroundAuto(true);
	this->fbo.draw(0, 0, ofGetWidth(), ofGetHeight());
	if (this->bTakesnap == true) {
		string now = ofGetTimestampString("%Y%m%d%H%M%S");
		this->img.grabScreen(0, 0, ofGetWidth(), ofGetHeight());
		this->img.save("of" + now + ".png");
		this->bTakesnap = false;
	}
}
//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
	if (key == 'x') {
		this->bTakesnap = true;
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {
	for (int i = 0; i < NUM; i++) {
		ofVec2f mouseLoc = ofVec2f(x, y);
		this->particles[i]->attract(mouseLoc, 400.0, 5.0, 60.0);
	}
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}