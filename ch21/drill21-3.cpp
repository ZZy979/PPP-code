#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <vector>

using namespace std;

int main() {
    istream_iterator<double> iit(cin), eos;
    vector<double> vd(iit, eos);

    ostream_iterator<double> oit(cout, "\n");
    cout << "vd:\n";
    copy(vd.begin(), vd.end(), oit);

    vector<int> vi(vd.size());
    copy(vd.begin(), vd.end(), vi.begin());
    cout << "\n(vd[i], vi[i]) pairs:\n";
    for (int i = 0; i < vd.size(); ++i)
        cout << '(' << vd[i] << ',' << vi[i] << ')' << endl;

    double sum_vd = accumulate(vd.begin(), vd.end(), 0.0);
    cout << "\nsum(vd) = " << sum_vd << endl;
    cout << "sum(vd) - sum(vi) = " << (sum_vd - accumulate(vi.begin(), vi.end(), 0)) << endl;

    reverse(vd.begin(), vd.end());
    cout << "\nreversed vd:\n";
    copy(vd.begin(), vd.end(), oit);

    double mean_vd = sum_vd / vd.size();
    cout << "\naverage(vd) = " << mean_vd << endl;

    vector<double> vd2(vd.size());
    auto it = copy_if(vd.begin(), vd.end(), vd2.begin(), [mean_vd](double d) { return d < mean_vd; });
    vd2.erase(it, vd2.end());
    cout << "\nelements of vd with values less than the mean:\n";
    copy(vd2.begin(), vd2.end(), oit);

    sort(vd.begin(), vd.end());
    cout << "\nsorted vd:\n";
    copy(vd.begin(), vd.end(), oit);
    return 0;
}
