#include<iostream>
#include<list>
#include<math.h>
using namespace std;
int leaf_nodes = 0;
int non_leaf_nodes = 0;
template<class T>
class BST
{
    public:
        class node
        {
            public:
            T info;
            node* left;
            node* right;
        };
    node* top = NULL;

    void insert(T x)
    {
        node* t = new node;
        t->info = x;
        node* temp = top;
        if(top==NULL)
        {
            top = t;
            return ;
        }
        node* q;
        while(temp!=NULL)
        {
            q = temp;
            if(temp->info>x)
            {
                temp = temp->left;
            }
            else
            {
                temp = temp->right;
            }
        }
        if(q->info>x)
        {
            q->left = t;
        }
        else
        {
            q->right = t;
        }

    }
    void preorder(node* first)
    {
        if(first!=NULL)
        {
            cout<<"\t"<<first->info;
            preorder(first->left);
            preorder(first->right);
        }
    }
    void inorder(node* first)
    {
        if(first!=NULL)
        {

            inorder(first->left);
            cout<<"\t"<<first->info;
            inorder(first->right);
        }
    }

    void postorder(node* first)
    {
        if(first!=NULL)
        {
            postorder(first->left);
            postorder(first->right);
            cout<<"\t"<<first->info;
        }
    }

    void dfs(node* first)
    {
        list <node*>  l;
        if(first==NULL)
            return;
        l.push_front(first);
        while(!l.empty())
        {
            node* t = l.front();
            l.pop_front();
            cout<<endl;
            cout<<"\t"<<t->info;
            if(t->left!=NULL)
            {
                l.push_back(t->left);
            }
            if(t->right!=NULL)
            {
                l.push_back(t->right);
            }
        }
    }
    int height(node* first)
    {
        return first==NULL?0:1+max(height(first->left),height(first->right));
    }
    void count(node* first )
    {
        if(first==NULL)
        {
            return;
        }
        if(first->left==NULL&&first->right==NULL)
        {
            leaf_nodes++;
        }
        else
        {
            non_leaf_nodes++;
        }
        count(first->left);
        count(first->right);
    }
    void  mirror_image(node* first)
    {

        if(first==NULL)
            return ;
        if(first!=NULL)
        {
           mirror_image(first->left);
            mirror_image(first->right);

            node* t = first->left;
            first->left = first->right;
            first->right = t;

        }


    }

    void del(int x)
    {
        node* p = top;
        node* q = NULL;
        node* t = NULL;
        if(p==NULL)
        {
            return ;
        }
        while(p!=NULL)
        {
            if(p->info==x)
            {
                break;
            }
            else if(p->info>x)
            {
                p = p->left;
            }
            else
            {
                p = p->right;
            }
            q = p;
        }
        if(p==NULL)
        {
            cout<<"\nElement Not Found";
            return;
        }
        if(p->left!=NULL&&p->right!=NULL)
        {
            q = p;
            t = p->left;
            while(t->right!=NULL)
            {
                q = t;
                t = t->right;
            }
            p->info = t->info;
            p = t;

        }
        if(q!=NULL)
        {
            if(p->left==NULL&&p->right==NULL)
            {
                if(q->right==p)
                {
                    q->right=NULL;
                }
                else
                {
                    q->left = NULL;
                }
            }
            else if(p->left!=NULL)
            {
                if(q->right == p)
                {
                    q->right = p->left;
                }
                else
                {
                    q->left = p->left;
                }
            }
            else
            {
                if(q->right == p)
                {
                    q->right = p->right;
                }
                else
                {
                    q->left = p->right;
                }

            }
        }
        else
        {
            if(p->left==NULL&&p->right==NULL)
            {
                top = NULL;
            }
            else if( p->left!=NULL)
            {
                top = p->left;
            }
            else
            {
                top = p->right;
            }
        }


    }

};

int main()
{
    BST<int> tree;
    while(true)
    {
        cout<<"\nMENU DRIVEN PROGRAM";
        cout<<"\n1.Insert a node";
        cout<<"\n2.Print (preorder)";
        cout<<"\n3.Print(inorder)";
        cout<<"\n4.Print(postorder)";
        cout<<"\n5.DFS";
        cout<<"\n6.height of tree";
        cout<<"\n7.count";
        cout<<"\n8.Mirror Image";
        cout<<"\n9.Delete by Copying";
        cout<<"\nEnter your choice";
        int ch;
        cin>>ch;
        if(ch==1)
        {
            int x;
            cout<<"\nEnter the info";
            cin>>x;
            tree.insert(x);
        }
        else if(ch==2)
        {
            tree.preorder(tree.top);
        }
        else if(ch==3)
        {
            tree.inorder(tree.top);
        }
        else if(ch==4)
        {
            tree.postorder(tree.top);
        }
        else if(ch==5)
        {
            tree.dfs(tree.top);
        }
        else if(ch==6)
        {
            cout<<"\nHeight of Tree is"<<tree.height(tree.top);
        }
        else if(ch==7)
        {
            leaf_nodes = 0;
            non_leaf_nodes = 0;
            tree.count(tree.top);
            cout<<"\nNumber of leaf nodes is "<<leaf_nodes;
            cout<<"\nNumber of non leaf nodes "<<non_leaf_nodes;
        }
        else if(ch==8)
        {
            tree.mirror_image(tree.top);
        }
        else if(ch==9)
        {
            cout<<"\nEnter the element to delete";
            int x;
            cin>>x;
            tree.del(x);
        }
        else
        {
            break;
        }




    }
}
