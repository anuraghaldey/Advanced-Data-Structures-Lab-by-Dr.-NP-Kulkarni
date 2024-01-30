import sys

MAX = 20
INF = 999

class Graph:
    def __init__(self, n):
        self.n = n
        self.A = [[INF if i != j else 0 for j in range(n)] for i in range(n)]

    def create_graph(self):
        for i in range(self.n):
            for j in range(self.n):
                if i != j:
                    r = input(f"Are {i} and {j} adjacent? (Y/N)").lower()
                    if r == 'y':
                        w = int(input(f"Enter the weight of the edge ({i}, {j}): "))
                        self.A[i][j] = w


    def display_graph(self):
        print("Your graph is:")
        for row in self.A:
            print("\t".join(str(cell) for cell in row))

    def display_mst(self):
        visited = [0] * self.n
        print("Enter the starting vertex:")
        sv = int(input())
        visited[sv] = 1
        no_edge = 0
        cost_mst = 0
        print("Edges: Weight")
        while no_edge < self.n - 1:
            m = INF
            x = y = 0
            for i in range(self.n):
                if visited[i]:
                    for j in range(self.n):
                        if not visited[j] and self.A[i][j]:
                            if m > self.A[i][j]:
                                m = self.A[i][j]
                                x = i
                                y = j
            print(f"{x} -> {y}: {self.A[x][y]}")
            cost_mst += self.A[x][y]
            visited[y] = 1
            no_edge += 1
        print("Cost of MST:", cost_mst)

    def total_cost(self):
        tc = sum(self.A[i][j] for i in range(self.n) for j in range(i+1, self.n) if self.A[i][j])
        print("Total cost:", tc)


n = 0
while n != 5:
    print("1. Create graph")
    print("2. Display graph")
    print("3. Display minimum spanning tree")
    print("4. Display total cost")
    print("5. Exit")
    n = int(input("Enter your choice: "))
    
    if n == 1:
        print("Enter the number of vertices:")
        no_of_vertices = int(input())
        g = Graph(no_of_vertices)
        g.create_graph()
    elif n == 2:
        g.display_graph()
    elif n == 3:
        g.display_mst()
    elif n == 4:
        g.total_cost()
    elif n == 5:
        break
    else:
        print("Invalid choice.")
