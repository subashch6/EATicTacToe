
int x = 1;
int o = 4;
int none = 0;
int board[9] = {0,0,0,0,0,0,0,0,0};
int turn = 1;

struct node
{
    int x;
    int y;
    int z;
    node *next;
    node *prev;
}

void addNode(struct node *nextToNode, struct node *nodeToAdd)
{
    nodeToAdd->next = nextToNode->next;
    nodeToAdd->prev = nextToNode;
    nextToNode->next = nodeToAdd;

}
struct node node0, node1,node2,node3,node4,node5,node6,node7;
struct node nodeOurs, nodeOurs1, nodeOurs2, nodeOurs3, nodeOurs4, nodeOurs5, nodeOurs6, nodeOurs7;
struct node nodeOp, nodeOp1, nodeOp2, nodeOp3, nodeOp4, nodeOp5, nodeOp6, nodeOp7;
void settingUp()
{
	addNode(&nodeOurs, &nodeOurs1);
	addNode(&nodeOurs1, &nodeOurs2);
	addNode(&nodeOurs2, &nodeOurs3);
	addNode(&nodeOurs3, &nodeOurs4);
	addNode(&nodeOurs4, &nodeOurs5);
	addNode(&nodeOurs5, &nodeOurs6);
	addNode(&nodeOurs6, &nodeOurs7);
	(&nodeOurs7)->next = &nodeOurs;

	addNode(&nodeOp, &nodeOp1);
	addNode(&nodeOp1, &nodeOp2);
	addNode(&nodeOp2, &nodeOp3);
	addNode(&nodeOp3, &nodeOp4);
	addNode(&nodeOp4, &nodeOp5);
	addNode(&nodeOp5, &nodeOp6);
	addNode(&nodeOp6, &nodeOp7);
	(&nodeOp7)->next = &nodeOp;
}
void reset()
{
	struct node *nodeMain = &nodeOurs;
	while(nodeMain->next != &nodeOurs)
	{
		nodeMain->x = -1;
		nodeMain = nodeMain->next;
	}
	nodeMain->x = -1;
	nodeMain = &nodeOp;
	while(nodeMain->next != &nodeOp)
	{
		nodeMain->x = -1;
		nodeMain = nodeMain->next;
	}
	nodeMain->x = -1;
}

void headNode(struct node *node)
{
    node->next = node;
    node->prev = node;
}




void removeNode(struct node *nodeToRemove)
{
    node *prev= nodeToRemove->prev;
    node *next = nodeToRemove->next;
    prev->next = next;
    next->prev = prev;
    headNode(nodeToRemove);
}

void setNode(int x, int y, int z, struct node* node)
{
    node->x = x;
    node->y = y;
    node->z = z;
}


int checkWin(struct node *nodeGiven)
{
    struct node *thisNode = nodeGiven;
    do
    {
        int a = board[nodeGiven->x] + board[nodeGiven->y] + board[nodeGiven->z];
        if(a == 3)
        {
            return 1;
        }
        else if(a == 12)
        {
            return 4;
        }
        nodeGiven = nodeGiven->next;
    }
    while(nodeGiven != thisNode);


    return 0;
}


/*void destroyNodeTree(struct node* headNode)
{
    struct node *startNode = headNode->next;
    while(startNode!=headNode)
    {
        struct node* prevNode = startNode;
        startNode = startNode->next;
        free(prevNode);
    }
    free(startNode);
}
*/

int gameWon()
{
    struct node* node = &node0;
    do
    {
        int a = board[node->x] + board[node->y] + board[node->z];
        if(a == 3*x)
        {
        	displayString(7, "X Wins!!\n");
          return 1;
        }
        else if(a == 3*o)
        {
            displayString(7, "Y Wins!!\n");
            return 1;
        }
        node = node->next;
    }
    while(node != &node0);

    int x = 1;
    for(int i = 0; i < 9; i++)
    {
        if(board[i] == none)
        {
            x = 0;
            break;
        }
    }
    if(x)
        displayString(7, "Tie !!\n");
    return x;

}

