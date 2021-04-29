#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
class BST
{
	struct node
	{
		int item;
		node* left;
		node* right;
		node(int valu)
		{
			item = valu;
			left = right = NULL;
		}
	};
	node* root = nullptr;
	void add_help(node* temp2, int val)
	{
		if (val > temp2->item)
		{
			if (temp2->right == NULL)
			{
				temp2->right = new node(val);
			}
			else
			{
				add_help(temp2->right, val);
			}
		}
		else
		{
			if (temp2->left == NULL)
			{
				temp2->left = new node(val);
			}
			else
			{
				add_help(temp2->left, val);
			}

		}
	}
	int get_max_help(node* temp3)
	{
		if (temp3->right == nullptr)
			return temp3->item;
		else
			return get_max_help(temp3->right);
	}
	int get_min_help(node* temp4)
	{
		if (temp4->left == nullptr)
			return temp4->item;
		else
			return get_max_help(temp4->left);
	}
	int get_hight_help(node* temp5)
	{

		if (temp5 == nullptr)
			return -1;
		int left_subTree = get_hight_help(temp5->left);
		int right_subTree = get_hight_help(temp5->right);
		return (1 + max(left_subTree, right_subTree));
	}
	void pre_order(node* temppre)
	{
		if (temppre == nullptr)
			return;
		cout << temppre->item << " ";
		pre_order(temppre->left);
		pre_order(temppre->right);
	}
	void in_order(node* tempin)
	{
		if (tempin == nullptr)
			return;
		in_order(tempin->left);
		cout << tempin->item << " ";
		in_order(tempin->right);
	}
	void post_order(node* temppost)
	{
		if (temppost == nullptr)
			return;
		post_order(temppost->left);
		cout << temppost->item << " ";
		post_order(temppost->right);
	}
	node* remove_help(node* temp6, int itemremovehelp)
	{
		if (root == nullptr)return NULL;
		else if (itemremovehelp < temp6->item)
			temp6->left = remove_help(temp6->left, itemremovehelp);
		else if (itemremovehelp > temp6->item)
			temp6->right = remove_help(temp6->right, itemremovehelp);
		else
		{
			if (temp6->left == nullptr)
			{
				node* temp7 = temp6->right;
				delete temp6;
				return temp7;
			}
			else if (temp6->right == nullptr)
			{

				node* temp7 = temp6->left;
				delete temp6;
				return temp7;
			}
			else
			{
				int maxvalue = this->get_max_help(temp6->left);
				temp6->item = maxvalue;
				temp6->left = remove_help(temp6->left, maxvalue);
			}
		}
		return temp6;
	}
	node* shearch_help(node* temp8, int itemsearch)
	{
		if (temp8 == nullptr)return NULL;
		if (itemsearch > temp8->item)
		{
			if (itemsearch == temp8->item)return temp8;
			else if (temp8->left == nullptr && temp8->right == nullptr && itemsearch != temp8->item)return nullptr;
			temp8->right = shearch_help(temp8->right, itemsearch);
		}
		else if (itemsearch <= temp8->item)
		{
			if (itemsearch == temp8->item)return temp8;
			else if (temp8->left == nullptr && temp8->right == nullptr && itemsearch != temp8->item)return nullptr;
			temp8->left = shearch_help(temp8->left, itemsearch);
		}
	}
public:

	void add(int value)
	{
		if (root == NULL)
		{
			root = new node(value);
		}
		else
		{
			add_help(root, value);
		}
	}
	int get_max()
	{
		return get_max_help(root);
	}
	int get_min()
	{

		return get_min_help(root);
	}
	int get_hight()
	{
		if (root == nullptr)
			return -1;
		else
		{
			return get_hight_help(root);
		}
	}
	void display_by_level_order()
	{
		if (root == nullptr)return;
		queue<node*>Q;
		Q.push(root);
		while (!Q.empty())
		{
			node* cur = Q.front();
			Q.pop();
			cout << cur->item << " ";
			if (cur->left != nullptr)Q.push(cur->left);
			if (cur->right != nullptr)Q.push(cur->right);
		}
		cout << endl;
	}
	void display_by_pre_order()
	{
		if (root != nullptr)
			pre_order(root);
		cout << endl;
	}
	void display_by_in_order()
	{
		if (root != nullptr)
			in_order(root);
		cout << endl;
	}
	void display_by_post_order()
	{
		if (root != nullptr)
			post_order(root);
		cout << endl;
	}
	void remove(int itemremove)
	{
		root = remove_help(root, itemremove);
	}
	void shearch(int valuesearch)
	{
		node* sh = shearch_help(root, valuesearch);
		if (sh != nullptr)
			cout << "Founde \n";
		else
			cout << "Not Found \n";
	}

};
int main()
{
	BST ob;
	ob.add(10);
	ob.add(7);
	ob.add(15);
	ob.add(2);
	ob.add(1);
	ob.add(18);
	cout << "Print by post order : " << endl;
	ob.display_by_post_order();
	int x = 0;
	cout << "Enter a number you need searching it : "; cin >> x;
	ob.shearch(x);
	system("pause");
	return 0;
}