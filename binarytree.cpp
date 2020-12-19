/*二叉树学习*/
本篇针对面试中常见的二叉树操作作个总结：
1、前序遍历，中序遍历，后序遍历；
2、层次遍历；
3、求树的结点数；
4、求树的叶子数；
5、求树的深度；
6、求二叉树第k层的结点个数；
7、判断两棵二叉树是否结构相同；
8、求二叉树的镜像；
9、求两个结点的最低公共祖先结点；
10、求任意两结点距离；
11、找出二叉树中某个结点的所有祖先结点；
12、不使用递归和栈遍历二叉树；
13、二叉树前序中序推后序；
14、判断二叉树是不是完全二叉树；
15、判断是否是二叉查找树的后序遍历结果；
16、给定一个二叉查找树中的结点，找出在中序遍历下它的后继和前驱；
17、二分查找树转化为排序的循环双链表；
18、有序链表转化为平衡的二分查找树；
19、判断是否是二叉查找树。

/*前序遍历非递归(根 左 右)*/
void PreOrderNoRec(Node *node){
	
	if(NULL != node){
		
		stack<Node *>S;
		cout << node->data << ' ';
		node = node->left;
		
		while(!S.empty() || node){
			
			while(node){
				
				cout << node->data << ' ';
				S.push(node);
				node = node->left;
			}
			
			node = S.top()->right;
			S.pop();
		}
	}
}


/*中序的非递归遍历(左 根 右)*/
void InfixOrderNoRec(Node *node){
	
	if(NULL != node){
		
		stack<Node *>S;
		S.push(node);
		node = node->left;
		
		while(!S.empty() || node){
			
			while(node){
				
				S.push(node);
				node = noed->left;
			}
			
			cout << S.top()->data << ' ';
			node = S.top()->right;
			S.pop();
		}
	}
}

/*后序遍历非递归(左 右 根)*/
void PostOrderNoRec(Node *node){
	
	if(NULL != node){
		
		Node *pre = nullptr;
		stack<Node *> S;
		S.push(node);
		
		while(!S.empty()){
			
			node = S.top();
			
			if((!node->left && !node->right) ||
				pre && (pre == node->left || pre == node->right))){
			
				cout << node->data << ' ';
				pre = node;
				S.pop();
			}else{
				
				if(node->right){
					
					S.push(node->right);
				}
				if(node->left){
					
					S.push(node->left);
				}
			}
		}
	}
}
			  A
		B  		   C
	D      E    F     G 

/*层次遍历 从上到下*/
void LevelOrder(Node *node){
	
	if(NULL != node){
		Node *p = node;
		queue<Node *> Q;
		Q.push(p);

		
		while(!Q.empty()){
			
			p = Q.front();
			cout << p->data << ' ';	
			/*先将 A入队， 在访问A, 然后将 A的左右 孩子 B C 入队， 入队之后访问B 在将B的左右孩子入队， 在访问C 依次类推*/
			Q.pop();
			if(p->left){
				
				Q.push(p->left);
			}
			
			if(p->right){
				
				Q.push(p->right);
			}
		}
	}
}



/*求二叉树的节点个数*/
void CountNode(Node *node){
	
	if(nullptr != node){
		
		return CountNode(node->left) + CountNode(node->right) + 1;
	}
}

			  A
		B  		   C
	D      E    F     G 

/*求二叉树的叶子节点个数*/
int CountLeafNode(Node *node){
	
	if(nullptr != node){
		
		if(!node->left && !node->right)
			return 1;
		
		return CountLeafNode(node->left) + CountLeafNode(node->right);
	}
}
			 A
		B  		   C
	D      E    F     G 

/*求树的深度*/
int DepthOfTheTree(Node *node){
	if(nullptr == node){
		return 0;
	}
	
	int iLeftLenth = DepthOfTheTree(node->left) + 1;
	int iRightLenth = DepthOfTheTree(node->right) + 1;
	
	return iLeftLenth > iRightLenth ? iLeftLenth : iRightLenth;
}


/*求二叉树第k层的节点个数*/
int GetKLevelCountNode(Node *node, int k){
	
	if(nullptr == node){
		return 0;
	}
	
	if(1 == k){
		
		return 1;
	}
	
	return GetKLevelCountNode(node->left, k - 1) + GetKLevelCountNode(node->right, k - 1);

}


