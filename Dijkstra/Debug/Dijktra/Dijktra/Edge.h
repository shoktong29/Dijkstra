class Node;

class Edge
{
public:
	Edge();
	Edge(Node &start, Node &end, int cost);
	Node getStartNode();
	Node getEndNode();
	int getEdgeCost();

private:
	Node *mStart;
	Node *mEnd;
	int mCost;
};

Edge::Edge()
{

}
Edge::Edge(Node &start, Node &end, int cost)
{
	mStart = &start;
	mEnd = &end;
	mCost = cost;
}

int Edge::getEdgeCost()
{
	return mCost;
}

Node Edge::getStartNode()
{
	return *mStart;
}

Node Edge::getEndNode()
{
	return *mEnd;
}