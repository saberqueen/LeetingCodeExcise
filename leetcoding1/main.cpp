#include "commonheader.h"

using namespace std;

//struct CombineTree
//{
//    multimap<int, CombineTree> childrenTree;
//};


//// 创建组合多叉树
//CombineTree createCombineTree(const vector<int>&data, int pos, CombineTree& node)
//{
//    // 递归处理
//    if (pos >= (data.size() - 1))
//    {
//        CombineTree nullNode;
//        return node;
//    }

//    auto value = data[pos];
//    for (auto i = 1; i <= value; ++i)
//    {
//        CombineTree childNode;
//        auto index = pos + i;
//        if(index >= (data.size() - 1))
//        {
//            index = data.size() - 1;
//        }
//        node.childrenTree.emplace(data[index], createCombineTree(data, pos + i, childNode));
//    }

//    return node;
//}

//// 树的深度遍历
//int treeDeepSearch(const CombineTree& tree)
//{
//    auto iDeep = 0;

//    // 记录树的每个路径深度，找出最小
//    return iDeep;
//}


int main(){
    ////题号1：两数和
    CodeID1::Solution::testTwoSum();
    return 0;
}
