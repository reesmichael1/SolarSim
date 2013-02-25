#include "testApp.h"

double x = 0;

//--------------------------------------------------------------
void testApp::setup(){
	ofBackground(0,0,0);

	ofSetFrameRate(30);
	ofSetVerticalSync(true);

	glEnable(GL_DEPTH_TEST); //enable depth comparisons and update the depth buffer
	ofDisableArbTex(); //needed for textures to work with gluSphere
	earth.loadImage("earth.jpg");

	quadric = gluNewQuadric();
	gluQuadricTexture(quadric, GL_TRUE);
	gluQuadricNormals(quadric, GLU_SMOOTH);
}

//--------------------------------------------------------------
void testApp::update(){


}

//--------------------------------------------------------------
void testApp::draw(){
	x-=0.1;

	//Center Set
	glTranslatef(ofGetWidth()/2+200*cos(x), ofGetHeight()/2, 200*sin(x));
	
	//rotate sphere over time
	ofRotateY(ofGetFrameNum()*6);
	ofRotateX(270); //south pole facing up



	earth.getTextureReference().bind();
	gluSphere(quadric, 100, 100, 100);
	
	//ofSetColor(255,255,255);
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