void onePeiceRow(int value, struct node *nodeUsed, struct node *winWayNode)
{
    int b,c;
    if(board[winWayNode->x] == value)
    {
        b = winWayNode->y;
        c = winWayNode->z;
    }
    else if(board[winWayNode->y] == value)
    {
        b = winWayNode->x;
        c = winWayNode->z;
    }
    else
    {
        b = winWayNode->x;
        c = winWayNode->y;
    }
    struct node* helpNode = nodeUsed;
    while(nodeUsed->next->x != -1)
    {
        nodeUsed = nodeUsed->next;
    }
    nodeUsed->next->x = b;
    nodeUsed = nodeUsed->next;
    nodeUsed->next->x = c;
    //nodeUsed->next->next = helpNode;
    nodeUsed = helpNode;

}

int testRand(int y )
{
	int x =  rand();
	if(x<0)
		x = -x % y;
	else
		x = x %  y;
	return x;
}

int takeTurn(int myValue)
{
		reset();
    int opValue = myValue == x ? o : x;
    if(turn == 1)
    {

        int x = testRand(4);
        if(x == 0)
            return 0;
        else if(x == 1)
            return 2;
        else if(x == 2)
            return 6;
        return 8;
    }
    else if(turn == 2)
    {
        int x = board[0] == opValue ? 1 : board[2] == opValue ? 1 : board[6] == opValue ? 1: board[8] == opValue ? 1 : 0;
        if(x)
            return 4;
        x = testRand(4);
        if(x == 0)
            return 0;
        else if(x == 1)
            return 2;
        else if(x == 2)
            return 6;
        return 8;
    }
    struct node* nodeMain = node0.next;
    struct node* nodePrev = &node0;
    /*struct node* nodeOurs;
    struct node* nextNode1;
    struct node* nextNode2;
    struct node* nextNode3;
    struct node* nextNode4;
    //nodeOurs->x = -1;
    nodeOurs->next = nextNode1;
    //nodeOurs->next->x = -1;
    nodeOurs->next->next = nextNode2;
    //nextNode2->x = -1;
    //nodeOurs->next->next->x = -1;
    nodeOurs->next->next->next = nextNode3;
    nodeOurs->next->next->next->x = -1;
    nodeOurs->next->next->next->next = nextNode4;
    nodeOurs->next->next->next->next->x = -1;
    nodeOurs->next->next->next->next->next = nodeOurs;*
    struct node* nodeOp;
    struct node* nextNode11;
    struct node* nextNode22;
    struct node* nextNode33;
    struct node* nextNode44;
    //nodeOp->x = -1;
    nodeOp->next = nextNode11;
    //nodeOp->next->x = -1;
    nodeOp->next->next = nextNode22;
    //nodeOp->next->next->x = -1;
    nodeOp->next->next->next = nextNode33;
    /*nodeOp->next->next->next->x = -1;
    nodeOp->next->next->next->next = nextNode44;
    nodeOp->next->next->next->next->x = -1;
    nodeOp->next->next->next->next->next = nodeOp;*/
    while(nodeMain != nodePrev)
    {
        int a = board[nodeMain->x] + board[nodeMain->y] + board[nodeMain->z];
        if(a == 2*x | a == 2*o)
        {
            //destroyNodeTree(nodeOurs);
            //destroyNodeTree(nodeOp);
            return board[nodeMain->x] == 0 ? nodeMain->x : board[nodeMain->y] == 0 ? nodeMain->y : nodeMain->z;
        }
        else if(a == myValue)
        {
            onePeiceRow(myValue, (&nodeOurs), nodeMain);

        }
        else if(a == opValue)
        {
            onePeiceRow(opValue, (&nodeOp), nodeMain);
        }
        nodeMain = nodeMain->next;
    }

    struct node *helper;
    helper = (&nodeOurs)->next;
    while(helper!=(&nodeOurs))
    {
        int b = helper->x;
        struct node *helper2 = helper->next;
        while(helper2!=helper)
        {
            if(helper2->x == b && b != -1)
            {
                //destroyNodeTree(nodeOurs);
                //destroyNodeTree(nodeOp);
                return b;
            }
            helper2 = helper2->next;
        }
        helper = helper->next;
    }

    helper = (&nodeOp)->next;
    while(helper!=(&nodeOp))
    {
        int b = helper->x;
        struct node *helper2 = helper->next;
        while(helper2!=helper)
        {
            if(helper2->x == b && b!= -1)
            {
                //destroyNodeTree(nodeOurs);
               //destroyNodeTree(nodeOp);
                return b;
            }
            helper2 = helper2->next;
        }
        helper = helper->next;
    }
    if((&nodeOurs)->next->x != -1)
    {
        struct node *helper = (&nodeOurs)->next;
        while(helper != (&nodeOurs))
        {
            if(helper->x == 0 | helper->x == 2 | helper->x == 6 | helper->x == 8)
            {
                int b = helper->x;
                //destroyNodeTree(nodeOurs);
                //destroyNodeTree(nodeOp);
                return b;
            }
            helper = helper->next;
        }
        int b = (&nodeOp)->next->x;
        //destroyNodeTree(nodeOurs);
        //destroyNodeTree(nodeOp);
        return b;
    }
    else if((&nodeOp)->next->x != -1)
    {
        struct node *helper = (&nodeOp)->next;
        while(helper != (&nodeOp))
        {
            if(helper->x == 0 | helper->x == 2| helper->x == 6 | helper->x == 8)
            {
                int b = helper->x;
                //destroyNodeTree(nodeOurs);
                //destroyNodeTree(nodeOp);
                return b;
            }
            helper = helper->next;
        }
        int b = (&nodeOp)->next->x;
        //destroyNodeTree(nodeOurs);
        //destroyNodeTree(nodeOp);
        return b;
    }

    for(int x = 0; x<9; x++)
    {
        if(board[x] == none)
        {
            return x;
        }
    }
    return -1;
}

