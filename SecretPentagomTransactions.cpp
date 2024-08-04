#include <iostream>
#include <vector>
using namespace std;

class MoneyMovement {
private:
    string name;
    double moneyout;
    double moneyin;
public:
    MoneyMovement(string n, double mt, double mn) {
        name = n;
        moneyout = mt;
        moneyin = mn;
    }

    string GetName() {
        return name;
    }
    double GetMoneyout() {
        return moneyout;
    }
    double GetMoneyin() {
        return moneyin;
    }
};

class MoneyInfo {
private:
    vector<MoneyMovement> VecOfMoney;
public:

    double in = 0;
    double out = 0;

    void SetMoney(MoneyMovement& mnmvt) {
        VecOfMoney.push_back(mnmvt);
    }

    int MoneySum() {
        double sum = 0;
        for (auto it : VecOfMoney) {
            in += it.GetMoneyin();
            out += it.GetMoneyout();
        }
        sum = in - out;
        return sum;
    }

    void ReportOfInOut() {
        cout << "Money In = " << in << endl;
        cout << "Money Out = " << out << endl;
    }
};

int main()
{
    MoneyInfo mninfo;
    MoneyMovement mnmvt1("asdas", 50.0, 500.0);
    MoneyMovement mnmvt2("adasda", 450.0, 500.0);
    MoneyMovement mnmvt3("adfsdf", 10.0, 100.0);
    MoneyMovement mnmvt4("vgcscvxz", 100.0, 50.0);

    mninfo.SetMoney(mnmvt1);
    mninfo.SetMoney(mnmvt2);
    mninfo.SetMoney(mnmvt3);
    mninfo.SetMoney(mnmvt4);

    double sum = mninfo.MoneySum();
    mninfo.ReportOfInOut();
    cout << "General:" << sum << endl;
}
