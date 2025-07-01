#include "DaThuc.h"
#include <cmath>
#include <iomanip>

DaThuc::DaThuc() : N(0), data(1, 0) {}

DaThuc::DaThuc(int n) : N(n), data(n + 1, 0) {}

DaThuc::~DaThuc() {}

void DaThuc::input() {
    std::cout << "Nhap bac cua da thuc: ";
    std::cin >> N;
    data.resize(N + 1);
    for (int i = 0; i <= N; ++i) {
        std::cout << "He so x^" << i << ": ";
        std::cin >> data[i];
    }
}

void DaThuc::print() const {
    for (int i = N; i >= 0; --i) {
        std::cout << std::showpos << data[i] << "*x^" << i << " ";
    }
    std::cout << std::endl;
}

double DaThuc::tinhGiaTri(double x) {
    double sum = 0;
    for (int i = 0; i <= N; ++i) {
        sum += data[i] * std::pow(x, i);
    }
    return sum;
}

DaThuc DaThuc::daoHam() const {
    if (N == 0) return DaThuc(0);

    DaThuc d(N - 1);
    for (int i = 1; i <= N; ++i) {
        d.data[i - 1] = data[i] * i;
    }
    return d;
}

DaThuc DaThuc::tichPhan() const {
    DaThuc t(N + 1);
    for (int i = 0; i <= N; ++i) {
        t.data[i + 1] = data[i] / (i + 1);
    }
    t.data[0] = 0; // Không cộng hằng số tích phân
    return t;
}

DaThuc DaThuc::operator+(const DaThuc& b) const {
    int maxN = std::max(N, b.N);
    DaThuc res(maxN);
    for (int i = 0; i <= maxN; ++i) {
        res.data[i] = (i <= N ? data[i] : 0) + (i <= b.N ? b.data[i] : 0);
    }
    return res;
}

DaThuc DaThuc::operator-(const DaThuc& b) const {
    int maxN = std::max(N, b.N);
    DaThuc res(maxN);
    for (int i = 0; i <= maxN; ++i) {
        res.data[i] = (i <= N ? data[i] : 0) - (i <= b.N ? b.data[i] : 0);
    }
    return res;
}

DaThuc DaThuc::operator*(const DaThuc& b) const {
    DaThuc res(N + b.N);
    for (int i = 0; i <= N; ++i) {
        for (int j = 0; j <= b.N; ++j) {
            res.data[i + j] += data[i] * b.data[j];
        }
    }
    return res;
}

double DaThuc::operator[](int k) const {
    if (k < 0 || k > N) return 0;
    return data[k];
}

double& DaThuc::operator[](int k) {
    if (k > N) {
        data.resize(k + 1, 0);
        N = k;
    }
    return data[k];
}

DaThuc& DaThuc::operator++() {
    for (double& coeff : data) {
        ++coeff;
    }
    return *this;
}

DaThuc& DaThuc::operator--() {
    for (double& coeff : data) {
        --coeff;
    }
    return *this;
}

std::istream& operator>>(std::istream& in, DaThuc& d) {
    std::cout << "Nhap bac cua da thuc: ";
    in >> d.N;
    d.data.resize(d.N + 1);
    for (int i = 0; i <= d.N; ++i) {
        std::cout << "He so x^" << i << ": ";
        in >> d.data[i];
    }
    return in;
}

std::ostream& operator<<(std::ostream& out, const DaThuc& d) {
    for (int i = d.N; i >= 0; --i) {
        out << std::showpos << d.data[i] << "*x^" << i << " ";
    }
    return out;
}
