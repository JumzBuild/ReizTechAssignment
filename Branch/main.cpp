#include <iostream>
#include <vector>

using namespace std;

class Branch {
public:
   vector<Branch> branches;

    int calculateDepth() const
    {
        if (branches.empty())
            {
                return 1;  // Depth is 1 if there are no child branches
            }
        else
            {
                int maxChildDepth = 0;
                for (const Branch& branch : branches)
                {
                    int childDepth = branch.calculateDepth();
                    if (childDepth > maxChildDepth)
                    {
                    maxChildDepth = childDepth;
                    }
                }
            return 1 + maxChildDepth;  // Depth is 1 plus the maximum depth of child branches
            }
    }
};

int main()
{

    Branch root;
    for (int i = 0; i < 3; ++i)
        {
        Branch branch1;
        for (int j = 0; j < 2; ++j)
        {
            Branch branch2;
            for (int k = 0; k < 4; ++k)
            {
                Branch branch3;
                branch2.branches.push_back(branch3);
            }
            branch1.branches.push_back(branch2);
        }

        root.branches.push_back(branch1);
    }

    // Calculate the depth using recursion
    int depth = root.calculateDepth();
    cout << "Depth of the structure: " << depth <<endl;

    return 0;
}
