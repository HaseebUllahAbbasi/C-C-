#include<iostream>
#include<queue>
using namespace std;

class Link
{
    public:
    int data;
    Link* left,*right;
};
class tree
{
    Link* root;
    public:
    tree()
    {
        root = NULL;
    }
    void insert(int x)
    {
        Link* new_Node = new Link;
        new_Node->data = x;
        new_Node->left = NULL;
        new_Node->right = NULL;
        if(root==NULL)
        {
            root = new_Node;
        }
        else
        {
            Link* current = root;
            Link* prev = NULL;
            while(current)
            {
                prev = current;
                if(current->data==x)
                {
                    cout<<"data is already here"<<endl;
                    delete new_Node;
                    return;
                }
                else if(current->data>x)
                {
                    current = current->left;
                }
                else if(current->data<x)
                {
                    current = current->right;
                }
            }
            if(prev->data>x)
            {
                prev->left = new_Node;
            }
            else
            {
                prev->right = new_Node;
            }
        }
    }
    void display_root()
    {
        if(root)
        {
            cout<<root->data<<endl;
        }
        else
        {
            cout<<"tree is empty"<<endl;
        }
    }
    Link* get_root()
    {
        return root;
    }
    void level_order()
    {
        cout<<"in level order"<<endl;
        cout<<endl;
        Link* current = root;
        queue<Link*> que;
        que.push(current);
        while(!que.empty())
        {
            //cout<<"in loop"<<endl;
            Link* new_Node = que.front();
            que.pop();
            cout<<new_Node->data<<" ";
            if(new_Node->left)
            {
                que.push(new_Node->left);
            }
            if(new_Node->right)
            {
                que.push(new_Node->right);
            }
        }
    }
    void pre_order(Link* node)
    {
        if(node)
        {
            cout<<node->data<<" ";
            pre_order(node->left);
            pre_order(node->right);
        }
    }
    void post_order(Link* node)
    {
        if(node)
        {
            post_order(node->left);
            post_order(node->right);
            cout<<node->data<<" ";
        }
    }
    void in_order(Link* node)
    {
        if(node)
        {
            in_order(node->left);
            cout<<node->data<<" ";
            in_order(node->right);
        }
    }
    void ascending(Link* node)
    {
        in_order(node);
    }
    void descending(Link* node)
    {
        if(node)
        {
            post_order(node->right);
            cout<<node->data<<" ";
            pre_order(node->left);
        }
    }
    void delete_node(int x)
    {
        if(root==NULL)
        {
            cout<<"tree is alraedy empty"<<endl;
        }
        else
        {
            Link* current = root;
            Link* prev = current;
            while(current)
            {

                if(current->data ==x)
                break;
                else if(current->data>x)
                {
                    prev = current;
                    current = current->left;
                }
                else
                {
                    prev = current;
                    current = current->right;
                }
            }
            if(current)
            {
                 if(current->right == NULL&&current->left==NULL)
                 {
                    if(current == prev->left)
                    {
                        prev->left = NULL;
                    }
                    else
                    {
                        prev->right = NULL;
                    }
                    delete current;
                 }
                 else if(current->left==NULL)
                 {
                    if(prev->right==current)
                    {
                        prev->right = current->right;
                    }
                    else
                    {
                        prev->left = current->right;
                    }

                 }
                 else if(current->right==NULL)
                 {
                    if(current==prev->right)
                    {
                        prev->right = current->left;
                    }
                    else
                    {
                        prev->left = current->left;
                    }
                 }
                 else
                 {
                    Link* temp, *trail;
                    temp = current->left;
                    while(temp->right)
                    {
                        trail = temp;
                        temp = temp->right;
                    }
                    current->data = temp->data;
                    if(temp->left)
                    {
                        trail->right = temp->left;
                    }
                    delete temp;

                    //
                    /*
                    temp = current->right;
                    while(temp->left)
                    {
                        trail = temp;
                        temp = temp->left;
                    }
                    current->data = temp->data;
                    if(temp->right)
                    {
                        trail->left = temp->right;
                    }
                    delete temp;
                    */
                    //

                 }
                 cout<<x<<" is deleted successfully"<<endl;
            }
            else
            {
                cout<<"not found"<<endl;
            }
        }

    }
    void search_node(int x)
    {
        Link* current = root;
        while(current)
        {
            if(current->data == x)
            {
                cout<<"found the data"<<endl;
                return;
            }
            else if(current->data>x)
            {
                current = current->left;
            }
            else if(current->data<x)
            {
                current = current->right;
            }
        }
        if(current==NULL)
        {
            cout<<"data not found in tree"<<endl;
        }
    }
    void node_with_two_child(int x)
    {

    }
    void leaf_node_conf(int x)
    {
        Link* current = root;
        while(current)
        {
            if(current->data == x)
            {
                cout<<"found the data"<<endl;
                if(current->left==NULL&&current->right==NULL)
                {
                    cout<<x<<" is a leaf node"<<endl;
                }
                else
                {
                    cout<<x<<" is not a leaf node"<<endl;
                }
                return;
            }
            else if(current->data>x)
            {
                current = current->left;
            }
            else if(current->data<x)
            {
                current = current->right;
            }
        }
        if(current==NULL)
        {
            cout<<"data not found in tree"<<endl;
        }
    }
    void call_count_leaf_nodes()
    {
        cout<<count_leaf_nodes(root)<<endl;
    }
    int count_leaf_nodes(Link* node)
    {
        if(node==NULL)
        {
            return 0;
        }
        else if(node->right==NULL&&node->left==NULL)
        {
            return 1;
        }
        else
        {
            return (count_leaf_nodes(node->right)+count_leaf_nodes(node->left));
        }
    }
    void call_number_of_nodes()
    {
        cout<<"number of the nodes in  a tree "<<number_of_nodes(root)<<endl;
    }
    int number_of_nodes(Link* node)
    {
        if(node==NULL)
        {
            return 0;
        }
        else
        {
            return (1+number_of_nodes(node->right)+number_of_nodes(node->left));
        }
    }
    int height(Link* node)
    {
        if(node==NULL)
        {
            return 0;
        }
        else
        {
            return (1+max(height(node->right),height(node->left)));
        }
    }
    void display_height()
    {
        cout<<"height of the tree is "<<height(root)<<endl;
    }
    void successor(Link* node)
    {
        Link* temp;
        if(node->right)
        {
            temp = node->right;
        }
        while(temp->left)
        {
            temp = temp->left;
        }
        if(temp)
        cout<<"the successor is "<<temp->data<<endl;
        else
        cout<<"it does not have any successor"<<endl;
    }
    void pre_desuccessor(Link* node)
    {
        Link* temp;
        if(node->right)
        {
            temp = node->left;
        }
        while(temp->right)
        {
            temp = temp->right;
        }
        if(temp)
        cout<<"the successor is "<<temp->data<<endl;
        else
        cout<<"it does not have any successor"<<endl;
    }
    void minimum()
    {
        if(root==NULL)
        {
            cout<<"tree is null"<<endl;
        }
        else
        {
            Link* current = root;
            while(current->left)
            {
                current = current->left;
            }
            cout<<"minimum number "<<current->data<<endl;
        }
    }
    void maximum()
    {
        if(root==NULL)
        {
            cout<<"tree is null"<<endl;
        }
        else
        {
            Link* current = root;
            while(current->right)
            {
                current = current->right;
            }
            cout<<"minimum number "<<current->data<<endl;
        }
    }
    void delete_tree_function()
    {
        if(root)
        delete_tree(root);
    }
    void delete_tree(Link* node)
    {
        while(node)
        {
            delete_tree(node->right);
            delete_tree(node->left);
            delete node;
            node = NULL;
        }
    }
    ~tree()
    {
        delete_tree_function();
    }
    void depth()
    {
        cout<<"depth of the tree "<<height(root)<<endl;
    }
    void level_of_tree()
    {
        cout<<"level of the tree "<<height(root)<<endl;
    }
    void copy_tree_fucntion(tree &obj)
    {
        delete_tree_function();
        copy_tree(obj.root,root);
    }
    void copy_tree(Link* &copy_from,Link* &copy_to)
    {
        if(copy_from==NULL)
        {
            copy_to = NULL;
        }
        else
        {
            insert(copy_from->data);
            copy_tree(copy_from->left,copy_to->left);
            copy_tree(copy_from->right,copy_to->right);
        }
    }
    tree(tree &obj)
    {
        copy_tree_fucntion(obj);
    }
    void operator=(tree &obj)
    {
        copy_tree_fucntion(obj);
    }
    void path_of_number(int x)
    {
        Link* current = root;
        while(current)
        {
            if(current->data==x)
            {
                cout<<x<<" ";
                break;
            }
            else if(current->data>x)
            {
                cout<<current->data<<" ";
                current = current->left;
            }
            else
            {
                cout<<current->data<<" ";
                current = current->right;
            }
        }
        if(current==NULL)
        {
            cout<<"not found "<<endl;
        }
    }
    void sum_of_tree_function()
    {
        int sum = 0;
        sum_of_tree(root,sum);
        cout<<sum;
    }
    int sum_of_tree(Link* node,int &sum)
    {
        if(node==NULL)
        {
            return 0;
        }
        else
        {
            sum+=node->data;
            sum_of_tree(node->right,sum);
            sum_of_tree(node->left,sum);
        }
    }
    void swap_subTree()
    {
        Link* tempL = root->left;
        Link* tempR = root->right;
        root->left = tempR;
        root->right = tempL;
    }
    void call_single_parent()
    {
        cout<<single_parent(root);
    }
    int single_parent(Link* node)
    {
        if(node==NULL)
        {
            return 0;
        }
        else if(node->left==NULL)
        {
            return 1+single_parent(node->right);
        }
        else if(node->right==NULL)
        {
            return 1+single_parent(node->left);
        }
        else if(node->left&&node->right)
        {
            return single_parent(node->left)+single_parent(node->right);
        }
    }
};

