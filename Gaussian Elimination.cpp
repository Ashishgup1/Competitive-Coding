// Logic:
// https://math.stackexchange.com/questions/48682/maximization-with-xor-operator

struct Gaussian {
    int no_of_bits = 20;
    vector<int> v;
    int set, origsize = 0, redsize = 0;

    void push(int val) {
        origsize++;
        if (val) {
            v.push_back(val);
        }
    }

    void clear() {
        v.clear();
        set = 0, redsize = 0;
    }

    void eliminate() {
        set = redsize = 0;
        for (int bit = 0; bit <= no_of_bits; bit++) {
            bool check = false;

            for (int i = redsize; i < v.size(); i++) {
                if ((v[i] >> bit) & 1) {
                    swap(v[i], v[redsize]);
                    check = true;
                    break;
                }
            }

            if (check) {
                for (int i = redsize + 1; i < v.size(); i++) {
                    if ((v[i] >> bit) & 1) {
                        v[i] ^= v[redsize];
                    }
                }

                redsize++;
            }
        }

        v.resize(redsize);

        for (auto it : v) {
            set |= it;
        }
    }

    Gaussian &operator=(Gaussian &orig) {
        v = orig.v;
        set = orig.set;
        redsize = orig.redsize;
        origsize = orig.origsize;

        return *this;
    }
};

// Sample Problem 1: http://codeforces.com/contest/959/problem/F
// Sample Solution 1: http://codeforces.com/contest/959/submission/39772298