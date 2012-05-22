class Node
{
public:
	Node();
	Node(int id, int cost);
	int getNodeId();
	int getNodeCost();
	void setNodeCost(int cost);
	void setParent(Node &parent);
	
private:
	int mId;
	char mName;
	int mCost;
	Node *mParent;
};

Node::Node()
{

}
Node::Node(int id, int cost)
{
	mId = id;
	mCost = cost;
	mParent = NULL;
}

int Node::getNodeId()
{
	return mId;
}

int Node::getNodeCost()
{
	return mCost;
}

void Node::setNodeCost(int cost)
{
	mCost = cost;
}

void Node::setParent(Node &parent)
{
	mParent = &parent;
}