/*判断两棵二叉树是否结构相同*/
/*不考虑数据内容。结构相同意味着对应的左子树和对应的右子树都结构相同*/
bool JudgeTheTreeIsSame(Node *node1, Node *node2){
	
	/*两棵二叉树的节点必须同时满足为空菜认为是相同的二叉树*/
	if(nullptr == node1 && nullptr == node2){
		
		return true;
	}/*若不同时为空，一方先为空， 则认为是fasle*/
	else if(nullptr == node1 || nullptr == node2){
		return false;
	}
	
	/*首先判断的是两棵二叉树的左节点， 然后判断两棵二叉树的右节点
	然后&& 必须同时满足才认为相同*/
	return JudgeTheTreeIsSame(node1->left, node2->left) && JudgeTheTreeIsSame(node1->right, node2->right);
}

/*求二叉树的镜像*/
/*对于每个节点 我们交换他的左右孩子即可*/
			 A
		B  		     C
	D      E     F
void ImageoftheTree(Node *node){
	
	if(nullptr == node){
		
		return;
	}
	
	Node *temp = node->left;
	node->left = node->right;
	node->right = temp;
	
	ImageoftheTree(node->left);
	ImageoftheTree(node->right);
}

                              1
				  2                    7
			3           4                   8 
					 


/*求两个节点的最低公共祖先节点*/
//https://blog.csdn.net/yunzhongguwu005/article/details/11124491
Node *FindLCA(Node *node, Node *target1, Node *target2){
	
	if(nullptr == node){
		return nullptr;
	}
	
	if(node == target1 || node == target2){
		
		return node;
	}
	
	/*这两层递归分别是找到两个节点是否在左右子树上*/
	Node *Left = FindLCA(node->left, target1, target2);
	Node *Right = FindLCA(node->right, target1, target2);
	
	if(Left && Right){
		return node;		/*若两个节点分别在左右子树，那么祖先节点就是根节点*/
	}
	
	return Left ? Left : Right;  /*两个节点分别左子树或右子树上*/
}

/*10、找到两个节点之间的距离*/
/****
 *1.先找到两个节点的祖先节点
 *2.在计算祖先节点到这两个节点的距离
****/

Node *FindLCA(Node *node, Node *target1, Node *target2)
{
	if(nullptr == node){
		
		return nullptr;
	}
	
	if(node == target1 || node == target2){
		return node;
	}
	
	Node *Left = FindLCA(node->left, target1, target2);
	Node *Right = FindLCA(node->right, target1, target2);
	
	if(Left && right){
		return node;
	}
	
	return Left ? Left : Right;
}

int CalcTargetDistance(Node *node, Node *target){
	
	if(nullptr == node){
		return -1;
	}
	if(target == node){
		
		return 0;
	}
	
	//循环遍历左子树是否有该节点
	iLevel = CalcTargetDistance(node->left, target);
	if(-1 == iLevel){
		
		//不在左子树上循环遍历右子树
		iLevel = CalcTargetDistance(node->right, target);
	}
	
	if(iLevel != -1){
		
		return iLevel + 1;
	}	
	
	return -1;
	
}

int CalcTwoNodeDistance(Node *node, Node *target1, Node *target2){
	
	Node *Lca = FindLCA(node, target1, target2);
	int iLevel1 = CalcTargetDistance(Lca, target1);
	int iLevel2 = CalcTargetDistance(Lca, target2);
	
	return iLevel1 + iLevel2;
}

/*11.找出二叉树中某个节点的所有祖先节点*/
					
					1
				   / \
			      2   7
				 / \   \
				3   4   8 
				   / \   \
				  5   6   9
				         / \
						10  11
/*如果给定结点 5，则其所有祖先结点为 4,2,1*/
bool FindNodeAllLCA(Node *node, Node *target){
	if(nullptr == node){
		return false;
	}
	if(node == target){
		return true;
	}
	
	if(FindNodeAllLCA(node->left, target) || FindNodeAllLCA(node->right, target)){
		cout << node->data << ' ';
		return true;
	}
	
	return false;
}					

/*13.二叉树前序中序推后序*/
/*
方式	序列
前序	[1 2 4 7 3 5 8 9 6]
中序	[4 7 2 1 8 5 9 3 6]
后序	[7 4 2 8 9 5 6 3 1]

根据上述可以推出二叉树的图形
				1
			   / \
			  2   3
			 /   / \
			4   5   6
			 \ / \
			  78  9
			  
以上面图表为例，步骤如下：

根据前序可知根结点为1；
根据中序可知 4 7 2 为根结点 1 的左子树和 8 5 9 3 6 为根结点 1 的右子树；
递归实现，把 4 7 2 当做新的一棵树和 8 5 9 3 6 也当做新的一棵树；
在递归的过程中输出后序。
*/


