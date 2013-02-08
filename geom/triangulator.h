#ifndef TRIANGULATOR_H
#define TRIANGULATOR_H
#include <opencv2/core/core.hpp>
class Triangulator
{
public:
    Triangulator();
    static cv::Vec3d sumTo(const cv::Vec3d M_hat,
                           const cv::Vec3d P_up,
                           const cv::Vec3d P_fwd,
                           const cv::Vec3d D);
    /** Find out if point P is within triangle ABC.
        Thanks to <a href="http://www.blackpawn.com/texts/pointinpoly/default.html">
        blackpawn.com</a> for the code. */
    static bool inTri(const cv::Vec3d P,
                      const cv::Vec3d A,
                      const cv::Vec3d B,
                      const cv::Vec3d C);

    /** Get a best-fit plane for a set of points.

        The function returns a vector Q. The equation for
        the plane is x = Q.dot(cv::Vec3d(y,z,1)).*/
    static cv::Vec3d getPlane(std::vector<cv::Vec3d> pts);

    /** Get the centroid of a set of pts. */
    static cv::Vec3d getCentroid(std::vector<cv::Vec3d> pts);

    /** Get the normal of a plane returned by getPlane(). */
    //static cv::Vec3d getPlaneNormal(cv::Vec3d plane);
};

#endif // TRIANGULATOR_H
