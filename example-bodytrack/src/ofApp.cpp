//
//  ofApp.cpp
//  example
//
//  Created by Pierre Proske on 12/04/17.
//
//

#include "ofApp.h"

void ofApp::setup(){
	ofBackground(0);
    ofSetWindowShape(1280, 960);
	ofSetVerticalSync(true);


	astra.setup();
   // astra.setLicenseString("<INSERT LICENSE KEY HERE>");

	astra.initDepthStream();
    astra.initBodyStream();

}

void ofApp::update(){
	ofSetWindowTitle(ofToString(ofGetFrameRate()));

	astra.update();

}

void ofApp::draw(){
    astra.drawDepth(0, 0,ofGetWidth(),ofGetHeight());

    if(astra.getJointPositions().size() > 0) {
       ofLogNotice() << "Number of bodies = " << astra.getJointPositions().size();
        vector<ofVec2f>& joints = astra.getJointPositions()[0];
        for(int i = 0; i < joints.size();i++)
        {
            ofDrawCircle(joints.at(i)*2,5);
        }
    }
}

void ofApp::keyPressed(int key){

}
