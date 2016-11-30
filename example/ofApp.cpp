
#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup() {
  key = ofxKeyboard::get();
}

//--------------------------------------------------------------
void ofApp::update() {
  if (key->isPressed('A')) {
    ofLog() << "pressed : a";
  }
  if (key->isPushing('A')) {
    ofLog() << "pushing : a";
  }
  if (key->isRelease('A')) {
    ofLog() << "release : a";
  }

  if (key->anyKey()) {
    ofLog() << "pressed any key";
  }
}

//--------------------------------------------------------------
void ofApp::draw() {}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ) {}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {}
