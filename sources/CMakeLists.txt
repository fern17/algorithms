cmake_minimum_required(VERSION 3.1)
SET(CMAKE_APP_NAME "Algorithms")

project (${CMAKE_APP_NAME})

INCLUDE_DIRECTORIES(tools)
INCLUDE_DIRECTORIES(sorting)
INCLUDE_DIRECTORIES(searching)
INCLUDE_DIRECTORIES(data_structures)
INCLUDE_DIRECTORIES(techniques)

add_executable(${CMAKE_APP_NAME} main.cpp 
tools/Tools.cpp 
tools/Tools.h 
sorting/Sorting.h 
searching/Searching.h 
data_structures/Heap.h 
data_structures/PriorityQueue.h 
data_structures/NodeSingleLinked.h 
data_structures/NodeDoubleLinked.h 
data_structures/Stack.h 
data_structures/Queue.h 
data_structures/Hash.h 
data_structures/Deque.h 
data_structures/Tree.h 
data_structures/NodeBinaryTree.h 
data_structures/BinaryTree.h
data_structures/NodeRBTree.h
data_structures/RBTree.h
data_structures/Matrix.h
techniques/DynamicProgramming.h
)