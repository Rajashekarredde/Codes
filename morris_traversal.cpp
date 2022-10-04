#include<bits/stdc++.h>
using namespace std;
struct bst
{
    int data;
    bst *left;
    bst *right;
};

bst * create( int val )
{
    bst *node = new bst();
    node->left = nullptr;
    node->data = val;
    node->right = nullptr;
    return node;
}

bst *insert( bst *root, int val )
{
    if( root == nullptr )
    {
        root = create( val );
    }
    else if( val <= root->data )
    {
        root->left = insert( root->left, val );
    }
    else
    {
        root->right = insert( root->right, val );
    }
    return root;
}

void print( bst *root )
{
    if( !root )
        return;
        
    cout<<root->data<<" ";
    print( root->left );
    print( root->right );
}

void morris( bst* root )
{
    bst *cur = root;
    while( cur )
    {
        if( cur->left == nullptr )
        {
            cout<<cur->data<<" ";
            cur = cur->right;
        }
        else
        {
            bst *prev = cur->left;
            while( prev->right && prev->right != cur )
                prev = prev->right;
            if( prev->right == nullptr )
            {
                prev->right = cur;
                cur = cur->left;
            }
            else
            {
                prev->right = nullptr;
                cout<<cur->data<<" ";
                cur = cur->right;
            }
        }
    }
}

int main()
{
    int n;
    cin>>n;
    bst *root = nullptr;
    for( int i = 0; i<n; i++ )
    {
        int k;
        cin>>k;
        root = insert( root, k );
    }
    morris( root );
    return 0;
}
