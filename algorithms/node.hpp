#include <vector>

namespace yaal {
template <typename T>
struct ListNode {
    T val;
    ListNode *next;
    ListNode(T v): val(v), next(nullptr) {};
};

template <typename T>
struct TreeNode {
    T val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(T v): val(v), left(nullptr), right(nullptr) {};
};

template <typename T>
struct GraphNode {
    T val;
    std::vector<GraphNode> *adj;
    GraphNode(T v): val(v) {};
};
}


