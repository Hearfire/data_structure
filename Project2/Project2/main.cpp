//tree traversals
//3�У�N������������������
//����������
//ÿ����ֵ������

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
int pre[MAXN], in[MAXN], post[MAXN];//�������򣬺���
int n;//�ڵ����

node* create(int postL, int postR, int inL, int inR) {
	if (postL > postR) {//�ݹ�߽磬����Ҷ�ӽ��
		return NULL;
	}
	node*root = new node;
	root->data = post[postR];//�������������Ϊ���ڵ���ֵ
	int k;
	for (k = inL; k <= inR; k++) {//����������ҵ����ڵ�λ��
		if (in[k] == root->data) {
			break;
		}
	}
	int numleft = k - inL;//�������Ľ�����
	root->left = create(postL, postL + numleft - 1, inL, k - 1);
	root->right = create(postL + numleft,postR-1, k + 1, inR);
	return root;
}

void BFS(node*root) {
	queue<node*>q;//��ָ��ֵ����������ֵ
	q.push(root);//���ڵ����
	while (!q.empty()) {
		node*now = q.front();
		q.pop();//���ʸ��ڵ�
		printf("%d ", now->data);
		if (now->left != NULL) {			q.push(now->left);		}
		if (now->right != NULL) { 			q.push(now->right);		}		
	}




}



int main() {
	//��ʼ��
	scanf_s("%d", &n);
	int i;
	for (i = 0; i < n; i++) {
		scanf_s("%d", &post[i]);
	}
	for (i = 0; i < n; i++) {
		scanf_s("%d", &in[i]);
	}

	node*root = create(0, n - 1, 0, n - 1);//����
	BFS(root);//�������
	return 0;
}