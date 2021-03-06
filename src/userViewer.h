
#ifndef _USERSELECTOR_VIEWER_H_
#define _USERSELECTOR_VIEWER_H_

//#include "ros/ros.h"
//#include "NiTE.h"
#include "userSelector.h"

#define MAX_DEPTH 10000

class UserViewer
{
public:
	UserViewer(const char* strName);
	virtual ~UserViewer();
	
	virtual openni::Status init(int argc, char** argv, UserSelector* pUserSelectorObj = NULL);
	virtual openni::Status run(); // does not return
	void updateFrame();
	void detectionRoutine();
protected:
	virtual void DisplayCallback();
	virtual void DisplayPostDraw(){};
	
	virtual void OnKey(unsigned char key, int x, int y);
	
	virtual openni::Status InitOpenGL(int argc, char** argv);
	void InitOpenGLHooks();
	
	void Finalize();
	
private:
	UserViewer(const UserViewer&);
	UserViewer& operator=(UserViewer&);

	static UserViewer* 	ms_self;
		
	static void glutIdle();
	static void glutDisplay();
	static void glutKeyboard(unsigned char key, int x, int y);
	
	float 					m_pDepthHist[MAX_DEPTH];
	char 					m_strSampleName[ONI_MAX_STR];
	openni::RGB888Pixel* 	m_pTexMap;
	unsigned int 			m_nTexMapX;
	unsigned int 			m_nTexMapY;
	
	openni::Device 			m_device;
	
	nite::UserTrackerFrameRef* 		m_pUserTrackerFrame;	
	UserSelector*					m_pUserSelector;
};

#endif // _USERSELECTOR_VIEWER_H_
