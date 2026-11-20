#include <iostream>
#include <cmath>

struct CmplxNum{
private:
    float Re;
    float Im;
public:
    CmplxNum(float Re=0, float Im=0): Re(Re), Im(Im) {}

    CmplxNum operator+(const CmplxNum& other){
        CmplxNum res;
        res.Re=this->Re+other.Re;
        res.Im=this->Im+other.Im;
        return res;
    }
    CmplxNum operator-(const CmplxNum& other){
        CmplxNum res;
        res.Re=this->Re-other.Re;
        res.Im=this->Im-other.Im;
        return res;
    }
    CmplxNum operator*(const CmplxNum& other){
        CmplxNum res;
        res.Re=(this->Re*other.Re)-(this->Im*other.Im);
        res.Im=(this->Re*other.Im)+(this->Im*other.Re);
        return res;
    }
    CmplxNum operator/(const CmplxNum& other){
        CmplxNum res;
        res.Re=((this->Re*other.Re)+(this->Im*other.Im))/((other.Re*other.Re)+(other.Im*other.Im));
        res.Im=((this->Im*other.Re)-(this->Re*other.Im))/((other.Re*other.Re)+(other.Im*other.Im));
        return res;
    }
    float operator~(){
        return sqrt(this->Re*this->Re+this->Im*this->Im);
    }

    void print(){
        if(this->Im>=0)
            std::cout << this->Re << '+' << this->Im << "i\n";
        else
            std::cout << this->Re << this->Im << "i\n";
    }
};

int main(){
    CmplxNum z1(2, 3), z2(1, 5), z3;
    z3=z1+z2;
    z3.print();
    z3=z1-z2;
    z3.print();
    z3=z1*z2;
    z3.print();
    z3=z1/z2;
    z3.print();
    std::cout << ~z1;

    return 0;
}