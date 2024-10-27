#include<vector>
#include<unordered_map>
using namespace std;

class SnapshotArray2 {
public:
    SnapshotArray2(int length) {
        current = new int[length];
        for (size_t i = 0; i < length; i++)
        {
            current[i] = 0;
        }
        l = length;
    }

    void set(int index, int val) {
        current[index] = val;
    }

    int snap() {
        /*arrays.push_back(current);
        current = new int[l];
        return version++;*/
        int idx = arrayExist();
        if (idx != -1)
        {
            versionToIndex.insert({ version,idx });
        }
        else
        {
            int* copyCurrent = new int[l];
            for (size_t i = 0; i < l; i++)
            {
                copyCurrent[i] = current[i];
            }
            arrays.push_back(copyCurrent);
            versionToIndex.insert({ version,arrays.size() - 1 });
        }
        return version++;
    }

    int get(int index, int snap_id) {
        /*return arrays[snap_id][index];*/
        return arrays[versionToIndex[snap_id]][index];
    }

    int arrayExist()
    {
        for (int i = 0; i < arrays.size(); i++)
        {
            bool arrayUnmatch = false;
            for (size_t j = 0; j < l; j++)
            {
                if (current[j] != arrays[i][j])
                {
                    arrayUnmatch = true;
                    break;
                }
            }

            if (!arrayUnmatch)
            {
                return i;
            }
        }
        return -1;
    }

    int l;
    int* current;
    vector<int*>arrays;
    unordered_map<int, int>versionToIndex;
    int version = 0;
};

class SnapshotArray {
public:
    SnapshotArray(int length) {
        current = new int[length];
        for (size_t i = 0; i < length; i++)
        {
            current[i] = 0;
        }
        l = length;
    }

    void set(int index, int val) {
        bool found = false;
        for (size_t i = 0; i < localIndex.size(); i++)
        {
            if (localIndex[i] == index)
            {
                localValue[i] = val;
                found = true;
            }
        }
        if (!found)
        {
            localIndex.push_back(index);
            localValue.push_back(val);
        }
    }

    int snap() {
        int localLength = localIndex.size();
        for (int i = 0; i < localLength; i++)
        {
            int idxc = localIndex[i];
            int valuec = localValue[i];
            long long int unoChange;
            int* left = (int*)&unoChange;
            int* right = left + 1;
            *left = idxc;
            *right = valuec;
            history.push_back(unoChange);
        }
        localIndex.clear(); localValue.clear();
        versionToIndex.insert({ version,history.size() - 1 });
        return version++;
    }

    int get(int index, int snap_id) {
        int historyV = versionToIndex[snap_id];
        for (int i = historyV; i >= 0; i--)
        {
            long long int ppair = history[i];
            int* first = (int*)&ppair;
            if (*first == index)
            {
                return *(first + 1);
            }
        }
        return 0; // kao, because initialization was zero hahahahaha
    }

    int l;
    int* current;
    vector<int>localIndex, localValue;
    vector<long long int>history;
    unordered_map<int, int>versionToIndex;
    int version = 0;
};



/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */

int q1146()
{
    SnapshotArray* obj = new SnapshotArray(1);
    obj->set(0, 15);
    obj->snap();
    obj->snap();
    obj->snap();
    obj->get(0, 2);
    return 0;
}
