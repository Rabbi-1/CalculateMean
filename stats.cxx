// Provided by:   ____________Fuad Rabbi__________
// Email Address: ____________frabbi000@citymail.cuny.edu________
// The work in this assignment is my own. Any outside sources have been properly cited.

#include "stats.h"
#include <cassert>

namespace main_savitch_2C
{
    statistician::statistician() {
        count = 0;
        total = 0.0;
        // tinyest and largest are not valid until at least one next() call
    }

    void statistician::next(double r) {
        if (count == 0) {
            tinyest = r;
            largest = r;
        }
        else {
            if (r < tinyest) tinyest = r;
            if (r > largest) largest = r;
        }

        count++;
        total += r;
    }

    void statistician::reset() {
        count = 0;
        total = 0.0;
    }

    int statistician::length() const {
        return count;
    }

    double statistician::sum() const {
        return total;
    }

    double statistician::mean() const {
        assert(count > 0);
        return total / count;
    }

    double statistician::minimum() const {
        assert(count > 0);
        return tinyest;
    }

    double statistician::maximum() const {
        assert(count > 0);
        return largest;
    }

    statistician operator+(const statistician& s1, const statistician& s2) {
        if (s1.length() == 0) return s2;
        if (s2.length() == 0) return s1;

        statistician result;
        result.count = s1.count + s2.count;
        result.total = s1.total + s2.total;

        result.tinyest = (s1.tinyest < s2.tinyest) ? s1.tinyest : s2.tinyest;
        result.largest = (s1.largest > s2.largest) ? s1.largest : s2.largest;

        return result;
    }

    statistician operator*(double scale, const statistician& s)
    {
        if (s.length() == 0) return s;

        statistician result;
        result.count = s.count;
        result.total = scale * s.total;

        double a = scale * s.tinyest;
        double b = scale * s.largest;

        result.tinyest = (a < b) ? a : b;
        result.largest = (a > b) ? a : b;

        return result;
    }

    bool operator==(const statistician& s1, const statistician& s2)
    {
        if (s1.length() == 0 && s2.length() == 0) return true;
        if (s1.length() != s2.length()) return false;

        return (s1.sum() == s2.sum()) &&
               (s1.mean() == s2.mean()) &&
               (s1.minimum() == s2.minimum()) &&
               (s1.maximum() == s2.maximum());
    }
}
