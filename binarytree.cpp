/*二叉树学习*/


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
