import sys

noOfNodes = int(sys.argv[1])
initiatorNode = int(sys.argv[2])

def bully_algorithm():
    print("BULLY ALGORITHM SIMULATION:")
    print('Node %s notices the current coordinator %s has failed' % (initiatorNode, noOfNodes))
    biggerNodes = []
    for i in range(initiatorNode+1, noOfNodes):
        print("%s sends ELECTION message to %s" % (initiatorNode,i))
        biggerNodes.append(i)
    for i in biggerNodes:
        print("%s sends OK message to %s" % (i, initiatorNode))
    while len(biggerNodes) != 1:
        i = biggerNodes[0]
        for j in range(i+1, noOfNodes):
            print("%s sends ELECTION message to %s" % (i, j))
        for k in range(i+1, noOfNodes):
            print("%s sends OK message to %s" % (k, i))
        biggerNodes.remove(i)
    newCoordinatorNode = biggerNodes[0]
    for i in range(0, newCoordinatorNode):
        print("%s sends COORDINATOR message to %s" %(newCoordinatorNode, i))

if __name__ == '__main__':
    bully_algorithm()