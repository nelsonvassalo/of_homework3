#include "Ball.hpp"


Ball::Ball(){
};

void Ball::setup(float _x, float _y, int _dim){
    x = _x;
    y = _y;
    dim = _dim;
    
    speedX = ofRandom(-1, 1);
    speedY = ofRandom(-1, 1);
    
    fbo.begin();
    color.set(ofRandom(255), ofRandom(255), ofRandom(255));
    ofSetColor(255, 255, 255, 10);
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
    fbo.end();
    fbo.draw(0,0);
    
}

void Ball::update(){
    if(x < 0 ){
        x = 0;
        speedX *= -1;
    } else if(x > ofGetWidth()){
        x = ofGetWidth();
        speedX *= -1;
    }
    
    if(y < 0 ){
        y = 0;
        speedY *= -1;
    } else if(y > ofGetHeight()){
        y = ofGetHeight();
        speedY *= -1;
    }
    
    x+=speedX;
    y+=speedY;
}

void Ball::draw(){
    fbo.begin();
    ofSetColor(color);
    ofDrawCircle(x, y, dim);
    ofSetColor(255,255,255, 5);
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
    fbo.end();
    fbo.draw(0,0);
    
    
    
    }
