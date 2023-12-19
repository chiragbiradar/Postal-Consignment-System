# Postal Consignment System

## Contributers
[Chirag Biradar](https://github.com/chiragbiradar)

[Jaswanth Reddy](https://github.com/jaswanth2003)

[B Ajay Kushal](https://github.com/ajaykushal4)


## Problem Statement
For many years, the department of posts (DoP) has been the backbone of the  country’s communication and has played a crucial role in the country’s social-economic development. It touches the lives of Indian citizens in many ways. India  has the largest postal network in the world
with more than 1,55,000 post offices and more than 5,66,000 employees.There are huge number of posts to be supplied to various destinations across the country. Also segregation of posts need to be done according to the city.

## Pain points
1. Finding the shortest path  between the cities for postal delivery.
2. storing the related data and  analysing the data.

3. Segregation of all posts should be done according to the city. Also if there are more than N posts to be delivered to same city, extra postman must be added to make      work more efficient.
4. All the input data need to be stored before we use random function for consideration of data. As we are not taking any input from user, it is typical to store            multiple information.

## Solution for Pain Points
### 1 .Dijkstra's algorithm
Dijkstra's algorithm is a famous and widely used graph traversal algorithm for finding the shortest path between nodes in a weighted graph. This algorithm was developed by Dutch computer scientist Edsger W. Dijkstra in 1956 and is often used in routing and as a subroutine in other graph algorithms. It is a greedy algorithm that works by selecting the node with the lowest distance from the source node and updating the distances of its neighbors. The algorithm maintains a set of visited nodes and a priority queue of nodes to be explored. The complexity of the algorithm is O((E+V)logV) in the worst case, where E is the number of edges and V is the number of vertices in the graph. Despite its efficiency, Dijkstra's algorithm may not work correctly if the graph contains negative-weight edges, as it assumes non-negative weights. Overall, Dijkstra's algorithm is a fundamental algorithm in computer science and plays a crucial role in solving many practical problems.

### 2. Array/Linked List
We need to store the data of the posts and the distance between the cities . data structures like arrays , linked list are used to store the data.
![Screenshot (177)](https://user-images.githubusercontent.com/83945477/200163619-053aa6af-e2b4-4932-900d-63c0b95c8805.png)

### 3. All the input part is stored in FILE memory where data can be read or written from the file whenever required.



![image](https://user-images.githubusercontent.com/78417411/200106762-254aee93-7e06-4651-a9b0-23dfe70183b5.png)

