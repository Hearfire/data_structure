//tree traversals
//3行：N；后序遍历；中序遍历
//输出先序遍历
//每个数值都互异

#include<cstdio>
#include<string>
#include<queue>
#include<algorithm>
using namespace std;

struct node {
	int data;
	node*left;
	node*right;
};

const int MAXN = 100;
int pre[MAXN], in[MAXN], post[MAXN];//先序，中序，后序
int n;//节点个数

node* create(int postL, int postR, int inL, int inR) {
	if (postL > postR) {//递归边界，到达叶子结点
		return NULL;
	}
	node*root = new node;
	root->data = post[postR];//后序遍历最后的数为根节点数值
	int k;
	for (k = inL; k <= inR; k++) {//中序遍历中找到根节点位置
		if (in[k] == root->data) {
			break;
		}
	}
	int numleft = k - inL;//左子树的结点个数
	root->left = create(postL, postL + numleft - 1, inL, k - 1);
	root->right = create(postL + numleft,postR-1, k + 1, inR);
	return root;
}

void BFS(node*root) {
	queue<node*>q;//存指针值，不存数据值
	q.push(root);//根节点入队
	while (!q.empty()) {
		node*now = q.front();
		q.pop();//访问根节点
		printf("%d ", now->data);
		if (now->left != NULL) {			q.push(now->left);		}
		if (now->right != NULL) { 			q.push(now->right);		}		
	}




}



int main() {
	//初始化
	scanf_s("%d", &n);
	int i;
	for (i = 0; i < n; i++) {
		scanf_s("%d", &post[i]);
	}
	for (i = 0; i < n; i++) {
		scanf_s("%d", &in[i]);
	}

	node*root = create(0, n - 1, 0, n - 1);//建树
	BFS(root);//层序遍历
	return 0;
}