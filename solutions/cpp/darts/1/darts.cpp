#include "darts.h"

namespace darts {
    double score(double x, double y) {
        double square_radius = x * x + y * y;

        if (square_radius > 100.0) return 0;
        if (square_radius > 25.0) return 1;
        if (square_radius > 1.0) return 5;
        return 10;
    }
} // namespace darts
