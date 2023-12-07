#include <iostream>
#include <climits>
#include <math.h>
#include <string>
#include <cstring> //using strlen in char arrays
#include <set>
#include <algorithm>
#include <vector>
#include <fstream>
#include <list>
#include <stack>
#include <queue>
#include <unordered_map>
#include <map>
#include <set>
#include <cstdlib> // for absolute function

using namespace std;

#define ll long long

// things left to do-
// change parents after rotation  / tried to do, but something is wrong  / done

class node
{
public:
    int data;
    node * left;
    node * right;
    string color;
    node * parent;

    node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;

    }

};

void print_in(node * root);

node * og_root = NULL;


// we rotate towards the right
node * ll_rotation(node * root)
{
    node * temp = root->left;

    node * temp1 = temp->right;
    
    node * temp2 = root->parent;

    root->parent = temp;
    temp->parent = temp2;

    temp->right = root;

    root->left = NULL;
    
    if (temp1 != NULL)
    {
        root->left = temp1;
        temp1->parent = root;
    }
    return temp;
}

// we rotate towards the left
node * rr_rotation(node * root)
{
    node * temp = root->right;

    node * temp1 = temp->left;

    node * temp2 = root->parent;

    root->parent = temp;
    temp->parent = temp2;

    temp->left = root;
    root->right = NULL; 

    if (temp1 != NULL)
    {
        root->right = temp1;
        temp1->parent = root;
    }
    
    return temp;
}

void recolor(node * root)
{
    if (root->color == "black")
    {
        root->color = "red";
    }

    else
    {
        root->color = "black";
    }
}

bool is_returning_node_the_root_node = false;
node * returning = NULL;
bool did_rotation_happen = false;
void check_and_resolve_RR(node * root, int d)
{
    if (root->parent->color == "black")
        {
            // do nothing
        }

        else
        {
            node * parent = root->parent;
            node * grandparent = parent->parent;

            node * sibling = NULL;

            // that is we got the sibling
            if (grandparent->left != parent)
            {
                sibling = grandparent->left;
            }

            else
            {
                sibling = grandparent->right;
            }

            // if sibling is null color is black
            if (sibling == NULL || sibling->color == "black")
            {
                did_rotation_happen = true;
                node * temp = grandparent;
                char rotation[2];
                for (int i = 0; i < 2; i++)
                {
                    if (d <= temp->data)
                    {
                        rotation[i] = 'L';
                        temp = temp->left;
                    }

                    else
                    {
                        rotation[i] = 'R';
                        temp = temp->right;
                    }
                    
                }

                returning = NULL;
                if (rotation[0] == 'L' && rotation[1] == 'L')
                {
                    recolor(grandparent);
                    recolor(parent);
                    returning = ll_rotation(grandparent);
                }

                else if (rotation[0] == 'R' && rotation[1] == 'R')
                {
                    
                    recolor(grandparent);
                    recolor(parent);
                    returning = rr_rotation(grandparent);

                }

                else if (rotation[0] == 'L' && rotation[1] == 'R')
                {
                    recolor(grandparent);
                    recolor(root);
                    grandparent->left = rr_rotation(grandparent->left);
                    returning = ll_rotation(grandparent);
                }

                else if (rotation[0] == 'R' && rotation[1] == 'L')
                {
                    recolor(grandparent);
                    recolor(root);
                    grandparent->right = ll_rotation(grandparent->right);
                    returning = rr_rotation(grandparent);
                }

                // problem might be here
                if (returning->parent != NULL)
                {
                    node * bigp = returning->parent;
                    if (bigp->left == grandparent)
                    {
                        bigp->left = returning;
                    }

                    else
                    {
                        bigp->right = returning;
                    }
                }

                else
                {
                    is_returning_node_the_root_node = true;
                }
            }

            else
            {
                recolor(sibling);
                recolor(parent);

                if (grandparent == og_root)
                {
                    // do nothing
                }

                else
                {
                    recolor(grandparent);
                    
                    check_and_resolve_RR(grandparent, grandparent->data);
                }
            }

        }
}

bool is_root_node = true;
node * insert_in_red_black_tree(node * root, int d, node * parent)
{
    if (root == NULL)
    {
        root = new node(d);

        if (is_root_node)
        {
            root->color = "black";
            root->parent = NULL;
            is_root_node = false;
        }

        else
        {
            root->color = "red";
            root->parent = parent;

            if (root->data <= parent->data)
            {
                parent->left = root;
            }
            
            else
            {
                parent->right = root;
            }
            check_and_resolve_RR(root, d);
            
            
        }

        return root;

    }

    if (d <= root->data)
    {
        // root->left->parent = root;
        // root->left = insert_in_red_black_tree(root->left, d, root);

        // node * temp = insert_in_red_black_tree(root->left, d, root);

        // if (!did_rotation_happen)
        // {
        //     root->left = temp;
        // }
        insert_in_red_black_tree(root->left, d, root);
    }

    else
    {
        // root->right->parent = root;
        // root->right = insert_in_red_black_tree(root->right, d, root);

        // node * temp = insert_in_red_black_tree(root->right, d, root);

        // if (!did_rotation_happen)
        // {
        //     root->right = temp;
        // }

        insert_in_red_black_tree(root->right, d, root);
    }


    return root;


}

void print_in(node * root)
{
    if (root == NULL)
    {
        return;
    }

    print_in(root->left);
    cout << root->data << "(" << root->color << ")" << " ";
    print_in(root->right);
    
}
int main()
{   
    cout << "Enter number of elements to be inserted: ";
    int n;
    cin >> n;

    node * root = NULL;
    for (int i = 0; i < n; i++)
    {
        int d;
        cout << "Enter element: ";
        cin >> d;

        root = insert_in_red_black_tree(root, d, NULL);

        if (is_returning_node_the_root_node)
        {
            root = returning;
        }
        og_root = root;

        cout << "tree after insertion of " << d << " is: ";

       
        print_in(root);
        cout << endl;

        
        is_returning_node_the_root_node = false;
        did_rotation_happen = false;

    }

}
