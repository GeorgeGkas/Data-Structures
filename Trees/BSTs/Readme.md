## BSTs (Binary Search Trees)

**BSTs (Binary Search Trees)** are a special category of binary trees, trees in which each node has at most two child nodes, that allow quick insertion, removal and traverse of each node. In BST, each node has a value greater than all nodes in the left subtree and less than all nodes in the right subtree *(we make the assumption that duplicates are not allowed in our implementation)*.

![Typical BST structure](http://storage2.static.itmages.com/i/17/0429/h_1493474162_6152056_7197840319.png)

Bellow we provide a simple instance. As you can see the above criteria are met. 

![BST example](http://storage7.static.itmages.com/i/17/0429/h_1493474925_5293235_b320989346.png)

### Basic Operations

**initBST(rootBST)**: for a given **rootBST** node, we initialize the BST tree.
**insertBSTNode(rootBST, x)**: insert item **x** to BST tree **rootBST**, if **x** is not exist.
**deleteBSTNode(rootBST, x)**: remove item **x** from BST tree **rootBST**, id **x** exist.
**searchBST(rootBST, x)**: search item **x** in BST tree **rootBST**.

### BST Traversal

Bellow we discuss some traversal methods we can use to get the nodes from a BST tree.

#### In-Order Traversal

**inOrderBST(rootBST)**: traverse BST tree **rootBST** with in-order form.

1. Traverse the left subtree by recursively calling **inOrderBST**.
2. If **node != empty** then visit the node.
3. Traverse the right subtree by recursively calling **inOrderBST**.

![BST In-order Traversal example](http://storage7.static.itmages.com/i/17/0429/h_1493477203_3052333_2cfca09af8.png)

***Note***: In BST tree, in-order traversal retrieves the nodes in sorted order.

#### Pre-Order Traversal

**preOrderBST(rootBST)**: traverse BST tree **rootBST** with pre-order form.

1. If **node != empty** then visit the node.
2. Traverse the left subtree by recursively calling **inOrderBST**.
3. Traverse the right subtree by recursively calling **inOrderBST**.

![BST pre-order Traversal example](http://storage7.static.itmages.com/i/17/0429/h_1493477511_3831110_803a4f4db0.png)

#### Post-Order Traversal

**postOrderBST(rootBST)**: traverse BST tree **rootBST** with post-order form.

1. Traverse the left subtree by recursively calling **inOrderBST**.
2. Traverse the right subtree by recursively calling **inOrderBST**.
3. If **node != empty** then visit the node.

![BST post-order Traversal example](http://storage3.static.itmages.com/i/17/0429/h_1493477911_5561446_23884aa4bf.png)