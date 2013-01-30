#ifndef SCANMANAGER_H
#define SCANMANAGER_H

#include "camera/camera.h"
#include <vector>
#include "standards/calibrationstandard.h"

/**
  A class to wrangle the cameras and projector.

  In the interest of simplicity, ScanManager automatically finds all cameras
  on the system.
  */
class ScanManager
{
public:
    ScanManager();

    /**
      Get a camera from the manager.
      */
    Camera *getCamera(unsigned int i);

    /** Determine whether left and right cameras are ready. */
    bool areCamerasSet();

    /** Count the number of cameras this manager is responsible for. */
    unsigned int numCameras();

    /** Refresh the list of cameras. */
    unsigned int getAllCameras();

    /** Assign a standard. */
    void setStandard(CalibrationStandard *std){standard = std;}

    void setLeft(Camera *cam);
    void setRight(Camera *cam);



    /** Get the current standard. */
    CalibrationStandard *getStandard(){return standard;}

    void releaseAll();

private:
    std::vector<Camera *> cameras;

    CalibrationStandard *standard;
};

#endif // SCANMANAGER_H
