#include<iostream>
using namespace std;

template <typename T>
class Link
{
    public:
    T data;
    int leftSize;
    Link<T>* left,*right;
};
template <typename T>
class Two4Tree
{
    int size ;
    Link<T>* root;
public:
    Two4Tree()
    {
        size = 0;
        root = NULL;
    }
    Two4Tree(T array[],int s)
    {
        size = 0;
        root = NULL;
        for(int i=0; i<s; i++)
        {
            insert(array[i]);
        }
    }
    ~Two4Tree()
    {

    }

    void insert(T value)
    {
        Link<T>* new_Node = new Link<T>;
        new_Node->data = value;
        new_Node->left = NULL;
        new_Node->right = NULL;
        if(root==NULL)
        {
            root = new_Node;
        }
        else
        {
            Link<T>* current = root;
            Link<T>* prev = NULL;
            while(current)
            {
                prev = current;
                if(current->data==value)
                {
                    cout<<"data is already here"<<endl;
                    delete new_Node;
                    return;
                }
                else if(current->data>value)
                {
                    current = current->left;
                }
                else if(current->data<value)
                {
                    current = current->right;
                }
            }
            if(prev->data>value)
            {
                prev->left = new_Node;
            }
            else
            {
                prev->right = new_Node;
            }
        }
        size++;
    }

    void preorder(Link<T>* node)
    {
        if(node)
        {
            cout<<node->data<<" ";
            preorder(node->left);
            preorder(node->right);
        }
    }

    void postorder(Link<T>* node)
    {
        if(node)
        {
            postorder(node->left);
            postorder(node->right);
            cout<<node->data<<" ";
        }
    }


    void inorder(Link<T>* node)
    {
        if(node)
        {
            inorder(node->left);
            cout<<node->data<<" ";
            inorder(node->right);
        }
    }
    Link<T>* search(T value)
    {
        Link<T>* current = root;
        while(current)
        {
            if(current->data == value)
            {
                cout<<"found the data"<<endl;
                return current;
            }
            else if(current->data>value)
            {
                current = current->left;
            }
            else if(current->data<value)
            {
                current = current->right;
            }
        }
        if(current==NULL)
        {

            cout<<"data not found in tree"<<endl;
            return NULL;
        }
    }
    void delete_node(T value)
    {
        if(root==NULL)
        {
            cout<<"tree is already empty"<<endl;
        }
        else
        {
            Link<T>* current = root;
            Link<T>* prev = current;
            while(current)
            {

                if(current->data==value)
                break;
                else if(current->data>value)
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
                size--;
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
                    Link<T>* temp, *trail;
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

                 }

            }
            else
            {
                cout<<"not found"<<endl;
            }
        }
    }
    void successor(Link<T>* node)
    {
        Link<T>* temp;
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
    void pre_desuccessor(Link<T>* node)
    {
        Link<T>* temp;
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
    Link<T>* get_root()
    {
        return root;
    }
    int getRank(Link<T>* root, T value)
    {
        // Step 1.
        if (root->data == value)
            return root->leftSize;

        // Step 2.
        if (value < root->data) {
            if (!root->left)
                return -1;
            else
                return getRank(root->left, value);
        }

        // Step 3.
        else {
            if (!root->right)
                return -1;
            else {
                int rightSize = getRank(root->right, value);
                  if(rightSize == -1 ) return -1;
                return root->leftSize + 1 + rightSize;
            }
        }
    }
    Link<T>* getSmallestKey (Link<T>* root)
    {
       int  minLeft = 1000000;
       int  minRight = 1000000;
        if (root.left)
            minLeft = getSmallestKey(root.left);
        if (root.right)
            minRight = getSmallestKey(root.right);
        return min (minLeft, minRight, root.data);
    }

};

int main()
{
    //Two4Tree<int> obj;
    //obj.insert(9);
    //obj.insert(10);
    //obj.insert(8);
    //obj.inorder(obj.get_root());
    int array [] = {1,2,3,4,5};
    Two4Tree<int> obj(array,5);
    obj.inorder(obj.get_root());
}