int main()
{
    tree obj;
    obj.insert(45);
    obj.insert(88);
    obj.insert(54);
    obj.insert(53);


    obj.insert(76);
    obj.insert(86);
    obj.insert(65);
    obj.insert(98);
    obj.insert(100);
    obj.insert(1);
    obj.insert(2);
    obj.insert(20);
    obj.insert(6);
    obj.insert(14);
    obj.insert(42);
    obj.insert(32);
    obj.insert(28);
    /*
    //obj.call_number_of_nodes();
    cout<<endl;
    //obj.level_order();
    cout<<endl;
    obj.in_order(obj.get_root());
    //obj.ascending(obj.get_root());
    cout<<endl;
    obj.delete_node(45);
    //obj.ascending(obj.get_root());
    obj.in_order(obj.get_root());
    cout<<endl;
    //obj.descending(obj.get_root());
    //obj.level_order();
    cout<<endl;
    //obj.descending(obj.get_root());
    cout<<endl;
    //cout<<"number of leaf nodes ";obj.call_count_leaf_nodes();
    //obj.sum_of_tree_function();
    //obj.search_node(53);
    */
    //obj.sum_of_tree_function();
    //obj.level_order();
    //cout<<endl;
    //obj.swap_subTree();
    //obj.level_order();
    obj.call_single_parent();

}

