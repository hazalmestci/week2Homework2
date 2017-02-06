#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    nPts = 0;
    position= ofVec2f(ofGetWindowWidth () * 0.5, ofGetWindowHeight() * 0.5);
    velocity = ofVec2f (0);
    acceleration = ofVec2f (0);
    radius= 50;
    friction = 0.95;
}

//--------------------------------------------------------------
void ofApp::update(){
    velocity *= friction;
    position += velocity;
    radius = velocity.length() * 10;
    
    
    if(position.x >= ofGetWindowWidth() || position.x <= 0){
        //        position.x = ofGetWindowWidth() -1;
        velocity.x= velocity.x * -1;
    }
    
    if(position.y >= ofGetWindowHeight() || position.y <= 0){
        //        position.y = ofGetWindowHeight() -1;
        velocity.y= velocity.y * -1;
    }

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofDrawTriangle(position, position, position);
    cout << acceleration << endl;

    
    ofSetColor(255,0,0);
    if (nPts > 1) {
        for (int i = 0; i < nPts - 1; i++) {
            ofLine(pts[i].x, pts[i].y, pts[i+1].x, pts[i+1].y);
        }
        
    }
    

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
}


//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    if (nPts < MAX_PTS) {
        pts[nPts].x =x;
        pts[nPts].y =y;
        nPts++;
    }
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    nPts= 0;
    
    ofVec2f mousePos= ofVec2f (x,y);
    
    acceleration = mousePos - position;
    acceleration = 10 * acceleration.getNormalized();
    
    velocity += acceleration;
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
