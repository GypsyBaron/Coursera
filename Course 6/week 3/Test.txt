import sys
import itertools

class BubbleDetector:

    def __init__(self, k, t, reads):
        self.k = k
        self.t = t
        self.g = {}
        self.paths = {}
        self.b = 0

        self.inn = lambda vertex: self.g[vertex][1] > 1
        self.out = lambda vertex: len(self.g[vertex][0]) > 1

        self.solveBubble(self.kMerFunction(reads))

	#Getting kmer
    def kMerFunction(self, reads):
        break_read = lambda read: [ read[j:j + self.k] for j in range(len(read) - self.k + 1) ]
        return [ kMerFunction for read in reads for kMerFunction in break_read(read) ]

	#Solving
    def solveBubble(self, kmers):

        def add_edge(g, left, right):
            g.setdefault(left, [set(), 0])
            g.setdefault(right, [set(), 0])
            
            if right not in g[left][0]:
                g[left][0].add(right)
                g[right][1] += 1

        for kMerFunction in kmers:
            left, right = kMerFunction[:-1], kMerFunction[1:]
            if left != right:
                add_edge(self.g, left, right)

	#Checking if path has a bubble
    def bubbles(self):
        for k, v in self.g.items():
            if self.out(k):
                self.dfs(path=[k], start=k, current=k, depth=0)

        for _, candidates_list in self.paths.items():
            for pair in itertools.combinations(candidates_list, r=2):
                if self.isConnected(pair):
                    self.b += 1

        return self.b

	#Returning the legth of the set pair
    def isConnected(self, pair):
        return len(set(pair[0]) & set(pair[1])) == 2

	#Running dfs thought path
    def dfs(self, path, start, current, depth):
        if current != start and self.inn(current):
            self.paths.setdefault((start, current), list()).append(path[:])

        if depth == self.t:
            return

        for next_ in self.g[current][0]:
            if next_ not in path:
                path.append(next_)
                self.dfs(path, start, next_, depth + 1)
                path.remove(next_)


if __name__ == "__main__":
    data = sys.stdin.read().split()
    k, t, reads = data[0], data[1], data[2:]
    print(BubbleDetector(int(k), int(t), reads).bubbles())