/*14.判断二叉树是不是完全二叉树
若设二叉树的深度为 h，除第 h 层外，其它各层 (1～h-1) 的结点数都达到最大个数，第 h 层所有的结点都连续集中在最左边，这就是完全二叉树（Complete Binary Tree）。如下图：图片

					  1
				/		   \
			   2		   3
			 /	 \        /   \
           4       5      6      7
          / \     / \    /
         8   9   10  11 12		  
首先若一个结点只有右孩子，肯定不是完全二叉树；其次若只有左孩子或没有孩子，那么接下来的所有结点肯定都没有孩子，否则就不是完全二叉树，因此设置 flag 标记变量。
*/
bool IsCBT(Node *node){
	
	bool flag = false;
	queue<Node *> Q;
	Q.push(node);
	
	while(!Q.empty()){
		
		Node *p = Q.front();
		Q.pop();
		if(flag){
			if(p->left || p->right)
			return false;
		}
		else{
			
			if(p->left && p->right){
				
				Q.push(p->left);
				Q.push(p->right);
			}else if(p->left){
				
				return true;
			}else if(p->right){
				
				return false;
			}else{
					//没有节点
				return true;
			}
		}
	}
	return true;
}

/*15判断是否是二叉树的后序遍历结果
在后续遍历得到的序列中，最后一个元素为树的根结点。从头开始扫描这个序列，比根结点小的元素都应该位于序列的左半部分；从第一个大于跟结点开始到跟结点前面的一个元素为止，所有元素都应该大于跟结点，因为这部分元素对应的是树的右子树。根据这样的划分，把序列划分为左右两部分，我们递归地确认序列的左、右两部分是不是都是二元查找树。*/
int array[n];	/*长度为n的序列，注意begin和end遵循的是左闭右闭原则*/
bool IsSequenceOfBST(int begin, int iEnd){
	
	if(iEnd - begin <= 0){
		return true;
	}
	
	int iRootData = array[iEnd];	//数组尾为根节点
	int i = begin;
		
	for(; array[i] < iRootData; i++)
		;
	
	int j = i;
	
	for(; j < iEnd; j++){
		if(array[j] < iRootData){
			return false;
		}
	}
	
	return IsSequenceOfBST(begin, i - 1) && IsSequenceOfBST(i, iEnd - 1);
}

/*16.给定一个二叉查找树种中的节点（存在一个指向父亲节点的指针） 找出在中序遍历下它的后继和前驱

一棵二叉查找树的中序遍历序列，正好是升序序列。假如根结点的父结点为 nullptr，则：

如果当前结点有右孩子，则后继结点为这个右孩子的最左孩子；
如果当前结点没有右孩子；
2.1. 当前结点为根结点，返回 nullptr；
2.2. 当前结点只是个普通结点，也就是存在父结点；
2.2.1. 当前结点是父亲结点的左孩子，则父亲结点就是后继结点；
2.2.2. 当前结点是父亲结点的右孩子，沿着父亲结点往上走，直到 n-1 代祖先是 n 代祖先的左孩子，则后继为 n 代祖先或遍历到根结点也没找到符合的，则当前结点就是中序遍历的最后一个结点，返回 nullptr。
*/
Node *FindIncrement(Node *node){
	
	/*当前节点有右孩子*/
	if(node->right){
		node = node->right;
		while(node->left){
			
			node = node->left;
		}
		return node;
	}else{			/*当前节点没有右孩子*/
		
		if(node->parent == nullptr){  /*2.1*/ 
			
			return node;
		}
		
		Node *p = node->parent;
		if(p->left == node){
			
			return p;
		}else{
			
			while(p->right == node){
				
				node = p;
				p = p->parent;
				if(p == nullptr){
					
					return nullptr;
				}
			}
			
			return p;
			
		}
	}
}

/*优化算法*/
Node *FindIncrement(Node *node){
	
	if(node->right){
		node = node->right;
		while(node){
			node = node->left;
		}
	}else{
		Node *p = node->parent;
		while(p && p->right == node){
			
			node = p;
			p = p->parent;
		}
		node = p;
	}
	return node;
}