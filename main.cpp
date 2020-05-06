#include <iostream>
#include "math/vector3d.h"

using Carbon3D::Vector3D;

int main() {
    Vector3D v = Vector3D(2.3, 4.5, 6.7);

    std::cout << "Hello, World!" << std::endl;
    std::cout << "v = (" << v.x << "," << v.y << "," << v.z << ")" << std::endl;
    std::cout << v[0] << std::endl;

    int n[3][3];

    std::cout << n[0][0] << std::endl;
    std::cout << (*reinterpret_cast<Vector3D *>(n[0])).x << std::endl;

    return 0;
}
