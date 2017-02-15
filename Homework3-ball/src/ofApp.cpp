#include "ofApp.h"
ofFbo fbo2;



//--------------------------------------------------------------
void ofApp::setup(){
   
    for(int i=0; i<myBall.size(); i++){
        
        int size = (i+1) * 20; // defining the size of each ball based on its place in the array
        int randomX = ofRandom( 0, ofGetWidth() ); //generate a random value bigger than 0 and smaller than our application screen width
        int randomY = ofRandom( 0, ofGetHeight() ); //generate a random value bigger than 0 and smaller than our application screen height
        
        myBall[i].setup(randomX, randomY, size);
        //fbo.allocate(ofGetWidth(), ofGetHeight(), GL_RGBA);
        fbo.allocate(ofGetWidth(), ofGetHeight(), GL_RGBA32F);  // higher precision alpha (no artifacts)
        
        fbo.begin();
        ofClear(255,255,255, 255);
        fbo.end();
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    for(int i=0; i<myBall.size(); i++){
        myBall[i].update();
    }

}

//--------------------------------------------------------------
void ofApp::draw(){
    for(int i=0; i<myBall.size(); i++){
        fbo.begin();
        myBall[i].draw();
        fbo.end();
        ofSetColor(255, 255, 255, 10);
        ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());

        fbo.draw(0,0);
    }}

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
    Ball tempBall;                          // create the ball object
    tempBall.setup(x,y, ofRandom(10,40));   // setup its initial state
    myBall.push_back(tempBall);             // add it to the vector
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

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
