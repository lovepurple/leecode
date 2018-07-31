"""
    695.
    Given a non-empty 2D array grid of 0's and 1's, an island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.)
    You may assume all four edges of the grid are surrounded by water.

    Find the maximum area of an island in the given 2D array. (If there is no island, the maximum area is 0.)

    Example 1:
    [[0,0,1,0,0,0,0,1,0,0,0,0,0],
     [0,0,0,0,0,0,0,1,1,1,0,0,0],
     [0,1,1,0,1,0,0,0,0,0,0,0,0],
     [0,1,0,0,1,1,0,0,1,0,1,0,0],
     [0,1,0,0,1,1,0,0,1,1,1,0,0],
     [0,0,0,0,0,0,0,0,0,0,1,0,0],
     [0,0,0,0,0,0,0,1,1,1,0,0,0],
     [0,0,0,0,0,0,0,1,1,0,0,0,0]]
    Given the above grid, return 6. Note the answer is not 11, because the island must be connected 4-directionally.

    Example 2:
    [[0,0,0,0,0,0,0,0]]
    Given the above grid, return 0.

    note:
        求的是1最多连接在一起的数量，解题思路使用深搜
"""

class max_area_of_island:

    def maxAreaOfIslandInMatrix(self, grid):
        self._visited = [[0 for i in range(len(grid[0]))] for j in range(len(grid))]

        rowCount = len(grid)
        columnCount = len(grid[0])

        maxAreaIsland = 0

        for i in range(len(grid)):
            for j in range(len(grid[i])):
                if self.hasVisited(i, j):
                    continue
                else:
                    islandIndex = []
                    self.dfs(grid, i, j, rowCount, columnCount, islandIndex)

                    maxAreaIsland = max(maxAreaIsland, len(islandIndex))

        return maxAreaIsland

    def dfs(self, grid, rowNum, columnNum, gridTotalRows, gridTotalColumns, maxIslandIndexList):
        if rowNum >= gridTotalRows or rowNum < 0 or columnNum >= gridTotalColumns or columnNum < 0:
            return

        if self.hasVisited(rowNum, columnNum):
            return

        self._visited[rowNum][columnNum] = 1

        if grid[rowNum][columnNum] == 0:
            return
        else:
            maxIslandIndexList.append((rowNum, columnNum))
            self.dfs(grid, rowNum + 1, columnNum, gridTotalRows, gridTotalColumns, maxIslandIndexList)
            self.dfs(grid, rowNum - 1, columnNum, gridTotalRows, gridTotalColumns, maxIslandIndexList)
            self.dfs(grid, rowNum, columnNum + 1, gridTotalRows, gridTotalColumns, maxIslandIndexList)
            self.dfs(grid, rowNum, columnNum - 1, gridTotalRows, gridTotalColumns, maxIslandIndexList)

    def hasVisited(self, row, column):
        if row < 0 or row >= len(self._visited) or column < 0 or column >= len(self._visited[0]):
            return 1
        else:
            return self._visited[row][column] == 1


instance = max_area_of_island()
grid = [[0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0],
        [0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0],
        [0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0]]

print(instance.maxAreaOfIslandInMatrix(grid))
