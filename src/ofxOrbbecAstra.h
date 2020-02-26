//
//  ofxOrbbecAstra.h
//  ofxOrbbecAstra
//
//  Created by Matt Felsen on 10/24/15.
//	Updated by Pierre Proske in 2018-2019
//

#pragma once

#include "ofMain.h"
#include <astra/astra.hpp>
#include <astra/capi/astra.h>

class ofxOrbbecAstra : public astra::FrameListener {

public:

	ofxOrbbecAstra();
	~ofxOrbbecAstra();  

	// For multiple cameras, use "device/sensor0",
	// "device/sensor1", etc. Otherwise, leave blank.
	void setup();
	void setup(const string& uri);
    void setLicenseString(const string& license);
    
	void enableDepthImage(bool enable);
	void enableRegistration(bool useRegistration);
	void setDepthClipping(unsigned short near, unsigned short far);

	void initColorStream();
	void initDepthStream();
	void initPointStream();
	void initHandStream();
    void initBodyStream();
	void initVideoGrabber(int deviceID = 0);

	void update();
	bool isFrameNew();

	void draw(float x = 0, float y = 0, float w = 0, float h = 0);
	void drawDepth(float x = 0, float y = 0, float w = 0, float h = 0);

#ifndef TARGET_OSX
    ofVec2f getJointPosition(int body_id, int joint_id);
    ofVec2f getNomalisedJointPosition(int body_id, int joint_id);
    vector<astra::Joint>& getJointPositions(int body_id);
    int getNumBodies();
    int getNumJoints(int body_id);
    astra::JointType getJointType(int body_id, int joint_id);
    string getJointName(astra::JointType id);
#endif
    
	ofVec3f getWorldCoordinateAt(int x, int y);    

	unsigned short getNearClip();
	unsigned short getFarClip();

	ofShortPixels& getRawDepth();
	ofImage& getDepthImage();
	ofImage& getColorImage();

    map<int32_t,ofVec2f>& getHandsDepth();
    map<int32_t,ofVec3f>& getHandsWorld();

    float getCameraWidth() {return cameraWidth;}
    float getCameraHeight() {return cameraHeight;}

protected:

	virtual void on_frame_ready(astra::StreamReader& reader,
		astra::Frame& frame) override;

	void updateDepthLookupTable();

    astra::StreamSet *streamset;
    astra::StreamReader reader;

    int cameraWidth;
    int cameraHeight;
	bool bSetup;
	bool bIsFrameNew;
	bool bDepthImageEnabled;
	unsigned short nearClip;
	unsigned short farClip;
	int maxDepth;

	ofShortPixels depthPixels;
	ofImage depthImage;
	ofImage colorImage;

	// Hack for Astra Pro cameras which only expose color via a webcam/UVC
	// stream, not through the SDK
	bool bUseVideoGrabber;
	shared_ptr<ofVideoGrabber> grabber;

	vector<char> depthLookupTable;
	vector<ofVec3f> cachedCoords;

    map<int32_t,ofVec2f> handMapDepth;
    map<int32_t,ofVec3f> handMapWorld;

#ifndef TARGET_OSX
    vector<vector<astra::Joint>> joints;
    size_t numBodies;
#endif

};