void printBoard()
{
    char boardState[9];
    for(int i=0; i<9; i++)
    {
        if(board[i] == x)
            boardState[i] = 'x';
        else if(board[i] == o)
            boardState[i] = 'o';
        else
            boardState[i] = ' ';
    }
    char buffer[sizeof(char)*5];
    sprintf(buffer,"%c|%c|%c", boardState[0],boardState[1],boardState[2]);
    displayString(1,buffer);
    displayString(2,"-----");
    sprintf(buffer,"%c|%c|%c", boardState[3],boardState[4],boardState[5]);
    displayString(3,buffer);
    displayString(4,"-----");
    sprintf(buffer,"%c|%c|%c", boardState[6],boardState[7],boardState[8]);
    displayString(5,buffer);
}

task main()
{
    setNode(0,1,2,&node0);
    setNode(3,4,5,&node1);
    setNode(6,7,8,&node2);
    setNode(0,3,6,&node3);
    setNode(1,4,7,&node4);
    setNode(2,5,8,&node5);
    setNode(0,4,8,&node6);
    setNode(2,4,6,&node7);
    headNode(&node0); //node0->prev will always point to node0, don't use prev if using the node system for interation!
    addNode(&node0,&node1);
    addNode(&node1,&node2);
    addNode(&node2,&node3);
    addNode(&node3,&node4);
    addNode(&node4,&node5);
    addNode(&node5,&node6);
    addNode(&node6,&node7);
    settingUp();
    while(gameWon()==0)
    {
       if(turn%2)
        {
            board[takeTurn(x)] = x;
        }

        else
        {
            board[takeTurn(o)] = o;
        }
       turn++;
       printBoard();
       delay(1000);
    }
    displayString(9,"Game Over!\n");
    delay(10000);

}
